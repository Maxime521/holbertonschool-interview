# Making Change

This project implements a function that determines the fewest number of coins needed to meet a given total amount.

## Project Info

- **Repository:** `holbertonschool-interview`
- **Directory:** `making_change`
- **File:** `0-making_change.py`

## Function Prototype

```python
def makeChange(coins, total):
```

## Requirements Covered

- Return the fewest number of coins needed to meet `total`.
- Return `0` if `total` is `0` or less.
- Return `-1` if `total` cannot be met with the available coin denominations.
- Assume an infinite number of each coin denomination.
- Each coin value is a positive integer.

## How It Works

Uses dynamic programming:

1. Initialize `dp[0] = 0` and set unreachable amounts to a sentinel value.
2. For each amount from `1` to `total`, try every coin denomination.
3. Update `dp[amount] = min(dp[amount], dp[amount - coin] + 1)`.
4. Return `dp[total]` if reachable, otherwise `-1`.

## Complexity

- **Time:** `O(total × len(coins))`
- **Space:** `O(total)`

## Example

```python
makeChange([1, 2, 25], 37)                # 7
makeChange([1256, 54, 48, 16, 102], 1453) # -1
```

## Run Example

```bash
./0-main.py
```

Expected output:

```
7
-1
```
