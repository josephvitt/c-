/*
查找
1，顺序查找
*/
template<class T>
int seqSearch(const T list[],int n,const T &key){
    for(int i=0;i<n;i++){
        if(list[i] == key)
            return i;
    }
    return -1;
}

