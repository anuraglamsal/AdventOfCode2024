grid = []

with open('input') as file:
    for line in file:
        grid.append(list(line.strip()))

rows = len(grid)
cols = len(grid[0])
guard_pos_y, guard_pos_x = 0, 0
grid_visited = []

for i in range (0, rows):
    grid_visited.append([])
    for j in range (0, cols):
        grid_visited[i].append(False) 
        if grid[i][j] == '^':
            guard_pos_y, guard_pos_x = i, j
            grid_visited[i].append(True)

count = 1 
dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
dir_next = {0: 3, 1: 2, 2: 0, 3: 1}
dir_index = 0
dy, dx = -1, 0 

while True:
    if 0<=guard_pos_y + dy<rows and 0<=guard_pos_x + dx<cols:
        if grid[guard_pos_y + dy][guard_pos_x + dx] == '#':
            dir_index = dir_next[dir_index]
            dy, dx = dirs[dir_index][0], dirs[dir_index][1]
            continue
        elif not(grid_visited[guard_pos_y + dy][guard_pos_x + dx]):
            count += 1
            grid_visited[guard_pos_y + dy][guard_pos_x + dx] = True
        guard_pos_y += dy 
        guard_pos_x += dx
    else:
        break

print(count)
