"""
Title: Find K Largest Elements in an Array

Problem Statement:
    - Given an array of integers and a number k,
      return the k largest elements from the array in descending order.

Approach:
    - Use a min-heap (priority queue) to keep track of the k largest elements.
    - Initialize the heap with the first k elements.
    - For each remaining element, if it is larger than the root of the heap,
      replace the root with this element.
    - Finally, pop all elements from the heap and reverse the list to get descending order.

Time Complexity:
    - O(n log k), where n is the number of elements in the array.
      (Each insertion/removal from the heap takes O(log k))

Space Complexity:
    - O(k), for storing the k largest elements in the heap.

Author: Vishal Singhaniya
"""

import heapq

def kLargest(arr, k):
    minH = arr[:k]
    heapq.heapify(minH)

    for x in arr[k:]:
        if x > minH[0]:
            heapq.heapreplace(minH, x)

    res = []
    while minH:
        res.append(heapq.heappop(minH))
    
    res.reverse()  # To return results in descending order
    return res

def main():
    arr = [7, 10, 4, 3, 20, 15]
    k = 1
    result = kLargest(arr, k)
    print("The", k, "largest elements are:", result)

if __name__ == "__main__":
    main()
