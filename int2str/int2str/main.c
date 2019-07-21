#include <stdio.h>
#include <stdlib.h>


char* int2str(const int input);
void _main();

int main()
{
    _main();
    return 0;
}

void _main()
{
    char* ret = int2str(226);
    printf("result = %s",ret);
}
char* int2str(const int input)
{
    char ret[20];
    sprintf(ret, "%d", input);
    return ret;
}
