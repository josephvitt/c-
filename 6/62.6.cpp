/*
VECTOR对象
1.封装任何类型的动态数组，自动创建和删除
2.数组下标越界检查。

定义：
vector<元素类型> 数组名对象名(数组长度)

vector<int> arr(5)
建立大小为5的int数组

对象的使用
1.对数组元素的引用，与普通数组具有相同的形式
vector对象名 [下标表达式]
vector数组对象名不表示数组首地址
2.获得数组长度
用size函数
vector对象名.size()

*/
#include <iostream>
#include <vector>
using namespace std;

//计算数组arr中元素的平均值
double average(const vector<double> &arr){
    double sum = 0;
    for(unsigned i = 0;i<arr.size();i++){
        sum += arr[i];
    }
    return sum/arr.size();
}

int main(){
    unsigned n;
    cout << "n= ";
    cin >> n;

    vector<double> arr(n);//创建数组对象
    cout << "Please input " << n << " real numbers:" << endl;
    for(unsigned i = 0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Average = " << average(arr) << endl;

    return 0;
}