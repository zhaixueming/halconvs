#include "halconvs.h"
#include <QFileDialog>

#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#  if defined(__linux__) && (defined(__i386__) || defined(__x86_64__)) \
                         && !defined(NO_EXPORT_APP_MAIN)
#    include <X11/Xlib.h>
#  endif
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#  include <stdio.h>
#  include <HALCON/HpThread.h>
#  include <CoreFoundation/CFRunLoop.h>
#endif



using namespace HalconCpp;

HalconVs::HalconVs(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

HalconVs::~HalconVs()
{
}

void HalconVs::on_pushButton_clicked()
{
	QFileDialog *fileDlg = new QFileDialog(this);
	fileDlg->setWindowTitle(tr("打开图片"));

	QStringList qstrFilters;
	qstrFilters << "Images (*.png *.bmp *.jpg)";
	qstrFilters << "All files(*)";
	fileDlg->setNameFilters(qstrFilters);            //设置文件过滤器
	fileDlg->setFileMode(QFileDialog::ExistingFile); //设置选择单文件，如果是多个文件就写成ExistingFiles
	fileDlg->setAcceptMode(QFileDialog::AcceptOpen);

	if (fileDlg->exec() == QDialog::Accepted)
	{
		QStringList strPathList = fileDlg->selectedFiles();
		if (strPathList.count() > 0)
		{
			showPic(strPathList.at(0));
		}
	}

	fileDlg->close();
	delete fileDlg;
	fileDlg = nullptr;





}

void HalconVs::showPic(const QString & path)
{
	HObject ho_Image;
	HTuple hv_Width, hv_Height, hv_WindowHandle1, hv_WindowHandle2;

	std::string p1 = path.toStdString();
	const char *p2 = p1.c_str();

	try
	{
		//打开图片
		ReadImage(&ho_Image, p2);                      //读取图片
		GetImageSize(ho_Image, &hv_Width, &hv_Height); //获得图像宽高

		std::cout << hv_Width.I() << std::endl;
		std::cout << hv_Height.I() << std::endl;

		//清除缓存
		if (HDevWindowStack::IsOpen())
		{
			CloseWindow(HDevWindowStack::Pop()); //这段话很重要,否则无法连续打开图像显示,仅仅固定显示第一次打开的图
		}

		if (HDevWindowStack::IsOpen())
		{
			CloseWindow(HDevWindowStack::Pop()); //这段话很重要,否则无法连续打开图像显示,仅仅固定显示第一次打开的图
		}

		//显示在graphicsView控件
		Hlong wndView = (Hlong)ui.graphicsView->winId();                                                                   //获得graphicsView控件句柄
		OpenWindow(0, 0, ui.graphicsView->width(), ui.graphicsView->height(), wndView, "visible", "", &hv_WindowHandle1); //打开窗口
		HDevWindowStack::Push(hv_WindowHandle1);                                                                            //这段话很重要,否则无法连续打开图像显示
		SetPart(hv_WindowHandle1, 0, 0, hv_Height, hv_Width);                                                               //自适应窗口
		DispObj(ho_Image, hv_WindowHandle1);                                                                                //graphicsView控件显示

		//显示在QLabel控件
		Hlong wndLabel = (Hlong)ui.label_pic->winId();                                                                //获得Lable控件句柄
		OpenWindow(0, 0, ui.label_pic->width(), ui.label_pic->height(), wndLabel, "visible", "", &hv_WindowHandle2); //打开窗口
		HDevWindowStack::Push(hv_WindowHandle2);                                                                       //这段话很重要,否则无法连续打开图像显示
		SetPart(hv_WindowHandle2, 0, 0, hv_Height, hv_Width);                                                          //自适应窗口
		DispObj(ho_Image, hv_WindowHandle2);                                                                           //label显示
	}
	catch (...)
	{
		std::cout << "err" << std::endl;
	}




}
