#ifndef _STACK_COMMON_H
#define _STACK_COMMON_H

typedef int ElementType;

#ifdef USE_ARRAY_STACK
    struct StackRecord;
    typedef struct StackRecord *Stack;
#else
    struct Node;
    typedef struct Node *PtrToNode;
    typedef PtrToNode Stack;
#endif

int IsEmpty(Stack S);

#ifdef USE_ARRAY_STACK
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
ElementType TopAndPop(Stack S);
#else
Stack CreateStack(void);
#endif

void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /* _STACK_COMMON_H */