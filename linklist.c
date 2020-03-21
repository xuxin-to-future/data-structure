#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}lnode;

typedef struct LinkList{
    int length;
    lnode head;
}linklist;

lnode *init_node(int val){
    lnode *p = (lnode *)malloc(sizeof(lnode));
    p->data = val;
    p->next = NULL;
    return p;
}

linklist *init_lst(){
    linklist *lst = (linklist *)malloc(sizeof(linklist));
    lst->head.next = NULL;
    lst->length = 0;
    return lst;
}

bool insert(linklist *lst, int loc, int val){
    if(lst == NULL) return false;
    if(loc < 0 || loc > lst->length) return false;
    lnode *p = &(lst->head), *node = init_node(val);
    while(loc--) p = p->next;
    node->next = p->next;
    p->next = node;
    lst->length++;
    return true;
}

bool delete_node(linklist *lst, int loc){
    if(lst == NULL) return false;
    if(loc < 0 || loc >= lst->length) return false;
    lnode *p = &(lst->head), *q;
    while(loc--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    lst->length--;
    return true;
}

void output(linklist *lst){
    for(lnode *p = lst->head.next; p; p = p->next){
        printf("%d ", p->data);
    }
    printf("\n");
}

bool clear_node(lnode *node){
    if(node == NULL) return false;
    free(node);
    return true;
}

bool clear_lst(linklist *lst){
    if(lst == NULL) return false;
    lnode *p = lst->head.next, *q;
    while(p){
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(lst);
    return true;
}

int main(){
    return 0;
} 