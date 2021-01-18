# getToken-for-C-
C++源代码单词扫描程序
# 一、实验内容及要求：

（1）C++源代码扫描程序识别C++记号。  
       C++语言包含了几种类型的记号：标识符，关键字，数（包括整数、浮点数），字符串、注释、特殊符号（分界符）和运算符号等。  
（2）打开一个C++源文件，打印出所有以上的记号。  
（3）要求应用程序应为Windows界面。  
（4）选作部分：为了提高C++源程序的可读性，C++程序在书写过程中加入了空行、空格、缩进、注释等。  
    假设你想牺牲可读性，以节省磁盘空间，那么你可以存贮一个删除了所有不必要空格和注释的C++源程序的压缩文本。  
    因此，程序中还应该有这样的压缩功能。  
（5）选作部分：进一步思考或实现——如何进一步实现减小源文件大小的压缩功能。  
（6）应该书写完善的软件文档。  

# 二、支持的符号
1.数字：整数、浮点数、正整数、正浮点数、负数、负浮点数、正科学计数法表示数，负科学计数法表示数、二进制数、八进制数、十六进制数。  
2.标识符：依照C++标识符命名规则  
3.关键字：do while include define ifndef alignas alignof and and_eq asm auto 
bitand bitor bool break case catch char char8_t char16_t char32_t 
class compl concept const const_cast consteval constexpr constinit 
continue co_await co_return co_yield decltype default delete do 
double dynamic_cast else enum explicit export extern false float
for friend goto if inline int long mutable namespace new noexcept
not not_eq nullptr operator or or_eq private protected public register 
reinterpret_cast requires return short signed sizeof static static_assert 
static_cast struct switch template this thread_local throw true try typedef 
typeid typename union unsigned using  
4.注释：//单行注释  
/*多行注释*/   
5.特殊符号：支持识别特殊符号，但不支持多个特殊符号组成的运算符  
6.字符串："支持扫描字符串"  

# 三、界面设计  
![界面](https://github.com/Gao-JF/getToken-for-C-/blob/main/%E7%95%8C%E9%9D%A2.png?raw=true)

