#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
} Person;

// random comment: this line was added for fun
int add(int a, int b);

int main(void) {
    printf("Hello, world!\n");
    printf("This is a simple C program.\n");

    int *numbers = malloc(20 * sizeof(int));
    if (numbers == NULL) {
        perror("malloc");
        return 1;
    }

    int *freePointer = malloc(5 * sizeof *freePointer);
    if (freePointer == NULL) {
        perror("malloc");
        free(numbers);
        return 1;
    }

    srand((unsigned) time(NULL));
    for (int i = 0; i < 20; i++) {
        numbers[i] = 100 + rand() % 101; // random number from 100 to 200
    }

    for (int i = 0; i < 20; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        freePointer[i] = 100 + rand() % 101; // random number from 100 to 200
        printf("freePointer[%d] = %d\n", i, freePointer[i]);
    }

    Person sue;
    strcpy(sue.name, "Sue");
    sue.age = 20;
    printf("Person: %s, Age: %d\n", sue.name, sue.age);

    free(freePointer); // free the pointer after use
    free(numbers);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
