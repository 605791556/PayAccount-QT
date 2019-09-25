#include "myThread.h"

myThread::myThread(QObject *parent)
	: QThread(parent)
{
	m_bStop = false;
	m_hSupendEvent = CreateEvent(NULL,TRUE,TRUE,NULL); //初始有信号
}

myThread::~myThread()
{
	SetEvent(m_hSupendEvent);
}

void myThread::run()
{
	m_bStop = false;
	for (int i=0;i<100 && !m_bStop;i++)
	{
		WaitForSingleObject(m_hSupendEvent,INFINITE);

		QThread::msleep(20);
		emit signUpPro(i+1);
	}
}

void myThread::suspend()//暂停
{
	ResetEvent(m_hSupendEvent);
}

void myThread::continueThd()//继续
{
	SetEvent(m_hSupendEvent);
}

void myThread::stop()
{
	SetEvent(m_hSupendEvent);
	m_bStop = true;
}
