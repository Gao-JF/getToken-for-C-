#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include<QSet>
#include<QString>
namespace Ui {
class myMainWindow;
}

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit myMainWindow(QWidget *parent = 0);
    ~myMainWindow();

private:
    Ui::myMainWindow *ui;
    QTextEdit *textEdit;
    QTextEdit *ans;


    QSet<QString>key_word= {"do","while","include","define","ifndef", "alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool","break","case","catch","char","char8_t","char16_t","char32_t","class","compl","concept","const","const_cast","consteval","constexpr","constinit","continue","co_await","co_return","co_yield","decltype","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","private","protected","public","register reinterpret_cast","requires","return","short","signed","sizeof","static","static_assert","static_cast","struct","switch","template","this","thread_local","throw","true","try","typedef","typeid","typename","union","unsigned","using" };
    QSet<QString>opera = { "::",".","->","^","++","--","typeid","const_cast","dynamic_cast","reinterpret_cast","static_cast","sizeof","~","!","-","+","&","*","new","delete",".*","->*","/","%","<<",">>","<=",">=","==","!=","|","&&","||","?:","=","*=","-=","<<=",">>=","&=","|=","^=","throw",",","#", "!","%","^","&","*","(",")","-","+","=","{","}","|","~","[","]","\\",";","'",":","<",">","?",",",".","/","#",">>","<<","$","\"" };
    QSet<QString>special_numeric={ "!","%","^","&","*","(",")","-","+","=","{","}","|","~","[","]","\\",";","'",":","<",">","?",",",".","/","#",">>","<<","$","\""};
protected:

    QString scan(QString code);
private slots:
    void on_pushButton_clicked();
};

#endif // MYMAINWINDOW_H
