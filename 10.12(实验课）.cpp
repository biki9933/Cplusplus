//
// Created by baiqi on 2023/10/12.
//
#include <iostream>
#include <string>
using namespace std;

//输入一行表达式，输出值
//数组表示这个表达式，以此进行分析
//利用中缀表达式法，如何实现？
//最后输出结果

template<class ElemType>
class Stack  //总栈
{
protected:
    ElemType *elems;
    int maxSize;
    int count;

    bool Full() const;
    void Init(int size);
public:
    Stack();
    Stack(int size);
    virtual ~Stack();

    void Push(const char &e); //入栈
    void Top(char &e);   //返回栈顶
    void Pop(char &e);   //出栈

};

template<class ElemType>
bool Stack<ElemType>::Full() const {
    return count==maxSize;
}

template<class ElemType>
void Stack<ElemType>::Init(int size) {
    maxSize=size;
    if(elems!=NULL) delete []elems;
    elems = new char [maxSize];
    count = 0;
}

template<class ElemType>
Stack<ElemType>::Stack() {

}

template<class ElemType>
Stack<ElemType>::Stack(int size) {
    elems = NULL;
    Init(size);
}

template<class ElemType>
Stack<ElemType>::~Stack(){
    delete []elems;
}

template<class ElemType>
void Stack<ElemType>::Push(const char &e) {
        elems[count++] =e;
}

template<class ElemType>
ElemType Stack<ElemType>::Top(char &e) {
    e = elems[count-1];
    return e;
}

template<class ElemType>
void Stack<ElemType>::Pop(char &e){
    e = elems[count-1];
    count--;
}

class optr:public Stack<char>
{
public:
    optr(int size);
    ~optr();
};

//optr
optr::optr(int size) {
    elems = NULL;
    Init(size);
}

optr::~optr(){
    delete []elems;
}

//opnd
class opnd:public Stack<int>
{
public:
    opnd(int size);
    ~opnd();
};
opnd::opnd(int size) {
    elems = NULL;
    Init(size);
};
int algorithm(string &e){
    optr otr(10);
    opnd ond(10);
    otr.Push('=');
    //https://blog.csdn.net/qq_51297987/article/details/118398105
    //从输入流获取一字符ch；
    int sum,i=0,k=0,q=0;
    int flag[5];
    while (i<e.length())
    {
        sum =0;
        while (isdigit(e[i]))
        {
            k=1;
            sum=sum*10+e[i++]-'0';
        }
        if(k==1){
            flag[q] = sum;
            q++;
        }
        k=0;
        while (!isdigit(e[i]))i++;
    }

    //取出optr的栈顶值optrTop
    char a =otr.Top();

}
