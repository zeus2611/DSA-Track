/*
Idea
    - Find the longest subarray with atmost k zeroes
    - For each A[j], try to find the longest subarray
    - if A[i] to A[j] has zeroes <= K, we continue to increase j
    - if A[i] to A[j] has zeroes > K, we increase i as well as j

Pseudo Code
-------------
int zerocnt = 0, i = 0, ans = 0;
for(int j = 0; j< A.size(); j++){
    if(A[j] == 0)
        zerocnt++;
    while(zerocnt > K){
        if(A[i] == 0)
            zerocnt--;
        i++;
    }
    ans = max(ans, j-i+1);
}
-------------
*/