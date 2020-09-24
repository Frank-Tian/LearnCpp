//
//  main.cpp
//  cpp_10
//
//  Created by Tian on 2020/9/23.
//

#include <iostream>
using namespace std;

// 类的构造函数
// 类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
// 构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
// 构造函数可用于为某些成员变量设置初始值。

class Person {
public:
    void setAge(int age);
    int getAge(void);
    double getSalary();
    Person();                   // 这个是构造函数
    Person(int a);              // 这个是构造函数
    Person(int a, double s);    // 这个是构造函数
    ~Person(void);              // 这个是析构函数
    Person(const Person &obj);  // 拷贝构造函数
    /*
     拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象
     1、通过使用另一个同类型的对象来初始化新创建的对象。
     2、复制对象把它作为参数传递给函数。
     3、复制对象，并从函数返回这个对象。
     如果在类中没有定义拷贝构造函数，编译器会自行定义一个。
     如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数
     */
    int getPtr();
private:
    int age;
    double salary;
    int *ptr;
};

// 无参构造方法
Person::Person() {
    cout << "对象正在创建" << endl;
}

// 带参数的构造方法
//Person::Person(int a) {
//    age = a;
//}

// 使用初始化列表来初始化字段：
Person::Person(int a):age(a) {
    cout << "对象正在创建: " << age << endl;
}
Person::Person(int a, double s):age(a),salary(s) {
    cout << "对象正在创建: " << age << "," << salary << endl;
}

// 类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
// 析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，
// 它不会返回任何值，也不能带有任何参数。
// 析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
Person::~Person(void) {
    cout << "对象正在被释放" << endl;
}

// 拷贝构造函数
// obj 是一个对象引用，该对象是用于初始化另一个对象的。
Person::Person(const Person &obj) {
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

void Person::setAge(int a) {
    age = a;
}

int Person::getAge() {
    return age;
}

double Person::getSalary(void) {
    return salary;
}

int Person::getPtr() {
    return *ptr;
}

void display(Person obj) {
   cout << "ptr 大小 : " << obj.getPtr() <<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Person liming;
    liming.setAge(20);
    cout << "Age of liming: " << liming.getAge() << endl;
    
    Person wangyang = Person(30);
    cout << "Age of wangyang: " << wangyang.getAge() << endl;
    
    Person zhangsan(25, 200000.50);
    cout << "Age of zhangsan: " << zhangsan.getAge() << ", salary:" << zhangsan.getSalary() << endl;
    
    display(zhangsan);
    
    Person lisi = zhangsan;
    display(lisi);
    
    return 0;
}
