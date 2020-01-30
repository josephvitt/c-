/*
私有继承（private）
1.继承的访问控制
1.1基类的public和protected成员：都以private身份出现在派生类中；
1.2基类的private成员：不可以直接访问

2.访问权限：
2.1派生类中的成员函数：可以直接访问基类中的public和protected成员，
但不能直接访问基类的private成员
2.2通过派生类的对象：不能直接访问从基类继承的任何成员
*/
#include "Rectangle2.h"
#include <iostream>
using namespace std;

int main(){
    Rectangle2 rect;//定义Rectangle类的对象
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