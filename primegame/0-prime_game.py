#!/usr/bin/python3
"""Prime game winner module."""


def _build_prime_prefix(limit):
    """Return prefix counts of primes from 0..limit."""
    is_prime = [True] * (limit + 1)
    prime_count = [0] * (limit + 1)
    p = 2

    if limit >= 0:
        is_prime[0] = False
    if limit >= 1:
        is_prime[1] = False

    while p * p <= limit:
        if is_prime[p]:
            multiple = p * p
            while multiple <= limit:
                is_prime[multiple] = False
                multiple += p
        p += 1

    i = 1
    while i <= limit:
        prime_count[i] = prime_count[i - 1]
        if is_prime[i]:
            prime_count[i] += 1
        i += 1

    return prime_count


def isWinner(x, nums):
    """
    Determine the player that wins the most rounds.

    Maria starts each round; winner is decided by optimal play.
    """
    maria_wins = 0
    ben_wins = 0
    rounds = 0
    max_n = 0

    if x <= 0 or not nums:
        return None

    rounds = x if x < len(nums) else len(nums)
    if rounds <= 0:
        return None

    i = 0
    while i < rounds:
        if nums[i] > max_n:
            max_n = nums[i]
        i += 1

    if max_n < 2:
        return "Ben"

    prime_prefix = _build_prime_prefix(max_n)

    i = 0
    while i < rounds:
        if prime_prefix[nums[i]] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1
        i += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
