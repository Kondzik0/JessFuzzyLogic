#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTextStream>

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
        QStringList arguments;
        arguments << "radioVolumeControl.clp";

        QProcess *jessProcessStart = new QProcess();
        jessProcessStart->start(jessExePath,arguments);
        jessProcessStart->waitForFinished(100);
        openResults();
    }


}
void MainWindow::on_btnSaveInputsValues_clicked()
{
    QFile inputsFile("inputsVal.clp");
    if(!inputsFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream stream(&inputsFile);

    stream << "(defglobal ?*zmPredkosciSamochodu* = " + QString::number(ui->spnSetFirstInput->value()) + " )"+"\n";
    stream << "(defglobal ?*zmHalWewnSam* = " + QString::number(ui->spnSetSecondInput->value()) + " )"+"\n";

    inputsFile.close();
    QMessageBox::information(this,"Info","Save complete",QMessageBox::Ok);
}

void MainWindow::openResults()
{
    ui->tblShowResults->reset();
    QFile inputsFile("results.txt");
    if(!inputsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QStringList list;
    QTextStream stream(&inputsFile);
    list.clear();
    while(!stream.atEnd())
    {
        list.append(stream.readAll());
    }
    inputsFile.close();
    model = new QStringListModel(list);
    ui->tblShowResults->setModel(model);

}
