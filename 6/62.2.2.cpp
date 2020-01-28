/*
指针类型的函数
若函数的返回值是指针，高函数就是指针类型的函数

语法
存储类型 数据类型 *函数名(){
    //函数体语句
}

注意：不要讲非静态局部地址用作函数的返回值
例：
int main(){
    int* frunction();
    int* ptr = function();
    *ptr = 5;//危险访问
    return 0;
}
int* function(){
    int local = 0;//非静态局部变量作用域和寿命都仅限于本函数体中
    return &local;
}//函数运行结束时，变量local被释放

返回的指针要确保在主调函数中是有效的、合法的地址。

正确的例子：
主函数中定义的数组，在子函数中对该数组元素进行某种操作后，返回其中一个元素的地址，这就是合法有效的地址。
int main(){
    int array[10];//主函数中定义的数组
    int* search(int* a,int num);
    for(int i=0;i<10;i++){
        cin >> array[i];
    }
    int* zeroptr = search(array,10);//将主函数中数组的首地址传给子函数
    return 0;
}
int* search(int* a,int num){
    for(int i=0;i<num;i++){
        if(a[i]==0)
        retrun &a[i];//返回的地址指向的元素是在主函数中定义的
    }
}//函数运行结束时，a[i]的地址仍然有效
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