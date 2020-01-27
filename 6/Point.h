#ifndef _POINT_H
#define _POINT_H
class Point {
    //私有数据成员
    private:
        int x,y;
    public:
        Point();
        Point(int x,int y);
        ~Point();
        void move(int newX,int newY);
        int getX() const {return x;};
        int getY() const {return y;};
        //静态函数成员
        static void showCount();
};
#endif