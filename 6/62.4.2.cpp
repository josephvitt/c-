/*
申请和释放动态数组

分配和释放动态数组
1.分配：new 类型名T[数组长度]
数组长度可以是任意整数类型表达式，在运行时计算

2.释放：delete[] 数组名p
释放指针p所指向的数组
p必须是用new分配得到的数组首地址
*/
//动态创建对象数组
#include <iostream>
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
int main(){
    Point *ptr = new Point[2];//创建对象
    ptr[0].move(5,10);//通过指针访问数组元素的成员
    ptr[1].move(15,20);//通过指针访问数组元素的成员
    cout << "Deleting... " << endl;
    delete[] ptr;//删除整个对象数组
    return 0;
}