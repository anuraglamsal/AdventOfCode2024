with open('input') as file:
     data = [list(map(int, line.split())) for line in file]

#print(data)

def check(a, b):
    if a == b or abs(a-b) > 3:
        return True, None
    else:
        return False, a > b 

#data = [[1, 2, 7, 8, 9], [9, 7, 6, 2, 1], [1, 3, 2, 4, 5], [8, 6, 4, 4, 1]]

# overthought completely when I should've just bruteforced from the get go.
# Is there a solution to this whose time complexity is not the same as the bruteforce approach? 
# This is n^2 for each report. 
safe_count = 0
for report in data:
    for j in range (-1, len(report)):
        if j == -1:
            _report = report
        else:
            _report = report.copy()
            _report.pop(j)
        cont, init_flag = check(_report[0], _report[1])
        if cont:
            continue
        for i in range (1, len(_report)-1):
            cont_2, flag = check(_report[i], _report[i+1])
            if cont_2 or flag != init_flag:
                cont = True
                break
        if cont:
            continue
        else:
            safe_count += 1
            break

    """cont, init_flag = check(report[0], report[1])
    #if cont:
        #continue
    unsafe_level_count = 0
    unsafe_level_index = 0
    for i in range (1, len(report)-1):
        cont_2, flag = check(report[i], report[i+1])
        if cont_2 or flag != init_flag:
            cont = True
            unsafe_level_count += 1
            unsafe_level_index = i
    if cont:
        if unsafe_level_count == len(report)-2: # edge case when only the first number is problematic
            safe_count += 1
            print(report)
        elif unsafe_level_count > 1:
            continue
        else:
            if unsafe_level_index == len(report)-2: # edge case when only the last number is problematic
                safe_count += 1
                continue
            _, flag_1 = check(report[unsafe_level_index-1], report[unsafe_level_index+1])
            #_, flag_2 = check(report[unsafe_level_index], report[unsafe_level_index+2])
            if flag_1 is not None and flag_1 == init_flag:
                safe_count += 1
            else:
                continue
    else:
        safe_count += 1"""

print(safe_count)
