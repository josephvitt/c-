#include <iostream>
using namespace std;
//复制构造函数调用案例
class Point{
    public:
        Point();
        Point(const Point &p);//拷贝构造函数
        int getX();
    private:
        int x,y;
};

Point::Point():x(0),y(0){

}

//拷贝构造函数的实现
Point::Point(const Point &p){
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}

//形参为Point类对象的函数
void fun1(Point p){
    cout << p.getX() << endl;
}

//返回值为Point类对象的函数
Point fun2(){
    Point a;
    return a;
}

int Point::getX(){
    return x;
}

int main(){
    Point a;//第一个对象A
    Point b(a);//情况1:用A初始化B,第一次调用拷贝构造函数
    cout << b.getX() << endl;
    fun1(b);//情况2,对象B作为fun1的实参,第二次调用拷贝构造函数
    b = fun2();//情况3,函数的返回值是类对象,函数返回时,调用拷贝构造函数
    cout << b.getX() << endl;
    return 0;
}