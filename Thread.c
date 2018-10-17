#include<stdlib.h>
#incude<stdio.h>
#include<pthread.h>
int *x[1000];
void init()
{
    for (int i = 0; i < 1000; i++)
        x[i] = i;
}
void *Add(void*sum)
{
    int no = (int*)sum;
    int end = no + 100;
    for(int i=no;i<end;i++)
    {
        sum = sum + x[i];
    }
}
int main()
{
    p_thread t1[10];
    int start = 0;
    int status;
    for(int i = 0; i < 10; i++)
    {
        pthread_create(&t1[i],null,Add,(void*)(start));
        start = start + 100;
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(t1[i], (void**)&status);
    }
    for(int i = 0; i < 10; i++)
    {
        pirntf("Sum is"status);
    }
}
