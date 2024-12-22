"""
{
  "test_cases": [
    {
      "id": 1,
      "time_out": 2,
      "input": "1\n6\n1 3 4 6 8 9\n3\n",
      "output": "This program supports these operations:\n\t1. Search a key in a non-decreasing sequence of integers.\n\n\t2. Count the number of vowels in a string.\n\nChoose an operation: How many numbers do you want to enter (between 1 and 100)? Enter 6 integers in non-decreasing order (no duplicates): Enter the key to search:  - Checking index 2\n - Checking index 0\n - Checking index 1\n3 found at index 1\n"
    },
    {
      "id": 2,
      "time_out": 2,
      "input": "2\nred\n",
      "output": "This program supports these operations:\n\t1. Search a key in a non-decreasing sequence of integers.\n\n\t2. Count the number of vowels in a string.\n\nChoose an operation: Enter a string: red has 1 vowels\n"
    }
  ]
}
"""
import random
import json

def binarySearch(arr, l, key):
    low, high = 0,  l - 1
    returnStatement = ""
    while (low <= high):
        mid = (low + high) // 2
        returnStatement += (f" - Checking index {mid}\n")
        if (arr[mid] == key):
            returnStatement += f"{key} found at index {mid}\n"
            return returnStatement
        elif (arr[mid] < key):
            low = mid + 1
        else:
            high = mid - 1
    returnStatement += f"{key} not found.\n"
    return returnStatement

def create_testcases():
    testcases = []
    for i in range(1000):
        test = []
        n = random.randint(1, 100)
        for j in range(n): 
            a = random.randint(-100, 100)
            test.append(a)
        # k = random.randint(-80, 80)
        if (random.randint(0, 1) == 0):
            k = test[random.randint(0, n-1)]
        else:
            k = random.randint(-100, 100)
        test = list(set(test))
        test = sorted(test)
        n = len(test)
        testcases.append({
            "id": i+1001,
            "time_out": 2,
            "input": f"1\n{n}\n{' '.join(map(str, test))}\n{k}\n",
            "output": f"This program supports these operations:\n\t1. Search a key in a non-decreasing sequence of integers.\n\n\t2. Count the number of vowels in a string.\n\nChoose an operation: How many numbers do you want to enter (between 1 and 100)? Enter {n} integers in non-decreasing order (no duplicates): Enter the key to search: {binarySearch(test, n, k)}"
        })
    return testcases

def countVowels(s):
    count = 0
    vowels = "aeiouAEIOU"
    for char in s:
        if char in vowels:
            count += 1
    # can we use ternary operator here?
    return count if count > 0 else 0;

def create_testcases2():
    testcases = []
    for i in range(1000):
        test = ""
        n = random.randint(1, 60)
        for j in range(n):
            if (random.randint(0,1) == 0):
                test += chr(random.randint(97, 122))
            else: test += chr(random.randint(65, 90))
        testcases.append({
            "id": i+1,
            "time_out": 2,
            "input": f"2\n{test}\n",
            "output": f"This program supports these operations:\n\t1. Search a key in a non-decreasing sequence of integers.\n\n\t2. Count the number of vowels in a string.\n\nChoose an operation: Enter a string: {test} has {countVowels(test)} vowels\n"
        })
    return testcases

cases = create_testcases2()
cases += create_testcases()
a = {"test_cases": cases}
with open("testcases2.json", "w") as f:
    json.dump(a, f, indent=2)
