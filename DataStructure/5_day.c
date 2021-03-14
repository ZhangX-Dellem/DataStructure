#include "main.h"
#include "Arrays_Queue.h"


int main()
{
    QUEUE Que;
    int pVal ;
    Queue_Init(&Que,10);    /* 队列初始化 */
    Enter_Queue(&Que, 7);
    Enter_Queue(&Que, 8);
    Enter_Queue(&Que, 12);  /* 入队 */
    Queue_Traverse(&Que);   /* 遍历队列 */
    Out_Queue(&Que, &pVal); /* 出队 */
    Queue_Traverse(&Que);   /* 遍历队列 */
    printf("delete value is %d\n",pVal);
    Queue_free(Que.pBase);  /* 释放内存 */
    printf("OK\n");
   return 0;   
}
