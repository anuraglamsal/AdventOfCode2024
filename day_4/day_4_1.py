inp = []

with open('input') as file:
    for line in file:
        inp.append(list(line.strip()))

rows = len(inp)
cols = len(inp[0])

def check_mas(i1, i2, i3, j1, j2, j3):
    if 0<=i1<rows  and 0<=i2<rows  and 0<=i3<rows  and 0<=j1<cols and 0<=j2<cols and 0<=j3<cols:
        arr = [inp[i1][j1], inp[i2][j2], inp[i3][j3]]
        return arr == ['M', 'A', 'S']
    return 0

count = 0
for i in range (0, rows):
    for j in range (0, cols):
        if inp[i][j] == 'X':
            count += check_mas(i-1, i-2, i-3, j, j, j)
            count += check_mas(i+1, i+2, i+3, j, j, j)
            count += check_mas(i, i, i, j-1, j-2, j-3)
            count += check_mas(i, i, i, j+1, j+2, j+3)
            count += check_mas(i-1, i-2, i-3, j-1, j-2, j-3)
            count += check_mas(i+1, i+2, i+3, j+1, j+2, j+3)
            count += check_mas(i-1, i-2, i-3, j+1, j+2, j+3)
            count += check_mas(i+1, i+2, i+3, j-1, j-2, j-3)

print(count)
