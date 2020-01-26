/*
静态数据成员
1.用关键字static声明
2.为该类的所有对象共享，静态数据成员具有静态生存期
3.必须在类外第一和初始化，用(::)来指明所属类
 */
#include <iostream>
using namespace std;
//Point类定义
class Point {
    //外部接口
    public:
        //构造函数
        Point(int x = 0,int y=0):x(x),y(y){
            //在构造函数中对count累加，所有对象共同维护同一个count
            count++;
        }
        //拷贝构造函数
        Point(Point &p){
            x = p.x;
            y = p.y;
            count++;
        }
        //析构函数
        ~Point(){
            count--;
        }
        int getX(){return x;}
        int getY(){return y;}
        //输出静态成员
        void showCount() {
            cout << " Object count = " << count << endl;
        }
    //私有数据成员
    private:
        int x,y;
        //静态数据成员声明，用于记录点的个数
        static int count;
};
///静态数据成员定义和初始化，使用类名限定
int Point::count = 0;

int main(){
    //定义对象a,其构造函数使count增1
    Point a(4,5);
    cout << "Point A: " << a.getX() << "," << a.getY();
    //输出对象个数
    a.showCount();

    Point b(4,5);
    cout << "Point B: " << b.getX() << "," << b.getY();
    //输出对象个数
    b.showCount();
    return 0;
}