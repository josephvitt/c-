/*
查找
1，二分查找（折半查找）
*/
template<class T>
int binSearch(const T list[],int n,const T &key){
    int low = 0;
    int high = n-1;
    while ((low <= high))
    {
        int mid = (low+high) /2;
        if(key == list[mid])
            return mid;
        else if(key < list[mid])
        {
            high = mid -1;
        } else {
            low = mid +1;
        }
    }
    return -1;
}