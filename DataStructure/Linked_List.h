#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>
#ifdef __cplusplus
extern "C"
{
#endif
/* 非循环单链表 */
/* 链表的操作依赖于头结点，只需要知道头结点，就能够退出其他位置，头结点不存放有效数据 */
/* 操作链表是不会去改变头指针的指向的，一般使用一个临时指针（可看做尾指针）去操作，而头指针始终不变 */

typedef struct node{

    int li_data;     //数据域
    struct node *pNext; //指针域

}NODE,*pNODE;


/* 产生一个头结点，作为链表的创建 */
/* 两种方法 */
extern void Init_List(NODE **pHead);
/* extern NODE* Init_List(void); */
/* 往链表尾部加入新元素 */
extern bool AddOne_val(NODE *const pHead, int const val);
/* 遍历链表 */
extern void Traverse_List(NODE *const pHead);
/* 判断链表是否为空 */
extern bool Judge_LIst_Empty(NODE *const pHead);
/* 返回链表长度 */
extern int Return_Length(NODE *const pHead);
/* 插入一个新节点 */
extern bool Insert_Node(NODE *const pHead, int pos, int val);
/* 删除节点 */
extern bool Delete_Node(NODE *const pHead, int pos, int *pval);
/* 链表排序，从小到大 */
extern void Sort_List(NODE *const pHead);


#ifdef __cplusplus
}
#endif

#endif
