#include <stdio.h>
#include <stdlib.h>

int A;              //全局未初始化变量
int B = 2;          //全局初始化变量
int static C;       //全局静态未初始化变量
int static D = 4;   //全局静态初始化变量
int const E = 5;    //全局常量

int main()
{
    int *m_addr;

    int a;           //局部未初始化变量
    int b = 2;       //局部初始化变量
    int static c;    //局部静态未初始化变量
    int static d = 4;//局部静态初始化变量
    int const e =5;  //局部常量

    m_addr = malloc(sizeof(int));

    printf("A_global_addr = %0x\n",&A);
    printf("B_global_init_addr = %0x\n",&B);
    printf("C_global_static_addr = %0x\n",&C);
    printf("D_global_static_init_addr = %0x\n",&D);
    printf("E_global_const_addr = %0x\n",&E);

    printf("\n");

    printf("a_addr = %0x\n",&a);
    printf("b_init_addr = %0x\n",&b);
    printf("c_static_addr = %0x\n",&c);
    printf("d_static_initaddr = %0x\n",&d);
    printf("e_const_addr = %0x\n",&e);

    printf("m_addr = %p\n",m_addr);

    while(1);

    return 0;
}

//cat /proc/2053/maps 