#include <iostream>
using namespace std;
/*
线性表：由同类型数据元素构成有序序列的线性结构
    表中元素的个数，称为线性表的长度
    线性表没有元素，称为空表
    表起始位置称表头，表结束位置称表尾
*/

//操作集
/*
MakeEmpty();  //建立空表
FindKth(int K, List L);    //返回第K个元素
Find(int x, List L);   //查找x第一次出现的位置
Insert(int x, int i, List L);  //在第i个位置前插入x
Length(List L);    //返回表的长度n
Delte(int i, List L);  //删除指定位置元素
*/

#define MAXSIZE 20

/*数组*/
class List_array{
    public:
        int array[MAXSIZE];
        int last;
        List_array(){
            for (int i = 0; i != MAXSIZE; i++){
                array[i] = i;
            }
            last = MAXSIZE - 1;
        }
        void print(){
            int i = 0;
            while(i != MAXSIZE){
                cout << this->array[i] << '\t';
                i++;
            }
        }
};

List_array* MakeEmpty(){
    List_array* Entry;
    Entry = (List_array*) new(List_array);
    return Entry;
}

int Find(int data, List_array* L){
    int i = 0;
    while(i <= L->last && L->array[i] != data){
        ++i;
    }
    if(i <= L->last){
        return i;
    }
    else{
        return -1;
    }
}

int Length(List_array* L){
    return L->last + 1;
}

int FindKth(int K, List_array* L){
    if(K < 1 || K > Length(L)){
        return -1;
    }
    else{
        return L->array[K-1];
    }
}

int Insert(int data, int pos, List_array* L){
    if(Length(L) == MAXSIZE){
        return -1;
    }
    if(pos < 1 || pos > Length(L)+1){
        return -1;
    }
    for(int i = L->last; i >= pos-1; --i){
        L->array[i+1] = L->array[i];
    }
    L->array[pos-1] = data;
    L->last++;
    return 0;
}

int Delete(int pos, List_array* L){
    if(pos < 1 || pos > Length(L)){
        return -1;
    }
    for(int i = pos-1; i < L->last; i++){
        L->array[i] = L->array[i+1];
    }
    L->array[L->last] = 0;
    L->last--;
    return 0;
}

/*链表*/
class chain_node{
    public:
        int data;
        chain_node* Next;
        chain_node(){
            this->data = 0;
            this->Next = nullptr;
        }
        chain_node(int data, chain_node* Next = nullptr){
            this->data = data;
            this->Next = Next;
        }
};

int c_length(chain_node* c){
    int i = 1;
    chain_node* p = c;
    if(c){
        while(p = p->Next){
            ++i;
        }
    }
    return i;
}

int main(){

    chain_node p5(5);
    chain_node p4(4, &p5);
    chain_node p3(3, &p4);
    chain_node p2(2, &p3);
    chain_node p1(1, &p2);
    
    cout << c_length(&p1) << endl;

    return 0;
}