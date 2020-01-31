/*
虚析构函数

如果你打算允许其他人通过基类指针调用对象的析构函数(通过delete这样做是正常的)，
就需要让基类的析构函数常为虚函数，否则执行delete的结果是不确定的。

*/
#include <iostream>
using namespace std;
class Base {
    public:
        virtual ~Base();//不是虚函数
};
Base::~Base(){
    cout << "Base destructor" << endl;
}
class Derived:public Base {
    public:
        Derived();
        virtual ~Derived();//不是虚函数
    private:
        int *p;
};
Derived::Derived(){
    p = new int(0);
}
Derived::~Derived(){
    cout << "Derived destructor" << endl;
    delete p;
}
void fun(Base* b){
    delete b;//静态绑定，只会调用~Base()
}
/*
结果:
Derived destructor
Base destructor
*/
int main(){
    Base *b = new Derived();
    fun(b);
    return 0;
}