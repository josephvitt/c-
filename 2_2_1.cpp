//int 数据类型在计算机中占多少个数据字节sizeof()
/*多行注释*/
//单行注释
#include <iostream>
using namespace std;
 int main(){
     cout << "The size of an int is:\t\t" << sizeof(int) << " bytes.\n";
     cout << "The size of an short is:\t\t" << sizeof(short) << " bytes.\n";
     cout << "The size of an long is:\t\t" << sizeof(long) << " bytes.\n";
     cout << "The size of an char is:\t\t" << sizeof(char) << " bytes.\n";
     cout << "The size of an float is:\t\t" << sizeof(float) << " bytes.\n";
     cout << "The size of an double is:\t\t" << sizeof(double) << " bytes.\n";
     return 0;
 }