#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actAbout_triggered();

    void on_btnSetJessPath_clicked();

    void on_btnRunJessProcess_clicked();

    void on_btnSaveInputsValues_clicked();

private:
    Ui::MainWindow *ui;
    QString jessExePath;
    QStringListModel *model;

    void openResults();
};

#endif // MAINWINDOW_H
