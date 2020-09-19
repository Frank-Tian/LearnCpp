//
//  main.cpp
//  cpp_01
//
//  Created by Tian on 2020/9/19.
//

#include <iostream>

// 常量定义1：预处理器
#define MAXCOUNT 100
#define NEWLINE '\n'
// 常量定义2：指定类型
const int MAXAGE = 60;

// 自定义类型
typedef int block;

// 当前文件域的全局变量
static int globalCount = 10;

// 命名空间下的全局变量
// 仅可在它在其上创建的线程上访问
// 变量在创建线程时创建，并在销毁线程时销毁
// 每个线程都有其自己的变量副本
// thread_local 不能用于函数声明或定义
//thread_local int tli;

// 枚举类型
enum season {
    spring, summer, fall = 5, winter
};

// 全局变量
// extern 存储类用于提供一个全局变量的引用
// 全局变量对所有的程序文件都是可见的
// extern 是用来在另一个文件中声明一个全局变量或函数
extern int abc, def;
extern float xyz;
extern void write_extern(void);

// 全局变量声明
int yuv;
// 全局变量声明,附初值
int wmn = 20;

// 告诉编译器使用 std 命名空间
using namespace std;

// 函数声明
void numericPrint();
void globalCountPrint();
void calPrint();
void relPrint();
void bitPrint();

/// 编译成可执行文件
/// gcc main.cpp -lstdc++ -o main
/// 生成 a.out 文件
/// g++ main.cpp
/// g++ main.cpp -o b  生成 b
/// ./main    或者 ./b   或者 ./a.out 一样
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << "Hello, World!" << endl;
    
    // 调用 extern
    write_extern();
    
    // 变量定义(局部变量,声明)
    int abc, def;
    float xyz;
    // 局部变量声明,赋初值
    int u = 10;
    cout << "u = " << u << endl;
    
    // 常量定义
    const char NEWLINE2 = '\n';
    cout << MAXAGE;
    cout << NEWLINE2;
    
    // 实际初始化
    abc = 10;
    def = 20;
    xyz = abc + def;
    
    short int si;                   // 有符号短整数
    unsigned short int usi = 100;   // 无符号短整数
    short unsigned int sui = 100;   // 无符号短整数
    usi = 50000;
    sui = 50000;
    si = usi; // 溢出
    cout << si << " " << usi << " " << sui << endl;
    
    while (globalCount--) {
        globalCountPrint();
    }
    
    // 自定义类型定义变量
    block count = 10;
    cout << "count = " << count << endl;
    
    // 输出枚举值
    season s1 = spring, s2 = summer, s3 = fall, s4 = winter;
    cout << "spring: " << s1 << ", summer: " << s2 << ", fall: " << s3 << ", winter: " << s4 << endl;
    
    calPrint();
    relPrint();
    bitPrint();
    // 函数调用
    numericPrint();
    
    return 0;
}

void globalCountPrint() {
    static int v = 0;
    v++;
    cout << "v = " << v << " globalCount = " << globalCount << endl;
}

void calPrint() {
    int a = 21;
    int b = 10;
    int c;
    
    c = a + b;
    cout << "Line 1 - c 的值是 " << c << endl ;
    c = a - b;
    cout << "Line 2 - c 的值是 " << c << endl ;
    c = a * b;
    cout << "Line 3 - c 的值是 " << c << endl ;
    c = a / b;
    cout << "Line 4 - c 的值是 " << c << endl ;
    c = a % b;
    cout << "Line 5 - c 的值是 " << c << endl ;
    
    int d = 10;   //  测试自增、自减
    c = d++;
    cout << "Line 6 - c 的值是 " << c << endl ;
    
    d = 10;    // 重新赋值
    c = d--;
    cout << "Line 7 - c 的值是 " << c << endl ;
}

void relPrint() {
    int a = 21;
    int b = 10;
    int c ;
    
    if (a == b) {
        cout << "Line 1 - a 等于 b" << endl ;
    } else {
        cout << "Line 1 - a 不等于 b" << endl ;
    }
    if (a < b) {
        cout << "Line 2 - a 小于 b" << endl ;
    } else {
        cout << "Line 2 - a 不小于 b" << endl ;
    }
    if (a > b) {
        cout << "Line 3 - a 大于 b" << endl ;
    } else {
        cout << "Line 3 - a 不大于 b" << endl ;
    }
    /* 改变 a 和 b 的值 */
    a = 5;
    b = 20;
    if (a <= b) {
        cout << "Line 4 - a 小于或等于 b" << endl ;
    }
    if (b >= a) {
        cout << "Line 5 - b 大于或等于 a" << endl ;
    }
}

void bitPrint() {
    int a = 21;
    int c ;
    
    c =  a;
    cout << "Line 1 - =  运算符实例，c 的值 = : " <<c<< endl ;
    
    c +=  a;
    cout << "Line 2 - += 运算符实例，c 的值 = : " <<c<< endl ;
    
    c -=  a;
    cout << "Line 3 - -= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c *=  a;
    cout << "Line 4 - *= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c /=  a;
    cout << "Line 5 - /= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c  = 200;
    c %=  a;
    cout << "Line 6 - %= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c <<=  2;
    cout << "Line 7 - <<= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c >>=  2;
    cout << "Line 8 - >>= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c &=  2;
    cout << "Line 9 - &= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c ^=  2;
    cout << "Line 10 - ^= 运算符实例，c 的值 = : " <<c<< endl ;
    
    c |=  2;
    cout << "Line 11 - |= 运算符实例，c 的值 = : " <<c<< endl ;
    
}

// 函数定义
void numericPrint() {
    cout << "type: \t\t" << "************size**************"<< endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);
    cout << "\t最大值：" << (numeric_limits<char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);
    cout << "\t最大值：" << (numeric_limits<short>::max)();
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);
    cout << "\t最大值：" << (numeric_limits<long>::max)();
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);
    cout << "\t最大值：" << (numeric_limits<long double>::max)();
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);
    cout << "\t最大值：" << (numeric_limits<float>::max)();
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size**************"<< endl;
}
