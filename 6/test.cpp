#include <iostream>
#include "Point.h"
#include "Point.cpp"
using namespace std;
//对象数组应用举例
int main(){
    cout << "Entering main..." << endl;
    Point a[2];
    for (int i = 0; i < 2; i++)
    {
        a[i].move(i+10,1+20);
    }
    cout << "Exiting main..." << endl;
    return 0;
}