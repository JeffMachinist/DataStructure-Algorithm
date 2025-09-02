#ifndef _STACK_COMMON_H
#define _STACK_COMMON_H

typedef int ElementType;

#ifdef USE_ARRAY_STACK
    #define EmptyTOS ( -1 )
    #define MinStackSize ( 5 )
#endif

// 类型定义，根据宏选择
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

// 通用接口声明
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(StackCapacity MaxElements);
void MakeEmpty(Stack S);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);

#endif /* _STACK_COMMON_H */