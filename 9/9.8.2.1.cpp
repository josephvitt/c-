/*
简单选择排序的基本思想
1.每次从待排序序列中选择一个关键字最小的元素（当需要按关键字升序排列时），
顺序排在已排序序列中的最后，直至全部排完。

任务：将待排序序列 5，4，10，20，12，3 按照元素有小到大的次序进行排列
[5 4 10 20  12 3]
找到3最小的 ，3和5交换
[3 4 10 20  12 5]
4最小
3 [4 10 20  12 5]
3 4 [10 20  12 5]
找到5最小的 ，5和10交换
3 4 [10 20  12 5]
3 4 [5 20  12 10]
*/
template <class T>
//交换函数
void mySwap(T &x,T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void selectionSort(T a[],int n){
    //不用到n,前面n-1个元素确定了，最后一个元素也就确定了。
    for (int i = 0; i < n-1; i++)
    {
        int leastIndex = i;
        //内层for循环，选出当前待排序序列中最小的元素
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[leastIndex])
                leastIndex = j;
        }
        mySwap(a[i],a[leastIndex]);
    }
}