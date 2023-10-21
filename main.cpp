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
    void Init(int size);

public:
    Stack(int size);
    virtual ~Stack();
    void Push(ElemType e); //入栈
    ElemType Top(ElemType &e);   //返回栈顶
    void Pop(ElemType &e);   //出栈

};



template<class ElemType>
void Stack<ElemType>::Init(int size) {
    maxSize=size;
    if(elems!=NULL) delete []elems;
    elems = new ElemType [maxSize];
    count = 0;
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
void Stack<ElemType>::Push(ElemType e) {
    elems[count++] =e;
}

template<class ElemType>
ElemType Stack<ElemType>::Top(ElemType &e) {
    e = elems[count-1];
    return e;
}

template<class ElemType>
void Stack<ElemType>::Pop(ElemType &e){
    e = elems[count-1];
    count--;
}

class optr: public Stack<char>
{
public:
    optr(int size);
    ~optr();
};


//optr
optr::optr(int size):Stack(size) {
    elems = NULL;
    Init(size);
}

optr::~optr(){
    delete []elems;
}

//opnd
class opnd: public Stack<int>
{
public:
    opnd(int size);
    ~opnd();
};

opnd::opnd(int size) : Stack(size) {
    elems = NULL;
    Init(size);
};

opnd::~opnd(){
    delete []elems;
}

int Sign_Sum(int a,int b,char c){
    if(c == '+')
        return a+b;
    else if(c == '-')
        return  a-b;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return a/b;
    return 0;

//    switch (c) {
//        case '+':
//            return a+b;
//        case '-':
//            return a-b;
//        case '*':
//            return a*b;
//        case '/':
//            return a/b;
//
//    }
//    return 0;
}

int Compare_more1less2EQ3(char a,char b){
    int va,vb;

    switch (a) {
        case '+':
        case '-':
            va = 0;
            break;
        case '*':
        case '/':
            va = 2;
            break;
        case '(':
        case ')':
            va = 4;
            break;
        case '=':
            va = 3;
            break;


    };

    switch (b) {
        case '+':
        case '-':
            vb = 0;
            break;
        case '*':
        case '/':
            vb = 2;
            break;
        case '(':
        case ')':
            vb = 4;
            break;
        case '=':
            vb = 3;
            break;

    }
    if (va > vb)
        return 1;
    if(va < vb)
        return 2;
    if (va == vb)
        return 3;
    return 0;

}

int algorithm() {

    optr otr(10);
    opnd ond(10);
    otr.Push('=');
    char ch;
    cin.get(ch);

    //https://blog.csdn.net/qq_51297987/article/details/118398105
    //从输入流获取一字符ch；
//    int sum, i = 0, k = 0, q = 0;
//    int flag[5];
//    读取的数字存储在flag中
//    while (i < e.length()) {
//        sum = 0;
//        while (isdigit(e[i])) {
//            k = 1;
//            sum = sum * 10 + e[i++] - '0';
//        }
//        if (k == 1) {
//            flag[q] = sum;
//            q++;
//        }
//        k = 0;
//        while (!isdigit(e[i]))i++;
//    }

    //取出optr的栈顶值optrTop
    char top;
    otr.Top(top);
    int q = 0;
    while(top != '=' || ch != '='){

        if(isdigit(ch) == 0 ){
//                cin.putback(ch);    //有待商榷
            ond.Push(ch);
            ch = cin.get();
        }
        else {
            if(Compare_more1less2EQ3(top,ch) == 2){
                otr.Push(ch);
                ch = cin.get();
            }
            else if(Compare_more1less2EQ3(top,ch) ==1) {
                char sign;
                otr.Pop(sign);
                int value0;
                ond.Pop(value0);
                int value1;
                ond.Pop(value1);
                int sum = Sign_Sum(value0,value1,sign);
                ond.Push(sum);
            }
            else if(Compare_more1less2EQ3(top,ch) == 3&& ch ==')'){
                char a;  //无用
                otr.Pop(a);
                ch = cin.get();

            }


        }

    }
    otr.Top(top);
    cout<<top<<endl;
    return 0;


}

int main(){
    algorithm();
    return 0;
}

