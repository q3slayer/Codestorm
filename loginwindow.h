#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "codingwindow.h"
#include <string>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_startButton_clicked();

private:
    Ui::LoginWindow *ui;
    CodingWindow *codingWindow;
    std::string name;
    std::string receiptNumber;
    std::string language;
    std::string difficulty;

};

#endif // LOGINWINDOW_H
