#include "main.h"
#include "List_Stack.h"


int main()
{
    LIST_STACK sta;
    Stack_Init(&sta);     /* 初始化栈 */
    Stack_push(&sta, 10);
    Stack_push(&sta, 15);
    Stack_push(&sta, 20);
    Stack_push(&sta, 25);
    Stack_push(&sta, 30);
    Stack_push(&sta, 35); /* 压栈 */
    Stack_Traverse(&sta); /* 遍历栈 */
    Stack_pop(&sta);
    Stack_pop(&sta);      /* 出栈 */
    Stack_Traverse(&sta);
    Clear_Stack(&sta);    /* 清空栈 */
    Stack_Traverse(&sta);
    printf("OK\n");
   return 0;   
}
