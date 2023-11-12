#include <stdio.h>
#include <pthread.h>

int sharedVariable = 0;

void *incrementThread(void *arg) {
    for (int i = 0; i < 1000000; ++i) {
        sharedVariable++;  // Increment the shared variable
    }
    return NULL;
}

void *decrementThread(void *arg) {
    for (int i = 0; i < 1000000; ++i) {
        sharedVariable--;  // Decrement the shared variable
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, incrementThread, NULL);
    pthread_create(&thread2, NULL, decrementThread, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the shared variable
    printf("Final Value of sharedVariable: %d\n", sharedVariable);

    return 0;
}
