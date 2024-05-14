#include <iostream>

using namespace std;

#define MAXSIZE 100   // 最大容量
#define INITSIZE 100  // 初始分配
#define ELemType int
#define INCREMENT 10  // 增量
#define STATUS bool
#define OK 1
#define ERROR 0

// 静态分配
typedef struct List1
{
    ELemType data[MAXSIZE]; // 元素 
    int length;             // 长度
}SqList;

typedef struct List2
{
    ELemType *data;          // 元素
    int max_Size, length;    // 最大容量与当前长度
    
}SeqList;



// 创建一个空的顺序表
STATUS InitList_sq(SqList &L)
{
    // 构造空线性表L
    // L.data = (ELemType *)malloc(INITSIZE*sizeof(ELemType));
    if(!L.data)
    {
        return ERROR;
    }
    L.length = 0;
    return OK;
}

// 动态创建一个空的顺序表
STATUS InitList_sq(SeqList &L)
{
    // 构造空线性表L
    L.data = (ELemType *)malloc(INITSIZE*sizeof(ELemType));
    // c++ new
    // L.data = new ELemType[INITSIZE];
    if(!L.data)
    {
        return ERROR;
    }
    L.length = 0;
    L.max_Size = INITSIZE;
    return OK;
}

// 插入
STATUS List_Insert(SqList &L, int i, ELemType e)
{
    if(i<1||i>L.length+1||L.length>=MAXSIZE)
    {
        return false;
    }
    for(int j = L.length; j>=i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 插入
STATUS List_Insert(SeqList &L, int i, ELemType e)
{
    if(i<1||i>L.length+1)
    {
        return false;
    }
    int *newbase;
    if(L.length>=L.max_Size)
    {
        newbase = (ELemType*)realloc(L.data, (L.max_Size+INCREMENT)*sizeof(ELemType));
        if(!newbase)
        {
            return 0;
        }
        L.data = newbase;
        L.max_Size += INCREMENT;
        
    }
    int *q;
    q = &(L.data[i-1]);
    for(int *p = &(L.data[L.length-1]); p >= q; --p)
        *(p+1) = *p;
    *q = e;
    L.length++;
    return true;
}

// 输出线性表元素
STATUS printList(SqList L)
{
    if(!L.data)
    {
        cout << "输出线性表元素：" << endl;
        for(int i = 0; i <= L.length; i++)
        {
            cout << L.data << endl;
        }
    }
    return true;
}

STATUS printList(SeqList L)
{
    if(!L.data)
    {
        cout << "输出线性表元素：" << endl;
        for(int i = 0; i <= L.length; i++)
        {
            cout << L.data << endl;
        }
    }
    return true;
}

int main()
{
    SqList L1;
    SeqList L2;
    InitList_sq(L1);
    InitList_sq(L2);
    List_Insert(L1, 1, 10);
    List_Insert(L2, 1, 1);
    printList(L1);
    printList(L2);
    cout << "end" << endl;
    return 0;
}
