#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<iostream>
#include <QDragEnterEvent>
#include<QDialog>
#include <QUrl>
#include <QFile>
#include <QMimeData>
#include <QTextStream>
#include<QString>
#include<QSet>
#include <QTextStream>
#include <stdio.h>
using namespace std;
myMainWindow::myMainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{

    ui->setupUi(this);
}

QString myMainWindow::scan(QString code)
{
    QString output;
    QSet<QString>::iterator iter;
    int lastword=-1;//0是数字 1是关键字 2是标识符 3是字符串 4是注释 5是运算符
    QString word;//存储单词
    int i=0;
    bool dot=false;
    while(i < code.length())
    {
        word="";
        if (code[i] == ' ' || code[i] == '\n'||code[i]=='\t')
           { i++;
            continue;}
        //识别数字
        if ((code[i] >= '0' && code[i] <= '9') || code[i] == '+' || code[i] == '-' || code[i] == '.')
                {
                    string codei;
                    bool dot = false;
                    if (code[i] == '+' || code[i] == '-')
                    {
                        if (lastword == 2)
                        {
                            word += code[i];
                            i++;
                            if (code[i - 1] == '+' && code[i] == '+')
                            {
                                word += code[i];
                                i++;
                            }
                            if (code[i - 1] == '-' && code[i] == '-')
                            {
                                word += code[i];
                                i++;
                            }
                            if (code[i - 1] == '-' && code[i] == '=')
                            {
                                word += code[i];
                                i++;
                            }
                            if (code[i - 1] == '+' && code[i] == '=')
                            {
                                word += code[i];
                                i++;
                            }
                            if (code[i - 1] == '-' && code[i] == '>')
                            {
                                word += code[i];
                                i++;
                                if (code[i] == '*')
                                {
                                    word += code[i];
                                    i++;
                                }
                            }
                            QString temp = word + ": 运算符\n";
                            output += temp;
                            lastword = 5;
                            continue;

                        }
                        else
                        {
                            word += code[i];
                            i++;
                            if (code[i] == '.')
                            {
                                dot = true;
                                word += code[i];
                                i++;
                                if (code[i] == 'E' || code[i] == 'e')
                                {
                                    cout << "error";
                                }
                                while (code[i] >= '0' && code[i] <= '9')
                                {
                                    word += code[i];
                                    i++;
                                }
                                if (code[i] == 'E' || code[i] == 'e')
                                {
                                    word += code[i];
                                    i++;
                                }
                                    if (code[i] == '+' || code[i] == '-')
                                    {
                                        word += code[i];
                                        i++;
                                        if (code[i] >= '0' && code[i] <= '9')
                                        {
                                            while (code[i] >= '0' && code[i] <= '9')
                                            {
                                                word += code[i];
                                                i++;
                                            }
                                            if (code[i] == 'f' || code[i] == 'F')
                                            {
                                                word += code[i];
                                                i++;
                                            }
                                            QString temp = word + ": 科学计数法表示数\n";
                                            output += temp;
                                            lastword = 0;
                                            continue;
                                        }
                                        else
                                        {
                                            cout << "error";
                                        }

                                }
                                else
                                {
                                    QString temp = word + ": 浮点数\n";
                                    output += temp;
                                    lastword = 0;
                                    continue;
                                }
                            }
                            QString temp = word + ": 特殊符号\n";
                            output += temp;
                            lastword = 0;
                            continue;
                        }
                    }
                    if (code[i] == '.')
                    {
                        dot = true;
                        word += code[i];
                        i++;

                        while (code[i] >= '0' && code[i] <= '9')
                        {
                            word += code[i];
                            i++;
                        }
                        if (code[i] == 'E' || code[i] == 'e')
                        {
                            word += code[i];
                            i++;
                            if (code[i] == '+' || code[i] == '-')
                            {
                                word += code[i];
                                i++;
                                if (code[i] >= '0' && code[i] <= '9')
                                {
                                    while (code[i] >= '0' && code[i] <= '9')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    if (code[i] == 'f' || code[i] == 'F')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    QString temp = word + ": 科学计数法表示的数\n";
                                    output += temp;
                                    lastword = 0;
                                    continue;
                                }
                                else
                                {
                                    cout << "error";
                                }
                            }
                            else if (code[i] >= '0' && code[i] <= '9')
                            {
                                while (code[i] >= '0' && code[i] <= '9')
                                {
                                    word += code[i];
                                    i++;
                                }
                            }
                        }
                        else
                        {
                            QString temp = word + ": 浮点数\n";
                            output += temp;
                            lastword = 0;
                            continue;
                        }
                    }
                    if (code[i] >= '0' && code[i] <= '9')
                    {
                        if (code[i] == '0')
                        {
                            word += code[i];
                            i++;
                            if (code[i] >= '0' && code[i] <= '9')
                            {
                                while (code[i] >= '0' && code[i] <= '9')
                                {
                                    word += code[i];
                                    i++;
                                }
                                QString temp = word + ": 八进制数\n";
                                output += temp;
                                lastword = 0;
                                continue;
                            }
                            else if (code[i] == 'b' || code[i] == 'B')
                            {
                                word += code[i];
                                i++;
                                while (code[i] >= '0' && code[i] <= '9')
                                {
                                    word += code[i];
                                    i++;
                                }
                                QString temp = word + ": 二进制数\n";
                                output += temp;
                                lastword = 0;
                                continue;
                            }
                            else if (code[i] == 'x' || code[i] == 'X')
                            {
                                word += code[i];
                                i++;
                                while (code[i] >= '0' && code[i] <= '9' || code[i] >= 'a' && code[i] <= 'f' || code[i] >= 'A' && code[i] <= 'F')
                                {
                                    word += code[i];
                                    i++;
                                }
                                QString temp = word + ": 十六进制数\n";
                                output += temp;
                                lastword = 0;
                                continue;
                            }
                            else if (code[i] == '.')
                            {
                                dot = true;
                                word += code[i];
                                i++;

                                while (code[i] >= '0' && code[i] <= '9')
                                {
                                    word += code[i];
                                    i++;
                                }
                                if (code[i] == 'E' || code[i] == 'e')
                                {
                                    word += code[i];
                                    i++;
                                    if (code[i] == '+' || code[i] == '-')
                                    {
                                        word += code[i];
                                        i++;
                                        if (code[i] >= '0' && code[i] <= '9')
                                        {
                                            while (code[i] >= '0' && code[i] <= '9')
                                            {
                                                word += code[i];
                                                i++;
                                            }
                                            if (code[i] == 'f' || code[i] == 'F')
                                            {
                                                word += code[i];
                                                i++;
                                            }
                                            QString temp = word + ": 科学计数法表示的数\n";
                                            output += temp;
                                            lastword = 0;
                                            continue;
                                        }
                                        else
                                        {
                                            cout << "error";
                                        }
                                    }
                                    else if (code[i] >= '0' && code[i] <= '9')
                                    {
                                        while (code[i] >= '0' && code[i] <= '9')
                                        {
                                            word += code[i];
                                            i++;
                                        }
                                    }
                                }
                                else
                                {
                                    QString temp = word + ": 浮点数\n";
                                    output += temp;
                                    lastword = 0;
                                    continue;
                                }
                            }
                            else
                            {

                                QString temp = word + ": 数\n";
                                output += temp;
                                lastword = 0;
                                continue;
                            }
                        }
                        else if (code[i] >= '1' && code[i] <= '9')
                        {
                            while (code[i] >= '0' && code[i] <= '9')
                            {
                                word += code[i];
                                i++;
                            }
                        }
                        if (code[i] == 'E' || code[i] == 'e')
                        {
                            word += code[i];
                            i++;
                            if (code[i] == '+' || code[i] == '-')
                            {
                                word += code[i];
                                i++;
                            }
                                if (code[i] >= '0' && code[i] <= '9')
                                {
                                    while (code[i] >= '0' && code[i] <= '9')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    if (code[i] == 'f' || code[i] == 'F')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    QString temp = word + ": 科学计数法表示数\n";
                                    output += temp;
                                    lastword = 0;
                                    continue;
                                }
                                else
                                {
                                    cout << "error";
                                }

                        }
                        if (code[i] == '.')
                        {
                            dot = true;
                            word += code[i];
                            i++;
                            if (code[i] == 'E' || code[i] == 'e')
                            {
                                cout << "error";
                            }
                            while (code[i] >= '0' && code[i] <= '9')
                            {
                                word += code[i];
                                i++;
                            }
                            if (code[i] == 'E' || code[i] == 'e')
                            {
                                word += code[i];
                                i++;
                            }
                                if (code[i] == '+' || code[i] == '-')
                                {
                                    word += code[i];
                                    i++;
                                }
                                if (code[i] >= '0' && code[i] <= '9')
                                {
                                    while (code[i] >= '0' && code[i] <= '9')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    if (code[i] == 'f' || code[i] == 'F')
                                    {
                                        word += code[i];
                                        i++;
                                    }
                                    QString temp = word + ": 科学计数法表示数\n";
                                    output += temp;
                                    lastword = 0;
                                    continue;
                                }
                                else
                                {
                                    cout << "error";
                                }




                        }
                        QString temp = word + ": 数\n";
                        output += temp;
                        lastword = 0;
                        continue;
                    }

                    continue;
                }

        //匹配关键字和标识符
        else if ((code[i] >= 'a' && code[i] <= 'z') ||( code[i] >= 'A' && code[i] <= 'Z')||code[i]=='_')
        {
            QString codei;
            codei=code[i];
            while (code[i]!='\000'&&code[i] != ' ' && code[i] != '\n' && (((iter = opera.find(codei)) == opera.end())&&((iter= special_numeric.find(codei))==special_numeric.end()) || code[i] == '_'))
            {

                codei = code[i];
                word += code[i];
                i++;
                codei = code[i];
            }
            iter = key_word.find(word);
            if (iter != key_word.end())
            {
                QString temp=word+ ": 关键字\n";
                output+=temp;
                lastword = 1;
                word = "";
            }
            else
            {
                QString temp=word+ ": 标识符\n";
                output+=temp;
                lastword = 2;
                word = "";
            }

            continue;
        }
        //匹配字符串
        else if (code[i] == '"')
        {
            word+=code[i];
            i++;
            while (code[i] != '"')
            {
                word += code[i];
                i++;


            }
            word += '"';
            i++;
            QString temp=word+ ": 字符串\n";
            output+=temp;

            lastword = 3;
            word="";

        }
        //匹配注释
        else if (code[i] == '/')
        {
            word += code[i];
            i++;
            if (code[i] == '/')
            {
                word += code[i];
                i++;
                while (code[i] != '\n')
                {              
                    if(code[i]=='\n')break;
                    word += code[i];
                    i++;
                }
                QString temp=word+ ": 注释\n";
                output+=temp;
                lastword = 4;
                word = "";

            }
            else if (code[i] == '*')
            {
                word+=code[i];
                i++;
                if(i==code.length())
                {
                    ui->t2->setPlainText("源程序不合法！结束程序！");
                    return "0";
                }
                word+=code[i];
                i++;
                if(i==code.length())
                {
                    ui->t2->setPlainText("源程序不合法！结束程序！");
                    return "0";
                }
                while (code[i - 1] != '*' && code[i] != '/')
                {                 
                    word += code[i];
                    i++;
                }
                word += code[i];
                i++;
                QString temp=word+ ": 注释\n";
                output+=temp;

                lastword = 4;
                word = "";

            }
            else
            {
                QString temp=word+ ": 运算符\n";
                output+=temp;

                lastword = 5;
                word = "";
            }

        }
        else
        {
            if(!((code[i] >= '0' && code[i] <= '9') || (code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')))
            {
                word += code[i];
                i++;
            }


                QString temp=word+ ": 特殊符号\n";
                output+=temp;
                lastword = 5;
                word = "";



        }
    }
    return output;
}



myMainWindow::~myMainWindow()
{
    delete ui;
}
/*拖放分为拖动(Drag)和放下(Drop)两种操作。数据拖动时会被存储为MIME(Multipurpose-
 * Internet Mail Extensions)类型，在Qt使用QMimeData类来表示MIME类型数据，并还用
 * QDrag类来完成数据的转换，而整个拖放操作都是在几个鼠标事件和拖放事件中完成.
*/





void myMainWindow::on_pushButton_clicked()
{
    QString text;
    try{
     text=ui->t1->toPlainText();
    }
    catch(std::bad_alloc)
    {
        QTextStream cout(stdout,  QIODevice::WriteOnly);
        cout<<1;
    }



    QString ans_code="词法分析如下：\n";
    ans_code.append(scan(text));
    ui->t2->setPlainText(ans_code);
}
