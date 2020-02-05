/*
向量<vector>
特点：
1.一个可以扩展的动态数组
2.随机访问，在尾部插入或删除元素快
3.在中间或头部插入或删除元素慢

向量的容量
1.容量<capacity> :实际分配空间的大小
2.s.capacity():返回当前容量
3.s.reverse():若容量小于n,则对s进行扩展，使其容量至少为n

双端队列（deque）
特点
1.在两端插入或删除元素快
2.在中间插入或删除元素慢
3.随机访问较快，但比向量容器慢
*/
#include <vector>
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;
//先按照从大到小顺序输出奇数，再按照从小到大的顺序输出奇偶数
int main(){
    istream_iterator<int> i1(cin),i2;//建立一对输入流迭代器
    vector<int> s1(i1,i2);//通过输入迭代器从标准输入流中输入数据
    sort(s1.begin(),s1.end());//将输入的整数排序
    deque<int> s2;
    //以下循环遍历s1
    for(vector<int>::iterator iter = s1.begin();iter != s1.end();++iter){
        if(*iter %2 == 0){//偶数放到s2的尾部
            s2.push_back(*iter);
        }else {//奇数放到s2的首部
            s2.push_front(*iter);
        }
    }
    //将s2的结果输出
    copy(s2.begin(),s2.end(),ostream_iterator<int>(cout," "));
    return 0;
}