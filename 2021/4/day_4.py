input_file = open("input.txt", "r")

def init():
    numbers = input_file.readline().split(",")
    boards_list = input_file.readlines()

    boards = []
    tmp = []
    for line in boards_list:
        if line == "\n":
            if tmp:
                boards.append(tmp)
            tmp=[]
        else:
            tmp_line = line.split(" ")
            while '' in tmp_line:
                tmp_line.remove('')
            tmp_line = [(int(x.replace("\n","")), False) for x in tmp_line]
            tmp.append(tmp_line)
    boards.append(tmp)

    return numbers, boards


def part_1():
    numbers, boards = init()

    found_board = False
    final_value,b_index = 0,0
    while not found_board:
        curr_num = int(numbers.pop(0))
        for x, board in enumerate(boards):
            for i, row in enumerate(board):
                tmp_x = True
                tmp_y = True
                for j, item in enumerate(row):
                    if item[0] == curr_num:
                        boards[x][i][j] = (item[0], True)
                    tmp_x = tmp_x and board[i][j][1]
                    tmp_y = tmp_y and board[j][i][1]

                if tmp_x or tmp_y:
                    final_value = curr_num
                    b_index = x
                    found_board = True


    print (final_value)
    unused_total = 0
    for y in boards[b_index]:
        for x in y:
            if not x[1]:
                unused_total += x[0]
    print (unused_total)
    print(final_value * unused_total)


# part_1()


def part_2():
    numbers, boards = init()

    found_board = False
    final_value,b_index = 0,0
    remaining_boards = [True for i in range(len(boards))]
    while not found_board:
        curr_num = int(numbers.pop(0))
        print(remaining_boards)
        for x, board in enumerate(boards):
            for i, row in enumerate(board):
                tmp_x = True and remaining_boards[x]
                tmp_y = True and remaining_boards[x]
                for j, item in enumerate(row):
                    if item[0] == curr_num:
                        boards[x][i][j] = (item[0], True)
                    tmp_x = tmp_x and board[i][j][1]
                    tmp_y = tmp_y and board[j][i][1]

                if tmp_x or tmp_y:
                    truth_value = False
                    for tv in remaining_boards:
                        if truth_value and tv:
                            truth_value = False
                            break
                        truth_value = truth_value ^ tv

                    if truth_value:
                        final_value = curr_num
                        b_index = x
                        found_board = True
                    else:
                        remaining_boards[x] = False

    print (final_value)
    unused_total = 0
    for y in boards[b_index]:
        print(y)
        for x in y:
            if not x[1]:
                unused_total += x[0]
    print (unused_total)
    print(final_value * unused_total)

part_2()
