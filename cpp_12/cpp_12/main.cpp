//
//  main.cpp
//  cpp_12
//
//  Created by Tian on 2020/9/24.
//

#include <iostream>

using namespace std;

class Person {
public:
    // 使用 static 关键字来把类成员定义为静态的
    // 意味着无论创建多少个类的对象，静态成员都只有一个副本
    // 静态成员在类的所有对象中是共享的
    static int objectCount; // 静态成员
    Person(double h=170, double w=65, int a= 20) {
        cout << "构造方法被调用" << endl;
        age = a;
        height = h;
        weight = w;
        // 每次创建对象时增加 1
        objectCount++;
    }
    // 如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
    // 静态成员函数即使在类对象不存在的情况下也能被调用，
    // 静态函数只要使用类名加范围解析运算符 :: 就可以访问
    // 静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
    // 静态成员函数有一个类范围，他们不能访问类的 this 指针。
    // 可以使用静态成员函数来判断类的某些对象是否已被创建。
    static int getCount() {
        // 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
        // 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。
        return objectCount;
    }
    double weightHeight() {
        return height * weight;
    }
    // 演示 this 指针
    int compare(Person p) {
        return this->weightHeight() > p.weightHeight();
    }
private:
    int age;
    double height;
    double weight;
};

// 不能把静态成员的初始化放置在类的定义中，
// 但是可以在类的外部通过使用范围解析运算符 ::
// 来重新声明静态变量从而对它进行初始化
// 初始化类 Person 的静态成员
int Person::objectCount = 0;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Person::getCount() << endl;
    
    Person p1(123, 45, 14);
    Person p2(133, 47, 15);
    if (p1.compare(p2)) {
        cout << "p1 is smaller than p2" << endl;
    } else {
        cout << "p1 is equal to or larger than p2" << endl;
    }
    
    // 一个指向 C++ 类的指针与指向结构的指针类似，
    // 访问指向类的指针的成员，需要使用成员访问运算符 ->
    Person *ptrPrson;               // 声明指向类的指针
    ptrPrson = &p1;                 // 保存第一个对象的地址
    cout << "p1 : " << ptrPrson->weightHeight() << endl;
    ptrPrson = &p2;                 // 保存第二个对象的地址
    cout << "p2 : " << ptrPrson->weightHeight() << endl;
    
    // 输出对象的总数
    cout << "Total objects: " << Person::objectCount << endl;
    
    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Person::getCount() << endl;

    return 0;
}
