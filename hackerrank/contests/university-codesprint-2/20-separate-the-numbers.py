#!/usr/bin/env python3

for _ in range(int(input().strip())):
    beautiful = False
    s = input().strip()
    for start_len in range(1, int(len(s)/2 + 1)):
        start, rest = int(s[:start_len]), s[start_len:]
        current = start
        while rest:
            nxt = str(current + 1)
            if not rest.startswith(nxt):
                break
            current, rest = int(rest[:len(nxt)]), rest[len(nxt):]
        else:
            beautiful = True
            break

    if beautiful:
        print('YES {}'.format(start))
    else:
        print('NO')
