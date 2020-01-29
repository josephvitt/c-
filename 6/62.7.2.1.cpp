/*
移动构造
c++11标准中提供了一种新的构造方法----移动构造

c++11之前，如果要将源对象的状态转移到目标对象只能通过复制。
在某些情况下，我们没有必要复制对象---只需要移动他们。

c++11引入移动语义：
源队形资源的控制权全部交给目标对象

移动构造函数
class_name(class_name &&)

当临时对象被复制后，就不再被利用了。
我们完全可以把临时对象的资源直接移动，这样就避免了多余的复制操作。
*/
#include <iostream>
#include <vector>
using namespace std;
//函数返回含有指针成员的对象
/*
一：使用深层复制构造函数
返回是构造临时对象，动态分配将临时对象返回到主调函数，然后删除临时对象。
二：使用移动构造函数
将要返回的局部对象转移到主调函数，省去了构造和删除临时对象的过程。
*/
class IntNum {
    public:
        //构造函数
        IntNum(int x = 0):xptr(new int(x)){
            cout << "Calling constructor..." << endl;
        }
        //拷贝构造函数
        IntNum(const IntNum &n):xptr(new int(*n.xptr)){
            cout << "Calling copy constructor..." << endl;
        }
        //移动构造函数
        /*
        注意：
        1.&&是右值引用
        2.函数返回的临时变量是右值
        */
        IntNum(IntNum && n):xptr(n.xptr){
            n.xptr = nullptr;
            cout << "Calling move constructor..." << endl;
        }
        //析构函数
        ~IntNum(){
            delete xptr;
            cout << "Destructing..." << endl;
        }
        //返回指针所指向的值
        int getInt(){
            return *xptr;
        }
    private:
        int *xptr;
};

//返回值为IntNum类对象
//gcc做了优化，不产生临时对象，也就不调用拷贝构造函数了
IntNum getNum(){
    IntNum a;
    return a;
}
int main(){
    cout << getNum().getInt() << endl;
    return 0;
}