#include <stdio.h>
#include <stdlib.h>

/*
* test the address and order in memory
* reference: http://wp.mlab.tw/?p=312
*/
void memory_int()
{
    int first = 1;
    int second = 1;
    int third = 1;
    char fourth[2] = {0};
    char fifth[2] = {0};
    char six;
    char seven;
    char eight;

    FILE* f_output;
    char* output_name = "output_file.txt";
    f_output = fopen(output_name,"w");

    if(0==f_output)
    {
        printf("Open file failed\n");
        return 0;
    }
    else
    {
        printf("Open success\n");
    }
    fprintf(f_output,"size of int = %d bytes\n", sizeof(first));
    fprintf(f_output,"memory address = 0x%p\n", &first);

    fprintf(f_output,"size of int = %d bytes\n", sizeof(second));
    fprintf(f_output,"memory address = 0x%p\n", &second);

    fprintf(f_output,"size of int = %d bytes\n", sizeof(third));
    fprintf(f_output,"memory address = 0x%p\n", &third);

    fprintf(f_output,"size of char[2] = %d bytes\n", sizeof(fourth));
    fprintf(f_output,"memory address = 0x%p\n", &fourth);

    fprintf(f_output,"size of char[2] = %d bytes\n", sizeof(fifth));
    fprintf(f_output,"memory address = 0x%p\n", &fifth);

    fprintf(f_output,"size of char = %d bytes\n", sizeof(six));
    fprintf(f_output,"memory address = 0x%p\n", &six);

    fprintf(f_output,"size of char = %d bytes\n", sizeof(seven));
    fprintf(f_output,"memory address = 0x%p\n", &seven);

    fprintf(f_output,"size of char = %d bytes\n", sizeof(eight));
    fprintf(f_output,"memory address = 0x%p\n", &eight);

    fclose(f_output);


    printf("size of int = %d bytes\n", sizeof(first));
    printf("memory address = 0x%p\n", &first);

    printf("size of int = %d bytes\n", sizeof(second));
    printf("memory address = 0x%p\n", &second);

    printf("size of int = %d bytes\n", sizeof(third));
    printf("memory address = 0x%p\n", &third);

    printf("size of char[2] = %d bytes\n", sizeof(fourth));
    printf("memory address = 0x%p\n", &fourth);

    printf("size of char[2] = %d bytes\n", sizeof(fifth));
    printf("memory address = 0x%p\n", &fifth);
}


int main()
{
    memory_int();


    return 0;
}
