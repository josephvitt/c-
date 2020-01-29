/*
string 类常用的构造函数
1.string();//默认构造函数，建立一个长度为0的串
例：string s1;
2.string(const chat *s); //用指针s所指向的字符串常量初始化string对象
例：
string s2 = "abc";
3.string(const string& rhs);//复制构造函数
例：
string s3 = s2;

常用操作
s + t       将串s和t连接成一个新串
s = t       用t更新s
s == t      判断s与t是否相等
s != t      判断s与t是否不等
s < t       判断s是否小于t(按字典顺序比较)
s <= t      判断s是否小于或等于t(按字典顺序比较)
s > t       判断s是否大于t(按字典顺序比较)
s >= t      判断s是否大于或等于t(按字典顺序比较)
s[i]        访问串中下标为i的字符
例：
string s1 = "abc",s2 = "def";
string s3 = s1 + s2;// 结果是“abcdef”
bool s4 = (s1<s2)//结果是true
char s5 = s2[1];// 结果是‘e’
*/
#include <iostream>
#include <string>
using namespace std;

//根据calue的值输出true或false
//title为提示文字
inline void test(const char* title,bool value){
    cout << title << " returns " 
    << (value ? "true":"false") << endl;
}
int main(){
    string s1 = "DEF";
    cout << "s1 is " << s1 << endl;
    string s2;
    cout << "Please enter s2: ";
    cin >> s2;
    cout << "length of s2:" << s2.length() << endl;

    //比较运算符的测试
    test("s1 <= \"ABC\"",s1<="ABC");
    test(" \"DEF\" <= s1","DEF"<=s1);

    //连接运算符的测试
    s2 += s1;
    cout << "s2 = s2+s1:" << s2 << endl;
    cout << "length of s2:" << s2.length() << endl;
    return 0;
}