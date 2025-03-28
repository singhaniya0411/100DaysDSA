"""
    Title: Group Anagrams Using Character Frequency Count

    Problem Statement:
        - Given a list of words, group all anagrams together.

    Optimized Approach:
        - Instead of sorting strings, count the frequency of each character.
        - Use a tuple of 26 elements (for each alphabet letter) as a hash key.
        - Store words in a dictionary where keys represent character frequencies.

    Time Complexity:
        - **O(n * m)** (n = number of words, m = average length of each word)

    Space Complexity:
        - **O(n * m)** (for storing words in dictionary)

    Author: Vishal Singhaniya
"""

from collections import defaultdict

def group_anagrams(arr):
    """
    Function to group words that are anagrams of each other.

    Parameters:
        arr (list of str): List of input words.

    Returns:
        list of list of str: Grouped anagrams.
    """

    ans = defaultdict(list)

    # Iterate through each word in the input array
    for s in arr:
        count = [0] * 26  # 26 letters in the English alphabet
        
        # Count occurrences of each character
        for c in s:
            count[ord(c) - ord("a")] += 1  
        
        # Store words in a dictionary based on character frequency
        ans[tuple(count)].append(s)  

    return list(ans.values())

def print_anagrams(groups):
    """
    Function to print grouped anagrams in a readable format.

    Parameters:
        groups (list of list of str): List containing grouped anagrams.
    """
    for group in groups:
        print("[", " ".join(group), "]")

if __name__ == "__main__":
    words = ["cat", "dog", "god", "tac", "act", "ten", "net"]
    grouped_anagrams = group_anagrams(words)

    print("Grouped Anagrams:")
    print_anagrams(grouped_anagrams)
