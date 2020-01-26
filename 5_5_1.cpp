/*
类的友元
1.友元是C++提供的一种破坏数据封装和数据隐藏的机制。
2.通过将一个模块声明为另一个模块的友元，一个模块能够引用到另一个模块中本是隐藏的信息。
3.可以声明友元函数和友元类。
4.为了确保数据的完整性，以及数据封装与隐藏的原则，建议慎用友元。

友元函数
1.友元函数是在类声明中由关键字friend修饰说明的非成员函数，在它的函数体中能够通过对象名访问private和protected成员。
2.作用:增加灵活性，使程序员可以在封装和快速性方面做合理选择。
3.访问对象中的成员必须通过对象名。
*/
#include <iostream>
#include <cmath>
using namespace std;
//使用友元函数计算两个点之间的距离

class Point {
    public:
        Point(int x= 0,int y=0):x(x),y(y){}
        int getX(){return x;}
        int getY(){return y;}
        //这个函数并没有作为类的成员函数,在类外作为一个独立的全局函数
        friend float dist(Point &a,Point &b);
    private:
        int x,y;
};
float dist(Point &a,Point &b){
    double x = a.x - b.x;
    double y = a.y - b.y; 
    return static_cast<float>(sqrt(x*x+y*y));
}

int main(){
    Point p1(1,1),p2(4,5);
    cout << "The distance is：";
    cout << dist(p1,p2) << endl;
    return 0;
}