#include "ms_timer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MsTimer w;
	w.show();
	return a.exec();
}
