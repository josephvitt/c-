/*基于范围的for循环*/
#include <iostream>
int main(){
    /*int array[3] = {1,2,3};
    //定义指针首地址赋值到指针
    int *p;
    for (p = array; p < array + sizeof(array) / sizeof(int); p++)
    {
        *p += 2;
        std::cout << *p << std::endl;
    }
    */
    int array[3] = {1,2,3};
    for(int &e : array){
        e+=2;
        std::cout << e << std::endl;
    }
    return 0;
}