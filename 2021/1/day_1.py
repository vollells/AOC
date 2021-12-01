numbers = [int(x) for x in open("input.txt", "r")]

def part_1():
    count = (0, 1000000000)
    for number in numbers:
        if number > count[1]:
            count = (count[0]+1, number)
        else:
            count = (count[0], number)

    print (count[0])

part_1()

def part_2():
    count = (0, 1000000000)
    for i in range (2, len(numbers)):
        curr_frame = numbers[i] + numbers[i-1] + numbers[i-2]
        if curr_frame > count[1]:
            count = (count[0]+1, curr_frame)
        else:
            count = (count[0], curr_frame)

    print (count[0])

part_2()
