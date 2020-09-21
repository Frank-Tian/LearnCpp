//
//  main.cpp
//  cpp_05
//
//  Created by Tian on 2020/9/21.
//

#include <iostream>

using namespace std;

void stringTest(void);
void stringTest2(void);
void pointerTest1(void);
void pointerTest2(void);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    stringTest();
    stringTest2();
    pointerTest1();
    pointerTest2();
    return 0;
}

void stringTest() {
    char greeting0[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting1[] = "Hello";
    
    cout << greeting0 << endl;
    cout << greeting1 << endl;
    
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    long  len ;
    
    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;
    
    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;
    
    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
}

void stringTest2() {
    string str1 = "Hello";
    string str2 = "World";
    string str3;
    long len ;
    
    // 复制 str1 到 str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;
    
    // 连接 str1 和 str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;
    
    // 连接后，str3 的总长度
    len = str3.size();
    cout << "str3.size() :  " << len << endl;
}

void pointerTest1() {
    int  var1;
    char var2[10];
    
    cout << "var1 变量的地址： ";
    cout << &var1 << endl;
    cout << "var2 变量的地址： ";
    cout << &var2 << endl;
    
    // var1 变量的地址： 0x7ffeefbff3b8
    // var2 变量的地址： 0x7ffeefbff3be
    
    // 指针是一个变量，其值为另一个变量的地址,内存位置的直接地址。
    // 像其他变量或常量一样，必须在使用指针存储其他变量地址之前，对其进行声明。
    // 指针变量声明的一般形式为：
    // type *var-name;
    // 类型 *指针变量名称
    
    

}

void pointerTest2() {
    
}
