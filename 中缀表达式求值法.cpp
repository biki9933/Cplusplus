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

//首先创建类模板Stack
//创建栈 optr otr，opnd ond；
//根据ppt上的中缀算数表达式求值的思路进行实现

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
    ElemType Pop();   //出栈

};



template<class ElemType>
void Stack<ElemType>::Init(int size) {
    maxSize=size;
    if(elems!=NULL) delete []elems;
    elems = new ElemType[maxSize];
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
    elems[count++] = e;
}

template<class ElemType>
ElemType Stack<ElemType>::Top(ElemType &e) {
    e = elems[count-1];
    return e;
}

template<class ElemType>
ElemType Stack<ElemType>::Pop(){
    count--;
    return elems[count];

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

}

int Compare_more1less2EQ3(char a,char b){
    int va,vb;

    switch (a) {
        case '+':
        case '-':
            va = 11;
            break;
        case '*':
        case '/':
            va = 14;
            break;
        case '(':
            va = 7;
            break;
        case ')':
            va = 14;
            break;
        case '=':
            va = 1;
            break;


    };

    switch (b) {
        case '+':
        case '-':
            vb = 10;
            break;
        case '*':
        case '/':
            vb = 13;
            break;
        case '(':
            vb = 16;
            break;
        case ')':
            vb = 7;
            break;
        case '=':
            vb = 1;
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

    optr otr(20);
    opnd ond(20);
    otr.Push('=');
    char ch;
    cin.get(ch);


    //取出optr的栈顶值optrTop
    char top;
    otr.Top(top);
    while( !(ch == '=' && top == '=')){

        if(isdigit(ch) > 0 ){
            int tem =ch -'0';


            ond.Push(tem);
            ch = cin.get();
            otr.Top(top);

        }
        else {
            if(Compare_more1less2EQ3(top,ch) == 2){
                otr.Push(ch);
                ch = cin.get();
                otr.Top(top);
            }
            else if(Compare_more1less2EQ3(top,ch) ==1) {
                char sign;
                sign = otr.Pop();
                int value0;
                value0= ond.Pop();
                int value1;
                value1 =ond.Pop();
                int sum = Sign_Sum(value0,value1,sign);
                ond.Push(sum);
                otr.Top(top);


            }else if(Compare_more1less2EQ3(top,ch) == 3&& ch ==')'){
                char a;  //无用
                a = otr.Pop();
                ch = cin.get();

            }


        }

    }
    int value11;
    ond.Top(value11);
    cout<<value11<<endl;
    return 0;

}

int main(){
    algorithm();
    return 0;

}

