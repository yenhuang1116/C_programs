#include <stdio.h>
#include <stdlib.h>

typedef union
{
    int int_4byte;
    char char_1byte[4];

}union_memory_test;

void main_memory_test();
void main_reverse_bits();
void main_reverse_bits_m2();

int main()
{
#if 0
    main_memory_test();
#elif 0
    main_reverse_bits();
#endif // 0
    main_reverse_bits_m2();
    return 0;
}
void main_memory_test()
{
    union_memory_test umt;
    umt.int_4byte = 0x12345678;
    printf("input:0x%p\n",umt.int_4byte);
    int i;
    for(i=0;i<4;i++)
    {
        printf("%p : %X\n",&umt.char_1byte[i],umt.char_1byte[i]);
    }
}
void main_reverse_bits()
{
    int a = 0x12345678;

    int ret = 0;
    int reg = 0;
    int mask = 0x000000FF;

    reg = a&0x000000FF;
    ret += reg<<24;
    reg = a&0x0000FF00;
    ret += reg<<8;
    reg = a&0x00FF0000;
    ret += reg>>8;
    reg = a&0xFF000000;
    ret += reg>>24;

    printf("result = 0x%p",ret);
}
void main_reverse_bits_m2()
{
    int a = 0x12345678;
    char *b;
    char temp;

    b = (char*)(&a);

    printf("original:");
    printf("%p\n",a);
    printf("%p\n",b[0]);
    printf("%p\n",b[1]);
    printf("%p\n",b[2]);
    printf("%p\n",b[3]);

    int i;
    for(i=0;i<2;i++)
    {
        temp = b[i];
        b[i] = b[3-i];
        b[3-i] = temp;
    }

    printf("reverse:");
    printf("%p\n",a);
    printf("%p\n",b[0]);
    printf("%p\n",b[1]);
    printf("%p\n",b[2]);
    printf("%p\n",b[3]);
}
