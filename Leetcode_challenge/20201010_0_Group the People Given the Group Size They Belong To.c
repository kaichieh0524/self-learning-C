// Group the People Given the Group Size They Belong To (medium)
// Runtime: 24 ms, faster than 100.00% of C online submissions for Group the People Given the Group Size They Belong To.
// Memory Usage: 11.6 MB, less than 6.67% of C online submissions for Group the People Given the Group Size They Belong To.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    int** temp = calloc(501,sizeof(int*));
    int* index = calloc(501,sizeof(int));
    *returnSize = 0;
    int n = 0;
    for (int i = 0; i < groupSizesSize; i++){
        if (temp[groupSizes[i]] == NULL){
            temp[groupSizes[i]] = malloc(sizeof(int)*501);            
        }
        temp[groupSizes[i]][index[groupSizes[i]]++] = i;

    }
   
    for (int i = 0; i < 501; i++){
        if (index[i] == 0){
           continue;
        }
        (*returnSize) += index[i]/i;
    }
    *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
    int** ans = malloc(sizeof(int*)*(*returnSize));


   for (int i = 0; i < 501; i++){
       if (index[i] == 0){continue;}
       printf("%d",i);
       for (int j = 0; j < index[i]/i; j++){
           ans[n] = malloc(sizeof(int)*i);
           returnColumnSizes[0][n] = i;
           memcpy(ans[n],temp[i]+i*j,sizeof(int)*i);
           n++;
       }
   }    


    return ans;
}