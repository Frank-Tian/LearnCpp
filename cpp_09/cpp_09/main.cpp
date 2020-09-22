//
//  main.cpp
//  cpp_09
//
//  Created by Tian on 2020/9/23.
//

#include <iostream>
using namespace std;

/*
 总结一下三种继承方式：
 
 继承方式        基类的public成员       基类的protected成员      基类的private成员      继承引起的访问控制关系变化概括
 public继承     仍为public成员         仍为protected成员       不可见                 基类的非私有成员在子类的访问属性不变
 protected继承  变为protected成员      变为protected成员       不可见                 基类的非私有成员都为子类的保护成员
 private继承    变为private成员        变为private成员         不可见                 基类中的非私有成员都称为子类的私有成员
 */
class Person {
    int uid;
public:
    string name;
protected:
    string code;
private:
    double salary;
};

// 有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。
class Man: public Person {
    string nick;
public:
    string hobby;
    int m;
    void fun() {
        cout << nick << endl;        //正确，private成员
        cout << hobby << endl;       //正确，public成员
        cout << name << endl;        //正确，基类的public成员，在派生类中仍是public成员。
        cout << code << endl;        //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
        // cout << salary << endl;      //错误，基类的private成员不能被派生类访问。
    }
};

class Teacher: protected Person {
    int num;
public:
    string subject;
    void fun() {
        cout << num << endl;        //正确，private成员
        cout << subject << endl;    //正确，public成员
        cout << name << endl;       //正确，基类的public成员，在派生类中仍是public成员。
        cout << code << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
        // cout << salary << endl;      //错误，基类的private成员不能被派生类访问。
    }
};

// 如果继承时不显示声明是 private，protected，public 继承，则默认是 private 继承
// 在 struct 中默认 public 继承：
class Woman: Person {
    int age;
public:
    string dog;
    void fun(){
        cout << age << endl;       //正确，private成员
        cout << dog << endl;       //正确，public成员。
        cout << name << endl;      //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
        cout << code << endl;      //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
        // cout << salary << endl;    //错误，基类的private成员不能被派生类访问。
    }
};

void testMan() {
    Man m;
    
    // cout << m.nick << endl; // 错误，类外不能访问private成员
    cout << m.hobby << endl; // 正确
    // cout << m.code << endl; // 错误，类外不能访问protected成员
    // cout << m.salary << endl; // 错误，类外不能访问private成员
}

void testTeacher() {
    Teacher t;
    // cout << t.nick << endl; // 错误，类外不能访问private成员
    cout << t.subject << endl; // 正确
    // cout << t.code << endl; // 错误，类外不能访问protected成员
    // cout << t.salary << endl; // 错误，类外不能访问private成员
}

void testWoman() {
    Woman w;
    cout << w.dog << endl;          //正确。public成员
    // cout << w.age << endl;       //错误，private成员不能在类外访问。
    // cout << w.name << endl;      //错误, private成员不能在类外访问。
    // cout << w.code << endl;      //错误，private成员不能在类外访问。
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
