"""
{
    "test_cases": [
        {
            "id": 1,
            "time_out": 4,
            "input": "3\nArnab\n50\nSurjya\n100\nSwaroop\n80\n1\n",
            "output": "Enter the number of employees: Enter name and productivity:\nEnter name and productivity:\nEnter name and productivity:\nThis program supports TWO operations:\n\t1. Print the employee's name with the highest productivity,\n\t2. Print all characters of the longest name in alphabetical order.\n\nChoose an operation (1 or 2): The employee with the highest productivity is Surjya\n"
        },
        ...
    ]
}
"""

import random
import json

testCases = {"test_cases": []}


def swap_chars(name, i, j):
    name_list = list(name)
    name_list[i], name_list[j] = name_list[j], name_list[i]
    return "".join(name_list)


id = 0
for i in range(1000):
    id += 1
    n = random.randint(1, 26)
    data = []
    for j in range(n):
        name = chr(97 + j) * random.randint(1, 3)
        for i in range(5):
            if random.randint(0, 1) == 0:
                name += chr(97 + random.randint(0, 25)) * random.randint(1, 5)
            else:
                name += chr(65 + random.randint(0, 25)) * random.randint(1, 5)
        productivity = random.randint(1, 100)
        data.append((name, productivity))
    operation = random.randint(1, 2)
    input = f"{n}\n"
    for name, productivity in data:
        input += f"{name}\n{productivity}\n"
        # print(name, productivity)
    input += f"{operation}\n"

    # data.sort(key=lambda x: x[1], reverse=True)

    # largestLength = 0
    largestName = ""
    largestLength = 0

    for name, productivity in data:
        if len(name) > largestLength:
            largestLength = len(name)
            largestName = name

    # sort the largest name in alphabetical order (case-insensitive), but case sensitive for the same letter)
    name = largestName
    name = list(name)

    for i in range(len(name)):
        for j in range(i):
            if name[i] >= "a" and name[j] >= "a":
                if name[i] < name[j]:
                    name = swap_chars(name, i, j)
            elif name[i] >= "a" and name[j] < "a":
                if name[i] < chr(ord(name[j]) + ord("a") - ord("A")):
                    name = swap_chars(name, i, j)
            elif name[i] < "a" and name[j] >= "a":
                if ord(name[i]) + ord("a") - ord("A") < ord(name[j]):
                    name = swap_chars(name, i, j)
                if ord(name[i]) + ord("a") - ord("A") == ord(name[j]):
                    name = swap_chars(name, i, j)
            else:
                if name[i] < name[j]:
                    name = swap_chars(name, i, j)

    name = "".join(name)
    largestName = name

    bestProd = 0
    bestName = ""
    for name, productivity in data:
        if productivity >= bestProd:
            bestProd = productivity
            bestName = name

    if operation == 1:
        output = f"Enter the number of employees: "
        for name, productivity in data:
            output += "Enter name and productivity:\n"
        output += (
            "This program supports TWO operations:\n\t1. Print the employee's name with the highest productivity,\n\t2. Print all characters of the longest name in alphabetical order.\n\nChoose an operation (1 or 2): The employee with the highest productivity is "
            + bestName
            + "\n"
        )
    else:
        output = f"Enter the number of employees: "
        for name, productivity in data:
            output += "Enter name and productivity:\n"
        output += (
            "This program supports TWO operations:\n\t1. Print the employee's name with the highest productivity,\n\t2. Print all characters of the longest name in alphabetical order.\n\nChoose an operation (1 or 2): The characters in the longest employee's name in alphabetical order are "
            + largestName
            + "\n"
        )
    testCases["test_cases"].append(
        {"id": id, "time_out": 4, "input": input, "output": output}
    )
    # print(data[0][0], data[0][1], largestName, largestLength, operation)

with open("testCases.json", "w") as f:
    json.dump(testCases, f, indent=2)
