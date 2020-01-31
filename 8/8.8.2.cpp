/*
声明一个车（Vehicle）基类，有Run、Stop等成员函数，
由此派生出自行车（bicycle）类、汽车（motorcar）类，
从bicycle和motorcar派生出摩托车（motorcycle）类，
他们都有Run、Stop等成员函数

注意:虚基类是解决类成员标识二义性和信息冗余问题，而虚基类是实现动态多态性的基础。
*/
#include <iostream>
using namespace std;
class Vehicle{
    public:
        int MaxSpeed;
        int Weight;
        //void Run() {cout << "vehicle run! " << endl;}
        //void Stop() {cout << "vehicle stop! " << endl;}
        virtual void Run() {cout << "vehicle run! " << endl;}
        virtual void Stop() {cout << "vehicle stop! " << endl;}
};
class Bicycle:virtual public Vehicle
{
    public:
        int Weight;
        void Run() {cout << "bicycle run! " << endl;}
        void Stop() {cout << "bicycle stop! " << endl;}
};
class Motorcar:virtual public Vehicle
{
    public:
        int SeatNum;
        void Run() {cout << "motorcar run! " << endl;}
        void Stop() {cout << "motorcar stop! " << endl;}
};
class Motorcycle:public Bicycle,public Motorcar{
    public:
        void Run() {cout << "motorcycle run! " << endl;}
        void Stop() {cout << "motorcycle stop! " << endl;}
};
int main(){
    Vehicle v;
    v.Run();
    v.Stop();
    Bicycle b;
    b.Run();
    b.Stop();
    Motorcar m;
    m.Run();
    m.Stop();
    Motorcycle mc;
    mc.Run();
    mc.Stop();
    /*
    1.如果Vehicle类中的run和stop为普通成员函数，
    通过基类Vehicle的指针就不能讷河访问派生类对象的run和stop.
    2.如果想要通过基类的指针和引用访问派生类对象的成员，就要使用虚函数。
    */
    Vehicle* vp = &v;
    vp->Run();
    vp->Stop();
    vp = &b;
    vp->Run();
    vp->Stop();
    vp = &m;
    vp->Run();
    vp->Stop();
    vp = & mc;
    vp->Run();
    vp->Stop();

    return 0;
}