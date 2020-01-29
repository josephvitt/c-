/*
将动态数组封装成类

更加简洁，便于管理
可以在访问数组元素前查下标是否越界
*/
#include <iostream>
#include <cassert>
using namespace std;
class Point {
    public:
        Point():x(0),y(0){
            cout << "Default Construct called;" << endl;
        }
        Point(int x,int y):x(x),y(y){
            cout << "Construct called;" << endl;
        }
        ~Point(){
            cout << "Destructor called. " << endl;
        }
        int getX() const {return x;}
        int getY() const {return y;}
        void move(int newX,int newY){
            x = newX;
            y = newY;
        }
    private:
        int x,y;
};
//动态数组类
class ArrayOfPoints {
    public:
        ArrayOfPoints(int size):size(size){
            points = new Point[size];
        }
        ~ArrayOfPoints(){
            cout << "Deleting..." << endl;
            delete[] points;
        }
        /*
        返回引用，可以用来操作封装数组对象内部的数组元素。如果返回“值”，则只是返回了一个
        副本，通过副本是无法操作原来数组中的元素的。
        */
        Point& element(int index){
            assert(index >= 0 && index < size);
            return points[index];
        }
    private:
        Point *points;//指向动态数组首地址
        int size;//数组大小
};
int main(){
    int count;
    cout << "Please enter the count of points:";
    cin >> count;
    ArrayOfPoints points(count);//创建数组对象
    points.element(0).move(5,0);//访问数组元素的成员
    points.element(1).move(15,20);//访问数组元素的成员
    return 0;
}