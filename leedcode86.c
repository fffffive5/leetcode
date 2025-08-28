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
struct ListNode* createList(int arr[], int n);
void printList(struct ListNode* head) ;

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* smallHead = small;
    struct ListNode* large = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = large;
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = NULL;
    small->next = largeHead->next;
    return smallHead->next;
}


    


int main(){
    int arr[] = {1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, n);
    int x = 6;
    struct ListNode* partitioned = partition(head, x);
    printList(partitioned);
    return 0;
}
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
struct ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    struct ListNode* cur = head;
    for (int i = 1; i < n; ++i) {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = arr[i];
    }
    cur->next = NULL;
    return head;
}