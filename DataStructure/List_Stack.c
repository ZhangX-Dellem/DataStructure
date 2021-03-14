#include "List_Stack.h"
#include <malloc.h>
#include <stdio.h>


/* 栈初始化 */
bool Stack_Init(LIST_STACK *sta){

    sta->pBottom = (SATCK_NODE *)malloc(sizeof(SATCK_NODE));
    if(NULL == sta->pBottom){
        return false;
    }
    else{
        sta->pTop = sta->pBottom;/* 初始栈，pTop与pbottom指向同一个节点（头结点） */
        sta->pBottom->pNext = NULL;
        return true;
    }
}
/* 判断栈空 */
bool Judge_Stack_empty(LIST_STACK *const sta){

    return sta->pBottom == sta->pTop? true : false;
}
/* 压栈 */
bool Stack_push(LIST_STACK *sta, int val){

    SATCK_NODE *pNew = (SATCK_NODE *)malloc(sizeof(SATCK_NODE));
    if(NULL == pNew){
        return false;
    }
    else{
        pNew->li_data = val;
        pNew->pNext = sta->pTop;
        sta->pTop = pNew;
        return true;
    }
}
/* 遍历栈 */
void Stack_Traverse(LIST_STACK *const sta){

    SATCK_NODE *p = sta->pTop;
    /* 判定p 与 pBottom 的相对位置，指向同一个节点时，就是栈底的位置 */
    while(sta->pBottom != p){
        printf("%d  ",p->li_data);
        p = p->pNext;
    }printf("\n");
}
/* 出栈 */
bool Stack_pop(LIST_STACK *sta){

    if(true ==Judge_Stack_empty(sta)){
        printf("栈已空\n");
        return false;
    }
    SATCK_NODE *p = sta->pTop;
    sta->pTop = p->pNext;
    free(p);
    p = NULL;
    return true;
}
/* 清空栈 */
void Clear_Stack(LIST_STACK *sta){

    if(true ==Judge_Stack_empty(sta)){
        printf("栈已空\n");
        return ;
    }
    SATCK_NODE *p = sta->pTop;
    SATCK_NODE *q = NULL;
    /* 判定p 与 pBottom 的相对位置，指向同一个节点时，就是栈底的位置 */
    while (sta->pBottom != p){
        q = p->pNext;
        free(p);
        p = q;
    }
    p = NULL;
    q = NULL;
    sta->pTop = sta->pBottom;
}
