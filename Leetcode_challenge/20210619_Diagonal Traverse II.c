//Diagonal Traverse II (mediun)
// Runtime: 380 ms, faster than 66.67% of C online submissions for Diagonal Traverse II.
// Memory Usage: 80.6 MB, less than 9.52% of C online submissions for Diagonal Traverse II.

#include<stdlib.h>
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
   int key;	
   struct node *next;
   struct node *prev;
};
typedef struct node node;

struct doublelinklist{
    node* head;
    node* last;
    int size;
};


typedef struct doublelinklist dLL;

bool isEmpty(node* head) {
   return head == NULL;
}

void insertLast(int key, dLL* dll) {

    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->next = NULL;
    link->prev = NULL;
	
   if(isEmpty(dll -> head)) {
      dll -> head = link;
      dll -> last = link;
       (dll -> size)++;
   } else {
      (dll -> last) -> next = link;     
      link -> prev = dll -> last;
      (dll -> size)++;
   }
   dll -> last = link;
}



void Backward(node* last, int* ans, int* index) {
   struct node *ptr = last;
   while(ptr != NULL) {
        ans[(*index)++] = ptr -> key;
        ptr = ptr ->prev;
      
   }
	
}

int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int max_col = 0;
    *returnSize = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        max_col = max_col < numsColSize[i] ? numsColSize[i] : max_col;
    }
    
    dLL** DLL = calloc((numsSize + max_col), sizeof(dLL*));
    for (int i = 0; i < numsSize + max_col; i++) {
        DLL[i] = malloc(sizeof(dLL));
        DLL[i]->head = NULL;
        DLL[i]->last = NULL;
        DLL[i]->size = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            insertLast(nums[i][j], DLL[i + j]);
        }
    }
    for (int i = 0; i < numsSize + max_col; i++) {
        *returnSize += DLL[i]->size;
    }

     int* ans = malloc(sizeof(int)*(*returnSize));
     for(int i = 0; i < numsSize + max_col; i++){
        Backward(DLL[i] -> last, ans, &index);
     } 
     // for (int i = 0; i < *returnSize; i++) {
     //     printf(" %d ", ans[i]);
     // }
    return ans;
}
