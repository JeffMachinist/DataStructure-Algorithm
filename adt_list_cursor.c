#include <stdlib.h>
#include "fatal.h"
#define USE_CURSOR_LIST
#include "adt_list.h"

struct Node
{
    ElementType Element;
    Position    Next;
};

struct Node CursorSpace[ SpaceSize ];

static Position
CursorAlloc( void ){
    Position P;
    P = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;
    return P;
}

static void
CursorFree( Position P ){
    CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = P;
}

void
InitializeCursorSpace( void ){
    int i;
    for( i = 0; i < SpaceSize; i++ )
        CursorSpace[ i ].Next = i + 1;
    CursorSpace[ SpaceSize - 1 ].Next = 0;
}

int
IsEmpty( List L ){
    return CursorSpace[ L ].Next == 0;
}

int
IsLast( Position P, List L ){
    return CursorSpace[ P ].Next == 0;
}

List
MakeEmpty( List L ){
    if( L != 0 )
        DeleteList( L );
    L = CursorAlloc( );
    if( L == 0 )
        FatalError( "Out of memory!" );
    CursorSpace[ L ].Next = 0;
    return L;
}

void
DeleteList( List L ){
    Position P, Tmp;
    P = CursorSpace[ L ].Next;  /* Header assumed */
    CursorSpace[ L ].Next = 0;
    while( P != 0 ){
        Tmp = CursorSpace[ P ].Next;
        CursorFree( P );
        P = Tmp;
    }
}

void
Insert( ElementType X, List L, Position P ){
    Position TmpCell;
    TmpCell = CursorAlloc( );
    if( TmpCell == 0 )
        FatalError( "Out of space!!!" );
    CursorSpace[ TmpCell ].Element = X;
    CursorSpace[ TmpCell ].Next = CursorSpace[ P ].Next;
    CursorSpace[ P ].Next = TmpCell;
}

Position
Find( ElementType X, List L ){
    Position P;
    P = CursorSpace[ L ].Next;
    while( P && CursorSpace[ P ].Element != X )
        P = CursorSpace[ P ].Next;
    return P;
}

Position
FindPrevious( ElementType X, List L ){
    Position P;
    P = L;
    while( CursorSpace[ P ].Next &&
            CursorSpace[ CursorSpace[ P ].Next ].Element != X )
        P = CursorSpace[ P ].Next;
    return P;
}

void
Delete( ElementType X, List L )
{
    Position P, TmpCell;
    P = FindPrevious( X, L );
    if( !IsLast( P, L ) )  /* Assumption of header use */
    {                      /* X is found; delete it */
        TmpCell = CursorSpace[ P ].Next;
        CursorSpace[ P ].Next = CursorSpace[ TmpCell ].Next;
        CursorFree( TmpCell );
    }
}

Position
Header( List L ){
    return L;
}

Position
First( List L ){
    return CursorSpace[ L ].Next;
}

Position
Advance( Position P ){
    return CursorSpace[ P ].Next;
}

ElementType
Retrieve( Position P ){
    return CursorSpace[ P ].Element;
}
