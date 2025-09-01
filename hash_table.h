#ifndef _HASH_TABLE_COMMON_H
#define _HASH_TABLE_COMMON_H
typedef int ElementType;
typedef unsigned int Index;

#ifdef USE_QUADRATIC_PROBING
        typedef Index Position;
#else
        struct ListNode;
        typedef struct ListNode *Position;
#endif

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );

#ifdef USE_QUADRATIC_PROBING
ElementType Retrieve( Position P, HashTable H );
HashTable Rehash( HashTable H );
#else
ElementType Retrieve( Position P );
#endif

#endif  /* _HASH_TABLE_COMMON_H */
