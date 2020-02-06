m = 3
n = 7

def print_array(arr):
    for row in arr:
        print(row)


def setup():
    arr = []
    arr.append([1, 0, 1, 0, 0, 0, 0])
    arr.append([1, 1, 0, 0, 1, 0, 1])
    arr.append([0, 0, 1, 0, 0, 0, 1])

    return arr

def check_neighbour(arr, i, j, index):
    # check the neighbours and then mark as passed
    i1 = i - 1
    j1 = j - 1
    i2 = i + 1
    j2 = j + 1

    # check boundary
    if i1 < 0:
        i1 = 0
    if j1 < 0:
        j1 = 0
    if i2 >= m:
        i2 = m - 1
    if j2 >= n:
        j2 = n - 1

    arr[i][j] = index

    for i3 in range(i1, i2+1):
        for j3 in range(j1, j2+1):
            if i != i3 or j != j3:
                if arr[i3][j3] == 1:
                    # check neighbours have any neighbours
                    check_neighbour(arr, i3, j3, index)

def check_island(arr):
    index = 2
    for i in range(m):
        for j in range(n):
            if arr[i][j] == 1:
                check_neighbour(arr, i, j, index)
                index = index +1

    return index - 2

arr = setup()
print_array(arr)
solutions = check_island(arr)
print('Total number of islands are : {}'.format(solutions))
print_array(arr)