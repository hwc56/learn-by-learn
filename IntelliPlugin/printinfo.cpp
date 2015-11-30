#include "printinfo.h"
#include <QMessageBox>
#include <QWebView>
#include <QWebFrame>
#include <QDebug>
#include <QApplication>

extern QWebView* view;
class QWebFrame;
PrintInfo::PrintInfo()
{
}

void  PrintInfo::GetMsg()
{
    view->page()->mainFrame()->evaluateJavaScript("JavaAlert(\"this is Qt data\");");;
}
void PrintInfo::PrintMsg(QString msg)
{
//        QMessageBox msgBox;
        //QFont font;
         //font.setPixelSize(30);
         //msgBox.setFont(font);
//         msgBox.setText(msg);
//         msgBox.setInformativeText("Just for test!");
//         msgBox.setStandardButtons(QMessageBox::Save |QMessageBox::Cancel);
//         msgBox.setDefaultButton(QMessageBox::Save);
//         msgBox.exec();
    qDebug()<<"JavaScript data :"+msg<<endl;
    view->page()->mainFrame()->evaluateJavaScript("JavaAlert(\"this is Qt data\");");

         qApp->exit(0);
}
