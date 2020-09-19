//
//  other.cpp
//  cpp_01
//
//  Created by Tian on 2020/9/19.
//

#include <stdio.h>
#include <iostream>

// 全局变量的引用
extern int wmn;

void write_extern(void) {
   std::cout << "extern wmn is " << wmn << std::endl;
}

