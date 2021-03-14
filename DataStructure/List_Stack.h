#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif


/* 栈遵循“先进后出”的原则，此为链表栈，属于动态栈 */
/* 栈的关键是指向头部和尾部的两个指针，通过这两个指针在整个链表中的相对位置，来实现相关栈的操作 */
typedef struct stack_node{

    int li_data;                //数据域
    struct stack_node *pNext;   //指针域

}SATCK_NODE,*pSTACK_NODE;

typedef struct list_Stack{

    SATCK_NODE *pTop;       /* 顶指针 */
    SATCK_NODE *pBottom;    /* 底指针 */

}LIST_STACK,*pLIAT_STACK;

/* 栈初始化 */
extern bool Stack_Init(LIST_STACK *sta);
/* 判断栈空 */
extern bool Judge_Stack_empty(LIST_STACK *const sta);
/* 压栈 */
extern bool Stack_push(LIST_STACK *sta, int val);
/* 遍历栈 */
extern void Stack_Traverse(LIST_STACK *const sta);
/* 出栈 */
extern bool Stack_pop(LIST_STACK *sta);
/* 清空栈 */
extern void Clear_Stack(LIST_STACK *sta);


#ifdef __cplusplus
}
#endif


#endif
