"""
{
    "test_cases": [
        {
            "id": 1,
            "time_out": 4,
            "input": "1\n10000\nBITS_Pilani.\n1\n2\n3\n1\n2\n1\n2\n20000\nIts_Magic.\n1\n1\n2\n2\n3\n3\n1\n",
            "output": "Enter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nEnter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nID of the employee with the highest salary is: 2\nThis program supports TWO operations for the employee with the highest salary:\n\t1. Find the longest word in the employee's favorite quote,\n\t2. Find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken.\n\nChoose an operation (1 or 2): The longest word is: Magic\n"
        },
        {
            "id": 2,
            "time_out": 4,
            "input": "1\n10000\nBITS_Pilani.\n1\n2\n3\n1\n2\n1\n2\n5000\nIts_Magic.\n1\n1\n2\n2\n3\n3\n1\n",
            "output": "Enter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nEnter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nID of the employee with the highest salary is: 1\nThis program supports TWO operations for the employee with the highest salary:\n\t1. Find the longest word in the employee's favorite quote,\n\t2. Find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken.\n\nChoose an operation (1 or 2): The longest word is: Pilani\n"
        },
        {
            "id": 3,
            "time_out": 4,
            "input": "1\n10000\nBITS_Pilani.\n1\n2\n3\n1\n2\n1\n2\n5000\nIts_Magic.\n1\n1\n2\n2\n3\n3\n2\n",
            "output": "Enter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nEnter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nID of the employee with the highest salary is: 1\nThis program supports TWO operations for the employee with the highest salary:\n\t1. Find the longest word in the employee's favorite quote,\n\t2. Find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken.\n\nChoose an operation (1 or 2): The number of sick leaves appearing the most: 1\nThe average number of sick leaves: 1.7\n"
        },
        {
            "id": 3,
            "time_out": 4,
            "input": "1\n10000\nBITS_Pilani.\n1\n2\n3\n1\n2\n1\n2\n20000\nIts_Magic.\n1\n1\n2\n2\n3\n3\n2\n",
            "output": "Enter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nEnter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nID of the employee with the highest salary is: 2\nThis program supports TWO operations for the employee with the highest salary:\n\t1. Find the longest word in the employee's favorite quote,\n\t2. Find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken.\n\nChoose an operation (1 or 2): The number of sick leaves appearing the most: 3\nThe average number of sick leaves: 2.0\n"
        }
    ]
}
"""


import json
import random

data = {"test_cases": []}

def maxSalary(id1, salary1, quote1, sick_leaves1, id2, salary2, quote2, sick_leaves2):
    if salary1 == salary2:
        if id1 > id2:
            return {"id": id1, "salary": salary1, "quote": quote1, "sick_leaves": sick_leaves1}
        return {"id": id2, "salary": salary2, "quote": quote2, "sick_leaves": sick_leaves2}
    if salary1 > salary2:
        return {"id": id1, "salary": salary1, "quote": quote1, "sick_leaves": sick_leaves1}
    return {"id": id2, "salary": salary2, "quote": quote2, "sick_leaves": sick_leaves2}

for i in range(1000):
    id = i + 1
    time_out = 4
    id1 = random.randint(1, 100)
    salary1 = random.randint(1000, 10000)
    quote1 = str(random.randint(1, 100)) + "_" + str(random.randint(1, 100)) + "_" + str(random.randint(1, 100)) + "."
    sick_leaves1 = [random.randint(1, 5) for _ in range(6)]
    id2 = random.randint(1, 100)
    salary2 = random.randint(1000, 10000)
    quote2 = str(random.randint(1, 100)) + "_" + str(random.randint(1, 100)) + "_" + str(random.randint(1, 100)) + "."
    sick_leaves2 = [random.randint(1, 5) for _ in range(6)]
    operation = random.randint(1, 2)

    input = f"{id1}\n{salary1}\n{quote1}\n" + "\n".join(map(str, sick_leaves1)) + f"\n{id2}\n{salary2}\n{quote2}\n" + "\n".join(map(str, sick_leaves2)) + f"\n{operation}\n"
    emp = maxSalary(id1, salary1, quote1, sick_leaves1, id2, salary2, quote2, sick_leaves2)
    output = f"Enter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nEnter employee id:\nEnter employee's salary:\nEnter Favorite Quote (each word is separated by '_' and the phrase ends with a '.'):\nEnter sick leaves taken by an employee for each month during the first 6 months\nID of the employee with the highest salary is: {emp['id']}\nThis program supports TWO operations for the employee with the highest salary:\n\t1. Find the longest word in the employee's favorite quote,\n\t2. Find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken.\n\nChoose an operation (1 or 2): "
    if operation == 1:
        quote = emp["quote"].split('_')
        quote[-1] = quote[-1][:-1]
        maxLen = 0
        longest_word = ""
        for (i, word) in enumerate(quote):
            if len(word) >= maxLen:
                maxLen = len(word)
                longest_word = word
        output += f"The longest word is: {longest_word}\n"
    else:
        # select the mode of the sick leaves
        mode = {}
        for i in emp["sick_leaves"]:
            if i in mode:
                mode[i] += 1
            else:
                mode[i] = 1
        maxMode = max(mode.values())
        for (i, j) in mode.items():
            if j == maxMode:
                mode = i
        # calculate the average of the sick leaves -> 0.1f
        output += f"The number of sick leaves appearing the most: {mode}\nThe average number of sick leaves: {sum(emp['sick_leaves']) / len(emp['sick_leaves']):.1f}\n"
    data["test_cases"].append({
        "id": id,
        "time_out": time_out,
        "input": input,
        "output": output
    })
    

with open("generatedTestCases.json", "w") as f:
    json.dump(data, f, indent=2)