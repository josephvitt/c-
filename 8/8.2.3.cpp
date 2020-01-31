/*
前置单目运算符的重载规则


1.如果要重载 U 为类成员函数，使之能够实现表达式 U oprd,其中oprd为A类对象，
则U 应该被重载为A 类的成员函数，无形参。

2.经重载后，
表达式U oprd相当于 oprd.operator U()

后置单目运算符++ 和 --重载规则
1.如果要重载++或--为类成员函数，使之能够实现表达式 oprd++ 或oprd--,其中 oprd为A类对象，
则++或--应该被重载为A类的成员函数，且具有一个int类型的参数。

2.经过重载后，表达式oprd++ 相当于 oprd.operator ++(0)

例子:
1.重载前置++和后置++为是种类成员函数

1.前置单目运算符，重载函数没有形参
2.后置++运算符，重载函数需要一个int形参
3.操作数是时钟类的对象
4.实现时间增加1秒钟

 */
#include <iostream>
using namespace std;
//时钟类定义
class Clock{
    public:
    Clock(int hour=0,int minute=0,int second=0);
    void showTime() const;
    //前置单目运算符重载
    Clock& operator ++();
    //后置单目运算符重载
    Clock operator ++(int);
    private:
        int hour,minute,second;
};
Clock::Clock(int hour,int minute,int second){
    if(0<=hour && hour <24 && 0<=minute && minute <60
    && 0<=second && second < 60){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }else {
        cout << "Time error!" << endl;
    }
}
//显示时间
void Clock::showTime() const{
    cout << hour << ":" << minute << ":" << second << endl;
}

//运算符重载函数
Clock& Clock::operator ++(){
    second++;
    if(second >= 60){
        second -=60;
        minute++;
        if(minute>=60){
            minute -= 60;
            hour = (hour+1) % 24;
        }
    }
    return *this;
}

//后置单目运算符重载
Clock Clock::operator ++(int){
    //注意形参表中的整形参数
    Clock old = *this;
    ++(*this);//调用前置 ++ 运算符
    return old;//返回临时的副本
}
/*
结果
First time output:23:59:59
Show myClock++: 23:59:59
Show ++myClock: 0:0:1
 */
int main(){
    Clock myClock(23,59,59);
    cout << "First time output:" ;
    myClock.showTime();
    cout << "Show myClock++: ";
    (myClock++).showTime();
    cout << "Show ++myClock: ";
    (++myClock).showTime();

    return 0;
}