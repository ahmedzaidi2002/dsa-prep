/*
https://leetcode.com/problems/koko-eating-bananas/

Pattern:
    Binary Search on Answer

Difficulty:
    Medium

Time Complexity:
    O(n log(maxPile))

Space Complexity:
    O(1)
*/

// ----------------------------------------
// My Code
// ----------------------------------------

class Solution {
public:

    bool solve(long long curr, vector<int>& piles, int h){
        long long temp = 0;
        for(int i=0;i<piles.size();i++){
            long long mo = piles[i]%curr;
            if(mo) temp++;
            temp+=(piles[i]/curr);
        }
        return h>=temp;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1;
        long long end = accumulate(piles.begin(), piles.end(), 0ll);
        long long ans = end;
        while(start<=end){
            long long mid = (end-start)/2+start;
            if(solve(mid,piles,h)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};

// ----------------------------------------
// Best Code
// ----------------------------------------

class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int speed) {
        long long hours = 0;

        for (int pile : piles)
            hours += (pile + speed - 1) / speed;

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

/*
----------------------------------------
Differences
----------------------------------------
1. Search range: my code uses end = sum(piles) as the upper bound.
   Best code uses high = max(piles) - eating at a speed equal to the
   largest pile always finishes every pile within 1 hour each, so the
   answer can never exceed the max pile size. Tighter bound = fewer
   iterations, and avoids needing long long for low/high.
2. Hours per pile: my code computes it in two steps (division + modulo
   check). Best code uses the single ceiling-division formula
   (pile + speed - 1) / speed - same result, less code.
3. Loop style: my code uses start<=end with a separate `ans` variable
   updated on success. Best code uses the standard low<high convergence,
   where `low` itself ends up being the answer - no extra variable needed.
4. Types: my code makes start/end/mid long long since it computes a sum
   upfront. Best code keeps low/high as int (bounded by max pile, fits in
   int) and only widens to long long for the accumulated `hours` count,
   which is the only value that can actually overflow int.

----------------------------------------
Key Learnings
----------------------------------------
- In "binary search on answer" problems, look for the tightest valid
  upper bound, not just any safe bound - it simplifies types and speeds
  up convergence.
- Ceiling division `(a + b - 1) / b` replaces separate div+mod logic.
- Prefer the low<high convergence form over tracking a separate `ans`
  variable when the loop invariant guarantees low lands on the answer.

----------------------------------------
Interview Notes
----------------------------------------
General "binary search on answer" pattern:
    - Define a monotonic predicate canFinish(speed): true for all speeds
      >= some threshold, false below it.
    - Binary search over the speed value itself (not the array), using
      canFinish() as the check function.
    - Search space bound should be the tightest correct bound you can
      justify (here: 1 to max(piles)).
Applies to: Capacity To Ship Packages Within D Days, Split Array Largest
Sum, Minimum Number of Days to Make m Bouquets.
*/
