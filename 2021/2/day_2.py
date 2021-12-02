instructions = [x.replace("\n","") for x in open("input.txt", "r")]

def part_1():

    y,x = 0,0

    for inst in instructions:
        a,b = inst.split(" ")
        if a == "down":
            y += int(b)
        elif a == "up":
            y -= int(b)
        elif a == "forward":
            x += int(b)

    print ("X: ", x,"Y: ", y, "Tot: ", x*y)

part_1()

def part_2():

    aim,y,x = 0,0,0

    for inst in instructions:
        a,b = inst.split(" ")
        if a == "down":
            aim += int(b)
        elif a == "up":
            aim -= int(b)
        elif a == "forward":
            x += int(b)
            y += aim * int(b)

    print ("X: ", x,"Y: ", y, "Tot: ", x*y)

part_2()
