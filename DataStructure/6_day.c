#include "main.h"

/* 共用体中套结构体：在共用体内部，value的值与结构体整体共一个地址。 */
/* 当结构体中有多个数据变量时，改变其中的一个任意数据变量内容，都可能改变共用体中其余变量的值，
当然也可能不改变（当修改结构体中变量的值超过union中的变量存储位置，就不会改变） */
union{
    unsigned int value;
    struct{
        unsigned char first;
        unsigned char second;/* 结构体内变量时连续存储的，多余的部分留作空白 */
    } half;
} number;
/* 结构体中套用共用体：在结构体内部，给共用体部分分配一个union内部最大数据类型的存储空间，但不与结构体其余部分共用地址 */
typedef struct{
    int name ;
    union{
        int i;
        int j;
    }numbers;
}temp;

int main()
{
    temp my_str;
    my_str.name = 20;
    my_str.numbers.i = 50;
    number.value = 512;
    printf("%d\n",sizeof(number));
    printf("%d\n",sizeof(temp));
    printf("%d  %d  %d \n",number.value, number.half.first, number.half.second);/* 测试共用体结构存储 */
    printf("%d  %d  %d \n",my_str.name, my_str.numbers.i,  my_str.numbers.j);/* 测试结构体结构存储 */
   return 0;   
}
