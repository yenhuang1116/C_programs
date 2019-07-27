#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int2str(const int* input,const int input_size);
void _main();

int main()
{
    _main();
    return 0;
}

void _main()
{
    int a[2] = {23,25};
    char* ret = int2str(a,2);
    printf("result = %s",ret);
}
char* int2str(const int* input,const int input_size)
{
    char ret[20] = {'\0'};
    strcpy(ret,"2323");
    puts(ret);
    int i;
    for(i=0;i<20;i++)
    {
        if(ret[i]=='\0')puts("NULL");
    }

    //sprintf(ret, "%d%d", input[0], input[1]);
    return ret;
}
