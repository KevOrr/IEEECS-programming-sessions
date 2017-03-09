print((lambda s:('not ','')[all(c in s for c in'abcdefghijklmnopqrstuvwxyz')]+'pangram')(input().lower()))
