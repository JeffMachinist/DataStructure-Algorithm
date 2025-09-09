#ifndef _DS_COMMON_H
#define _DS_COMMON_H

// 通用元素类型
typedef int ElementType;

// ================== 列表 List ==================
#ifdef USE_CURSOR_LIST
    #define SpaceSize 100
    typedef int ListCapacity;
    typedef int PtrToNode;
#else
    typedef void *ListCapacity;
    struct Node;
    typedef struct Node *PtrToNode;
#endif
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(ListCapacity cap);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
void DeleteList(List L);
void Insert(ElementType X, List L, Position P);
Position Find(ElementType X, const List L);
Position FindPrevious(ElementType X, const List L);
void Delete(ElementType X, List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);

#ifdef USE_CURSOR_LIST
void InitializeCursorSpace(void);
#endif

// ================== 队列 Queue ==================
typedef int QueueCapacity;
struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue(QueueCapacity MaxElements);
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void MakeEmpty(Queue Q);
void DisposeQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

// ================== 栈 Stack ==================
#ifdef USE_ARRAY_STACK
    typedef int StackCapacity;
    struct StackRecord;
    typedef struct StackRecord *Stack;
#else
    typedef void *StackCapacity;
    struct Node;
    typedef struct Node *PtrToNode;
    typedef PtrToNode Stack;
#endif

Stack CreateStack(StackCapacity MaxElements);
int IsEmpty(Stack S);
int IsFull(Stack S);
void MakeEmpty(Stack S);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);

// ================== 跳表 SkipList ==================
struct SkipNode;
typedef struct SkipNode *SkipList;
typedef struct SkipNode *SkipPosition;

SkipList InitializeSkipList(void);
SkipList MakeEmptySkipList(SkipList L);
SkipList InsertSkipList(ElementType X, SkipList L);
SkipPosition FindSkipList(ElementType X, SkipList L);
SkipPosition FindMinSkipList(SkipList L);
SkipPosition FindMaxSkipList(SkipList L);
SkipList DeleteSkipList(ElementType X, SkipList L);
ElementType RetrieveSkipList(SkipPosition P);

// ================== 哈希表 HashTable ==================
typedef unsigned int HashIndex;
#ifdef USE_QUADRATIC_PROBING
    typedef HashIndex HashPosition;
#else
    struct ListNode;
    typedef struct ListNode *HashPosition;
#endif
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
void InsertHash(ElementType Key, HashTable H);
HashPosition FindHash(ElementType Key, HashTable H);

#ifdef USE_QUADRATIC_PROBING
ElementType RetrieveHash(HashPosition P, HashTable H);
HashTable Rehash(HashTable H);
#else
ElementType RetrieveHash(HashPosition P);
#endif

// ================== 堆 Heap ==================
#ifdef USE_BIN_HEAP
    typedef int HeapCapacity;
    struct HeapStruct;
    typedef struct HeapStruct *PriorityQueue;
#elif defined(USE_LEFTIST_HEAP)
    typedef void *HeapCapacity;
    struct TreeNode;
    typedef struct TreeNode *PriorityQueue;
#elif defined(USE_PAIRING_HEAP)
    typedef void *HeapCapacity;
    struct PairNode;
    typedef struct PairNode *PairHeap;
    typedef struct PairNode *PriorityQueue;
#elif defined(USE_BINOMIAL_HEAP)
    typedef void *HeapCapacity;
    struct BinNode;
    typedef struct BinNode *BinTree;
    struct Collection;
    typedef struct Collection *BinQueue;
    typedef struct Collection *PriorityQueue;
#endif

PriorityQueue InitializeHeap(HeapCapacity capacity);
int IsEmptyHeap(PriorityQueue H);
int IsFullHeap(PriorityQueue H);
void MakeEmptyHeap(PriorityQueue H);
void DestroyHeap(PriorityQueue H);
ElementType FindMinHeap(PriorityQueue H);

// ================== 树 Tree ==================
typedef int TreeElementType;
#ifdef USE_AVL_TREE
    struct AvlNode;
    typedef struct AvlNode *TreePosition;
    typedef struct AvlNode *SearchTree;
#elif defined(USE_RED_BLACK_TREE)
    struct RedBlackNode;
    typedef struct RedBlackNode *TreePosition;
    typedef struct RedBlackNode *SearchTree;
#elif defined(USE_AA_TREE)
    struct AANode;
    typedef struct AANode *TreePosition;
    typedef struct AANode *SearchTree;
    extern TreePosition NullNode;
#elif defined(USE_TREAP)
    struct TreapNode;
    typedef struct TreapNode *TreePosition;
    typedef struct TreapNode *SearchTree;
    extern TreePosition NullNode;
#elif defined(USE_SPLAY_TREE)
    struct SplayNode;
    typedef struct SplayNode *TreePosition;
    typedef struct SplayNode *SearchTree;
#else
    struct TreeNode;
    typedef struct TreeNode *TreePosition;
    typedef struct TreeNode *SearchTree;
#endif

SearchTree InitializeTree(void);
SearchTree MakeEmptyTree(SearchTree T);
SearchTree InsertTree(TreeElementType X, SearchTree T);
TreePosition FindTree(TreeElementType X, SearchTree T);
TreePosition FindMinTree(SearchTree T);
TreePosition FindMaxTree(SearchTree T);
SearchTree DeleteTree(TreeElementType X, SearchTree T);

#ifdef USE_SPLAY_TREE
TreeElementType RetrieveTree(SearchTree T);
#else
TreeElementType RetrieveTree(TreePosition P);
#endif

#ifdef USE_RED_BLACK_TREE
void PrintTree(SearchTree T);
#endif

#endif /* _DS_COMMON_H */