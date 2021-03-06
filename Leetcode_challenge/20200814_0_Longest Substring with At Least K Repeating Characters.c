// Longest Substring with At Least K Repeating Characters (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage: 5.5 MB, less than 48.72% of C online submissions for Longest Substring with At Least K Repeating Characters.


void subroutine(char* s, int k, int first, int last, int* ans) {
    if ( first < 0 || first > last) { return; }
    int* temp = calloc(26, sizeof(int));
    int flag = 0;
    for (int i = first; i < last + 1; i++) {
        temp[s[i] - 'a'] += 1;
    }
    while (first < last && temp[s[first] - 'a'] < k) {
        first++;
    }
    int begin = first, end = 0; ;
    for ( end = first; end <= last; end++) {
        if (temp[s[end] - 'a'] < k) {            
            subroutine(s, k, begin, end - 1, ans);
            begin = end + 1;
            flag = 1;
            break;
        }
    }
    if (flag == 0 ) {
        if (*ans < last - first + 1) {
            *ans = last - first + 1;
        }
        return;
    } 
    subroutine(s, k, begin, last, ans);

}


int longestSubstring(char * s, int k){
    int len = strlen(s);
    int* ans = calloc(1,sizeof(int));
    subroutine(s, k, 0, len-1, ans);
    return *ans;
}
