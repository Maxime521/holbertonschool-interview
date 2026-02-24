#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys
import re


def print_stats(total_size, status_counts):
    """
    Print the current statistics
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] != 0:
            print("{}: {}".format(code, status_counts[code]))


def parse_line(line):
    """
    Parse a log line and extract status code and file size
    Returns (status_code, file_size) or (None, file_size) if only size found
    """
    line = line.strip()

    pattern_full = r'(\d{3}) (\d+)$'
    match_full = re.search(pattern_full, line)

    if match_full:
        status_code = int(match_full.group(1))
        file_size = int(match_full.group(2))
        return status_code, file_size

    pattern_size = r'(\d+)$'
    match_size = re.search(pattern_size, line)
    if match_size:
        file_size = int(match_size.group(1))
        return None, file_size

    return None, None


def main():
    """
    Main function to process stdin and compute metrics
    """
    total_size = 0
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    status_counts = {code: 0 for code in valid_codes}
    line_count = 0

    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)

            if file_size is not None:
                total_size += file_size
                line_count += 1

                if status_code is not None and status_code in valid_codes:
                    status_counts[status_code] += 1

                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise

    if line_count % 10 != 0 or line_count == 0:
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
