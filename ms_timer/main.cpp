#include "ms_timer.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setWindowIcon(QIcon(":/res/logo.ico"));
	MsTimer w;
	w.show();
	return a.exec();
}
