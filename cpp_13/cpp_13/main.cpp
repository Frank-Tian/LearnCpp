//
//  main.cpp
//  cpp_13
//
//  Created by Tian on 2020/9/24.
//

#include <iostream>

using namespace std;

class Person {
public:
    void setWeight(int w) {
        weight = w;
    }
    void setHeight(int h) {
        height = h;
    }
protected:
    int weight;
    int height;
};


// 访问控制和继承
// 派生类可以访问基类中所有的非私有成员。
// 因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。
// 我们可以根据访问权限总结出不同的访问类型，如下所示：

// 访问       public  protected    private
// 同一个类    yes     yes          yes
// 派生类      yes     yes          no
// 外部的类    yes     no           no

// 一个派生类继承了所有的基类方法，但下列情况除外：
// 1、基类的构造函数、析构函数和拷贝构造函数。
// 2、基类的重载运算符。
// 3、基类的友元函数。

// 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。
// 当使用不同类型的继承时，遵循以下几个规则：

// 1、公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，
//      基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
// 2、保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
// 3、私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员
class Man: public Person {
public:
    int getWeightHeight() {
        return weight * height;
    }
};

class Driver: public Person {
public:
    void setLevel(int l) {
        level = l;
    }
protected:
    int level;
};

class Soldier : public Man {
public:
    void setCode(string c) {
        code = c;
    }
protected:
    string code;

};

// 多继承即一个子类可以有多个父类，它继承了多个父类的特性。
// <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
// 访问修饰符继承方式是 public、protected 或 private 其中的一个，
// 用来修饰每个基类，各个基类之间用逗号分隔，
class AutomobileSoldier: public Soldier, public Driver
{
   public:
      void printCodeAndLevel() {
          cout << "code:" << code << ", level: " << level << endl;
      }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Man m;
    
    m.setHeight(100);
    m.setWeight(60);
    
    cout << m.getWeightHeight() << endl;
    
    AutomobileSoldier aSoldier;
    aSoldier.setCode("abcdefg");
    aSoldier.setLevel(6);
    aSoldier.printCodeAndLevel();
    
    return 0;
}
