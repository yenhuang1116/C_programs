#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int s_value = 0;

void* add_thread()
{
    sleep(2);
    s_value+=1;
}
int main(){

    int y=0;
    pthread_t t1;
    pthread_create(&t1, NULL, add_thread, NULL);


    if(s_value==0)
    {
	printf("[o] s_value is 0, and is going to calculate y = s_value*100\n");
	sleep(5);        
	y = s_value*100;
    }

    pthread_join(t1, NULL);

    printf("[o] final s_value=%d\n", s_value);
    printf("[o] final of y = %d\n", y);
    return 0;
}
