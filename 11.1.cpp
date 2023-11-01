#include <cstring>
#include <iostream>

//
// Created by Hedongyue on 2023/11/1.
//
typedef struct BinaryTreeNode{
    char data;
    struct BinaryTreeNode *lchild,*rchild;
}BinaryTreeNode,*BiTree;
void CreatBinaryTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void Exchange(BiTree &T);
using namespace std;

int main(){
    BiTree T;
    cout<<"先序遍历顺序建立二叉树为： "<<endl;
    CreatBinaryTree(T);
    cout<<"先序便利输出为： "<<endl;
    PreOrderTraverse(T);
    cout<<endl;
    Exchange(T);
    cout<<"交换后先序遍历顺序输出为： "<<endl;
    PreOrderTraverse(T);
}
void CreatBinaryTree(BiTree &T){
    char ch;
    cin>>ch;
    if(ch == '#'){
        T = NULL;
    } else if (ch!='#' && ch!='!'){
        T = new BinaryTreeNode ;
        T->data = ch;
        CreatBinaryTree(T->lchild);
        CreatBinaryTree(T->rchild);
    }
}
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void Exchange(BiTree &T){
    if(T){
        if(T->lchild==NULL && T->rchild==NULL){
            return;
        }else{
            BiTree temp;
            temp=T->lchild;
            T->lchild=T->rchild;
            T->rchild=temp;
        }
        Exchange(T->lchild);
        Exchange(T->rchild);
    }
}
