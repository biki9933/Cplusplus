#include <cstring>
#include "iostream"
using namespace std;
template<class ElemType>
class SqList
{
protected:
    int count;
    int maxSize;
    ElemType * elems;

    bool Full() const;
    void Init(int size);

public:
    SqList(int size);
    virtual ~SqList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void (* visit)(const ElemType &)) const;
    void GetElem(int position,ElemType &e ) const;




};

template<class ElemType>
void SqList<ElemType>::Init(int size)//进行初始化，分配内容
{
    maxSize=size;
    if (elems!=NULL) delete[] elems;
    elems=new ElemType[maxSize];
    count =0;

}

template<class ElemType>
SqList<ElemType>::SqList(int size) {
    elems = NULL;
    Init(size);
}

template<class ElemType>
SqList<ElemType>::~SqList(){
    delete [] elems;
}

template<class ElemType>
void SqList<ElemType>::GetElem(int position, ElemType &e) const {
    if (position<1 || position>Length())
    {
        cout<<"bucunzai"<<endl;
    }
    else
    {
        e = elems[position-1];
        cout<<"cunzai"<<endl;
    }
}
