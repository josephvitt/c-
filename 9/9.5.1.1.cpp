/*
链表的概念与结点类模板
链表是一种动态数据结构，可以用来表示顺序访问的线性群体
*/
template <class T>
class Node {
    private:
        Node <T> *next;
    public:
        T data;
        Node(const T& item,Node<T>* next=0);
        void insertAfter(Node<T> *p);
        Node<T> *deleteAfter();
        Node<T> *nextNode() const;
};
