/*
this指针

1.隐含与类的每一个非静态成员函数中
2.指出成员函数所操作的对象。
2.1当通过一个对象调用成员函数时，系统先将该对象的地址赋值给this指针，然后调用成员函数，成员函数对对象的数据成员进行操作时，
就隐含使用了this指针。

例：Point类的getX函数中的语句：
retrun x;
相当于：
return this->x;

*/

//前项引用
class Fred;//前向引用声明
class Barney {
    Fred *x;
};
class Fred {
    Barney y;
};