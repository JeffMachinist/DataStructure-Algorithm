#ifndef _LIST_COMMON_H
#define _LIST_COMMON_H

typedef int ElementType;

// 类型定义，根据宏选择
#ifdef USE_CURSOR_LIST
    #define SpaceSize 100
    typedef int PtrToNode;
#else
    struct Node;
    typedef struct Node *PtrToNode;
#endif

typedef PtrToNode List;
typedef PtrToNode Position;

// 通用接口声明
int IsEmpty( const List L );
int IsLast( const Position P, const List L );
List MakeEmpty( List L );
void DeleteList( List L );
void Insert( ElementType X, List L, Position P );
Position Find( ElementType X, const List L );
Position FindPrevious( ElementType X, const List L );
void Delete( ElementType X, List L );
Position Header( const List L );
Position First( const List L );
Position Advance( const Position P );
ElementType Retrieve( const Position P );

// 接口声明
#ifdef USE_CURSOR_LIST
    void InitializeCursorSpace(void);
#endif

#endif /* _LIST_COMMON_H */
