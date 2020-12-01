def day1_a():

    numbers = {int(x) for x in open("input.txt", "r")}

    for num in numbers:
        if (2020 - num) in numbers:
                print(num * (2020 - num))
                return

def day1_b():

    numbers = {int(x) for x in open("input.txt", "r")}

    for num1 in numbers:
        for num2 in numbers:
            if (2020 - num1 - num2) in numbers:
                print(num1* num2 * (2020 - num1 - num2))
                return
