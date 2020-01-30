#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point2.h"

class Rectangle2:private Point2 {//私有方式继承   派生类定义部分
public://新增公有函数成员
    void initRectangle(float x,float y,float w,float h){
        initPoint(x,y);//调用基类公有成员函数
        this->w = w;
        this->h = h;
    }
    void move(float offX,int offY){Point2::move(offX,offY);}
    float getX() const {return Point2::getX();}
    float getY() const {return Point2::getY();}
    float getH() const {return h;}
    float getW() const {return w;}
private://新增私有数据成员
    float w,h;
};
#endif //_RECTANGLE_H