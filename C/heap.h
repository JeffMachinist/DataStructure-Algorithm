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
typedef int HeapCapacity; // 数组实现
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
#elif defined(USE_LEFTIST_HEAP)
typedef void* HeapCapacity; // 链表实现（参数可忽略）
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
#elif defined(USE_PAIRING_HEAP)
typedef void* HeapCapacity; // 链表实现（参数可忽略）
struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;
typedef struct PairNode *PriorityQueue;
#elif defined(USE_BINOMIAL_HEAP)
typedef void* HeapCapacity; // 链表实现（参数可忽略）
struct BinNode;
typedef struct BinNode *BinTree;
struct Collection;
typedef struct Collection *BinQueue;
typedef struct Collection *PriorityQueue;
#endif

// 通用接口声明
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
PriorityQueue Initialize(HeapCapacity capacity);
void MakeEmpty(PriorityQueue H);
void Destroy(PriorityQueue H);
ElementType FindMin(PriorityQueue H);

// 接口声明
#ifdef USE_BIN_HEAP
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);

#elif defined(USE_LEFTIST_HEAP)
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#elif defined(USE_PAIRING_HEAP)
PairHeap Insert(ElementType Item, PairHeap H, Position *Loc);
PairHeap DeleteMin(ElementType *MinItem, PairHeap H);
PairHeap DecreaseKey(Position P, ElementType NewVal, PairHeap H);

#elif defined(USE_BINOMIAL_HEAP)
BinQueue Insert(ElementType Item, BinQueue H);
ElementType DeleteMin(BinQueue H);
BinQueue Merge(BinQueue H1, BinQueue H2);
#endif

#endif /* _HEAP_COMMON_H */