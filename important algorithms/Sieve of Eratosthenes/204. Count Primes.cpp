/*
https://leetcode.com/problems/count-primes/

Algorithm:
    Sieve of Eratosthenes (see Sieve of Eratosthenes.md in this folder)

Difficulty:
    Medium

Time Complexity:
    O(n log log n)

Space Complexity:
    O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> isComposite(n, false);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (!isComposite[i]) {
                count++;
                for (long j = (long)i * i; j < n; j += i) {
                    isComposite[j] = true;
                }
            }
        }

        return count;
    }
};
