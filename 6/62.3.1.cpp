/*
对象指针

定义形式
类名 *对象指针名；
Point a(5,10);
Point *ptr;
ptr = &a;


访问
通过指针访问对象成员
对象指针名->成员名

ptr->getX()相当于 （*ptr).getX();

 */
#include <iostream>
using namespace std;
class Point {
    public:
        Point(int x=0,int y=0):x(x),y(y){}
        int getX() const {return x;}
        int getY() const {return y;}
    private:
        int x,y;
};
int main(){
    Point a(4,5);
    Point *ptr;
    ptr = &a;//定义对象指针，用a的地址初始化
    cout << ptr->getX() << endl; // 用指针访问对象成员
    cout << a.getY() << endl; //用对象名访问对象成员
    return 0;
}