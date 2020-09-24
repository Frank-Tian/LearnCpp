//
//  main.cpp
//  cpp_11
//
//  Created by Tian on 2020/9/24.
//

#include <iostream>
using namespace std;

// 类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
// 尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
// 友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，
// 该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。
// 如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 friend

class Person {
    double weight;
public:
    double height;
    friend void printHeight(Person p);   // 友元函数
    void setHeight(double h);
};

// 请注意：printHeight() 不是任何类的成员函数
void printHeight(Person p) {
    /* 因为 printHeight() 是 Person 的友元，它可以直接访问该类的任何成员 */
    cout << "Height of p : " << p.height <<endl;
}

void Person::setHeight(double h) {
    height = h;
}

// 友元类
//friend class ClassTwo {
//
//}


// C++ 内联函数是通常与类一起使用。
// 如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
// 对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
// 如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline，在调用函数之前需要对函数进行定义。
// 如果已定义的函数多于一行，编译器会忽略 inline 限定符。
// 在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。

inline int Max(int x, int y) {
    return (x > y)? x : y;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Person p;
    // 使用成员函数设置高度
    p.setHeight(170.0);
    // 使用友元函数输出高度
    printHeight(p);
    
    cout << "Max (20,10): " << Max(20,10) << endl;
    cout << "Max (0,200): " << Max(0,200) << endl;
    cout << "Max (100,1010): " << Max(100,1010) << endl;
    return 0;
}
