# dsa-prep

Personal collection of LeetCode / Codeforces solutions and algorithm notes,
built while preparing for placements.

## Structure

```
dsa-prep/
├── important questions/       # Solved problems, one file per problem
│   └── "<number>. <Problem Name>.cpp"
│
├── important algorithms/      # One folder per core algorithm/technique
│   └── "<Algorithm Name>/"
│       ├── "<Algorithm Name>.md"   # simple explanation, standard code,
│       │                          # time/space analysis
│       └── "<number>. <Problem Name>.cpp"  # standard LeetCode problem
│                                            # implementing that algorithm
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

### `important algorithms/<Algorithm Name>/`
- `<Algorithm Name>.md` — explains what the algorithm does, why it's
  needed, the core idea in simple terms, standard implementation code, and
  time/space complexity.
- `<number>. <Problem Name>.cpp` — a standard LeetCode problem solved using
  that algorithm, with a short header comment linking back to the `.md`.

This structure will be updated as the repo grows.
