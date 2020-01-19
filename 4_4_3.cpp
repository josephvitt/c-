#include <iostream>
using namespace std;
//时钟类定义
class Clock
{
    //外部接口,共有的成员函数
    public:
        Clock(int newH,int newM,int newS);//构造函数
        Clock();//默认构造函数
        void setTime(int newH,int newM,int newS);
        void showTime();
    //私有数据成员
    private:
        int hour,minute,second;
};
//构造函数的具体实现
//初始化列表,如果要对类的成员变量进行初始化的,首选这种实现方式
//默认构造函数
Clock::Clock():hour(0),minute(0),second(0){}

//构造函数
Clock::Clock(int newH,int newM,int newS):hour(newH),minute(newM),second(newS){}

//其他函数实现同例4_1
void Clock::setTime(int newH,int newM,int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

inline void Clock::showTime(){
    cout << hour << ":" << minute << ":" <<second<<endl;
}

int main(){
    Clock c(8,10,0);//调用有参数的构造函数
    c.showTime();
    Clock c2;//调用不参数的构造函数
    c2.showTime();
    return 0;
}

