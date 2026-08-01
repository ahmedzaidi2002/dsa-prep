/*
https://leetcode.com/problems/top-k-frequent-elements/

Algorithm:
    Bucket Sort (see Bucket Sort.md in this folder)

Difficulty:
    Medium

Time Complexity:
    O(n)

Space Complexity:
    O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // bucket index = frequency (max possible frequency is n)
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, f] : freq) buckets[f].push_back(num);

        vector<int> ans;
        for (int f = n; f >= 0 && (int)ans.size() < k; f--) {
            for (int num : buckets[f]) {
                ans.push_back(num);
                if ((int)ans.size() == k) break;
            }
        }

        return ans;
    }
};
