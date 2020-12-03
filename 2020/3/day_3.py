def day_3_a(ss_x, ss_y):
    
    slope = [line for line in open("input.txt", "r")]

    x = 0 
    num_trees = 0

    for y, line in enumerate(slope):

        if y % ss_y == 0:
            if line[x] == "#":
                num_trees += 1

            x += ss_x
            if x >= (len(line) -1):
                x = x - (len(line) -1)

    return num_trees
        
def day_3_b():
    return (day_3_a(1,1) * day_3_a(3,1) * day_3_a(5,1) * day_3_a(7,1) * day_3_a(1,2)) 
