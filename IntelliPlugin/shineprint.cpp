#include "shineprint.h"
#include <QDebug>
#include <QTextCodec>

ShinePrint::ShinePrint(QWidget *parent) :
    QLabel(parent)
{
    qDebug()<< "ShinePrint::ShinePrint () "<<  endl;
}
void ShinePrint::GetMessag()
{
      m_printInfo.GetMsg();
}
ShinePrint::~ShinePrint()
{
        qDebug()<<"ShinePrint::~ShinePrint ()"<<endl;
}

void ShinePrint::PrintMessag(QString msg)
{
        m_printInfo.PrintMsg(msg);
}
