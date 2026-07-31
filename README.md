# dsa-prep

Personal collection of LeetCode / Codeforces solutions and algorithm notes,
built while preparing for placements.

## Structure

```
dsa-prep/
├── important questions/
│   ├── solved questions/       # straightforward solved problems
│   │   └── "<number>. <Problem Name>.cpp"
│   └── optimized solutions/    # problems needing deeper conceptual notes
│       └── "<number>. <Problem Name>/"      # one subfolder per problem
│           ├── "<number>. <Problem Name>.md"    # doubts/explanations, e.g.
│           │                                    # tricky recurrence walkthroughs
│           └── "<number>. <Problem Name>.cpp"
│
├── important algorithms/      # One folder per core algorithm/technique
│   └── "<Algorithm Name>/"
│       ├── "<Algorithm Name>.md"   # simple explanation, standard code,
│       │                          # time/space analysis
│       └── "<number>. <Problem Name>.cpp"  # standard LeetCode problem
│                                            # implementing that algorithm
│
├── tricky questions/           # problems with a specific conceptual doubt
│   └── "<number>. <Problem Name>/"      # one subfolder per problem
│       ├── "<number>. <Problem Name>.md"    # explains the sticking point
│       │                                    # in easy, short terms
│       └── "<number>. <Problem Name>.cpp"   # standard accepted code
│
└── README.md                  # this file
```

## File conventions

### `important questions/*.cpp`
Each file is named `<problem number>. <Problem Name>.cpp` and follows this
template:

```
/*
<Problem Link>

Pattern:
Difficulty:
Time Complexity:
Space Complexity:
*/

// My Code
// Best Code

/*
Differences
Key Learnings
Interview Notes
*/
```

Kept concise — bullet points, not long prose.

### `important questions/optimized solutions/<number>. <Problem Name>/`
Used when there's a specific conceptual doubt about a problem (e.g. a
confusing recurrence). Two files, same base name:
- `.md` — addresses the doubt directly (e.g. a timeline/state walkthrough),
  ends with the standard code block and time/space complexity.
- `.cpp` — the standard implementation, header comment points back to the `.md`.

### `important algorithms/<Algorithm Name>/`
- `<Algorithm Name>.md` — explains what the algorithm does, why it's
  needed, the core idea in simple terms, standard implementation code, and
  time/space complexity.
- `<number>. <Problem Name>.cpp` — a standard LeetCode problem solved using
  that algorithm, with a short header comment linking back to the `.md`.

### `tricky questions/<number>. <Problem Name>/`
For problems where the sticking point is understanding *why* the recursive
state/approach is designed the way it is (not just the code itself). Two
files, same base name:
- `.md` — short, easy-words explanation of the sticking point and how to
  reason about it from scratch, ends with the standard code + complexity.
- `.cpp` — the standard accepted implementation, header comment points
  back to the `.md`.

This structure will be updated as the repo grows.
