/*
利用指针数组存放矩阵
*/
#include <iostream>
using namespace std;
int main(){
    int line1[] = {1,0,0};
    int line2[] = {1,1,0};
    int line3[] = {1,0,1};

    //定义整型指针数组并且初始化
    int *pLine[] = {line1,line2,line3};
    cout << "Matrix test:" << endl;
    //输出矩阵
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << pLine[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}