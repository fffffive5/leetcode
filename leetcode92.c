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
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* list1=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* pre=list1;
    struct ListNode* list2=NULL;
    struct ListNode* next_ptr=NULL;
    int flag=0; int index=1;
    while (head != NULL)
    {
        next_ptr=head->next;
        if (index == left){
            flag=1;
        }
        if (1 == flag){
            head->next=list2;
            list2=head;
        }else{
            list1->next=head;
            list1=list1->next;
        }
        if (index == right)
        {
            flag =0;
            list1->next=list2;
            while (list1->next!=NULL){
                list1=list1->next;
            }
        }
        head=next_ptr;
        index++;
    }
    return pre->next;
}
int main(){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int left = 1;
    int right = 4;

    head = reverseBetween(head, left, right);

    struct ListNode *current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}