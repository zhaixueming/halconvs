#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_halconvs.h"
#pragma execution_character_set("utf-8")
class HalconVs : public QMainWindow
{
	Q_OBJECT

public:
	HalconVs(QWidget *parent = Q_NULLPTR);
	~HalconVs();

private slots:
	void on_pushButton_clicked();

private:
	void showPic(const QString &path);

private:
	Ui::HalconVsClass ui;
};
