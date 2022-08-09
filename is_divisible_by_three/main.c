#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

// Write your prototypes here
int intPow(int, int);
int divisibleByThree(struct digit *start);
struct digit *readNumber(void);
struct digit *createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

// Write your divisibleByThree() function here

int divisibleByThree(struct digit *start){
    int i = 0, num = 0;
    struct digit *ptr = start;
    while(ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    
    ptr = start;
    while (i > 0){
        num += (ptr->num) * intPow(i,10);
        --i;
        ptr = ptr->next;
    }
    
    if((num%3) == 0){
        return 1;
    } else {
        return 0;
    }
}

int intPow(int pwr, int base){
    int num=base, i;
    
    if (pwr == 0){
        return 1;
    } else {
        for (i = 1; i < pwr; i++){
        num *= base;
    }
    return num;
    }
    
}