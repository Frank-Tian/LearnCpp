//
//  main.cpp
//  cpp_03
//
//  Created by Tian on 2020/9/19.
//

#include <iostream>

using namespace std;
/**
 声明
 return_type function_name( parameter list );
 
 定义
 return_type function_name( parameter list )
 {
 body of the function
 }
 */

// 函数声明
int max(int a, int b);          // 传值调用
void swap1(int *a, int *b);     // 指针调用
void swap2(int &a, int &b);     // 指针调用
void lambdaTest(void);          // Lambda

int defaultValue(int a, int b=20);// 参数默认值

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a = 10, b = 20;
    // 函数调用
    int m = max(a, b);
    cout << "max value: " << m << endl;
    
    cout << "a = " << a << ", b = " << b << endl;
    
    swap1(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    
    swap2(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    
    int result = defaultValue(10);
    cout << result << endl;
    
    lambdaTest();
    
    return 0;
}

// 函数定义
int max(int a, int b) {
    return a > b ? a : b;
}

void swap1(int *a, int *b) {
    cout << "\t*a = " << a << ", *b = " << b << endl;
    int tmp;
    tmp = *a;   /* 保存地址 a 的值 */
    *a = *b;    /* 把地址 b 赋值给 a */
    *b = tmp;   /* 把地址 a 赋值给 b */
}

void swap2(int &a, int &b) {
    int tmp;
    cout << "\t&a = " << a << ", &b = " << b << endl;
    tmp = a;    /* 保存地址 a 的值 */
    a = b;      /* 把 b 赋值给 a */
    b = tmp;    /* 把 a 赋值给 b  */
}

int defaultValue(int a, int b) {
    return a + b;
}

void lambdaTest() {
    // Lambda: [capture](parameters)->return-type{body}
    //      capture list：捕获外部变量列表
    //      params list：形参列表
    //      mutable指示符：用来说用是否可以修改捕获的变量
    //      exception：异常设定
    //      return type：返回类型
    //      function body：函数体
    // 可以省略其中的某些成分来声明“不完整”的Lambda表达式
    //      [capture list] (params list) -> return type {function body}
    //      [capture list] (params list) {function body}
    //      [capture list] {function body}
    
    int a = 123;
    int b = 888;
    
    // 有参
    auto lambda = [](int a){cout << a << endl;};
    lambda(666); // 666 为参数
    
    // 值捕获
    // 如果以传值方式捕获外部变量,在Lambda表达式函数体中不能修改该外部变量的值
    auto v = [a] { cout << a << endl; };
    a = 321;
    v();// 10,
    
    // 引用捕获
    auto p = [&b] { cout << b << endl; };
    b = 999;
    p(); // 输出：999
    
    // 隐式捕获
    // 除了上面的在捕获列表中显示列出Lambda表达式中使用的外部变量
    // 还可以让编译器根据函数体中的代码来推断需要捕获哪些变量，这种方式称之为隐式捕获
    // 隐式捕获有两种方式，分别是[=]和[&]。
    //      [=]表示以值捕获的方式捕获外部变量
    //      [&]表示以引用捕获的方式捕获外部变量
    int abc = 234;
    // 值捕获（隐式）
    auto q = [=] { cout << abc << " " << a << endl; };    // 值捕获
    q(); // 输出：234 321
    
    // 引用捕获(隐式)
    auto m = [&] { cout << b << endl; };
    b = 777;
    m(); // 777
    
    // 混合方式捕获
    // []           不捕获任何外部变量
    // [变量名, …]   默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符）
    // [this]       以值的形式捕获this指针
    // [=]          以值的形式捕获所有外部变量
    // [&]          以引用形式捕获所有外部变量
    // [=, &x]      变量x以引用形式捕获，其余变量以传值形式捕获
    // [&, x]       变量x以值的形式捕获，其余变量以引用形式捕获
    auto c = [=, &b] { cout << abc << " " << b << endl; };
    b = 333;
    abc = 432;
    c(); // 234 333
    
    // 修改捕获变量
    // 如果以传值方式捕获外部变量，则函数体中不能修改该外部变量，否则会引发编译错误
    // 使用mutable关键字修饰之后，就可以修改捕获变量的值了
    auto modify = [abc]() mutable {cout << ++abc << endl;};
    modify(); // 433
    
    // Lambda表达式的参数
    // 1、参数列表中不能有默认参数
    // 2、不支持可变参数
    // 3、所有参数必须有参数名
    auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
    auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
    auto ab = hFunc(gFunc(7), 8);
    cout << ab << endl;
}
