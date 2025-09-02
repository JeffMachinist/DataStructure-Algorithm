#ifndef _TREE_COMMON_H
#define _TREE_COMMON_H

typedef int ElementType;

#ifdef USE_RED_BLACK_TREE
    #define NegInfinity (-10000)
#elif defined(USE_TREAP)
    #define Infinity 32767
#elif defined(USE_SPLAY_TREE)
        #define Infinity 30000
        #define NegInfinity (-30000)
#endif

// 根据宏选择树类型和结构体
#ifdef USE_AVL_TREE
    struct AvlNode;
    typedef struct AvlNode *Position;
    typedef struct AvlNode *SearchTree;
    typedef struct AvlNode *AvlTree;
#elif defined(USE_RED_BLACK_TREE)
    struct RedBlackNode;
    typedef struct RedBlackNode *Position;
    typedef struct RedBlackNode *SearchTree;
    typedef struct RedBlackNode *RedBlackTree;
#elif defined(USE_AA_TREE)
    struct AANode;
    typedef struct AANode *Position;
    typedef struct AANode *SearchTree;
    typedef struct AANode *AATree;
    extern Position NullNode;
#elif defined(USE_TREAP)
    struct TreapNode;
    typedef struct TreapNode *Position;
    typedef struct TreapNode *SearchTree;
    typedef struct TreapNode *Treap;
    extern Position NullNode;
#elif defined(USE_SPLAY_TREE)
    struct SplayNode;
    typedef struct SplayNode *Position;
    typedef struct SplayNode *SearchTree;
    typedef struct SplayNode *SplayTree;
#else // 默认二叉查找树
    struct TreeNode;
    typedef struct TreeNode *Position;
    typedef struct TreeNode *SearchTree;
#endif

// 通用接口声明
SearchTree Initialize(void); // 某些树有Initialize
SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(SearchTree T); // Splay树获取根节点

#ifdef USE_RED_BLACK_TREE
void PrintTree(SearchTree T);
#endif

#endif /* _TREE_COMMON_H */