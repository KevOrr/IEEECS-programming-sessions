#!/usr/bin/env python3

n = int(input())
string = input()

num_changes = 0
while '010' in string:
    first_double_index = string.find('01010')
    if first_double_index != -1:
        string = string[:first_double_index + 2] + '1' + string[first_double_index + 3:]
        num_changes += 1
    else:
        first_single_index = string.find('010')
        if first_single_index != -1:
            string = string[:first_single_index + 1] + '0' + string[first_single_index + 2:]
            num_changes += 1

print(num_changes)
