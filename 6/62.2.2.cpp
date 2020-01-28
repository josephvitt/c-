/*
以指针作为函数参数；
1.双向传递
2.传一大串数据的时候
*/
#include <iostream>
using namespace std;
//指向常量的指针做形参
const int N = 6;
void print(const int *p,int n);

int main(){
    //指向常量的指针做形参
    int array[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    print(array,N);
    
    return 0;
}
/*
指向常量的指针做形参;指针是可以改变的但是指针指向的数据不能改变
*/
void print(const int *p,int n){
    cout << "{ " << *p;
    for (int i = 1; i < N; i++)
    {
        cout << "," << *(p+i);
    }
    cout << "}" << endl;
}