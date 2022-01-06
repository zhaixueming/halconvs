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
	fileDlg->setWindowTitle(tr("��ͼƬ"));

	QStringList qstrFilters;
	qstrFilters << "Images (*.png *.bmp *.jpg)";
	qstrFilters << "All files(*)";
	fileDlg->setNameFilters(qstrFilters);            //�����ļ�������
	fileDlg->setFileMode(QFileDialog::ExistingFile); //����ѡ���ļ�������Ƕ���ļ���д��ExistingFiles
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
		//��ͼƬ
		ReadImage(&ho_Image, p2);                      //��ȡͼƬ
		GetImageSize(ho_Image, &hv_Width, &hv_Height); //���ͼ����

		std::cout << hv_Width.I() << std::endl;
		std::cout << hv_Height.I() << std::endl;

		//�������
		if (HDevWindowStack::IsOpen())
		{
			CloseWindow(HDevWindowStack::Pop()); //��λ�����Ҫ,�����޷�������ͼ����ʾ,�����̶���ʾ��һ�δ򿪵�ͼ
		}

		if (HDevWindowStack::IsOpen())
		{
			CloseWindow(HDevWindowStack::Pop()); //��λ�����Ҫ,�����޷�������ͼ����ʾ,�����̶���ʾ��һ�δ򿪵�ͼ
		}

		//��ʾ��graphicsView�ؼ�
		Hlong wndView = (Hlong)ui.graphicsView->winId();                                                                   //���graphicsView�ؼ����
		OpenWindow(0, 0, ui.graphicsView->width(), ui.graphicsView->height(), wndView, "visible", "", &hv_WindowHandle1); //�򿪴���
		HDevWindowStack::Push(hv_WindowHandle1);                                                                            //��λ�����Ҫ,�����޷�������ͼ����ʾ
		SetPart(hv_WindowHandle1, 0, 0, hv_Height, hv_Width);                                                               //����Ӧ����
		DispObj(ho_Image, hv_WindowHandle1);                                                                                //graphicsView�ؼ���ʾ

		//��ʾ��QLabel�ؼ�
		Hlong wndLabel = (Hlong)ui.label_pic->winId();                                                                //���Lable�ؼ����
		OpenWindow(0, 0, ui.label_pic->width(), ui.label_pic->height(), wndLabel, "visible", "", &hv_WindowHandle2); //�򿪴���
		HDevWindowStack::Push(hv_WindowHandle2);                                                                       //��λ�����Ҫ,�����޷�������ͼ����ʾ
		SetPart(hv_WindowHandle2, 0, 0, hv_Height, hv_Width);                                                          //����Ӧ����
		DispObj(ho_Image, hv_WindowHandle2);                                                                           //label��ʾ
	}
	catch (...)
	{
		std::cout << "err" << std::endl;
	}




}
