/*
顺序容器
1.向量（vector)
2.双端队列（deque)
3.列表（list)
4.单向列表（forward_list）
5.数组（array）

在逻辑上可看做是一个长度可扩展的数组

1.元素线性排列，可以随时在指定的位置插入元素和删除元素
2.必须符合Assignable这一概念（既有公有的复制构造函数并且可以用“=”赋值）
3.array对象的大小固定，forward_list有特殊的添加和删除的操作
*/
#include <iostream>
#include <list>
#include <deque>
using namespace std;

//输出指定的顺序容器的元素
template<class T>
void printContainer(const char* msg,const T&s){
    cout << msg << ": " ;
    copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}
int main(){
    //从标准输入读取10个整数，将它们分别从s的头部加入
    deque<int> s;//双端队列
    for (int i = 0; i < 10; i++)
    {   
        int x;
        cin >> x;
        s.push_front(x);
    }
    printContainer("deque at first",s);
    //用s容器的内容的逆序构造列表容器
    list<int> l(s.rbegin(),s.rend());
    printContainer("list at first",l);
    return 0;
}
