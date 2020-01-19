#include <iostream>
using namespace std;
//类定义
class Clock
{
    public:
        Clock(int newH,int newM,int newS);//构造函数
        void setTime(int newH,int newM,int newS);
        void showTime();
    private:
        int hour,minute,second;
};
//构造函数的具体实现
//初始化列表,如果要对类的成员变量进行初始化的,首选这种实现方式
Clock::Clock(int newH,int newM,int newS):hour(newH),minute(newM),second(newS){}

//其他函数实现同例4_1
void Clock::setTime(int newH,int newM,int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

inline void Clock::showTime(){
    cout << hour << ":" << minute << ":" <<second;
}

int main(){
    Clock c(0,0,0);//自动调用构造函数
    c.showTime();
    return 0;
}

