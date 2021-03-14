#include "main.h"
#include "Linked_List.h"


int main()
{
    NODE *pHead = NULL;         /* 头指针 */
    NODE *pMid = NULL;          /* 临时指针 */
    int i;
    int length = 0;
    int val = 0;
    Init_List(&pHead);          /* 产生一个空链表 */
    if(true == Judge_LIst_Empty(pHead)){
        printf("当前为空链表\n");
    }

    pMid = pHead;               /* 用临时指针做测试 */
    for(i=0; i<10;i++){
        AddOne_val(pHead, i);   /* 尾部增加节点 */
        pMid = pMid->pNext;     /* 移动至指向下一个节点 */
        printf("%d  ",pMid->li_data);
    }printf("\n");

    Insert_Node(pHead, 5, 32);  /* 插入一个节点 */
    if(false == Delete_Node(pHead, 3, &val)){
       printf("false delete\n");
    }                           /* 删除一个节点 */

    Sort_List(pHead);           /* 链表排序，从小到大 */
    Traverse_List(pHead);       /* 遍历链表 */
    printf("val = %d ",val);

    length= Return_Length(pHead);/*返回链表长度 */
    printf("\nlen=%d\n",length);
   return 0;   
}
