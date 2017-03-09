#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simplecrypt.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

if(ui->lineEdit->text() == "" || ui->textEdit->toPlainText() == ""){
QMessageBox::about(this,"Key Error!","Please enter a Key Value and Note it Down! or Enter a valid text in Input");
}

else {

SimpleCrypt setEncryptionKey(ui->lineEdit->text().toInt());
QString encryptInput(ui->textEdit->toPlainText());

QString encryptedOutput;

encryptedOutput = setEncryptionKey.encryptToString(encryptInput);
ui->textEdit_2->setText(encryptedOutput);

 }

}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "" || ui->textEdit_2->toPlainText() == ""){
QMessageBox::about(this,"Key Error!","Please enter a Key Value or Enter valid text in Encrypted text box.");
    }

else
    {

    SimpleCrypt setEncryptionKey(ui->lineEdit->text().toInt());

    QString decryptedString = setEncryptionKey.decryptToString(ui->textEdit_2->toPlainText());
    ui->textEdit->setText(decryptedString);
}

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_actionClear_Text_triggered()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void MainWindow::on_actionEncrypt_Text_triggered()
{
    ui->pushButton->animateClick();
}

void MainWindow::on_actionDecrypt_Text_triggered()
{
    ui->pushButton_2->animateClick();
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QFile file (file_name);
    file_path=file_name;

     if(!file.open(QFile::ReadOnly | QFile::Text)){
       return;
     }
     else{
       //Read the file
       QTextStream inputData(&file);
       QString fileText = inputData.readAll();
       ui->textEdit_2->setText(fileText);
       file.close();
     }
}

void MainWindow::on_actionSave_Encrypted_Text_triggered()
{
    QFile file(file_path);
   if(!file.open(QFile::WriteOnly | QFile::Text)){
     //Simply return if the user cancels or does something unexpected!
     return;
   }
   else{
     //Read the file
     QTextStream writeData(&file);
     QString fileText = ui->textEdit_2->toPlainText();
     writeData << fileText;
     file.flush();
     file.close();
   }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open a file");
    QFile file (file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
       //Simply return if the user cancels or does something unexpected!
        return;
     }
     else{
       //Read the file
       QTextStream writeData(&file);
       QString fileText = ui->textEdit_2->toPlainText();
       writeData << fileText;
       file.flush();
       file.close();
     }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_Encryption_Program_triggered()
{
 QMessageBox::about(this,"About Text Encryption Program","Simple Encryption Example! Not for Commercial Use");
}

void MainWindow::on_actionNew_triggered()
{
    file_path=""; // Clear the path
    ui->textEdit->setText(""); // Make the encrypt and decryptor blank
    ui->textEdit_2->setText("");
}

void MainWindow::on_actionOpen_Plain_Text_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QFile file (file_name);
    file_path=file_name;

     if(!file.open(QFile::ReadOnly | QFile::Text)){
       QMessageBox::critical(this,"Error Opening File","File Cannot be Opened!");
       return;
     }
     else{
       //Read the file
       QTextStream inputData(&file);
       QString fileText = inputData.readAll();
       ui->textEdit->setHtml(fileText);
       file.close();
     }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt using which the Encryption program was created");
}
