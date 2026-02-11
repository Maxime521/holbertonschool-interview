#!/usr/bin/python3
"""Utilities for checking if a set of lockboxes can all be opened"""

def canUnlockAll(boxes):
    """Check if all the boxes can be opened"""

    unlocked = [False] * len(boxes)
    unlocked[0] = True

    keys = [0]

    while keys:
        box = keys.pop()
        for key in boxes[box]:
            if key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)
