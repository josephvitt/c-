#include <iostream>
using namespace std;
int main(){
    unsigned int x;
    unsigned int y = 100;
    unsigned int z = 50;
    x = y -z;
    cout << "Diifference is: " << x ;
    x = z - y;
    cout << "\n Now difference is: " << x << endl;
    return 0;
    /*
        结果：程序的数据类型错误
        无符号整型：0~2^8或者2^16次方这样的整数；
        无符号整数不能表示负数
        把x 前面的unsiganed
        Diifference is: 50
        Now difference is: 4294967246
     */
}