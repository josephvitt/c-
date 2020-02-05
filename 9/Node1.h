#ifndef NODE_H
#define NODE_H
template <class T>
class Node {
    private:
        Node <T> *next;//指向后继结点的指针
    public:
        T data;//数据域
        Node(){data = 0;next = 0;}
        Node(const T& item,Node<T> *next = 0);//构造函数
        void insertAfter(Node<T> *p);//在本结点之后插入一个同类结点p
        Node<T> *deleteAfter();//删除本结点的后继结点，并且返回其地址
        Node<T> *nextNode();//获取后继结点的地址
        const Node<T> *nextNode() const;//获取后继结点的地址
};
template <class T>
Node<T>::Node(const T& data,Node<T> *next):data(data),next(next){}
//返回后继结点;只读的
template <class T>
const Node<T> *Node<T>::nextNode() const {
    return next;
}
template <class T>
//在本结点之后插入一个同类结点p
void Node<T>::insertAfter(Node<T> *p){
    p->next = next;//p结点指针与指向当前结点的后继结点
    next = p;//当前结点的指针域指向p
}
template <class T>
//删除本结点的后继结点，并且返回其地址
Node<T> *Node<T>::deleteAfter(){
    Node<T> *tempPtr = next;//将于删除的结点地址存储到tempPtr中
    if(next == 0)//如果当前结点没有后继结点，则返回空指针
        return 0;
    next = tempPtr->next;//使当前结点的指针域指向tempPtr的后继结点
    return tempPtr;
}
#endif//NODE_H