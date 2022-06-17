#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        for(; j < n; ){
            if(arr[i] == 0){
                i++;
                j += 2;
            }else{
                i++;j++;
            }
        }

        if(j == n + 1){
            arr[n - 1] = arr[i];
            i--;
            j -= 2;
        }
        while (true)
        {
            /* code */
            i--;
            if(arr[i] == 0){
                arr[j - 2] = arr[j - 1] = 0;
                j -= 2;
            }else{
                arr[j - 1] = arr[i];
                j--;
            }
            if(i >= j) break;
        }
    }
};