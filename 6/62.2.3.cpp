/*
指向函数的指针

函数指针的定义
1.定义形式
存储类型 数据类型 (*函数指针名)()
2.含义
函数指针指向的是程序代码存储区


函数指针的典型用途--实现函数回调
1.通过函数指针调用的函数
例如将函数的指针作为参数传递给一个函数，使得在处理相似事件的时候可以灵活的使用不同的方法。
2.调用者不关心谁是被调用者
需知道存在一个具有特定原型和限制条件的被调用函数。


举例
1.编写一个计算函数compute,对两个整数进行各种计算。
有一个形参为指向具体算法函数的指针，根据不同的是参函数，用不同的算法进行计算。
2.编写三个函数：求两个整数的最大值，最小值，和。
分别为这三个函数为实参，测试compute函数。



*/
#include <iostream>
using namespace std;

int compute(int a,int b,int(*func)(int,int)){
    return func(a,b);
}

int max(int a,int b){
    return ( (a>b) ? a:b);
}

int min(int a,int b){
    return ( (a<b) ? a:b);
}

int sum(int a,int b){
    return a+b;
}


int main(){
    int a,b,res;
    cout << "请输入整数a:";cin >> a;
    cout << "请输入整数b:";cin >> b;

    res = compute(a,b,&max);
    cout << "Max of " << a << " and " << b << "is " << res << endl;
    res = compute(a,b,&min);
    cout << "Min of " << a << " and " << b << "is " << res << endl;
    res = compute(a,b,&sum);
    cout << "Sum of " << a << " and " << b << "is " << res << endl;
    return 0;
}