#include <iostream>
using namespace std;
class Clock{
    public:
        void setTime(int newH=0,int newM=0,int newS=0);
        void showTime();
    private:
        //类内初始值
        int hour,minute,second;
};

//成员函数的实现,写上类名和作用域限定名
//setTime,showTime不是一般的全局函数是Clock类里面的成员函数要加上类名
void Clock::setTime(int newH,int newM,int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime(){
    cout << hour << ":" << minute << ":" <<second;
}

//对象的使用
int main(){
    Clock myClock;
    myClock.setTime(8,30,30);
    myClock.showTime();
    return 0;
}