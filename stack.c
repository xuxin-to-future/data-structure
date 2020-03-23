#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int max_size, top;
}Stack;

void init(Stack *s, int size){
    s->data = (int *)malloc(sizeof(int) * size);
    s->max_size = size;
    s->top = -1;
}

int push(Stack *s, int val){
    if(s->top >= s->max_size - 1){
        return 0;
    }
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s){
    if(s->top < 0){
        return 0;
    }
    s->top--;
    return 1;
}

int get_top(Stack *s){
    return s->data[s->top];
}

int empty(Stack *s){
    if(s->top < 0){
        return 1;
    }
    return 0;
}

void clear(Stack *s){
    free(s->data);
    free(s);
}

int main(){

    return 0;
}