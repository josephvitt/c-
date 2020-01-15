/*
例题二：
在main()函数中提示输入两个整数x,y,
使用cin语句得到x,y的值，
调用pow(x,y)函数计算x的y次幂的结果，再显示出来
注意：包含cmath库
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x,y;
    cout << "Enter int x:";
    cin >> x;

    cout << "Enter int y:";
    cin >> y;

    cout << "\n";

    cout<<"x= "<<x<<"\t";
    cout<<"y= "<<y<<"\t";
    cout<<"pow(x,y)= "<<pow(x,y)<<endl;
    
    return 0;
}