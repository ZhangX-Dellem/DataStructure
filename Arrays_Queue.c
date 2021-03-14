#include "Arrays_Queue.h"
#include <malloc.h>
#include <stdio.h>

static bool Judge_Queue_Full(QUEUE *const pQue);
static bool Judge_Queue_Empty(QUEUE *const pQue);

/* 队列初始化   length为队列长度，实际长度为length-1，保留一个长度给rear。好便捷判定满队列和空队列*/
void Queue_Init(QUEUE *pQue, int const length){

    pQue->pBase = (int *)malloc(sizeof(int)*length);/* 分配内存 */
    pQue->len = length;
    pQue->front = 0;
    pQue->rear = 0;

}

void  (*Queue_free)(void *ptr) = free;/* 释放分配内存 */

/* 当rear到达front的前一个位置时，就认为队列已满 就是说分配len长度，只用len-1长度 */
/* 判断队列满 */
static bool Judge_Queue_Full(QUEUE *const pQue){

    return (((pQue->rear + 1) % pQue->len) == pQue->front)? true : false;
}

/* 判断队列空 */
static bool Judge_Queue_Empty(QUEUE *const pQue){

    return pQue->rear == pQue->front? true : false;
}
/* 入队 */
bool Enter_Queue(QUEUE *const pQue, int val){

    if(true==Judge_Queue_Full(pQue)){
        printf("入队失败，队列已满\n");
        return false;
    }
    pQue->pBase[pQue->rear] = val;
    pQue->rear = (pQue->rear + 1 ) % pQue->len;/* 此方法可以实现自加会在len长度内循环自加 */
    return true;

}
/* 出队 */
bool Out_Queue(QUEUE *const pQue, int *pVal){

    if(true == Judge_Queue_Empty(pQue)){
        printf("出队失败，队列为空\n");
        return false;
    }
    *pVal = pQue->pBase[pQue->front];
    pQue->front = (pQue->front + 1) % pQue->len;
    return true ;
}
/* 遍历队列 */
void Queue_Traverse(QUEUE *const pQue){

    if(true == Judge_Queue_Empty(pQue)){
        printf("遍历失败，队列为空\n");
        return ;
    }
    int i = pQue->front;
    while( i != pQue->rear){

        printf("%d  ",pQue->pBase[i]);
        i = (i + 1) % pQue->len;
    }printf( "\n");
}