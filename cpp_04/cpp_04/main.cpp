//
//  main.cpp
//  cpp_04
//
//  Created by Tian on 2020/9/21.
//

#include <iostream>

using namespace std;
void numTest(void);
void randTest(void);
void arryaTest(void);
void arryaTest2(void);
void arryaTest3(void);
void arryaTest4(void);
void arryaTest5(void);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    numTest();
    randTest();
    arryaTest();
    arryaTest2();
    arryaTest3();
    arryaTest4();
    arryaTest5();
    return 0;
}

void numTest() {
    // 数字定义
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
    
    // 赋值
    s = 10;
    i = 100;
    l = 1000000;
    f = 230.47;
    d = 30949.374;
    
    // 输出
    cout << "short  s :" << s << endl;
    cout << "int    i :" << i << endl;
    cout << "long   l :" << l << endl;
    cout << "float  f :" << f << endl;
    cout << "double d :" << d << endl;
    
    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;
}

void randTest() {
    int i,j;
    
    // 设置种子
    srand( (unsigned)time( NULL ) );
    
    /* 生成 10 个随机数 */
    for( i = 0; i < 10; i++ ) {
        // 生成实际的随机数
        j= rand();
        cout <<"随机数： " << j << endl;
    }
}

void arryaTest() {
    // 声明数组,arraySize 必须是一个大于零的整数常量
    // type arrayName [ arraySize ];
    int arr[20];
    // 初始化数组
    double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    // 创建一个数组，不指定长度，长度和初始化的元素个数一致
    double balance1[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    // 赋值指定位置的内容
    balance1[4] = 20;
    
    for (int i = 0 ; i <= 4; i++) {
        // 访问数组
        cout << balance1[i] << endl;
    }
    
}

void arryaTest2() {
    // 二维数组
    // type arrayName [ x ][ y ];
    int a[3][4] = {
        {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
        {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
        {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
    };
    // 嵌套并不是必须的
    int b[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // 一个带有 5 行 2 列的数组
    int c[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
    
    // 输出数组中每个元素的值
    for ( int i = 0; i < 5; i++ )
    for ( int j = 0; j < 2; j++ ) {
        cout << "a[" << i << "][" << j << "]: ";
        cout << a[i][j]<< endl;
    }
}

void arryaTest3() {
    // 带有 5 个元素的双精度浮点型数组
    double arr[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    
    p = arr;
    
    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for ( int i = 0; i < 5; i++ ) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
    
    cout << "使用 arr 作为地址的数组值 " << endl;
    for ( int i = 0; i < 5; i++ ) {
        cout << "*(array + " << i << ") : ";
        cout << *(arr + i) << endl;
    }
}

// 这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针
// double getAverage(int *arr)      形式参数是一个指针
// double getAverage(int arr[10])   形式参数是一个已定义大小的数组：
// double getAverage(int arr[])     形式参数是一个未定义大小的数组：
double getAverage(int arr[], int size) {
    int i, sum = 0;
    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }
    
    return double(sum) / size;
}

void arryaTest4() {
    // 带有 5 个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    
    // 传递一个指向数组的指针作为参数
    avg = getAverage( balance, 5 ) ;
    
    // 输出返回值
    cout << "平均值是：" << avg << endl;
}

// 要生成和返回随机数的函数
int * getRandom( ){
    static int r[10];
    // 设置种子
    srand((unsigned)time( NULL ));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    
    return r;
}

// C++ 不允许返回一个完整的数组作为函数的参数。
// 但可以通过指定不带索引的数组名来返回一个指向数组的指针。
// 如果想要从函数返回一个一维数组，必须声明一个返回指针的函数
void arryaTest5() {
    // 一个指向整数的指针
    int *p;
    p = getRandom();
    for ( int i = 0; i < 10; i++ ) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
}










