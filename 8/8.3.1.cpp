/*
虚函数
1.用virtual关键字说明的函数
2.虚函数是实现运行时多态性基础
3.c++中虚函数是动态绑定的函数
4.虚函数必须是非静态的成员函数，虚函数经过派生之后，就可以实现运行过程中的多态。

什么函数可以是虚函数
1.一般成员函数可以是虚函数
2.构造函数不能是虚函数
3.析构函数可以是虚函数

一般虚函数成员
1.虚函数声明
virtual 函数类型 函数名（形参表）
2.虚函数声明只能出现在类定义中的函数原型声明中，
而不能在成员函数实现的时候
3.在派生类中可以对基类中的成员函数进行覆盖。
4.虚函数一般不声明为内联函数，因为对虚函数的调用需要动态绑定，而对内联函数的处理是静态的。

virtual关键字
1.派生类可以不显示地用virtual声明虚函数，这是系统就会以下规则来判断
派生类中的一个函数成员是不是虚函数：
1.1该函数是否与基类的虚函数有相同的名称、参数个数以及对应参数类型；
1.2该函数是否与基类的虚函数有相同的返回值或者满足类型兼容规则的指针、引用型的返回值；

2.如果从名称、参数、返回值三个方面检查之后，派生类的函数满足了上述条件，就会自动确定为虚函数。
这时，派生类的虚函数边覆盖了基类的虚函数。

3.派生类中的虚函数还会隐藏基类中同名函数的所有其他重载形式。

4.一般习惯于在派生类的函数中也使用virtual关键字，以增加程序的可读性。

*/
#include <iostream>
using namespace std;

class Base1 {
    public:
    /*
        void display() const {
            cout << "Base1::display()" << endl;
        }
    */
        //指示编译器不要在编译阶段静态绑定，在运行阶段动态绑定,不能写成内联函数。在类外实现函数体。
        virtual void display() const;//虚函数
};
void Base1::display() const {
    cout << "Base1::display()" << endl;
}
class Base2:public Base1{//公有派生类Base2定义
    public:
    /*
        void display() const {
            cout << "Base2::display()" << endl;
        }
    */
        virtual void display() const;
};
void Base2::display() const {
    cout << "Base2::display()" << endl;
}
class Derived:public Base2 {//公有派生类Drived定义
    public:
    /*
        void display() const {
            cout << "Derived::display()" << endl;
        }
    */
        virtual void display() const;
};
void Derived::display() const {
    cout << "Derived::display()" << endl;
}


void fun(Base1 *ptr){//参数为指向基类对象的指针
    ptr->display();//对象指针->成员名
}

int main(){
    /*
    Base1::display()
    Base1::display()
    Base1::display();
    编译器在编译阶段无法判断在运行时他是一个什么类型的，所以只能说指针是什么类型的就定义什么类型的函数。
    告诉编译器在编译阶段没法正确的判断，推迟这个决定。留到运行时再确定。指针在某个时刻再确定指针指向的是什么类型。
    */
    Base1 base1;
    Base2 base2;
    Derived derived;

    fun(&base1);
    fun(&base2);
    fun(&derived);
    return 0;
}