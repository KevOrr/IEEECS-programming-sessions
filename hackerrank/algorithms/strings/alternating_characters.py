#!/usr/bin/env python3

for _ in range(int(input())):
    string = input()
    last_char = string[0]
    deletions = 0

    for char in string[1:]:
        if last_char == char:
            deletions += 1
        else:
            last_char = char

    print(deletions)
