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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode First;
    struct ListNode* pre=&First;
    while (list1!=NULL && list2!=NULL)
    {
        if (list1->val <= list2->val){
                pre->next=list1;
                list1=list1->next;
                pre=pre->next;
        } else{
                pre->next=list2;
                list2=list2->next;
                pre=pre->next;
        }
    }
    pre->next=(list1!=NULL)?list1:list2;
    return First.next;
    
}
int main(){
    //leetcode 21
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //list1={1,2,3}
    struct ListNode* node11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node12 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node13 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next = node11; list1->val=1;
    node11->next = NULL; node11->val=2;
    node12->next = NULL; node12->val=4;
    node13->next=NULL;      node13->val=8;
    //list2={3,5,7}
    struct ListNode* node21 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node23 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next = node21; list2->val=1;
  
    node21->next = node22; node21->val=3;
    node22->next = NULL; node22->val=4;
    node23->next=NULL;      node23->val=8;
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    //print mergedList
    struct ListNode* current = mergedList;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
    return 0;
}