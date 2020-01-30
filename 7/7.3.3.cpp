/*
保护继承(protected)
1.继承的访问控制
1.1基类的public和protected成员：都以protected身份出现在派生类中
1.2基类的private成员：不可直接访问

2.访问权限
2.1派生类中的成员函数：可以直接访问基类中的public和protected成员，
但不能直接访问基类中的private成员；
2.2通过派生类的对象：不能直接访问从基类继承的任何成员


举例：
class A {
    protected:
        int x;
};
int main(){
    A a;
    a.x = 5;//错误
}

class A {
    protected:
        int x;
};
class B:public A{
    public:
        void function();
};
void B::function(){
    x = 5;//正确
}


 */