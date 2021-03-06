// Flatten Nested List Iterator (medium)
// Runtime: 8 ms, faster than 100% of C online submissions for Flatten Nested List Iterator.
// Memory Usage: 12.2 MB, less than 90.48% of C online submissions for Flatten Nested List Iterator.

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedIterator {
    struct NestedInteger** table;
    int index;
    
};

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    
    struct NestedIterator* nestediterator = malloc(sizeof(struct NestedIterator));
    nestediterator -> table = malloc(sizeof(struct NestedInteger*)*1000);
    nestediterator -> index = nestedListSize - 1;
    
    for (int i = 0; i < nestedListSize; i++){
        nestediterator -> table[i] = nestedList[nestedListSize -1 -i];
    }

    return nestediterator;
    
}

bool nestedIterHasNext(struct NestedIterator *iter) {
 
    if ( iter -> index >= 0){
        while (!NestedIntegerIsInteger(iter -> table[ iter -> index])){
            struct NestedInteger** temp = NestedIntegerGetList(iter -> table[ iter -> index]);
            int size =  NestedIntegerGetListSize(iter -> table[ iter -> index]);
            if (iter -> index == 0 && size == 0){return 0;}
            for (int i = 0; i < size; i++){
                iter -> table[ iter -> index + i] = temp[size -1 -i];
            }
            iter -> index =  iter -> index + size - 1;
        }       
        return 1;
    }   
    return 0;
}

int nestedIterNext(struct NestedIterator *iter) {
    int temp = NestedIntegerGetInteger(iter -> table[ iter -> index]);
    iter -> index -=  1;
    return temp;
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->table);
    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */