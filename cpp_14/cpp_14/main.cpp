//
//  main.cpp
//  cpp_14
//
//  Created by Tian on 2020/9/27.
//

#include <iostream>
using namespace std;

//C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。

class Print {
public:
    //C++ 中的函数重载
    void print(int i) {
        cout << "整数为: " << i << endl;
    }
    void print(double  f) {
        cout << "浮点数为: " << f << endl;
    }
    void print(char c[]) {
        cout << "字符串为: " << c << endl;
    }
};

//C++ 中的运算符重载
//您可以重定义或重载大部分 C++ 内置的运算符,也可以使用自定义类型的运算符。
//重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。
//与其他函数一样，重载运算符有一个返回类型和一个参数列表。

Box operator+(const Box&);


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    Print p;
    p.print(124);
    p.print(11.22);
    char c[] = "Hello C++";
    p.print(c);
    return 0;
}
