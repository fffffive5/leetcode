#include<stdio.h>
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

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode * dummy=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * latter=NULL;
    dummy->next=head;
    struct ListNode *index=dummy;
    while(index->next!=NULL){
        latter=index->next;
        if (latter->val==val){
            index->next=latter->next;
            free(latter);
        }else{
            index=index->next;
        }
    }
    return dummy->next;
}
int main (){
    //head = [1,2,6,3,4,5,6], val = 6
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 6;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 4;
    head->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 5;
    head->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next->next = NULL;

    int val = 6;
    head = removeElements(head, val);
    //print
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    return 0;
}