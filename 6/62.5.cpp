/*
智能指针

c++11智能指针
1.unique_str:
不允许多个指针共享资源，可以用标准库中的move函数转移指针
2.shared_ptr:
多个指针共享资源
3.weak_ptr:
可复制shared_ptr，但其构造或者释放对资源不产生影响
 */