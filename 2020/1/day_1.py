def day1():

    numbers = {int(x) for x in open("input.txt", "r")}

    for num in numbers:
        if (2020 - num) in numbers: 
                print(num * (2020 - num))
