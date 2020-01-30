/*
访问从基类继承的成员

当派生类与基类中有相同成员时：
1.若未特别限定，则通过派生类对象使用的是派生类中的同名成员。
2.如果要通过派生类对象访问基类中被隐藏的同名成员，
应该使用基类名和作用域操作符（::）来限定。

二义性问题:
1.如果从不同基类继承了同名成员，但是在派生类中没有定义同名成员，
“派生类对象名或引用名.成员名”、“派生类指针->成员名”访问成员存在二义性问题

2.解决方式：用类名相限定

举例
class A {
    public:
        void f();
};
class B {
    public:
        void f();
        void g();
};
class C:public A,public B {
    public:
        void g();
        void h();
}
如果定义：C c1;
则c1.f() 具有二义性
而c1.g()无二义性(同名隐藏)

解决方法一：用类名来限定
c1.A::f() 或 c1.B::f()
解决方法二：同名隐藏
在C中声明一个同名成员函数f(),f()再根据需要调用A::f() 或者B::f()


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