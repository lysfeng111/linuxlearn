#include <QApplication>
#include <QDialog>
int main(int args,char **argv)
{
	QApplication app(args,argv);
	//////////////////////////////
	
	QDialog dlg;
	dlg.setVisible(true);



	/////////////////////////////
	return app.exec();	//等待所有子线程结束，主线程才结束
}
