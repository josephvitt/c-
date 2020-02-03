/*
冒泡排序（起泡排序）
*/
template <class T>
//交换函数
void mySwap(T &x,T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void bubbleSort(T a[],int n){
    int i = n-1;
    while (i > 0 )
    {
        int lastExchangeIndex = 0;
        for(int j = 0;j<i ;j++){
            if(a[j+1] < a[j]){
                mySwap(a[j],a[j+1]);
                lastExchangeIndex = j;
            }
        }
        i = lastExchangeIndex;
    }
    
    
}