#include<unistd.h>
#include<pthread.h>
#include<sys/times.h>
#include<stdio.h>

void busy_wait_delay(int seconds){
    int i, dummy;
    int tps = sysconf(_SC_CLK_TCK);
    clock_t start;

    struct tms exec time;
    times(&exec_time);
    start = exec_time.tms_utime;

    while( (exec_time.tms_utime - start) < (seconds * tps)){
        for(i=0; i<1000; i++){
            dummy=i;
        }
        times(&exec_time);
    }
}

void *print(void *param);

int main(){
    pthread_t thread0;
    pthread_t thread1;
    pthread_create(&thread0, NULL, print, NULL);
    pthread_create(&thread1, NULL, print, NULL);

}

void *print(void *param){
    printf("Hello TTK4175\r\n");
    sleep(5);
}
