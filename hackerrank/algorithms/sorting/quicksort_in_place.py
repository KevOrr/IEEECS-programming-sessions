#!/usr/bin/env python3

def partition(array):
    pivot = array[-1]
    swap_to = 0
    for compare_to in range(len(array)):
        if array[compare_to] <= pivot:
            array[swap_to], array[compare_to] = array[compare_to], array[swap_to]
            print(array)
            swap_to += 1
    array[swap_to], array[-1] = array[-1], array[swap_to]
    return swap_to

def quicksort(array):
    if len(array) > 1:
        pivot = partition(array)
        print(array)
        array[:pivot] = quicksort(array[:pivot])
        array[pivot+1:] = quicksort(array[pivot+1:])

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    quicksort(nums)
