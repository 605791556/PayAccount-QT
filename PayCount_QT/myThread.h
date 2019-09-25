#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <Windows.h>

class myThread : public QThread
{
	Q_OBJECT

public:
	myThread(QObject *parent);
	~myThread();

signals:
	void signUpPro(int nValue);

public:
	void run();
	void suspend();//ÔÝÍ£
	void continueThd();//¼ÌÐø
	void stop();
	

private:
	bool m_bStop;
	HANDLE m_hSupendEvent;//ÔÝÍ£±êÖ¾
};

#endif // MYTHREAD_H
