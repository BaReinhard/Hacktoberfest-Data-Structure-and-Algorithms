#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void * print_number(void* argument) {
    int* number = (int *) argument;
    sleep(*number);
    printf("%d \n", *number);
}

int main(){
    int numbers[10] = {4, 5, 6, 7, 23, 34, 5, 3, 10, 15};
    int i;
    int length = sizeof(numbers)/sizeof(numbers[0]);
    pthread_t thread[length];
    for (i = 0 ; i < length ; i ++ ) {
        if (pthread_create(&thread[i], NULL, &print_number, (void *) (numbers + i)) < 0) {
            perror("pthread_create");
            exit(1);
        }
    }
    for (i = 0 ; i < length ; i ++ ) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}
