/*
https://leetcode.com/problems/group-anagrams/

Pattern:
    Hashing (character frequency as key)

Difficulty:
    Medium

Time Complexity:
    O(n*k) average, n = number of strings, k = avg string length

Space Complexity:
    O(n*k)
*/

// ----------------------------------------
// My Code
// ----------------------------------------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<vector<int>, vector<int>> mp;
        for(int i=0;i<n;i++){
            vector<int> curr(26);
            string temp = strs[i];
            for(auto ch:temp) curr[ch-'a']++;
            mp[curr].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> temp;
            for(auto j : it.second){
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// ----------------------------------------
// Best Code
// ----------------------------------------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string temp = strs[i];
            string key(26,'0');
            for(auto ch:temp) key[ch-'a']++;
            mp[key].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
----------------------------------------
Differences
----------------------------------------
1. My code: map<vector<int>, vector<int>> -> red-black tree, O(log n)
   insert, and vector<int> comparison for ordering is itself O(26).
   Best code: unordered_map<string, ...> -> O(1) average insert via
   hashing, string hashing is cheaper than comparing 26-length vectors.
2. My code stores indices and looks up strs[j] afterward.
   Best code stores the strings directly in the map value -> no
   indirection needed when building the answer.
3. Same time complexity O(n*k) either way - the win is purely from
   swapping the map key/value types, not from anything exotic.

----------------------------------------
Key Learnings
----------------------------------------
- unordered_map is preferred over map when order doesn't matter -
  avoids the log n tree overhead.
- A fixed-size frequency array can be encoded directly as a string key
  (26 chars) instead of using vector<int> as a key - strings hash faster
  and avoid heap-allocated vector-of-vector key comparisons.
- Store the actual data (strings) as map values when you'll need them
  anyway, instead of indices requiring a second lookup pass.

----------------------------------------
Interview Notes
----------------------------------------
General "group by signature" pattern:
    signature(item) -> bucket
Any two items with the same signature (frequency count, sorted string,
normalized form, etc.) belong in the same group. Choice of signature
representation (sorted string vs frequency-count string) affects
complexity: sorting costs O(k log k) per string, frequency counting
costs O(k) per string - frequency counting is asymptotically better here.
*/
