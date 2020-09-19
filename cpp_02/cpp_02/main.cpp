//
//  main.cpp
//  cpp_02
//
//  Created by Tian on 2020/9/19.
//

#include <iostream>

using namespace std;

void testLoop(void);
void nestedLoop(void);
void gotoLoop(void);
void condition(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    testLoop();
    nestedLoop();
    gotoLoop();
    condition();
    return 0;
}


void testLoop() {
    
    int i = 0;
    while (i++ < 10) {
        cout << "i = " << i << endl;
    }
    cout << endl;
    
    for (int j = 0; j < 20; j += 2) {
        if (j%3) {
            continue;
        }
        cout << "j = " << j << endl;
    }
    cout << endl;
    
    int arr[5] = {1, 2, 3, 4, 5};
    for (int &x : arr) {
        cout << "x = " << x << endl;
    }
    cout << endl;
    
    // auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
    for (auto &y : arr) {
        y *= 2;
        cout << "y = " << y << endl;
    }
    cout << endl;
    
    string str("abcdefg xyz");
    for (auto &z: str) {
        cout << "z = " << z << endl;
    }
    cout << endl;
    
    // 局部变量声明
    int a = 0;
    do {
        cout << "a = " << a << endl;
        a++;
    } while (a < 10);
}

void nestedLoop() {
    for (int i = 0; i < 10; i+=2) {
        for (int j = 10; j > 0; j-=2) {
            if (i == j) {
                break;
            }
            cout << "i = " << i << " j = " << j << endl;
        }
    }
    /*
     i = 0 j = 10
     i = 0 j = 8
     i = 0 j = 6
     i = 0 j = 4
     i = 0 j = 2
     i = 2 j = 10
     i = 2 j = 8
     i = 2 j = 6
     i = 2 j = 4
     i = 4 j = 10
     i = 4 j = 8
     i = 4 j = 6
     i = 6 j = 10
     i = 6 j = 8
     i = 8 j = 10
     */
}

void gotoLoop() {
    int m = 0, n = 0;
    outter: for (; m < 10; m++) {
        for (; n < 5; n++) {
            if (n == 3) {
                m++;
                n--;
                goto outter;
            }
            cout << "m = " << m << " n = " << n << endl;
        }
    }
    /*
    m = 0 n = 0
    m = 0 n = 1
    m = 0 n = 2
    m = 1 n = 2
    m = 2 n = 2
    m = 3 n = 2
    m = 4 n = 2
    m = 5 n = 2
    m = 6 n = 2
    m = 7 n = 2
    m = 8 n = 2
    m = 9 n = 2*/
}

void condition() {
    
    int a = 10, b = 20;
    
    if (a < 60) {
        cout << a << " is too low!" << endl;
    }
    
    if (a > 0) {
        cout << a << " > 0" << endl;
    } else {
        cout << a << " < 0" << endl;
    }
    
    if (a > 0) {
        if (b > 0) {
            // same as if (a > 0 && b > 0)
            cout << "a > 0, and b > 0" << endl;
        }
    }
    
    char c = 'A';
    
    switch (c) {
        case 'S':
            cout << "Great!" << endl;
            break;
        case 'A':
            cout << "nice!" << endl;
            break;
        case 'B':
            cout << "good!" << endl;
            break;
        case 'C':
            cout << "normal!" << endl;
            break;
        default:
            break;
    }
    
    int x = 10, y = 90;
    int z = x > 0 ? x : y;
    cout << z << endl;
}
