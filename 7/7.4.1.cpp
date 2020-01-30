/*
基类与派生类类型转换

类型转换
1.公有派生类对象可以被当做基类的对象使用；反之则不可。
1.1派生类的对象可以隐含转换为基类对象
1.2派生类的对象可以初始化基类的引用
1.3派生类的指针可以隐含的转换为基类的指针。

通过基类对象名、指针只能使用从基类继承的成员

 */
//类型转换规则举例
/*
结果
Base1::display()
Base1::display()
Base1::display()

注意:不要重新定义继承而来的非虚函数
*/
#include <iostream>
using namespace std;

class Base1 {
    public:
        void display() const {
            cout << "Base1::display()" << endl;
        }
};
class Base2:public Base1{//公有派生类Base2定义
    public:
        void display() const {
            cout << "Base2::display()" << endl;
        }
};
class Derived:public Base2 {//公有派生类Drived定义
    public:
        void display() const {
            cout << "Derived::display()" << endl;
        }
};

void fun(Base1 *ptr){//参数为指向基类对象的指针
    ptr->display();//对象指针->成员名
}

int main(){
    Base1 base1;
    Base2 base2;
    Derived derived;

    fun(&base1);
    fun(&base2);
    fun(&derived);
    return 0;
}