/*
派生类的构造函数

默认情况
1.基类的构造函数不被继承
2.派生类需要定义自己的构造函数

c++11规定
1.可以using语句基础基类的构造函数
2.但是只能初始化从基类继承的成员(对于派生类新增的成员是无能为力的)
3.语法形式
using B::B

若不继承基类的构造函数
1.派生类新增成员：派生类定义构造函数初始化；
2.继承来的成员：自动调用基类构造函数进行初始化；
3.派生类的构造函数需要给基类的构造函数传递参数
 
单继承时构造函数的定义语法：
派生类名::派生类名(基类所需的形参，本类成员所需的形参):
基类名(参数表)，本类成员初始化列表
{
    //其他初始化
};


 */ 
#include <iostream>
using namespace std;
class B {
    public:
        B();
        B(int i);
        ~B();
        //const 不改变对象状态
        void print() const;
    private:
        int b;
};

B::B(){
    b = 0;
    cout << "B default constructor called." << endl;
}
B::B(int i){
    b = i;
    cout << "B constructor called." << endl;
}
B::~B(){
    cout << "B destructor called." << endl;
}

void B::print() const {
    cout << b << endl;
}

class C :public B {
    public:
    C();
    C(int i,int j);
    ~C();
    void print() const;
    private:
        int c;
};

C::C(){
    c = 0;
    cout << "C default constructor called." << endl;
}
C::C(int i,int j):B(i),c(j){
    cout << "C constructor called." << endl;
}
C::~C(){
    cout << "C destructor called." << endl;
}

void C::print() const {
    B::print();
    cout << c << endl;
}

int main(){
    C obj(5,6);
    obj.print();
    return 0;
}