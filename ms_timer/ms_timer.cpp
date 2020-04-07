#include "ms_timer.h"
#include <qdebug.h>

MsTimer::MsTimer(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::MsTimerClass),
	ms_(0),
	sec_(0),
	min_(0)
{
	ui->setupUi(this);

	_timer = new QTimer(this);

	QObject::connect(_timer, &QTimer::timeout, this, &MsTimer::onTime);

	_timer->setInterval(std::chrono::milliseconds(1));

}

void MsTimer::onTime()
{
	++ms_;
	if (ms_ == 1000)
	{
		++sec_;
		ms_ = 0;
		if (sec_ == 60)
		{
			sec_ = 0;
			++min_;
			if (min_ == 100) min_ = 0;
		}
	}
	flushView();
}


void MsTimer::on_startBtn_clicked()
{
	_timer->start();
}

void MsTimer::on_stopBtn_clicked()
{
	_timer->stop();
}

void MsTimer::on_restartBtn_clicked()
{
	ms_ = 0;
	sec_ = 0;
	min_ = 0;
	flushView();
}


void MsTimer::flushView()
{
	QString str = QString("%1:%2:%3").arg(min_, 2, 10, QLatin1Char('0')).arg(sec_, 2, 10, QLatin1Char('0')).arg(ms_, 3, 10, QLatin1Char('0'));
	ui->ms_lab->setText(str);
}


