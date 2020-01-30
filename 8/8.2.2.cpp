/*
运算符重载类的成员函数

定义形式
函数类型 operator 运算符(形参)
{
    ....
}
参数个数=原操作数个数-1 (后置++、--除外)


双目运算符重载规则
1.如果要重载 B 为类的成员函数，使之能够实现表达式 oprd1 B oprd2,
其中oprd1 为A 类对象，则B 应该被重载为A类的成员函数，形参类型应该是 oprd2所属的类型。

2.经重载后，表达式 oprd1 B oprd2 相当于 oprd1.operator B(oprd2)

复数类加减法运算重载为成员函数
要求：
    将+ 、-运算重载为复数类的成员函数
规则：
    将实部和虚部分别相加减
操作数：
    两个操作数都是复数类的对象

*/

#include <iostream>
using namespace std;
class Complex{
    public:
        Complex(double r = 0.0,double i = 0.0):real(r),imag(i){}
        //运算符+重载成员函数
        Complex operator +(const Complex &c2) const;
        //运算符+重载成员函数
        Complex operator -(const Complex &c2) const;
        void display() const;//输出复数
    private:
        double real;//复数实部
        double imag;//复数虚部
};
Complex Complex::operator+(const Complex &c2) const{
    //创建一个临时无名对象作为返回值
    return Complex(real+c2.real,imag+c2.imag);
}

Complex Complex::operator-(const Complex &c2) const{
    //创建一个临时无名对象作为返回值
    return Complex(real-c2.real,imag-c2.imag);
}

void Complex::display() const{
    cout << "(" << real << "," << imag << ")" << endl;
}

/*
结果：
c1=(5,4)
c2=(2,10)
c3= c1-c2=(3,-6)
c3= c1+c2=(7,14)
*/
int main(){

    Complex c1(5,4),c2(2,10),c3;
    cout << "c1=" ; c1.display();
    cout << "c2=" ; c2.display();

    c3 = c1-c2;//使用重载运算符完成复数减法
    cout << "c3= c1-c2="; c3.display();
    c3 = c1+c2;//使用重载运算符完成复数加法
    cout << "c3= c1+c2="; c3.display();

    return 0;
}