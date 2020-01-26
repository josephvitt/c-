/*
共享数据的保护
常类型
1.常对象：必须进行初始化，不能被更新
 const 类名 对象名
2.常成员
 用const进行修饰的类成员：常数据成员和常函数成员
2.1 常成员函数
2.1.1:使用const关键字说明的函数
2.1.2:常成员函数不能更新对象的数据成员。
2.1.3：常成员函数说明格式:
    类型说明符 函数名（参数表）const;
    这里：const是函数类型的一个组成部分，因此在实现部分也要带const关键字。
2.1.4:const关键字可以被用于参与对重载函数的区分
2.1.5:通过常对象只能调用它的常成员函数

2.2常数据成员
    使用const说明的数据成员

3.常引用：被引用的对象不能被更新；不想达到双向传递；
在友元函数中用常引用做参数，既能获得较高的执行效率，又能保证实参的安全性。
 const 类型说明符 &引用名；
4.常数组：数组元素不能被更新（第六章）
    类型说明符 const 数组名[大小]
5.常指针：指向常量的指针（第六章）
*/
#include <iostream>
#include <cmath>
using namespace std;
//常对象;用const修饰的对象
/*
class A {
    public:
        A(int i,int j){x = i;y = j;}
    private:
        int x,y;
};
*/
//5-7成员常函数举例
class R {
    public:
        R(int r1,int r2):r1(r1),r2(r2){}
        void print();
        void print() const;
    private:
        int r1,r2;
};

void R::print(){
    cout << r1 << ":" << r2 << endl;
}

void R::print() const{
    cout << r1 << ":" << r2 << endl;
}

//5-8常数据成员举例
class A {
    public:
        A(int i);
        void print();
    private:
        //声明常成员
        const int a ;
        static const int b;//静态常数据成员
};
//初始化
const int A::b = 10;
A::A(int i):a(i){}
void A::print(){
    cout << a << ":" << b << endl;
}

//使用友元函数计算两个点之间的距离

class Point {
    public:
        Point(int x= 0,int y=0):x(x),y(y){}
        int getX(){return x;}
        int getY(){return y;}
        //这个函数并没有作为类的成员函数,在类外作为一个独立的全局函数
        friend float dist(const Point &p1,const Point &p2);
    private:
        int x,y;
};
//常引用；只读的引用
float dist(const Point &p1,const Point &p2){
    double x = p1.x - p2.x;
    double y = p1.y - p2.y; 
    return static_cast<float>(sqrt(x*x+y*y));
}

int main(){
    //a是常对象，不能被更新
    //A const a(3,4);

    R a(5,4);
    a.print();//调用 void print();
    const R b(20,52);
    b.print();//调用 void print();

    A a1(100),a2(0);
    a1.print();
    a2.print();

    const Point myp1(1,1),myp2(4,5);
    cout << "The distance is：";
    cout << dist(myp1,myp2) << endl;
    return 0;

    return 0;
}



