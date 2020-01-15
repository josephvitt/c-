//抽象实例：钟表
#include <iostream>
using namespace std;
//封装：将抽象出来的数据、代码封装在一起形成一个类。
//继承：已有类的基础上，进行扩展形成类
//多态：同一个名称，不同功能的实现方式
class Clock {
    public:
        void setTime(int newH,int newM,int newS);
        void showTime();
    private:
        int hour,minute,seconds;
};

int main(){
    return 0;
}