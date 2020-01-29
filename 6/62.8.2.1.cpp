/*
string 类

输入正行字符串(可以输入空格)
1.getline可以输入正行字符串（要包string头文件）
getline(cin,s2);默认已行结束作为分隔符
2.输入字符串时，可以使用其他分隔符作为字符串结束的表示（例如逗号，分号），
将分隔符作为getline的第三个采纳数即可
getline(cin,s2,',')

测试结果：
Beijing,Chiina
City:Beijing State:Chiina
San Francisco,the United States
City:San Francisco State:the United States

*/
#include <iostream>
#include <string>
using namespace std;


int main(){
    for (int i = 0; i < 2; i++)
    {
        string city,state;
        getline(cin,city,',');
        getline(cin,state);
        cout << "City:" << city << " State:" << state << endl;
    }
    return 0;
}