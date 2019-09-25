
#include "paycount_qt.h"
#include "CLogin.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CLogin lg;
	if(lg.exec() == QDialog::Accepted)
	{
		PayCount_QT w;
		w.show();
		return a.exec();
	}
	return 0;
}
