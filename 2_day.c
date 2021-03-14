#include "main.h"
#include "Arrays.h"
/*
    动态内存分配不依赖于函数调用，不会随函数调用而释放，必须使用free，对分配内存的地址释放。
    函数内部定义的变量属于静态分配。会随着函数调用完毕而释放。
    动态分配内存的地址要求在函数结尾释放，或者返回首地址，供其他函数调用使用，但在最后不用时将之释放（特别是在一直运行的函数）。
*/
int main()
{
    int val;
    int i;
    ARRAYS Arrs;
    Init_Arrays(&Arrs,10); //数组初始化
    for(i=0; i<20;i++){
        Addone_val(&Arrs, i);//赋值
    }
    
    printf("len=%d pBase=%d valid_cnt=%d\n",Arrs.len, Arrs.pBase, Arrs.valid_cnt);
   
    for(i=0; i<20;i++){
       printf("%d ",*(Arrs.pBase+i));//*(Arrs.pBase+i)) ==  Arrs.pBase[i] //打印每个数值
    }printf("\n");

    Delete_val(&Arrs, 4, &val);//删除某个位置的值
    Insert_val(&Arrs, 20, 30);//插入某个位置的值
    for(i=0; i<20;i++){
       printf("%d ",Arrs.pBase[i]);//打印每个数值
    }printf("\n");
   
    printf("del_val=%d\n",val);

    Arr_free(Arrs.pBase);//(*Arr_free) == Arr_free //释放动态分配的内存
    return 0;
}
