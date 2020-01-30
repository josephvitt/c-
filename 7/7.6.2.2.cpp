/*
虚基类及其派生类构造函数

1.建立对象是所指的的类称为 最远派生类
2.虚基类的成员是有最远派生类的构造函数通过调用虚基类的构造函数进行初始化的
3.在整个继承结构中，直接或间接继承虚基类的所有派生类，
都必须在构造函数的成员初始化表中为虚基类的构造函数列出参数。
如果未列出，则表示调用该虚基类的默认构造函数
4.在建立对象时，只有最远派生类的构造函数调用虚基类的构造函数，其他类对虚基类的构造函数的调用被忽略。

*/
#include <iostream>
using namespace std;
class Base0{
    public:
        Base0(int var):var0(var){}
        int var0;
        void fun0(){cout << " Member of Base0 " << endl;}
};
class Base1:virtual public Base0{//定义派生类Base1
    public:
        Base1(int var):Base0(var){}
        int var1;
};
class Base2:virtual public Base0{//定义派生类Base2
    public:
        Base2(int var):Base0(var){}
        int var2;
};
class Derived:public Base1,public Base2 {
    //派生类Drived定义,注意基类名的顺序
    public:
        Derived(int var):Base0(var),Base1(var),Base2(var){}
        int var;
        void fun(){cout << " Member of Derived " << endl;}
};

int main(){
    Derived d(1);
    d.var0 = 2;//直接访问虚基类的数据成员
    d.fun0();//直接访问虚基类的函数成员
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