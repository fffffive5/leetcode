#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };

#define TABLE_SIZE 10000
typedef struct Node{
    struct ListNode* key;
    int index;
    Node* next;
}Node;
Node *hash_table[TABLE_SIZE];

int hashfunc( struct ListNode* key){
    
    return ((size_t)key)%TABLE_SIZE;
}
void hash_insert(struct ListNode* key,int index){
    int hash_index=hashfunc(key);
    Node * new_node=(Node *)malloc(sizeof(Node));
    new_node->index=index;
    new_node->key=key;
    new_node->next=hash_table[hash_index];
    hash_table[hash_index]=new_node;
}

struct ListNode * hash_find(struct ListNode* key){
    int hash_index=hashfunc(key);
    Node *head=hash_table[hash_index];
    while (head!=NULL)
    {
        if (head->key==key){
            return head->key;
        }
        head=head->next;
    }
    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
    int index=0; struct ListNode * isfind=NULL;
    while (head != NULL){
        isfind=hash_find(head);
        if (isfind!=NULL){
            return isfind;
        } else{
            hash_insert(head,index);
        }
        hash_insert(head,index); 
        index++;
        head=head->next;
    }
    return NULL;
}
int main(){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = head->next; // Create a cycle

    struct ListNode *cycleNode = detectCycle(head);
    if (cycleNode) {
        printf("Cycle detected at node with value: %d\n", cycleNode->val);
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}