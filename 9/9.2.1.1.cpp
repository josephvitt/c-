/*
函数模板

问题：
整数类型和浮点数类型求绝对值的算法，需要写两种重载函数吗？
int abs(int x){
    return x < 0 ? -x : x;
}
double abs(double x){
    return x < 0 ? -x : x;
}
解决:函数模板
1.创建一个通用的功能函数
2.支持多种不同的形参
3.简化重载函数的函数体设计

template<typename T>
T abs(T x){
    return x <0 ? -x :x;
}
*/
#include <iostream>
using namespace std;
template<typename T>
T abs(T x){
    return x <0 ? -x :x;
}

int main(){
    int n = -5;
    double d = -5.5;
    cout << abs(n) << endl;
    cout << abs(d) << endl;
    return 0;
}