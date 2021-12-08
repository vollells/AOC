instructions = [x.replace("\n", "") for x in open("input.txt", "r")]


def part_1(instructions, offset=0):
    one_count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    zero_count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for byte in instructions:
        for i, bit in enumerate(byte):
            one_count[i] += int(byte[i])
            zero_count[i] += not int(byte[i])

    gamma = ""
    epsilon = ""

    for i in range(offset, len(one_count)):
        if one_count[i] > zero_count[i]:
            gamma += "1"
            epsilon += "0"
        elif one_count[i] < zero_count[i]:
            gamma += "0"
            epsilon += "1"
        else:
            gamma += "1"
            epsilon += "1"

    if not offset:
        print(int(gamma, 2))
        print(int(epsilon, 2))
        print(int(epsilon, 2) * int(gamma, 2))


    return (one_count[offset] >= zero_count[offset], one_count[offset] <= zero_count[offset])


part_1(instructions)


def part_2():
    new_instructions = instructions
    c = ""
    o = ""

    for i in range(len(new_instructions[0])):
        one_or_zero = part_1(new_instructions, i)

        tmp = []
        for inst in new_instructions:
            if (inst[i] == "1" and one_or_zero[0]) or (inst[i] == "0" and not one_or_zero[0]):
                tmp += [inst]

        if len(tmp) == 1:
            o = tmp[0]
            break
        else:
            new_instructions = tmp

    new_instructions = instructions

    for i in range(len(new_instructions[0])):
        one_or_zero = part_1(new_instructions, i)
        tmp = []
        for inst in new_instructions:
            if one_or_zero[1] and one_or_zero[0]:
                if inst[i] == "0":
                    tmp += [inst]
            elif (inst[i] == "1" and one_or_zero[1]) or (inst[i] == "0" and not one_or_zero[1]):
                tmp += [inst]

        if len(tmp) == 1:
            c = tmp[0]
            break
        else:
            new_instructions = tmp

    print(int(o, 2))
    print(int(c, 2))
    print(int(c, 2) * int(o, 2))


part_2()
