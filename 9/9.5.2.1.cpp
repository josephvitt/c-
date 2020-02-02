/*
链表类模板
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
    private:
        Node<T> *front,*rear;//表头和表尾指针
        Node<T> *prevPtr,*cuurrPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
        int size;//表中的元素个数
        int position;//当前元素在表中的位置序号。由函数reset使用
        //生成新结点，数据域为item,指针域为ptrNext;
        Node<T> *newNode(const T &item,Node<T> *ptrNext);
};


#endif //LINKEDLIST_H