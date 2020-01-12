#include <iostream>
using namespace std;
//输入一个数；将各位数字翻转输出
int main(){
    int n,right_digit,newnum = 0;
    cout << "Enter the number:";
    cin >> n;
    cout << "The number in reverse order is :";
    do {
        //最右边的数
        right_digit = n % 10;
        cout << right_digit;
        n /= 10;
    }while(n != 0);
    cout << endl;
    return 0;
}