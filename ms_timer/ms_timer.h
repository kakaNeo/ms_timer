#pragma once

#include <QtWidgets/QWidget>
#include "ui_ms_timer.h"
#include <QTimer>


class MsTimer : public QWidget
{
	Q_OBJECT

public:
	MsTimer(QWidget *parent = Q_NULLPTR);

	void onTime();

	void flushView();

private slots:
	void on_startBtn_clicked();
	void on_stopBtn_clicked();
	void on_restartBtn_clicked();
private:

	int ms_;
	int sec_;
	int min_;
	Ui::MsTimerClass *ui;

	QTimer *_timer;
};
