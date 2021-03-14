#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum{

    Arr_false,
    Arr_true
}Arr_bool;

typedef struct ARRAYS{

    int* pBase;      //数组基地址存放
    int  len;        //总长度
    int  valid_cnt;  //有效长度
    int  auto_factor; //自动扩充因子
    
}ARRAYS,*pARRAYS;



/* 初始化数组 */
extern Arr_bool Init_Arrays(pARRAYS pArr, const int lengh);
/* 释放开辟的空间 */
extern void  (*Arr_free)(void *ptr);
/* 在数组尾部加一个数*/
extern Arr_bool Addone_val(pARRAYS pArr, const int val);
/* 往数组中插入一个数 */
extern Arr_bool Insert_val(pARRAYS pArr, const int pos, const int val);
/* 删除数组中的一个元素 */
extern Arr_bool Delete_val(pARRAYS pArr, const int pos, int *const del_val);


#ifdef __cplusplus
}
#endif

#endif
