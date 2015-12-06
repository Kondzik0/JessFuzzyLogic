#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>

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

private:
    Ui::MainWindow *ui;
    QString jessExePath;
};

#endif // MAINWINDOW_H
