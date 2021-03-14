#include "Arrays.h"
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
// assert的作用是先计算表达式expression，如果其值为假（即为0），那么它先向标准错误流stderr打印一条出错信息，
// 然后通过调用abort来终止程序运行；否则，assert()无任何作用。


/* 判断数组是否为空 */
static Arr_bool Judge_Empty(pARRAYS pArr);
/* 判断数组是否已满 */
static Arr_bool Judge_Full(pARRAYS pArr);
/* 自动增长数组长度 增益为5 */
static Arr_bool Auto_expansion(pARRAYS pArr);



/* 初始化数组 */
Arr_bool Init_Arrays(pARRAYS pArr, const int lengh){

    assert( lengh>0 );//长度不能<=0
    pArr->pBase = (int *)malloc(sizeof(int)*lengh);//分配失败会返回NULL
    if( NULL == pArr->pBase){
        return Arr_false;
    }
    else{
        pArr->len = lengh;
        pArr->valid_cnt = 0;
        pArr->auto_factor = 5;
        return Arr_true;
    }

}

/* 释放开辟的空间 */
//理解这里，需要知道函数调用的原理
void  (*Arr_free)(void *ptr) = free;//可在free前加&，也可不加，是可选的；同样的，使用时可直接用Arr_free，与(*Arr_free)(防止歧义)是一样的，详见P261(c和指针)

/* 判断数组是否为空 */
static Arr_bool Judge_Empty(pARRAYS pArr){

    return 0 == pArr->valid_cnt ? Arr_true : Arr_false;
}

/* 判断数组是否已满 */
static Arr_bool Judge_Full(pARRAYS pArr){

    return pArr->valid_cnt == pArr->len ? Arr_true : Arr_false;
    
}
/* 在数组尾部加一个数*/
Arr_bool Addone_val(pARRAYS pArr, const int val){

    if(Arr_true == Judge_Full(pArr)){
        if(Arr_false == Auto_expansion(pArr)) return Arr_false;//扩充失败则返回Arr_false
    }
        pArr->pBase[pArr->valid_cnt] = val;
        pArr->valid_cnt++;
        return Arr_true;
}
/* 往数组中插入一个数 */
// pos: 从1开始
Arr_bool Insert_val(pARRAYS pArr, const int pos, const int val){

    assert( pos >= 1&&pos <= pArr->valid_cnt );//pos有效值介于1到valid_cnt，否则中断程序
    if(Arr_true == Judge_Full(pArr)){
       if(Arr_false == Auto_expansion(pArr)) return Arr_false;//扩充失败则返回Arr_false
    }
    int i;
    for ( i = pArr->valid_cnt; i >= pos; i--){
        pArr->pBase[i] = pArr->pBase[i-1];
    }
    pArr->pBase[pos-1] = val;
    return Arr_true;

}
/* 自动增长数组长度 增益为5 */
static Arr_bool Auto_expansion(pARRAYS pArr){

    pArr->len = (pArr->len + pArr->auto_factor);
    pArr->pBase =(int *)realloc(pArr->pBase, pArr->len*sizeof(int) );//重新分配
    if( NULL == pArr->pBase){
        return Arr_false;
    }
    else{
        return Arr_true;
    }
}
/* 删除数组中的一个元素 */
// pos: 从1开始
// del_val：读取删除的元素
Arr_bool Delete_val(pARRAYS pArr, int const pos, int *const del_val){

    assert( pos >= 1&&pos <= pArr->valid_cnt );//pos有效值介于1到valid_cnt，否则中断程序
    int i;
    *del_val = pArr->pBase[pos-1];//记录删除元素
    for(i=pos-1; i<pArr->valid_cnt; i++){
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    return Arr_true;
}
