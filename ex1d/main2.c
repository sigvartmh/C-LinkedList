#include<unistd.h>
#include<pthread.h>
#include<sys/times.h>
#include<stdio.h>

void busy_wait_delay(int seconds){
    int i, dummy;
    int tps = sysconf(_SC_CLK_TCK);
    clock_t start;

    struct tms exec_time;
    times(&exec_time);
    start = exec_time.tms_utime;

    while( (exec_time.tms_utime - start) < (seconds * tps)){
        for(i=0; i<1000; i++){
            dummy=i;
        }
        times(&exec_time);
    }
}

void *print(void *time);

int main(){
    int time = 5;
    int time2 = 6;
    pthread_t thread0;
    pthread_t thread1;
    pthread_create(&thread0, NULL, print, &time);
    pthread_create(&thread1, NULL, print, &time2);
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    return 0;
}

void *print(void *time){
    int *id = (int *) time;
    printf("Hello TTK4175:%d\r\n", *id);
    busy_wait_delay(5);
    printf("Hello TTK4175:%d\r\n", *id);
}
