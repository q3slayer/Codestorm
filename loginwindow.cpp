#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_startButton_clicked()
{
    this->name = ui->startButton->text().toStdString();
    this->receiptNumber = ui->receiptNumber->text().toStdString();
    this->language = ui->languageBox->currentText().toStdString();
    this->difficulty = ui->difficultyBox->currentText().toStdString();

    this->codingWindow = new CodingWindow();
    this->codingWindow->setInfo(language);
    this->codingWindow->show();
    this->hide();

}
