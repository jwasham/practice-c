#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Implements a singly linked list and solves addtwonum, quasi-OO style
// Rough example Added:  
// Example:  https://leetcode.com/problems/add-two-numbers/

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *testData1() {

  struct ListNode *node1 = malloc(sizeof(struct ListNode));
  struct ListNode *node2 = malloc(sizeof(struct ListNode));
  struct ListNode *node3 = malloc(sizeof(struct ListNode));
  node3->val = 3;
  node3->next = node2;
  node2->val = 8;
  node2->next = node1;
  node1->val = 7;
  node1->next = NULL;

  return node3;
}

struct ListNode *testData2() {

  struct ListNode *node4 = malloc(sizeof(struct ListNode));
  struct ListNode *node5 = malloc(sizeof(struct ListNode));
  struct ListNode *node6 = malloc(sizeof(struct ListNode));
  struct ListNode *node7 = malloc(sizeof(struct ListNode));

  node4->val = 9;
  node4->next = node5;
  node5->val = 1;
  node5->next = node6;
  node6->val = 9;
  node6->next = node7;
  node7->val = 7;
  node7->next = NULL;

return node4;

}


struct ListNode *add(struct ListNode *list1, struct ListNode *list2 ) {

  int pow10[10] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    int size = 0;
    int num1 = 0;
    while (list1 != 0) {
      num1 = num1 + ( list1->val * pow10[size]) ;
      size++;
      list1 = list1->next;
    }

    int size2 = 0;
    int num2 = 0;
    while (list2 != 0) {
      num2 = num2 + ( list2->val * pow10[size2]) ;
      size2++;
      list2 = list2->next;
    }
    printf("num2:(%d) - (%d) = (%d)\n",num1, num2, (num1 + num2));

    int sum = num1 + num2;

    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;
    for ( int i = 9; i >= 0; i--) {
          int v1 = (int) abs(sum/pow10[i]);
          if (v1 > 0 || (num1 + num2) > sum) {
             sum = sum - (v1 * pow10[i]);
             if (head == NULL) {

              head = malloc(sizeof(struct ListNode));
              head->val = v1;
              head->next = NULL;
              temp = head;
             } else {
               struct ListNode *newNode = malloc(sizeof(struct ListNode));
               newNode->val = v1;
               newNode->next = NULL;
               temp->next = newNode;
               temp = temp->next;
              }
          }
    }
    return head;
}

int main(int argc, char* argv[]) {

    struct ListNode *head = add(testData1(),testData2());

    printf("head:(%d)\n",head->val);
    printf("head:(%d)\n",head->next->val);
    printf("head:(%d)\n",head->next->next->val);
    printf("head:(%d)\n",head->next->next->next->val);
    return EXIT_SUCCESS;
}
