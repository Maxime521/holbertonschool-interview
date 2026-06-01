#!/usr/bin/python3
"""
Module that queries the Reddit API and returns the number of subscribers
"""

import requests


def count_words(subreddit, word_list):
    """
    """

    words = {}
    for w in word_list:
        lower = w.lower()
        if lower in words:
            words[lower] += 0
        else:
            words[lower] = 0

    if not subreddit or not word_list:
        return

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "holberton:countit:v1.0"}

    def recurse(after=None):
        """
        Recursively fetch posts from the subreddit
        """
        params = {"limit": 100}
        if after:
            params["after"] = after

        result = requests.get(url, headers=headers, params=params)

        if result.status_code != 200:
            return

        data = result.json()
        children = data.get("children", [])
        next_after = data.get("after", None)

        for child in children:
            title = child.get("data", {}).get("title", "").lower()
            tokens = title.split()

            for key in words.keys():
                for token in tokens:
                    t_clean = t.strip(",!?\"':;()[]{}")

                    if t_clean == key:
                        words[key] += 1

        if next_after is not None:
            recurse(next_after)

    recurse()

    filtered_words = {k: v for k, v in words.items() if v > 0}
    if not filtered_words:
        return

    items = list(filtered.items())
    items.sort(key=lambda x: (-x[1], x[0]))
    for w, c in items:
        print(f"{w}: {c}")
