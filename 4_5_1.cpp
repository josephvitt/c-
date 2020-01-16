/*
析构函数完成对象被删除前的一些清理工作，
在对象的生存期结束的时刻系统自动调用析构函数，
如果程序中未声明析构函数，编译器将会自动产生一个默认的析构函数，其函数体为空。就像构造函数一样。
1.析构函数的原型 ~类名();
2.析构函数没有参数，没有返回类型;
3.不能在函数体重有return语句
4.不能有参数列表
*/
#include <iostream>
using namespace std;

class Point{
    public:
        Point(int xx,int yy);
        ~Point();
    private:
        int x,y;
};

Point::Point(int xx,int yy){
    x = xx;
    y = yy;
}

Point::~Point(){

}

int main(){

}


