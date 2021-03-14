#include "main.h"

void QuickSort(int *a, int low, int high);
int FindPos(int *a, int low, int high);
/* 快速排序:首先找到某一个数的确切位置，再利用递归，继续往左和往右依次找到每个数的确切位置 */
/* 快速排序：利用递归思想，简单快捷的实现了功能 */
int main()
{
    int a[] ={0, 9, 1, 22, 3};
    int i;
    QuickSort(a, 0, 4);
    for(i=0; i<5; i++)
    printf("%d  ",a[i]);
    printf("Ok\n");
   return 0;   
}
/* 
*   func:快速排序
*   param: a:数组首地址
           low:数组第一个元素下标
           high:数组最后一个元素下标
 */
void QuickSort(int *a, int low, int high){

    int pos = 0;
    if(low < high){
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos-1);
        QuickSort(a, pos+1, high);
    }
}
/* 
*   func:找到一个数的位置
*   param: a:数组首地址
           low:数组第一个元素下标
           high:数组最后一个元素下标
 */
int FindPos(int *a, int low, int high){
    
    int val = a[low];
    while(low < high){

        while(low < high && a[high] >= val){
            --high;
        }
        a[low] = a[high];
        while(low < high && a[low] <= val){
            ++low;
        }
        a[high] = a[low];
    }

    a[low] = val;
    return low;
}