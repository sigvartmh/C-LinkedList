#include<stdlib.h>
#include<stdio.h>

void allocate(int value) {
     int *ptr = NULL;
     ptr = malloc(100000 * sizeof(int));
     if(ptr == NULL){
         perror("An nondescriptive error occured");
         exit(1);
     }
     *ptr = value;
    printf("test of allocated memory: %i\n");
}

int main(){
    while(1){
        allocate(10);
    }
}
