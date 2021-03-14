#ifndef __ARRAYS_QUEUE_H__
#define __ARRAYS_QUEUE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

/* 队列遵循“先入先出”原则 */
/* 静态队列 ，以数组为基底；动态队列，要求知道先进来的元素的位置，可采用双链表构成 */
typedef struct queue{

    int *pBase; /* 分配内存的初始地址 */
    int front;  /* 队列头部位置*/
    int rear;   /* 队列最后一个有效元素的下一个位置 */
    int len;    /* 分配空间的长度，有效长度为len-1 */

}QUEUE,*pQUEUE;

/* 队列初始化 */
extern void Queue_Init(QUEUE *pQue, int const len);
/* 入队 */
extern bool Enter_Queue(QUEUE *const pQue, int val);
/* 出队 */
extern bool Out_Queue(QUEUE *const pQue, int *pVal);
/* 遍历队列 */
extern void Queue_Traverse(QUEUE *const pQue);
/* 释放分配内存 */
extern void (*Queue_free)(void *ptr);


#ifdef __cplusplus
}
#endif


#endif
