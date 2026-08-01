# Bucket Sort

## What problem does it solve?
Sorting numbers normally costs O(n log n) (comparison-based sorts). Bucket
sort can sort in **O(n)** when you know something extra about the values —
usually that they fall into a small, known range (like array indices,
frequencies, or scores 0-100).

## Why do we need it?
Comparison sorts (merge sort, quicksort) can't beat O(n log n) in general
because they only ever ask "is A bigger than B?". Bucket sort skips
comparisons entirely — it places each value directly into a "slot" based on
its own value, so sorting becomes just reading the slots in order.

## Core idea (simple terms)
Imagine you have `n` items and you know their values only range from `0` to
`n` (or any small known range). Create one bucket for every possible value.
Drop each item straight into its bucket. When you're done, just walk the
buckets in order — everything is already sorted, because bucket index
*is* the value (or maps directly to it).

No comparisons needed — the position you place something in already
encodes its order relative to everything else.

**When does this work?** Only when the range of possible values is known
and reasonably small (ideally O(n)). If values could be anything from
`-infinity` to `+infinity`, you'd need infinite buckets — doesn't work.
That's why bucket sort is a "counting trick", not a general-purpose sort.

## Standard Code (sorting values known to be in range [0, maxVal])

```cpp
vector<int> bucketSort(vector<int>& arr, int maxVal) {
    vector<vector<int>> buckets(maxVal + 1);

    for (int x : arr) buckets[x].push_back(x);

    vector<int> sorted;
    for (auto& bucket : buckets)
        for (int x : bucket)
            sorted.push_back(x);

    return sorted;
}
```

## Time & Space Complexity

**Time:** O(n + k), where n = number of items, k = number of buckets
(range of values). If k = O(n), this is O(n) overall.

**Space:** O(n + k) — one bucket per possible value, plus storing all items.

## When to use it
- You know values fall into a small, fixed range.
- You want to avoid the O(n log n) floor of comparison sorts.
- Classic use case: **counting/ranking by frequency** — since frequency of
  an item in an array of size n can never exceed n, "frequency" itself is a
  perfect small range to bucket on (see Top K Frequent Elements below).

## Applying it: Top K Frequent Elements (LeetCode 347)

A max-heap solution sorts by frequency in O(n log k). Bucket sort makes it
O(n) instead:

1. Count how often each number appears (a hash map).
2. A number's frequency can never exceed `n` (array size). So create
   `n + 1` buckets, indexed `0` to `n`, where **bucket index = frequency**.
3. For each number, drop it into `buckets[frequency]`.
4. Walk the buckets from index `n` down to `0` (highest frequency first),
   collecting numbers until you have `k` of them.

No sorting comparisons at all — the bucket index already tells you exactly
where a number ranks by frequency.
