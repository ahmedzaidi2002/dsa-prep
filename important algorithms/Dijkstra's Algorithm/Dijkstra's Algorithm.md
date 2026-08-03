# Dijkstra's Algorithm

## What problem does it solve?
Given a weighted graph (all weights non-negative) and a source node, find
the **shortest distance from the source to every other node**.

## Why do we need it?
BFS finds shortest paths only when every edge has the same "cost" (1 hop
= 1 unit). Once edges have different weights, BFS breaks — the path with
fewer edges isn't necessarily the cheapest one. Dijkstra fixes this by
always expanding the node that is currently **closest** to the source,
so by the time you finalize a node's distance, you know it can never be
beaten by a cheaper path found later.

## Core idea (simple terms)
Think of it like water spreading outward from the source, but it always
spreads to the *nearest unvisited* point first, never randomly.

1. Set distance to source = 0, distance to everything else = infinity.
2. Repeatedly pick the unvisited node with the **smallest known
   distance** (a min-heap/priority queue makes this fast).
3. For that node, look at all its neighbours: if going through the
   current node gives a shorter path to a neighbour than what's already
   recorded, update (relax) that neighbour's distance.
4. Mark the current node as done, move to the next-smallest.
5. Stop when all nodes are processed (or the priority queue is empty).

**Why does picking the smallest each time work?** Since all weights are
non-negative, once you pop a node with the smallest distance, no future
path can ever reach it cheaper (any other path would have to go through
a node that's already >= the current smallest, so adding more non-negative
weight can't make it smaller). That's why greedily finalizing the minimum
each step is safe.

## Dry Run

Graph (directed, weighted):
```
1 -> 2  (weight 4)
1 -> 3  (weight 1)
3 -> 2  (weight 2)
2 -> 4  (weight 1)
3 -> 4  (weight 5)
```
Source = 1. dist[] starts as `{1:0, 2:inf, 3:inf, 4:inf}`.

**Step 1:** Pop node 1 (dist 0).
- Relax edge 1->2: dist[2] = min(inf, 0+4) = 4
- Relax edge 1->3: dist[3] = min(inf, 0+1) = 1
- dist = `{1:0, 2:4, 3:1, 4:inf}`, queue = `[(4,2), (1,3)]`

**Step 2:** Pop smallest = node 3 (dist 1).
- Relax edge 3->2: dist[2] = min(4, 1+2) = 3  (found a cheaper path to 2!)
- Relax edge 3->4: dist[4] = min(inf, 1+5) = 6
- dist = `{1:0, 2:3, 3:1, 4:6}`, queue = `[(3,2), (4,2)_stale, (6,4)]`

**Step 3:** Pop smallest = node 2 (dist 3). (The stale `(4,2)` entry will
be popped later and skipped since 4 > dist[2]=3.)
- Relax edge 2->4: dist[4] = min(6, 3+1) = 4  (found a cheaper path to 4!)
- dist = `{1:0, 2:3, 3:1, 4:4}`

**Step 4:** Pop node 4 (dist 4). No outgoing edges. Done.
Later, the stale `(4,2)` and `(6,4)` entries get popped but skipped
because they no longer match the recorded shortest distance.

**Final shortest distances from 1:** `{1:0, 2:3, 3:1, 4:4}`.

Note how node 2's distance changed from 4 -> 3 once a cheaper path via
node 3 was discovered — that's the "relaxation" step in action, and why
we don't finalize a node's distance the instant we first hear about it,
only when we actually pop it as the current minimum.

## Standard Code (adjacency list + min-heap)

```cpp
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // stale entry, skip

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

## Time & Space Complexity

**Time:** O((V + E) log V) — each edge can push into the heap, and each
heap push/pop costs O(log V).

**Space:** O(V + E) — adjacency list plus the distance array and heap.

## When to use it
- Shortest path from a single source, non-negative weights only.
- If weights can be negative, use Bellman-Ford instead (Dijkstra's greedy
  assumption breaks with negative edges).
