# Sieve of Eratosthenes

## What problem does it solve?
Given a number `n`, find **all prime numbers from 2 to n** efficiently.
Checking each number one by one for primality (trial division) is slow when
you need *many* primes at once. The sieve finds them all together, fast.

## Why do we need it?
- Checking primality of one number by trial division: O(sqrt(n)).
- Doing that for every number up to n: O(n * sqrt(n)) total — slow.
- Sieve finds all primes up to n in O(n log log n) — much faster when you
  need a range of primes (common in number theory problems, "count primes",
  prime factorization precompute, etc).

## Core idea (simple terms)
Start by assuming every number is prime. Then, starting from the first
prime (2), cross out (mark as not-prime) all of its multiples — because a
multiple of 2 can never be prime. Move to the next number that's still
unmarked (that's the next prime), and cross out all of its multiples too.
Repeat until you've passed sqrt(n).

Think of it like crossing names off a list: once you know 2 is prime, you
know 4, 6, 8, 10... are NOT prime, so cross them all out immediately instead
of checking each individually.

**Key optimization:** when crossing out multiples of `i`, start from `i*i`
instead of `2*i` — because any smaller multiple of `i` (like `2*i`, `3*i`,
... up to `(i-1)*i`) has already been crossed out by a smaller prime factor.

## Standard Code

```cpp
vector<bool> sieve(int n) {
    vector<bool> isComposite(n + 1, false);
    for (int i = 2; (long long)i * i <= n; i++) {
        if (!isComposite[i]) {
            for (int j = i * i; j <= n; j += i) {
                isComposite[j] = true;
            }
        }
    }
    return isComposite; // isComposite[x] == false means x is prime (for x >= 2)
}
```

## Time & Space Complexity

**Time:** O(n log log n)
- Outer loop runs up to sqrt(n).
- Inner loop, summed over all primes i, marks n/2 + n/3 + n/5 + n/7 + ...
  which converges to n * log(log(n)) by known number theory results.

**Space:** O(n)
- One boolean array of size n+1 to track composite/prime status.

## When to use it
- Whenever you need **all primes up to n**, not just one primality check.
- Precomputation step before answering multiple queries (e.g. prime
  factorization, smallest prime factor tables, "count primes below n").
