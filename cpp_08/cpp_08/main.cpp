//
//  main.cpp
//  cpp_08
//
//  Created by Tian on 2020/9/23.
//

#include <iostream>

using namespace std;

// 类定义是以关键字 class 开头，后跟类的名
// 定义一个类，本质上是定义一个数据类型的蓝图,这实际上并没有定义任何数据
class Person {
    // 关键字 public 确定了类成员的访问属性,也可以指定类的成员为 private 或 protected
    double id; // 默认情况下，类的所有成员都是私有的.如果您没有使用任何访问修饰符，类的成员将被假定为私有成员
public:// 公有成员在程序中类的外部是可访问的,可以不使用任何成员函数来设置和获取公有变量的值
    int age;            // 年龄
    string name;        // 姓名
    double height;      // 身高
    double weight;      // 体重
    // 在类定义中定义的成员函数把函数声明为内联的，即便没有使用 inline 标识符
    // 成员函数声明
    double getBMI(void);// 返回 BMI
    bool fat() {
        return getBMI() > 25.0;
    };
    
    // 私有成员的，公共访问方法
    void setSalary(double salary);
    double getSalary(void);
    
protected: // 受保护成员,保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的
    string birthday;
    
private:// 私有成员,私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的,
    // 只有类和友元函数可以访问私有成员,默认情况下，类的所有成员都是私有的
    // 一般会在私有区域定义数据，在公有区域定义相关的函数，以便在类的外部也可以调用这些函数
    double salary;// 薪水，私有的
};

class Man: Person { // Man 是 Person的派生类，子类
    
public:
    void setBirthday(string birthday);
    string getBirthday();
};

void Man::setBirthday(string bd) {
    birthday = bd;
}

string Man::getBirthday() {
    return birthday; //保护成员在派生类（即子类）中是可访问的
}

// 成员函数定义
// 可以在类的外部使用范围解析运算符 :: 定义该函数
// 在 :: 运算符之前必须使用类名,调用成员函数是在对象上使用点运算符（.）
double Person::getBMI() {
    return weight / pow((height / 100), 2);
}

double Person::getSalary() {
    return salary;
}

void Person::setSalary(double s) {
    salary = s;
}

void classTest() {
    Person xiaoming, xiaoli;    // 声明 xiaoming，xiaoli, 类型为 Person
    
    xiaoming.name = "小明";
    xiaoming.age = 20;
    xiaoming.height = 180;
    
    xiaoli.name = "小李";
    xiaoli.age = 19;
    xiaoli.height = 175;
    
    cout << xiaoming.name << xiaoming.age << "," << xiaoming.height << endl;
    cout << xiaoli.name << xiaoli.age << "," << xiaoli.height << endl;
}

void methodTest() {
    Person xiaowang;
    xiaowang.height = 170;
    xiaowang.weight = 82;
    
    double bmi = xiaowang.getBMI();
    string tips = xiaowang.fat() ? "肥胖" : "正常";
    cout << bmi << "," << tips << endl;
}

void privatePropertyTest() {
    Person zhang;
    
    // 不使用成员函数设置高度
    zhang.height = 160.0;       // OK: 因为 height 是公有的
    cout << "Height of zhang : " << zhang.height <<endl;
    // 不使用成员函数设置薪水
    // zhang.salary = 100000.0; // Error: 因为 salary 是私有的
    zhang.setSalary(50000.0);  // 使用成员函数设置宽度
    cout << "Salary of zhang : " << zhang.getSalary() <<endl;
}

void protectedPropertyTest() {
    Man wang;
    
    wang.setBirthday("1990-01-01");
    cout << wang.getBirthday() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    classTest();
    methodTest();
    privatePropertyTest();
    protectedPropertyTest();
    return 0;
}
