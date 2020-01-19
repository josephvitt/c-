/*
例一：
声明一个CPU类，包含等级（Rank）,频率（frequency）,
电压（voltage）等属性，有两个公共成员函数run ,stop

其中:rank 为枚举类型CPU_Rank;声明为enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7}
frequency为单位是MHz的整数型；voltage为浮点型的电压值

注意不同访问属性的成员访问方式，并且观察构造函数和析构函数的调用顺序
*/
#include <iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU {
    private:
        CPU_Rank rank;
        int frequency;
        float voltage;
    public:
        CPU(CPU_Rank r,int f,float v){
            rank = r;
            frequency = f;
            voltage = v;
            cout << "构造了一个CPU" << endl;
        }
        ~CPU(){
            cout << "析构了一个CPU" << endl;
        }
        //外部接口函数
        CPU_Rank GetRank() const{
            return rank;
        }
        int GetFrequency() const{
            return frequency;
        }
        float Getvoltage() const{
            return voltage;
        }
        void SetRank(CPU_Rank r){
            rank = r;
        }
        void SetFrequency(int f){
            frequency = f;
        }
        void Setvoltage(float v){
            voltage  = v;
        }
        void Run(){
            cout << "CPU开始运行" <<endl;
        }
        void Stop(){
            cout << "CPU停止运行" <<endl;
        }
};

int main(){
    CPU a(P6,300,2.8);
    a.Run();
    a.Stop();
    return 0;
}

