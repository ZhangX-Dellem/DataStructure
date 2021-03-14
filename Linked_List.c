#include "Linked_List.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

/* 产生一个头结点，作为链表的创建 */
void Init_List(NODE **pHead){

    *pHead = (NODE*)malloc(sizeof(NODE));
    assert(NULL != pHead);
    (*pHead)->pNext = NULL;
    return ;

}
/* 产生一个头结点，作为链表的创建 */
/* NODE* Init_List(void){

    NODE* pHead = (NODE*)malloc(sizeof(NODE));
    assert(NULL != pHead);
    pHead->pNext = NULL;
    return pHead;

} */

/* 往链表尾部加入新节点 */
bool AddOne_val(NODE *const pHead, int const val ){

    NODE* pEnd = NULL;          /* 创建一个尾指针 */
    NODE* pMid = pHead;         /* 临时中间指针，并指向头结点 用于寻找最后的节点位置 */
    while( NULL != pMid->pNext ){
       pMid = pMid->pNext;
    }                           /* 找到链表最后的节点，并用pMid指向该节点 */
    pEnd = pMid;

    NODE* pNew = (NODE*)malloc(sizeof(NODE)); /* 创建一个新节点 */
    if(NULL == pNew){
        return false;
    }
    pNew->li_data = val;        /* 数据域存放数据 */
    pEnd->pNext = pNew;         /* 连接两个节点 */
    pNew->pNext = NULL;         /* 最后的节点指向为空，便于查找 */
    return true;
}

/* 遍历链表 */
void Traverse_List(NODE *const pHead){

    NODE *p = pHead->pNext;
     /* 当前指向非空，则表示存在 打印当前节点数据域的值 */
    while(NULL != p){
        printf("%d  ",p->li_data);
        p = p->pNext;/* 指向后一个节点，循环判断，直至下一个节点为空，表示为尾节点 */
    }printf("\n");
}

/* 判断链表是否为空 */
bool Judge_LIst_Empty(NODE *const pHead){

    return NULL == pHead->pNext? true : false;
}

/* 返回链表长度 */
int Return_Length(NODE *const pHead){

    NODE *p = pHead->pNext;
    int len = 0;
    /* 当前指向非空，则表示存在 len++ */
    while(NULL != p){
        len++;
        p = p->pNext;/* 指向后一个节点，循环判断，直至下一个节点为空，表示为尾节点 */
    }
    return len;
}

/* 插入一个新节点 */
bool Insert_Node(NODE *const pHead, int pos, int val){

    int i = 0;
    NODE *p = pHead;
    while(NULL != p && i < pos-1){
        p = p->pNext;
        i++;
    }
    if(i>pos-1 || NULL == p){
        return false;
    }/* 保证pos位置前一个节点是存在的，否则就返回false */

    NODE* pNew = (NODE*)malloc(sizeof(NODE)); //创建一个新节点
    if(NULL == pNew){
        return false;
    }   
    pNew->li_data = val;    /* 保存数值 */
    pNew->pNext = p->pNext; /* 新节点小指向原先的下一个节点 */
    p->pNext = pNew;        /* 原先的当前节点指向新节点 */
    return true;

}

/* 删除一个节点 */
bool Delete_Node(NODE *const pHead, int pos, int *pval){

    int i = 0;
    NODE *p = pHead;
    NODE *delete_p = NULL;
    while(NULL != p->pNext && i < pos-1){
        p = p->pNext;
        i++;
    }
    if(i>pos-1 || NULL == p->pNext){
        return false;
    }/* 保证pos位置是存在节点的，否则就返回false */

    delete_p = p->pNext;        /* 保存要删除节点的地址 */
    *pval = delete_p->li_data;  /* 保存要删除节点的数值 */

    p->pNext = delete_p->pNext; /* 让上一个节点连接要删除节点的后一个节点 */
    free(delete_p);             /* 释放要删除节点 */
    delete_p = NULL;            /* delete_p指向空 */

    return true;
}

/* 链表排序，从小到大 */
void Sort_List(NODE *const pHead){

    int i = 0, j = 0, t = 0;
    NODE *p = NULL, *q = NULL;
    int len = Return_Length(pHead);

    for(i = 0, p = pHead->pNext; i < len-1; i++, p = p->pNext){

        for(j = i+1, q = p->pNext; j < len; j++, q = q->pNext){

            if(p->li_data > q->li_data){

                t = p->li_data;
                p->li_data = q->li_data;
                q->li_data = t;
            }
        }

    }
}