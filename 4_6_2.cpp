/**
 * 类的组合程序举例
 */
#include <iostream>
#include <cmath>
using namespace std;

//Point类
class Point {
    public:
        //构造函数in
        Point(int xx,int yy);
        //拷贝构造函数
        Point(const Point&p);
        //普通函数
        int getX() {return x;};
        int getY() {return y;};
    private:
        int x,y;
};
//构造函数
Point::Point(int xx,int yy):x(xx),y(yy){};

//拷贝构造函数的实现
Point::Point(const Point&p){
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor of Point" << endl;
};

//Line类
class Line {
    public:
        //构造函数
        Line(Point xp1,Point xp2);
        //拷贝构造函数
        Line(Line &l);
        double getLen() {return len;};
    private:
        Point p1,p2;
        double len;
};

//组合类的构造函数
Line::Line(Point xp1,Point xp2) : p1(xp1),p2(xp2){
    cout << "Calling constructor of Line " << endl;
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt( x*x + y*y );
}
//组合类的拷贝构造函数
Line::Line(Line &l):p1(l.p1),p2(l.p2) {
    cout << "Calling the copy constructor of Line " <<endl;
    len = l.len;
}


int main(){
    //建立Point对象
    Point myp1(1,1),myp2(4,5);
    //建立Line对象
    Line line(myp1,myp2);
    //利用拷贝构造函数建立一个新对象
    Line line2(line);
    
    cout << "The length of the line is: ";
    cout << line.getLen() <<endl;
    cout << "The length of the line2 is: ";
    cout << line2.getLen() <<endl;
    return 0 ;
}