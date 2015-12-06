#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Jess Fuzzy Logic");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actAbout_triggered()
{
    QMessageBox::information(this,"Information","Designed by:\n Konrad Lata\n email: konzdik0@gmail.com\n AGH University Of Science and Technology 2015",QMessageBox::Ok);
}

void MainWindow::on_btnSetJessPath_clicked()
{
    jessExePath = QFileDialog::getOpenFileName(this, "Open Jess","/home","*.bat");
    if(jessExePath.isEmpty())
    {
        return;
    }
    else
    {
        ui->lnlJessPath->setText(jessExePath);
    }
}

void MainWindow::on_btnRunJessProcess_clicked()
{
    if(ui->lnlJessPath->text().isEmpty())
    {
        QMessageBox::information(this,"ERROR!","SET JESS PATH TO START!",QMessageBox::Ok);
        return;
    }
    else
    {
        QString clpPath = QFileDialog::getOpenFileName(this,"Choose clp File","/home","*.clp");
        //QProcess::start(jessExePath,path,QIODevice::ReadOnly);
    }

}
