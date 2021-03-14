#include "main.h"
/* 汉诺塔递归实现，理解算法原理，知晓递归的便利 */
/* 实现伪算法：
    如果是一个盘子
        直接将A柱子上的盘子从A移到C
    否则
        先将A上的n-1个盘子借助C移到B
        直接将A上的盘子移到C
        最后将B上的n-1个盘子借助A移到C
 */
void Hanoi(int n, char A, char B, char C){

    if(1 == n){
        printf("将编号为%d的盘子直接从%c柱子到%c柱子\n", n, A, C);
    }
    else{
        Hanoi(n-1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子到%c柱子\n", n, A, C);
        Hanoi(n-1, B, A, C);
    }
}
int main()
{
    char A = 'A', B = 'B', C = 'C';
    Hanoi(11, A, B, C);
   return 0;   
}
