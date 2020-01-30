/*
虚基类

需要解决的问题
1.当派生类从多个基类派生，而这些基类又有共同的基类，则咋访问此共同基类中的成员时，将产生冗余，
并有可能因为冗余带来不一致性。

2.虚基类声明
2.1以virtual说明基类继承方式
例：class B1:virtual public B

3.作用
1.主要用来解决多继承时可能发生的对同一基类继承多次而产生的二义性问题；
2.为最远的派生类提供唯一的基类成员，而不重复产生多次复制

注意:
在第一级继承时就要将共同基类设计为虚基类
*/
#include <iostream>
using namespace std;
//二义性问题:
class Base0{
    public:
        int var0;
        void fun0(){cout << " Member of Base0 " << endl;}
};
class Base1:virtual public Base0{//定义派生类Base1
    public://新增外部接口
        int var1;
};
class Base2:virtual public Base0{//定义派生类Base2
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