/*
例一
编写矩阵转置函数，输入参数为3*3整型数组。
编写main()函数 实现输入和输出

 */

#include <iostream>
using namespace std;
//元素和元素之间的对调，使用引用
void swap(int& a,int&b){
    int temp = a;
    a = b;
    b= temp;
}

int main(){
    int a[3][3];
    cout << "输入9个整数作为矩阵元素值" << endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    cout << "初始矩阵" << endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cout << a[i][j] << ' ';
        cout << endl;


    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            swap(a[i][j],a[j][i]);

    cout << "转置后的矩阵" << endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    return 0;
}