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
//二义性问题:
class Base0{
    public:
        int var0;
        void fun0(){cout << " Member of Base0 " << endl;}
};
class Base1:public Base0{//定义派生类Base1
    public://新增外部接口
        int var1;
};
class Base2:public Base0{//定义派生类Base2
    public:
        int var2;
};
class Derived:public Base1,public Base2 {
    //派生类Drived定义,注意基类名的顺序
    public:
        int var;
        void fun(){cout << " Member of Derived " << endl;}
};

int main(){
    Derived d;
    d.Base1::var0 = 2; 
    d.Base1::fun0();
    d.Base2::var0 = 3;
    d.Base2::fun0();
    /*
    有二义性
    d.var0
    d.Base0::var0

    无二义性
    d.Base1::var0
    d.Base2::var0
    */

    return 0;
}