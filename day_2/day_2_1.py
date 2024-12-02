with open('input') as file:
     data = [list(map(int, line.split())) for line in file]

#print(data)

def check(a, b):
    if a == b or abs(a-b) > 3:
        return True, None
    else:
        return False, a > b 

safe_count = 0
for report in data:
    cont, init_flag = check(report[0], report[1])
    if cont:
        continue
    for i in range (1, len(report)-1):
        cont_2, flag = check(report[i], report[i+1])
        if cont_2 or flag != init_flag:
            cont = True
            break
    if cont:
        continue
    else:
        safe_count+=1

print(safe_count)
