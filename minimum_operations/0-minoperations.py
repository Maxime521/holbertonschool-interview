#!/usr/bin/python3
"""
Method that calculates the fewest number of operations needed to
 result in exactly n H characters in the file.

"""


def minOperations(n):

    if n <= 1:
        return 0

    operation_needed = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operation_needed += divisor
            n //= divisor
        divisor += 1

    return operation_needed
