inp = []

with open('input') as file:
    for line in file:
        inp.append(list(line.strip()))

rows = len(inp)
cols = len(inp[0])

def check_mas(i1, i2, j1, j2):
    if 0<=i1<rows and 0<=i2<rows and 0<=j1<cols and 0<=j2<cols:
        arr_1 = [inp[i1][j1], inp[i2][j2]]
        arr_2 = [inp[i1][j2], inp[i2][j1]]
        comp_1 = ['M', 'S']
        comp_2 = ['S', 'M']
        return (arr_1 == comp_1 or arr_1 == comp_2) and (arr_2 == comp_1 or arr_2 == comp_2)
    return 0

count = 0
for i in range (0, rows):
    for j in range (0, cols):
        if inp[i][j] == 'A':
            count += check_mas(i-1, i+1, j-1, j+1)

print(count)
