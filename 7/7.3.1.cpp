/*
派生类的构成
1.吸收基类成员
    1.默认情况下派生类包含了全部基类中除构造和析构函数之外的所有成员
    2.c++11规定可以用using语句基础基类构造函数
2.改造基类成员
    如果派生类声明了一个和某基类成员同名的新成员，
    派生的新成员就隐藏或覆盖了外层同名的成员
3.添加新的成员
    派生类增加新成员使派生类在功能上有所发展

不同继承方式的影响主要体现在：
1.派生类成员对基类成员的访问限制
2.通过派生类对象对基类成员的访问限制

公有继承(public)
1.继承的访问控制
  1.1基类的public和protected成员：访问属性在派生类中保持不变；
  1.2基类的private成员：不可直接访问
2.访问权限
    2.1派生类中的成员函数：可以直接访问基类中的public和protected成员。
    但不能直接访问private成员
    2.2通过派生类的对象：只能访问public成员
*/
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main(){
    Rectangle rect;//定义Rectangle类的对象
    rect.initRectangle(2,3,20,10);//设置矩形的数据
    rect.move(3,2);//移动矩形位置
    cout << "The data of rect(x,y,w,h):" << endl;
    //输出矩形的特征参数
    cout << rect.getX() << ","
    << rect.getY() << ","
    << rect.getW() << ","
    << rect.getH() << endl;
    return 0;
}