#ifndef CODINGWINDOW_H
#define CODINGWINDOW_H

#include <QMainWindow>
#include <string>

namespace Ui {
class CodingWindow;
}

class CodingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CodingWindow(QWidget *parent = 0);
    void setInfo(std::string language);
    ~CodingWindow();

private slots:
    void on_executeButton_clicked();
    std::string exec(const char* cmd);
    bool is_file_exist(const char* fileName);

private:
    Ui::CodingWindow *ui;
    std::string default_code_text;
    std::string language;
    std::string fileName;
    std::string commandName;
};

#endif // CODINGWINDOW_H
