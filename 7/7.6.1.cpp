/*
访问从基类继承的成员

当派生类与基类中有相同成员时：
1.若未特别限定，则通过派生类对象使用的是派生类中的同名成员。
2.如果要通过派生类对象访问基类中被隐藏的同名成员，
应该使用基类名和作用域操作符（：：）来限定。
*/
#include <iostream>
using namespace std;
class Base1{//基类Base1定义，构造函数有参数
    public:
        int var;
        void fun(){cout << " Member of Base1 " << endl;}
};
class Base2{//基类Base2定义，构造函数有参数
    public:
        int var;
        void fun(){cout << " Member of Base2 " << endl;}
};

class Derived:public Base1,public Base2 {
    //派生类Drived定义,注意基类名的顺序
    public:
        //同名的数据成员
        int var;
        void fun(){cout << " Member of Derived " << endl;}//同名函数成员
};
int main(){
    Derived d;
    Derived *p = &d;
    d.var = 1; //对象名.成员名标识
    d.fun();//访问D1类成员

    d.Base1::var  =2;//作用域分辨标识
    d.Base1::fun();//访问Base1基类成员

    p->Base2::var = 3;//作用域分辨标识
    p->Base2::fun();//访问Base2基类成员

    return 0;
}