/*
一：
声明Point类：
有坐标_x,_y两个成员变量
对Point类重载 “++” 自增、“--” 自减运算符
实现对坐标值的改变
*/
#include <iostream>
using namespace std;
class Point {
    private:
        int _x,_y;
    public:
        Point(int x=0,int y=0):_x(x),_y(y){}
        Point& operator++();
        Point operator++(int);
        Point& operator--();
        Point operator--(int);
        friend ostream& operator<<(ostream& o,Point& p);
};

Point& Point::operator++()
{
    _x++;
    _y++;
    return *this;
}

/**
 ++i在C++里面定义最后返回的是被++的对象的引用（系统就是这么实现的），
 所以++i可以作为左值，即可以写：++i = 3;*/

 //后缀是操作符接受一个额外的int型形参（不会使用它，仅做区分）
 Point Point::operator++(int){
     Point temp = *this;
     ++*this;//复用了前缀++的重载
     return temp;

     //后缀式版本中，返回值是尚未自增的原值，但对象本身已经做了自增操作了。
 }

 /**
 ++i在C++里面定义最后返回的是被++的对象值（系统就是这么实现的），
 所以++i不可以作为左值，即不可以写：i++ = 3;*/

Point& Point::operator--(){
    _x--;
    _y--;
    return *this;
}

Point Point::operator--(int){
    Point temp = *this;
    --*this;
    return temp;
}

//友元函数，返回值类型类ostream& ,可以支持<<级联操作
ostream& operator << (ostream& o,Point& p){
    o << '(' << p._x << "," << p._y << ')';
    return o;
}

int main(){
    Point p(1,2);
    cout << p << endl;
    //cout << p++ << endl;
    cout << ++p << endl;
    //cout << p-- << endl;
    cout << --p<< endl;
    return 0;
}