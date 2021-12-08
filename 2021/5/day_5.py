from collections import defaultdict

with open("input.txt", "r") as file:
    inputs = file.readlines()


def good_range(first, second):
    if first > second:
        yield from range(first, second-1, -1)
    elif second > first:
        yield from range(first, second+1)


def part_1():
    pipes = [[[int(z.replace('\n', '')) for z in y.split(',')]
              for y in x.split(' -> ')] for x in inputs]
    pipe_dict = defaultdict(int)

    for [(x1, y1), (x2, y2)] in pipes:
        if y1 == y2:
            for i in good_range(x1, x2):
                pipe_dict[(i, y1)] += 1
        elif x1 == x2:
            for i in good_range(y1, y2):
                pipe_dict[(x1, i)] += 1

    count = 0
    for x in pipe_dict.values():
        if x > 1:
            count += 1
    print("Part 1", count)


part_1()


def part_2():
    pipes = [[[int(z.replace('\n', '')) for z in y.split(',')]
              for y in x.split(' -> ')] for x in inputs]
    pipe_dict = defaultdict(int)

    for [(x1, y1), (x2, y2)] in pipes:

        if y1 == y2:
            for i in good_range(x1, x2):
                pipe_dict[(i, y1)] += 1
        elif x1 == x2:
            for i in good_range(y1, y2):
                pipe_dict[(x1, i)] += 1
        else:
            for i in good_range(x1, x2):
                for j in good_range(y1, y2):
                    if abs(i-x1) == abs(j-y1):
                        pipe_dict[(i, j)] += 1

    count = 0
    for key, value in pipe_dict.items():
        if value > 1:
            count += 1
    print("Part 2", count)


part_2()
