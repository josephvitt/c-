#include <iostream>
using namespace std;
//输入一系列整数，统计正整数个数i和负整数个数j,读入0则结束

int main(){
    int i = 0,j = 0,n;
    cout << "Enter some integers please (enter 0 to quit):"<< endl;
    cin >> n;
    while (n!=0)
    {
        if(n>0) i += 1;
        if(n<0) j += 1;
        cin >> n;
    }
    cout << "Count of positive integers:" << i << endl;
    cout << "Count of negetive integers:" << j << endl;
    return 0;
}