#include "Point.h"
#include <iostream>
using namespace std;

//使用类名初始化静态数据成员
int Point::count = 0;

Point::Point(const Point &p):x(p.x),y(p.y){
    count++;
}

void Point::showCount(){
    cout << "Object count = " << count <<endl;
}

int main(){
    return 0;
}