/*
深层复制

一个类中有指针指向的动态分配的内存
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
        //拷贝构造函数
        ArrayOfPoints(const ArrayOfPoints &pointsArray);
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
ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints &v){
    size = v.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = v.points[i];
    }
}
int main(){
    int count;
    cout << "Please enter the count of points:";
    cin >> count;
    ArrayOfPoints pointsArray1(count);//创建对象数组
    
    pointsArray1.element(0).move(5,10);
    pointsArray1.element(1).move(15,20);
   
    //使用的默认的复制构造函数
    ArrayOfPoints pointsArray2(pointsArray1);//创建副本
    
    cout << "Copy of pointsArray1:" << endl;
    //输出第二个数组的两个元素的坐标
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ","
    << pointsArray2.element(0).getY() << endl;

    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ","
    << pointsArray2.element(1).getY() << endl;

    //移动第一个数组
    pointsArray1.element(0).move(25,30);
    pointsArray1.element(1).move(35,40);

    cout << "After the moving of pointsArray1:" << endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ","
    << pointsArray2.element(0).getY()  << endl;

    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ","
    << pointsArray2.element(1).getY() << endl;

    return 0;
}