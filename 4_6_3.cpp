/*
前向引用声明

两个类相互引用（出现矛盾）；引用前需要让编译器知道类的声明

1.类应该先声明，后使用
2.如果需要在某个类的声明之前，引用该类，则应进行前向引用声明
3.前向引用声明只为程序引入一个标识符，但具体声明在其他地方

注意:
1.在提供一个完整的类声明之前，不能声明该类的对象，也不能在内联成员函数中使用该类的对象
2.当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节

*/
#include <iostream>
using namespace std;

class B;//前向引用声明
class A {
    public:
        void f(B b);
};
class B {
    public:
        void g(A a);
};


//例
//前向引用声明,只声明了类名而已，不能涉及到任何的细节，定义这个对象，起码得知道占的字节数
class Fred;
class Barney {
    Fred x;//错误：类Fred的声明尚不完善
};
class Fred {
    Barney y;
};


int main(){

    return 0;
}