#include <Python.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
module:    Python脚步的模块名
function:  要调用的函数名
format:    传递给Py_VaBuildValue函数的可变参数模板
 */
int PyCall( const char * module, const char * function, const char *format, ... )
{
    PyObject* pMod    = NULL;
    PyObject* pFunc   = NULL;
    PyObject* pParm   = NULL;
    PyObject* pRetVal = NULL;

    //导入模块
    if( !(pMod = PyImport_ImportModule(module) ) ){
        return -1;
    }
    //查找函数
    if( !(pFunc = PyObject_GetAttrString(pMod, function) ) ){
        return -2;
    }

    //创建参数
    va_list vargs;
    va_start( vargs, format );
    pParm = Py_VaBuildValue( format, vargs );
    va_end(vargs);

    //函数调用
    pRetVal = PyEval_CallObject( pFunc, pParm);

    //假定返回值为整形
    int ret;
    PyArg_Parse( pRetVal, "i", &ret );
    return ret;
}
#if 1
string  SPyCall( const char * module, const char * function, const char *format, ... )
{
    PyObject* pMod    = NULL;
    PyObject* pFunc   = NULL;
    PyObject* pParm   = NULL;
    PyObject* pRetVal = NULL;

    //导入模块
    if( !(pMod = PyImport_ImportModule(module) ) ){
        return "";
    }
    //查找函数
    if( !(pFunc = PyObject_GetAttrString(pMod, function) ) ){
        return "";
    }

    //创建参数
    va_list vargs;
    va_start( vargs, format );
    pParm = Py_VaBuildValue( format, vargs );
    va_end(vargs);

    //函数调用
    pRetVal = PyEval_CallObject( pFunc, pParm);

    //假定返回值为整形
    string  *ret;
    PyArg_Parse( pRetVal, "s", ret );
    return *ret;
}
#endif
    /* 这做个简单的说明
     ** format参数用()扩起来是表示元组的意思。元组中的个数对应Python脚本中的参数。
     ** 因为fun,fun1,fun2函数的参数个数分别是 0,1,2，所以，元组中的个数必须为0,1,2，不然调用将失
     ** 败。当然，元组中的每个元素都是可以为任意的类型，比如：
     **     PyCall( "pytest", "fun2", "( i,{s:s,s:s})", 2, "name", "linxr", "age", "25" );
     */
int  main(int  argc,char *argv[])
 {
         Py_Initialize();
         PyRun_SimpleString("import sys");
         PyRun_SimpleString("sys.path.append('./')");
         //PyObject  *pM = NULL;
         //PyObject  *pF = NULL;
         //PyObject  *pParm = NULL;
         //PyObject  *pRetVal = NULL;
         //pM = PyImport_ImportModule("lx");
         //pF = PyObject_GetAttrString(pM,"setup_dbus");
         //PyEval_CallObject(pF,NULL);
         printf( "ret = %d\n", PyCall( "lx","setup_dbus","()"));
         printf( "ret = %d\n", PyCall( "lx","minterface","()"));
         if(argc > 1)
        {
         //printf( "ret = %d\n", PyCall( "lx","disconnect", "(i)",atoi(argv[1])));
         if(argc > 3)
         printf( "ret = %d\n", PyCall( "lx","encryption_connect", "(iss)",atoi(argv[1]),argv[2],argv[3]));
         printf( "ret = %s\n", SPyCall( "lx","WirelessNetworkEntry", "(i)",atoi(argv[1])).c_str());
         }
         //printf( "ret = %d\n", PyCall( "lx", "fun2", "(is)", 12, "12"));
 
         Py_Finalize();
         return  0;
 }
