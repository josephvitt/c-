#include <iostream>
using namespace std;

//求自然数1~10之和
int main(){
    int i = 1,sum = 0;
    do {
        sum += i;
        i++;
    }while(i<=10);
    cout << "sum = " << sum << endl;
    return 0;
}