#ifndef _HEAP_COMMON_H
#define _HEAP_COMMON_H

// 根据需要统一 ElementType 类型
typedef int ElementType;

// 可选：支持 long 类型
#ifdef USE_BINOMIAL_HEAP
typedef long ElementType;
#define Infinity (30000L)
#define MaxTrees (14)   /* Stores 2^14 -1 items */
#define Capacity (16383)
#endif

// 类型定义，根据宏选择
#ifdef USE_BIN_HEAP
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
#elif defined(USE_LEFTIST_HEAP)
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
#elif defined(USE_PAIRING_HEAP)
struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;
#elif defined(USE_BINOMIAL_HEAP)
struct BinNode;
typedef struct BinNode *BinTree;
struct Collection;
typedef struct Collection *BinQueue;
#endif

// 接口声明
#ifdef USE_BIN_HEAP
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#elif defined(USE_LEFTIST_HEAP)
PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#elif defined(USE_PAIRING_HEAP)
PairHeap Initialize(void);
void Destroy(PairHeap H);
PairHeap MakeEmpty(PairHeap H);
PairHeap Insert(ElementType Item, PairHeap H, Position *Loc);
PairHeap DeleteMin(ElementType *MinItem, PairHeap H);
ElementType FindMin(PairHeap H);
PairHeap DecreaseKey(Position P, ElementType NewVal, PairHeap H);
int IsEmpty(PairHeap H);
int IsFull(PairHeap H);

#elif defined(USE_BINOMIAL_HEAP)
BinQueue Initialize(void);
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);
BinQueue Insert(ElementType Item, BinQueue H);
ElementType DeleteMin(BinQueue H);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType FindMin(BinQueue H);
int IsEmpty(BinQueue H);
int IsFull(BinQueue H);
#endif

#endif /* _HEAP_COMMON_H */