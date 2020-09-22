//
//  main.cpp
//  cpp_07
//
//  Created by Tian on 2020/9/22.
//

#include <iostream>

using namespace std;

// 定义结构，须使用 struct 语句
/*
 struct type_name {
 member_type1 member_name1;
 member_type2 member_name2;
 member_type3 member_name3;
 } object_names;
 */
struct Books {
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
} book;

// 更简单的定义结构的方式，可以为创建的类型取一个"别名"
// 可以在使用的时候，不用写 struct 了。
typedef struct Articles {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   article_id;
} Articles;

// 结构体作为参数传递
void printBook(struct Books book) {
    cout << "标题：" << book.title << endl;
    cout << "作者：" << book.author << endl;
    cout << "类目：" << book.subject << endl;
    cout << "ID：" << book.book_id << endl;
}

// 可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似
// struct Books *struct_pointer;
// 定义的指针变量中存储结构变量的地址
// struct_pointer = &Chinese;
void printBookByPointer(struct Books *book) {
    cout << "书标题  : " << book->title <<endl;
    cout << "书作者 : " << book->author <<endl;
    cout << "书类目 : " << book->subject <<endl;
    cout << "书 ID : " << book->book_id <<endl;
}

void structTest1() {
    Books Chinese;    // 定义结构体变量 Chinese
    Books English;    // 定义结构体变量 English
    
    strcpy(Chinese.title, "国语");
    strcpy(Chinese.author, "人民教育出版社");
    strcpy(Chinese.subject, "中文");
    Chinese.book_id = 10001;
    
    strcpy(English.title, "英语");
    strcpy(English.author, "朗文出版社");
    strcpy(English.subject, "外语");
    English.book_id = 10002;
    
    cout << "国语 标题：" << Chinese.title << endl;
    cout << "国语 作者：" << Chinese.author << endl;
    cout << "国语 类目：" << Chinese.subject << endl;
    cout << "国语 ID：" << Chinese.book_id << endl;
    
    cout << "英语 标题：" << English.title << endl;
    cout << "英语 作者：" << English.author << endl;
    cout << "英语 类目：" << English.subject << endl;
    cout << "英语 ID：" << English.book_id << endl;
    
    cout << endl;
    
    printBook(English);
    printBook(Chinese);
    
    cout << endl;

    printBookByPointer(&English);
    printBookByPointer(&Chinese);
}

void structTest2() {
    Articles article;
    strcpy(article.title, "外语");
    cout << article.title << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    structTest1();
    structTest2();
    
    return 0;
}
