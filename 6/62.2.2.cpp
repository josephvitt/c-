/*
指针类型的函数

*/

#include <iostream>
using namespace std;
int* newintvar();
int main(){
    int* intptr = newintvar();
    *intptr = 5;//访问的是合法有效的地址
    delete intptr;//如果忘记释放会造成内存泄漏
    return 0;
}
int* newintvar(){
    int* p = new int();
    return p;//返回的地址指向的是动态分配的开空间。
}//函数运行结束时，p中的地址仍然有效