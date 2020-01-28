/*
以指针作为函数参数；
1.双向传递
2.传一大串数据的时候
*/
#include <iostream>
using namespace std;

//将实数x分成整数部分和小数部分，形参intpart\fracpart是指针。
void splitFloat(float x,int *intPart,float *fracPart){
    *intPart = static_cast<int>(x);
    *fracPart = x-*intPart;
}

int main(){
    cout << "Enter 3 float point numbers:" << endl;
    for (int  i = 0; i < 3; i++)
    {
        float x,f;
        int n;
        cin >> x;
        //变量地址作为实参
        splitFloat(x,&n,&f);
        cout << "integer Part=" << n << " Fraction Part = " << f << endl;
    }
    return 0;
}