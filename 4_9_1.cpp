/*
 *c++11新标准

枚举类定义
1.语法
    enum class 枚举类型名：底层类型{枚举值列表};默认底层类型 int类型

    enum class Type {General,Light,Medium,Heavy}
    enum class Type:char {General,Light,Medium,Heavy}
    enum class Category {General=1,Pistol,MachineGun,Cannon}
2.优势
    1.作用域强制，其作用域限制在枚举类中。
        如：使用Type的枚举值Gereral:
        Type::Gereral
    2.转换限制
        枚举类对象不可以与整形隐式的互相转换
    3.可以指定底层类型
        enum class Type:char {General,Light,Medium,Heavy}

#include <iostream>
using namespace std;
enum class Side {Right,Left};
//以前不同的枚举，枚举常量一样是会发生冲突的
//不冲突
enum class Thing{Wrong,Right};
int main(){
    Side s = Side::Right;
    Thing w = Thing::Wrong;
    cout << (s == w) << endl;//编译错误，无法直接比较不同的枚举类
    return 0;
}

 */
