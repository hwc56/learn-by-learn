#include <QtGui/QApplication>
#include <QtWebKit>
#include <QTimer>

#include "intelliplugin.h"

QWebView* view =NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *gbk = QTextCodec::codecForName("gb18030");
    QTextCodec::setCodecForTr(gbk);
    QTextCodec::setCodecForLocale(gbk);
    QTextCodec::setCodecForCStrings(gbk);

    QFont font;
    font.setPixelSize(30);
    a.setFont(font);

    qDebug()<<"Enter main()"<<endl;
    view = new QWebView;
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setGeometry(50, 50, 1024, 768);

    view->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    view->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);

    view->page()->setPluginFactory(new IntelliPlugin);
    view->load(QUrl("test_2.html"));

    view->show();

    return a.exec();
}

