#include <iostream>
using namespace std;
//华氏摄氏度
float Convert(float F){
    float C;
    C = (F-32)*5/9;
    return C;
}

int main(){
    float F;

    cout << "Please input the temperatur in fahrenheit:\n";
    cin >> F;

    cout << "Conver the temperatur in celsius:\n";
    cout << Convert(F);
    return 0;
}