#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义顺序表结构体，数据域，长度，表结构大小
typedef struct{
    int *data;
    int lenth, size;
}sqlist;

//初始化顺序表（开辟内存）
sqlist *init(int max_size){
    sqlist *lst = (sqlist *)malloc(sizeof(sqlist));
    lst->data = (int *)malloc(sizeof(int) * max_size);
    lst->lenth = 0;
    lst->size = max_size;
    printf("%d\n", lst);
}

//判断顺序表是否为空
bool is_empty(sqlist *lst){
    return lst == NULL;
}

//输出顺序表
void output(sqlist *lst){
    if(is_empty(lst)) return;
    for(int i = 0; i < lst->lenth; i++){
        printf("%d ", lst->data[i]);
    }
    printf("\n");
}

//返回顺序表中指定元素，时间复杂度为O(1)
bool get_elem(sqlist *lst, int i, int *e){
    if(i < 1 || i >= lst->lenth) return false;
    *e = lst->data[i];
    return true;
}

//返回元素的索引
int locate_elem(sqlist *lst, int e){
    int i = 0;
    while(i < lst->lenth && lst->data[i] != e){
        i++;
    }
    if(i >= lst->lenth) return -1;
    else return i;
}

//顺序表的插入
bool list_insert(sqlist *lst, int i, int e){
    if(is_empty(lst)) return false;
    if(i < 0 || i > lst->lenth) return false;
    for(int j = lst->lenth; j > i; j--){
        lst->data[j] = lst->data[j - 1];
    }
    lst->data[i] = e;
    lst->lenth++;
    return true;
}

//顺序表删除对应索引的元素
bool list_delete(sqlist *lst, int i){
    if(is_empty(lst)) return false;
    if(i < 0 || i >= lst->lenth) return false;
    for(int j = i + 1; j < lst->lenth; j++){
        lst->data[j - 1] = lst->data[j];
    }
    lst->lenth--;
    return true;
}

//清空顺序表，释放内存
void clear_list(sqlist *lst){
    if(is_empty(lst)) return;
    free(lst->data);
    free(lst);
}

int main(){
    return 0;
}