#include <stdio.h>
#include <stdlib.h>
int i1 = 10; //��̬ȫ����(data��)
int i2; //��̬ȫ����(bss��)
static int i3 = 30; //��̬ȫ����(data��)
const int i4 = 40;  //������!!!
void fun(int i5) //ջ��
{
    int i6 = 60; //ջ��
    static int i7 = 70; //��̬ȫ����(data��)
    const int i8 = 80; //ջ��!!!
    char* str1 = "ABCDE"; //������(�ַ�������)
    char str2[] = "ABCDE"; //ջ��(�ַ�����)
    int* pi = malloc(sizeof(int)); //����
    printf("&i5=%p\n", &i5);
    printf("&i6=%p\n", &i6);
    printf("&i7=%p\n", &i7);
    printf("&i8=%p\n", &i8);
    printf("str1=%p\n", str1);
    printf("str2=%p\n", str2);
    printf("pi=%p\n", pi);
    free(pi);
}

int main(void)
{
    printf("&i1=%p\n", &i1);
    printf("&i2=%p\n", &i2);
    printf("&i3=%p\n", &i3);
    printf("&i4=%p\n", &i4);
    fun(50);
    return 0;
}