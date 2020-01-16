/*
结构体
c++中，结构体是一种特殊形态的类
与类的唯一区别
1.类的缺省访问权限是private,结构体的缺省访问权限是public

什么时候用结构体而不用类
1.定义主要用来保存数据，而没有什么操作的类型
2.人们习惯将结构体的数据成员设为公有，因此这时用结构体更方便

定义

struct 结构体名称{
    公有成员
    protected:
        保护型成员
    private:
        私有成员
};

注意:结构体中可以有数据成员和函数成员

结构体的初始化：
如果：
1.一个结构体的全部数据成员都是公共成员
2.没有用户定义的构造函数
3.没有基类和虚函数（基类和虚函数第7章介绍）
这个结构体的变量可以用下面的语法形式初始化：
类型名 变量名 = {成员数据1初值，成员数据2初值，......}

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//学生信息结构体
struct Student {
    int num;//学号
    string name;//姓名，字符串对象，将在第6章详细介绍
    char sex;
    int age;
};

int main(){
    Student stu = {97007,"Lin Lin",'F',19};
    cout << "Num: " << stu.num << endl;
    cout << "Name: " << stu.name << endl;
    cout << "Sex: " << stu.sex << endl;
    cout << "Age: " << stu.age << endl;
    return 0;
}