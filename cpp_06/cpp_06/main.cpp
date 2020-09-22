//
//  main.cpp
//  cpp_06
//
//  Created by Tian on 2020/9/22.
//

#include <iostream>
using namespace std;

//struct tm {
//    int    tm_sec;        /* seconds after the minute [0-60] */
//    int    tm_min;        /* minutes after the hour [0-59] */
//    int    tm_hour;    /* hours since midnight [0-23] */
//    int    tm_mday;    /* day of the month [1-31] */
//    int    tm_mon;        /* months since January [0-11] */
//    int    tm_year;    /* years since 1900 */
//    int    tm_wday;    /* days since Sunday [0-6] */
//    int    tm_yday;    /* days since January 1 [0-365] */
//    int    tm_isdst;    /* Daylight Savings Time flag */
//    long    tm_gmtoff;    /* offset from UTC in seconds */
//    char    *tm_zone;    /* timezone abbreviation */
//};
//struct tm {
//  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
//  int tm_min;   // 分，范围从 0 到 59
//  int tm_hour;  // 小时，范围从 0 到 23
//  int tm_mday;  // 一月中的第几天，范围从 1 到 31
//  int tm_mon;   // 月，范围从 0 到 11
//  int tm_year;  // 自 1900 年起的年数
//  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
//  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
//  int tm_isdst; // 夏令时
//}

void time01();
void time02();
void inputAndOutput();
void errorMsg();
void logMsg();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    time01();
    time02();
    inputAndOutput();
    errorMsg();
    logMsg();
    return 0;
}

void time01() {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    
    cout << "本地日期和时间：" << dt << endl;
    
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间："<< dt << endl;
}

void time02() {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    
    cout << "1970 到目前经过秒数:" << now << endl;
    
    tm *ltm = localtime(&now);
    
    // 输出 tm 结构的各个组成部分
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
}

void inputAndOutput() {
    // 输出
    char str[] = "Hello C++";
    cout << "标准输出 : " << str << endl;
    
    char name[50];
    cout << "请输入您的名称： ";
    // 输入
    cin >> name;
    // 输出
    cout << "您的名称是： " << name << endl;
    
    // C++ 编译器根据要输入值的数据类型
    // 选择合适的流提取运算符来提取值，并把它存储在给定的变量中。
    // 流提取运算符 >> 在一个语句中可以多次使用，如果要求输入多个数据
    // cin >> name >> age; => cin >> name; cin >> age;
}

void errorMsg() {
    char str[] = "Unable to read....";
    cerr << "Error message : " << str << endl;
}

void logMsg() {
    char str[] = "Unable to read....";
    clog << "Log message : " << str << endl;
    // 使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出
}
