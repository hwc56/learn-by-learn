#include <Python.h>
#include <stdio.h>

int  main()
{
    Py_Initialize();
    PyRun_SimpleString("import  sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject  *pM = NULL;
    PyObject  *pF = NULL;
    pM = PyImport_ImportModule("helloWorld");
    pF = PyObject_GetAttrString(pM,"hello");
    PyEval_CallObject(pF,NULL);

    Py_Finalize();

    return  0;
}
