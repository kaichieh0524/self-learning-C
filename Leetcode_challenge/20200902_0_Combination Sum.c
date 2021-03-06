// Combination Sum (medium)
// Runtime: 8 ms, faster than 96.72% of C online submissions for Combination Sum.
// Memory Usage: 11.8 MB, less than 44.26% of C online submissions for Combination Sum.


void subroutine(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* temp, int step, int start,int** ans){
    if (target == 0){
        ans[*returnSize] = malloc(sizeof(int)*step);
        for (int i = 0; i < step; i++){
            ans[*returnSize][i] = temp[i];
        }
        returnColumnSizes[0][(*returnSize)++] = step;
        return;
        
    }
    if (start >= candidatesSize ||  target < 0){return;}    
   
    temp[step] = candidates[start];
    if (target - candidates[start] >= 0){
        
        subroutine(candidates, candidatesSize, target - candidates[start], returnSize, returnColumnSizes, temp, step + 1, start, ans);        
    }    
    subroutine(candidates, candidatesSize, target , returnSize, returnColumnSizes, temp, step, start + 1, ans);
    if (target - candidates[start] < 0){return;}
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int* temp = malloc(sizeof(int)*50);
    *returnSize = 0;
    returnColumnSizes[0] = malloc(sizeof(int)*256);
    int** ans = malloc(sizeof(int*)*256);
    subroutine(candidates, candidatesSize, target, returnSize, returnColumnSizes, temp, 0, 0, ans);
    return ans;
}