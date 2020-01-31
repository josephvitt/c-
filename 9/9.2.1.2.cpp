/*

函数模板语法
1.语法形式
template <模板参数表>
函数定义
2.模板参数表的内容
2.1类型参数：class (typename) 标识符
2.2常量参数：类型说明符 标识符
2.3模板参数：template <参数表> class 标识符

注意：
1.一个函数模板并非自动可以处理所有类型的数据
2.只有能够进行函数模板中运算的类型，可以做为类型实参
3.自定义类，需要重载模板中的运算符，餐能作为类型实参
*/
#include <iostream>
using namespace std;
template<class T>//定义函数模板
void outputArray(const T *array,int count){
    for (int i = 0; i < count; i++)
    {
        //注意如果数组元素是类的对象，需要该对象所属类重载了流插入运算符“<<”
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    const int A_COUNT = 8,B_COUNT = 8,C_COUNT = 20;
    int a[A_COUNT] = {1,2,3,4,5,6,7,8};
    double b[B_COUNT] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
    char c[C_COUNT] = "Welcome!";

    cout << "a array contains:" << endl;
    outputArray(a,A_COUNT);
    cout << "b array contains:" << endl;
    outputArray(b,B_COUNT);
    cout << "c array contains:" << endl;
    outputArray(c,C_COUNT);
    return 0;
}