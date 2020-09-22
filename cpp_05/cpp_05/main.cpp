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
void pointerTest3(void);
void pointerTest4(void);
void pointerTest5(void);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    stringTest();
    stringTest2();
    pointerTest1();
    pointerTest2();
    pointerTest3();
    pointerTest4();
    pointerTest5();
    
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
    int    *ip_;   /* 一个整型的指针 */
    double *dp;    /* 一个 double 型的指针 */
    float  *fp;    /* 一个浮点型的指针 */
    char   *ch;    /* 一个字符型的指针 */
    
    int  var = 20;   // 实际变量的声明
    int  *ip;        // 指针变量的声明
    
    ip = &var;       // 在指针变量中存储 var 的地址
    
    cout << "变量 var 的值: ";
    cout << var << endl;
    
    // 输出在指针变量中存储的地址
    cout << "IP 变量保存的地址: ";
    cout << ip << endl;
    
    // 访问指针中地址的值
    cout << "指针变量 *ip 中存储的值: ";
    cout << *ip << endl;
}

void pointerTest2() {
    // 在变量声明的时候，如果没有确切的地址可以赋值，
    // 为指针变量赋一个 NULL 值好的编程习惯
    
    int  *ptr = NULL;
    cout << "ptr 的值是 " << ptr ;
    
    // 内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置
    if(ptr) {
        /* 如果 ptr 非空，则完成 */
        
    }
    if(!ptr) {
        /* 如果 ptr 为空，则完成 */
    }
}

const int MAX = 3;
void pointerTest3() {
    /* 指针是一个用数值表示的地址
     可以对指针进行四种算术运算：++、--、+、-
     */
    int  var[MAX] = {10, 200, 300};
    int  *ptr;
    
    // 指针中的数组地址
    ptr = var;
    for (int i = 0; i < MAX; i++) {
        cout << "地址：\t var[" << i << "] = ";
        cout << ptr << endl;
        
        cout << "值：\t var[" << i << "] = ";
        cout << *ptr << endl;
        
        // 移动到下一个位置
        ptr++;
    }
}

void pointerTest4() {
    
}

void pointerTest5() {
    
}
