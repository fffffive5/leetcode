#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

int findindex(struct Node* target_ptr,struct Node*list_head){
    struct Node* head=list_head;
    int index=0;
    while (head!=NULL){
        if (head == target_ptr){
            return index;
        }   
        head=head->next;
        index=index+1;
    }
    return -1;
}
struct Node* findptr(int target_index,struct Node* list2_head){
    struct Node* head=list2_head;
    int index=0;
    while(head!=NULL){
        if (index==target_index){
            return head;
        }
        head=head->next;
        index=index+1;

    }
    return NULL;
}
struct Node* copyRandomList(struct Node* head) {
    struct Node* node=head;
    while (node!=NULL){
        struct Node * new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->val=node->val;
        new_node->next=node->next;
        node->next=new_node;
        node=node->next->next;
    }
    node=head;
    while (node!=NULL){
        if (node->random!=NULL){
        node->next->random=node->random->next;
        }else 
        {
            node->next->random=NULL;
        }
        node=node->next->next;
    }

    node=head;
    struct Node* new_head=head->next;
    struct Node* node_new=NULL;
    while (node!=NULL){
        node_new=node->next;
        node->next=node->next->next;
        if (node->next!=NULL){
        node_new->next=node_new->next->next;
        }else{
           node_new->next=NULL; 
        }

        node=node->next;
        
    }
    return new_head;
    
}
int main(){
    //list  [val,random_index] [[7,null],[13,0],[11,4],[10,2],[1,0]]
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->val = 7;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->val = 13;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->val = 11;
    head->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->val = 10;
    head->next->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->next->val = 1;
    head->next->next->next->next->next = NULL;

    head->random = NULL; // 7's random points to NULL
    head->next->random = head;       // 13's random points to 7
    head->next->next->random = head->next->next->next->next; // 11's random points to 1
    head->next->next->next->random = head->next->next; // 10's random points to 11
    head->next->next->next->next->random = head; // 1's random points to 13


    
    struct Node *copy = copyRandomList(head);
    // Print original and copied list
    struct Node *current = head;
    struct Node *currentCopy = copy;
    //输出复制后链表，以及随机指针指向的值
    while (current && currentCopy) {
        printf("Original: %d, Copy: %d\n", current->val, currentCopy->val);
        if (current->random) {
            printf("Original Random: %d, Copy Random: %d\n", current->random->val, currentCopy->random->val);
        } else {
            printf("Original Random: NULL, Copy Random: NULL\n");
        }
        current = current->next;
        currentCopy = currentCopy->next;
    }

    return 0;
}