def day_2_a():

    passwords = [x for x in open("input.txt", "r")]

    word_count = 0
    for password in passwords:
        lower_bound,upper_bound,bound_count = 0,0,0
        bounded_char = ""

        limits,password = password.split(": ")
        lower_bound,upper_bound = limits.split("-")
        upper_bound,bounded_char = upper_bound.split(" ")

        for letter in password:
            if letter == bounded_char:
                bound_count += 1

        if bound_count >= int(lower_bound) and bound_count <= int(upper_bound):
            word_count += 1

    print(word_count)


def day_2_b():

    passwords = [x for x in open("input.txt", "r")]

    word_count = 0
    for password in passwords:
        first_pos,second_pos = 0,0
        bounded_char = ""

        limits,password = password.split(": ")
        first_pos,second_pos = limits.split("-")
        second_pos,bounded_char = second_pos.split(" ")

        if (password[int(first_pos)-1] == bounded_char) ^\
           (password[int(second_pos)-1] == bounded_char):
            word_count += 1

    print(word_count)

