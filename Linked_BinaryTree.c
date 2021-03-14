#include "Linked_BinaryTree.h"
#include <stdio.h>
#include <malloc.h>

/* 创建二叉树 */
BINARYTREE * CreateTree(void){

    BINARYTREE *pA = (BINARYTREE *)malloc(sizeof(BINARYTREE));
    BINARYTREE *pB = (BINARYTREE *)malloc(sizeof(BINARYTREE));
    BINARYTREE *pC = (BINARYTREE *)malloc(sizeof(BINARYTREE));
    BINARYTREE *pD = (BINARYTREE *)malloc(sizeof(BINARYTREE));
    BINARYTREE *pE = (BINARYTREE *)malloc(sizeof(BINARYTREE));  

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';/* 树节点保存的数据 */

    pA->pLeftTree = pB;
    pA->pRightTree = pC;
    pB->pLeftTree = NULL;
    pB->pRightTree = NULL;
    pC->pLeftTree = NULL;
    pC->pRightTree = pD;
    pD->pLeftTree = NULL;
    pD->pRightTree = pE;
    pE->pLeftTree = NULL;
    pE->pRightTree = NULL;/* 形成树的连接关系 */

    return pA;      /* 返回根节点 */
}
/* 先序遍历 */
void PreTraverseTree(BINARYTREE *const pBi_Tree){

    if(NULL != pBi_Tree){

        printf("%c  ",pBi_Tree->data);

        if(NULL != pBi_Tree->pLeftTree){
            PreTraverseTree(pBi_Tree->pLeftTree);
        }

        if(NULL != pBi_Tree->pRightTree){
            PreTraverseTree(pBi_Tree->pRightTree);
        }
    }

}

/* 中序遍历 */
void IntTraverseTree(BINARYTREE *const pBi_Tree){

    if(NULL != pBi_Tree){

        if(NULL != pBi_Tree->pLeftTree){
            PreTraverseTree(pBi_Tree->pLeftTree);
        }

        printf("%c  ",pBi_Tree->data);

        if(NULL != pBi_Tree->pRightTree){
            PreTraverseTree(pBi_Tree->pRightTree);
        }
    }

}

/* 后序遍历 */
void LastTraverseTree(BINARYTREE *const pBi_Tree){

    if(NULL != pBi_Tree){

        if(NULL != pBi_Tree->pLeftTree){
            PreTraverseTree(pBi_Tree->pLeftTree);
        }

        if(NULL != pBi_Tree->pRightTree){
            PreTraverseTree(pBi_Tree->pRightTree);
        }

        printf("%c  ",pBi_Tree->data);
    }

}


