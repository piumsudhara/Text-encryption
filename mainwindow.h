#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QTextCursor>
#include <QtGui>


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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionClear_Text_triggered();

    void on_actionEncrypt_Text_triggered();

    void on_actionDecrypt_Text_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_Encrypted_Text_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_Encryption_Program_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_Plain_Text_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};

#endif // MAINWINDOW_H
