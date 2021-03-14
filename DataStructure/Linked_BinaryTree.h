#ifndef _LINKED_BINARYTREE_H_
#define _LINKED_BINARYTREE_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
typedef struct BinaryTree{

    char data;                       /* 数据域 */
    struct BinaryTree *pLeftTree;   /* 左子树 */
    struct BinaryTree *pRightTree;  /* 右子树 */

}BINARYTREE,*pBINARYTREE;

/* 创建二叉树 */
extern BINARYTREE * CreateTree(void);
/* 先序遍历 */
extern void PreTraverseTree(BINARYTREE *const pBi_Tree);
/* 中序遍历 */
extern void IntTraverseTree(BINARYTREE *const pBi_Tree);
/* 后序遍历 */
extern void LastTraverseTree(BINARYTREE *const pBi_Tree);
#ifdef __cplusplus  
}
#endif


#endif
