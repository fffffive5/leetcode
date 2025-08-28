//hash表，支持插入整数，查找，删除
#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

typedef struct Node{
    int value;
    int key;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];
int hashfunc(int key){
    //hashfunc
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key % TABLE_SIZE;
}
int hash_insert(int key,int value ){
    int hash_index=hashfunc(key);
    Node* new_node=(Node *)malloc(sizeof(Node));
    new_node->key=key;
    new_node->value=value;
    new_node->next=hash_table[hash_index];
    hash_table[hash_index]=new_node;
    return 0;
}
int hash_find(int key){
    int hash_index=hashfunc(key);
    Node *cur=hash_table[hash_index];
    while (cur != NULL){
        if (cur->key == key){
            return 1;
        }
        cur=cur->next;
    }
    return 0;
}
 void printhash(){
    for (int i=0;i<TABLE_SIZE;i++){
        Node *cur=hash_table[i];
        printf("hash_table[%d]: ",i);
        while (cur != NULL){
            printf("(%d,%d) -> ",cur->key,cur->value);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}
int main(){
    for (int i=0;i<=200;i=i+8){
        hash_insert(i,i);
    }
    printf("find 8==%d\n",hash_find(8));
    printf("find 2==%d\n",hash_find(2));
    printf("find 200==%d\n",hash_find(200));
    printhash();
}