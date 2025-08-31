#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *nxt;
    struct ListNode *pre=NULL;
    struct ListNode *p0 = dummy;
    struct ListNode *cur = head;
    struct ListNode *tempp0;
    int number = 0;
    while (cur != NULL){
        number++;
        cur=cur->next;
    }
    cur = p0->next;
    while (number >= k)
    {
       number=number-k;
        int temp=k;
        while (temp > 0)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            temp--;
        }
        tempp0=p0->next;
        p0->next->next = cur;
        p0->next = pre;

        p0=tempp0;
    }
    return dummy->next;
}
int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = NULL;


    int k = 2;
    head = reverseKGroup(head, k);

    // Print the reversed list
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    return 0;
}