#ifndef _LIST_COMMON_H
#define _LIST_COMMON_H

typedef int ElementType;

#ifdef USE_CURSOR_LIST
    #define SpaceSize 100
    typedef int PtrToNode;
#else
    struct Node;
    typedef struct Node *PtrToNode;
#endif

typedef PtrToNode List;
typedef PtrToNode Position;

#ifdef USE_CURSOR_LIST
    void InitializeCursorSpace(void);
#endif

List MakeEmpty( List L );
int IsEmpty( const List L );
int IsLast( const Position P, const List L );
Position Find( ElementType X, const List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, const List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( const List L );
Position First( const List L );
Position Advance( const Position P );
ElementType Retrieve( const Position P );

#endif /* _LIST_COMMON_H */
