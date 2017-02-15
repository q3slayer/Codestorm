#include "codingwindow.h"
#include "ui_codingwindow.h"
#include <string>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <qtimer.h>

CodingWindow::CodingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodingWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    ui->codeText->setText(QString::fromStdString(default_code_text));
}

void CodingWindow::setInfo(std::string language){
    this->language = language;
    if(language == "C++"){
        default_code_text = "#include<stdio.h> // DO NOT DELETE THIS LINE\n\nint main(){\nfreopen (\"input\",\"r\",stdin); // DO NOT DELETE THIS LINE\n\n\nreturn 0;\n}";
        fileName = "code.cpp";
        commandName = "g++ code.cpp 2>&1";

    }
    else if(language == "C"){
        default_code_text = "#include<stdio.h> // DO NOT DELETE THIS LINE\n\nint main(){\nfreopen (\"input\",\"r\",stdin); // DO NOT DELETE THIS LINE\n\n\nreturn 0;\n}";
        fileName = "code.c";
        commandName = "gcc -std=c99 code.c 2>&1";
    }

    else if(language == "Python"){
        default_code_text = "import sys # DO NOT DELETE THIS LINE\n\n\n\nsys.stdin = open('input', 'r') # DO NOT DELETE THIS LINE";
        fileName = "code.py";
        commandName = "python code.py 2>&1";
    }

    else if(language == "Java"){
        default_code_text = "import java.io.File; // DO NOT DELETE THIS LINE\nimport java.io.FileInputStream; // DO NOT DELETE THIS LINE\n\n\npublic class Code{\n\npublic static void main(String[] args){\ntry{System.setIn(new FileInputStream(new File(\"input\")));}catch(Exception e){} // DO NOT DELETE THIS LINE\n\n}\n\n}";
        fileName = "Code.java";
        commandName = "javac Code.java 2>&1";
    }

    ui->codeText->setText(QString::fromStdString(default_code_text));

}


CodingWindow::~CodingWindow()
{
    delete ui;
}

void CodingWindow::on_executeButton_clicked()
{
    remove("a.exe");
    remove("Code.class");
    remove("input");
    std::ofstream inputFile("input");
    inputFile << ui->inputText->toPlainText().toStdString();
    inputFile.close();
    std::ofstream codeFile(fileName);
    codeFile << ui->codeText->toPlainText().toStdString();
    codeFile.close();
    std::string result = exec(commandName.c_str());
    if(is_file_exist("a.exe"))
        result += exec("a.exe 2>&1");
    if(is_file_exist("Code.class"))
        result += exec("java Code 2>&1");
    ui->outputText->setText(QString::fromStdString(result));

}

std::string CodingWindow::exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");

    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (std::exception e) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

bool CodingWindow::is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
