#include <stdio.h>
#include <stdlib.h>

int A;              //ȫ��δ��ʼ������
int B = 2;          //ȫ�ֳ�ʼ������
int static C;       //ȫ�־�̬δ��ʼ������
int static D = 4;   //ȫ�־�̬��ʼ������
int const E = 5;    //ȫ�ֳ���

int main()
{
    int *m_addr;

    int a;           //�ֲ�δ��ʼ������
    int b = 2;       //�ֲ���ʼ������
    int static c;    //�ֲ���̬δ��ʼ������
    int static d = 4;//�ֲ���̬��ʼ������
    int const e =5;  //�ֲ�����

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