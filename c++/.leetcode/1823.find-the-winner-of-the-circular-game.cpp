#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         if (n == 1) {
//             return 1;
//         }
//         return (k + findTheWinner(n - 1, k) - 1) % n + 1;
//     }
// };
int main(){

    Solution solution;
    solution.findTheWinner(6, 5);
    return 0;
}