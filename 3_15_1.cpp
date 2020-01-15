/*
1.功能接近而名字相同的函数：重载函数，也是多态性的一种体现
2.系统函数，不用重复造轮子
3.1e-10的数符被省略了（默认为'+'），十进制数为1，阶符为'-'，阶码为10。

注：阶码标志'E'或'e'之前必须有数字。
1e-10是C/C++规定的浮点数的科学计数写法，意思是1.0x10的-10次方。
这个记数法有一些要求:
一是e前面整数部分为1位的浮点数，如1.0、3.3、9.999978901等(但不按这个规则写，如123.4E-3编译器也认可)；
二时e可以大写也可以小写；
三是e后面紧跟带符号的十进制整数，长度最大为3位，正数时可不写+号。
所以，1.234E-2、1.234e-02、1.234E-002等其实是一个意思。

例题1:
分别编写四个同名的函数max1，实现函数重载：
可分别求取两个整数，三个整数，两个双精度数，
三个双精度数的最大值。
在main()函数中测试函数功能
*/
#include <iostream>
#include <cmath>
using namespace std;
//两个整数的最大值
int max1(int x,int y);
//三个整数的最大值
int max1(int x,int y,int z);

//两个双精度的最大值
double max1(double x,double y);
//三个双精度的最大值
double max1(double x,double y,double z);

int main(){
    int a,b,c;
    double m,n,l;

    cout << "Enter int a:";
    cin >> a;

    cout << "Enter int b:";
    cin >> b;

    cout << "Enter int c:";
    cin >> c;

    cout << "\n";

    cout << "max of"<<a<<" and "<<b<<"is "<<max1(a,b)<<endl;
    cout << "max of"<<a<<" and "<<b<<"is "<<max1(a,b)<<endl;

    cout << "\n\n";

    cout << "Enter double m:";
    cin >> m;

    cout << "Enter double n:";
    cin >> n;

    cout << "Enter double l:";
    cin >> l;

    cout << "\n";

    cout << "max of"<<m<<" and "<<n<<"is "<<max1(m,n)<<endl;
    cout << "max of"<<m<<" and "<<n<<"and "<<l<<"is "<<max1(m,n,l)<<endl;

    return 0;
}
//两个整数的最大值
int max1(int x,int y){
    if(x==y) return x;
    else if (x>=y)
    {       
        return x;
    }else{
        return y;
    }
}
//三个整数的最大值
int max1(int x,int y,int z){
    return max1(max1(x,y),z);
}

//两个双精度的最大值
double max1(double x,double y){
    //判断浮点数是否相等的创建处理方式
    if (abs(x-y)<1e-10) return x;
    else if (x>=y)
        return x;
    else
        return y;
    
}

