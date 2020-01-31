/*
Override与final

Override
1.多态行为的基础：基类声明虚函数，派生类声明一个函数覆盖该虚函数；
2.覆盖要求:函数签名（signature)完成一致。
3.函数签名包括：函数名 参数列表 const

1.c++11引入显示函数覆盖，在编译期而非运行期间捕获此类错误。
2.在虚函数显示的重载中运用，编译器会检查基类是否存在以虚拟函数，与派生类中带有声明的override的虚拟函数，
有相同的函数签名（signature）;若不存在，则会报错误。


*/
#include <iostream>
using namespace std;
class Base {
    public:
        virtual void f1(int) const;
        virtual ~Base(){}
};
void Base::f1(int) const {
    cout << "Base f1" << endl;
    return;
}

class Derived:public Base {
    public:
        void f1(int);
        ~Derived(){}
};
void Derived::f1(int) {
    cout << "derived f1" << endl;
}

/*
结果:
Base f1
Base f1
*/
int main(){
    Base *b;
    b = new Base;
    b->f1(1);
    b = new Derived;
    b->f1(1);
    return 0;
}
