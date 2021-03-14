#include "main.h"
#include "Linked_BinaryTree.h"
int main()
{
    BINARYTREE *pTree = NULL;
    pTree = CreateTree();/* 创建二叉树 */
    PreTraverseTree(pTree);/* 先序遍历 */
    printf("\n");
    IntTraverseTree(pTree);/* 中序遍历 */
    printf("\n");
    LastTraverseTree(pTree);/* 后序遍历 */
    printf("\n");
   return 0;   
}