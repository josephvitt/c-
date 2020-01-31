/*
final

struct Base1 final {};

struct  Derived1:Base1{};//编译错误：Base1为final，不允许被继承

struct Base2 {
    virtual void f() final;

}

struct Derived2:Base2 {
    void f();//编译错误：Base2::final,不允许被覆盖
}
*/

