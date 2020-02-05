/*
列表（list）
特点：
1.在任意位置插入和删除元素都很快
2.不支持随机访问

接合（splice）操作
s1.splice(p,s2,q1,q2):将s2中[q1,q2）移动到s1中p所指向元素之前
*/
#include <vector>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
//列表容器splice操作
int main(){
    string names1[] = {"Alice","Helen","Lucy","Susan"};
    string names2[] = {"Bob","David","Levin","Mike"};
    //用names1数组的内容构造列表s1
    list<string> s1(names1,names1+4);
    //用names2数组的内容构造列表s2
    list<string> s2(names2,names2+4);

    //将s1的第一个元素放到s2的最后
    s2.splice(s2.end(),s1,s1.begin());
    list<string>::iterator iter1 = s1.begin();//iter1指向s1首
    advance(iter1,2);//iter1前进2个元素，它将指向s1第三个元素
    list<string>::iterator iter2 = s2.begin();//iter2指向s2首
    ++iter2;//iter2前进1个元素，它将指向s2第二个元素
    list<string>::iterator iter3 = iter2;//用iter2初始化iter3
    advance(iter3,2);//iter3前进2个元素，它将指向s2第4个元素
    //将[iter2,iter3)范围内的结点接到s1中iter指向的结点前
    s1.splice(iter1,s2,iter2,iter3);

    //分别输出s1和s2
    copy(s1.begin(),s1.end(),ostream_iterator<string>(cout," "));
    cout << endl;
    copy(s2.begin(),s2.end(),ostream_iterator<string>(cout," "));
    cout << endl;


    return 0;
}