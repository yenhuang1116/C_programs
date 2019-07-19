/*
*Author: Bryan Huang
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct {

    int name :16;
    int number :16;

}id;

void _main()
{
    id id_01 ={
        .name=1,
        .number=1
    };

    id id_02 ={2,2};

    printf("name,number=(%d,%d)\n",id_01.name,id_01.number);
    printf("name,number=(%d,%d)\n",id_02.name,id_02.number);
}

int main()
{
    _main();
    return 0;
}
