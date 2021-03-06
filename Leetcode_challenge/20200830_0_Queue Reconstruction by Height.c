// Queue Reconstruction by Height (medium)
// Runtime: 44 ms, faster than 93.94% of C online submissions for Queue Reconstruction by Height.
// Memory Usage: 10.4 MB, less than 60.61% of C online submissions for Queue Reconstruction by Height.


typedef struct linklist{
    int* address;
    struct linklist* next;
} linklist;


linklist* createlinklist(int* ele){
    linklist* link_list = malloc(sizeof(linklist));
    link_list -> address = ele;
    link_list -> next = NULL;
    return link_list;
}

void insert(linklist* head, int* ele, int index){
    int count = 0;
    linklist* last;
    while (1) {
        if (index == count) {
            if (head != NULL) {
                int* temp_address = head->address;
                linklist* temp_next = head->next;
                linklist* insertion = createlinklist(temp_address);
                head->address = ele;
                head->next = insertion;
                insertion->next = temp_next;
                break;
            }
            else {
                linklist* insertion = createlinklist(ele);
                last-> next = insertion;
                break;
            }
        }
        if (head->next==NULL){last = head;}
        head = head->next;
        count++;
    }
}

int compare(const void** a, const void** b){
    int* ai = (int*)(*a);
    int* bi = (int*)(*b);
    
    if (ai[0]==bi[0]){
        return ai[1] - bi[1];
    }
    else{
        return bi[0] - ai[0];
    }
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (peopleSize == 0){*returnSize=0; return NULL;}
    int index = 0;
    int** ans = malloc(sizeof(int*)*peopleSize);
    *returnSize = peopleSize;
    returnColumnSizes[0] = malloc(sizeof(int)*peopleSize);
    for (int i = 0; i < peopleSize; i++){
        returnColumnSizes[0][i] = 2;    
    }   
    qsort(people,peopleSize,sizeof(int*),compare);    
    linklist* head = createlinklist(people[0]);    
    for (int i = 1; i < peopleSize; i++) {
        insert(head, people[i], people[i][1]);
    }
     linklist* temp = head;
    while (temp != NULL) {        
        ans[index++] = temp->address;
        temp = temp->next;
    }    
    return ans;
}