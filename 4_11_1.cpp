/*
例一：
声明一个CPU类，包含等级（Rank）,频率（frequency）,
电压（voltage）等属性，有两个公共成员函数run ,stop

其中:rank 为枚举类型CPU_Rank;声明为enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7}
frequency为单位是MHz的整数型；voltage为浮点型的电压值

注意不同访问属性的成员访问方式，并且观察构造函数和析构函数的调用顺序


扩展练习:
设计一个用于人事管理的People(人员)类。考虑到通用性,这里只抽象出所有类型人员都具有的属性：
number(编号)、sex(性别)、birthday(出生日期)、id(身份证号)等等。)
要求：
1.“出生日期”声明为一个“日期”类内嵌子对象。
2.用成员函数实现对人员信息的录入和显示。
3.包括构造函数和析构函数、拷贝构造函数、内联成员函数、组合。
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

        CPU(CPU &c){
            rank = c.rank;
            frequency = c.frequency;
            voltage = c.voltage;    

            cout << "拷贝构造了一个CPU!" << endl;

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

enum RAM_Type {DDR2=2,DDR3,DDR4};
class RAM {
    private:
        enum RAM_Type type;
        unsigned int frequency;//MHz
        unsigned int size;//GB
    public:
        //构造函数
        RAM(RAM_Type t,unsigned int f,unsigned int  s){
            type = t;
            frequency = f;
            size = s;
            cout << "构造了一个RAM!"<< endl;
        }
        //析构函数
        ~RAM(){
            cout << "析构了一个RAM!"<< endl;
        }
        RAM_Type GetType() const{return type;}
        unsigned int GetFrequency() const{return frequency;}
        unsigned int GetSize() const{return size;}

        void setType(RAM_Type t) {type=t;}
        void SetFrequency(int f){frequency=f;}
        void SetSize(int s){size =s;}

        void Run(){cout << "RAM开始运行！" << endl;}
        void Stop(){cout << "RAM停止运行！" << endl;}
};

enum CDROM_Interface {STAT,USB};
enum CDROM_Install_type {external,built_in};
class CD_ROM {
    private:
        enum CDROM_Interface interface_type;
        unsigned int cache_size;//MB
        CDROM_Install_type install_type;
    public:
        CD_ROM(CDROM_Interface i,unsigned int s,CDROM_Install_type it){
            interface_type = i;
            cache_size = s;
            install_type = it;
            cout << "构造了一个CD_ROM" << endl;
        }
        ~CD_ROM(){
            cout << "析构了一个CD_ROM" << endl;
        }
        //公共的getSet方法
        CDROM_Interface GetInterfaceType() const {return interface_type;}
        unsigned int GetSize() const {return cache_size;}
        CDROM_Install_type GetInstallType() const {return install_type;}

        void setInterfaceType(CDROM_Interface i)  { interface_type =i;}
        void setSize(unsigned int s)  { cache_size = s;}
        void setInstallType(CDROM_Install_type it)  { install_type = it;}

        void Run(){cout << "CD_ROM开始运行！" << endl;}
        void Stop(){cout << "CD_ROM开始停止！" << endl;}
};

class COMPUTER {
    private:
        CPU my_cpu;
        RAM my_ram;
        CD_ROM my_cdrom;
        unsigned int storage_size;//GB
        unsigned int bandwidth;//MB
    public:
        COMPUTER(CPU c,RAM r,CD_ROM cd,unsigned int s,unsigned int b);

        ~COMPUTER () {cout << "析构了一个COMPUTER!" << endl;}

        void Run(){
            my_cpu.Run();
            my_ram.Run();
            my_cdrom.Run();
            cout << "COMPUTER开始运行！" << endl;
        }

        void Stop(){
            my_cpu.Stop();
            my_ram.Stop();
            my_cdrom.Stop();
            cout << "COMPUTER开始停止！" << endl;
        }
};

COMPUTER::COMPUTER(CPU c,RAM r,CD_ROM cd,unsigned int s,unsigned int b)
:my_cpu(c),my_ram(r),my_cdrom(cd){
    storage_size = s;
    bandwidth = b;

    cout << "构造了一个COMPUTER!" <<endl;
}

int main(){
    CPU a(P6,300,2.8);
    a.Run();
    a.Stop();
    cout << "*****************\n";

    RAM b(DDR3,1600,8);
    b.Run();
    b.Stop();
    cout << "*****************\n";

    CD_ROM c(STAT,2,built_in);
    c.Run();
    c.Stop();
    cout << "*****************\n";

    COMPUTER my_computer(a,b,c,128,10);
    cout << "*****************\n";
    my_computer.Run();
    my_computer.Stop();
    cout << "*****************\n";

    return 0;
}

