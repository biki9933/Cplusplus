#include <cstring>

//
// Created by baiqi on 2023/10/3.
//
//结点类模板
template<class ElemType>
struct Node
{
    //数据成员
    ElemType date;  //数据域
    Node<ElemType> * next;  //指针域

    //构造函数模板
    Node();   //无参数的构造函数模板
    Node(ElemType item,Node<ElemType> * link = NULL);
    //已知数据域和指针域建立结构
};

//结点类模板的实现部分
template<class ElemType>
Node<ElemType>::Node()
{
    next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
{
    date = item;
    next = link;
}

//

template<class ElemType>
class SimpleLinkList
{
protected:
    Node<ElemType> *head; //结点头指针

    Node<ElemType> * GetElemPtr(int position) const;
    //返回指向第pozition个结点的指针
    void Inid(); //初始化线性表

public:
};