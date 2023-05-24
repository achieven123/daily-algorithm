import sys

size = int(sys.stdin.readline())
num_list = list()

for i in range(size):
    num_list.append(int(sys.stdin.readline()))

sum_of_list = sum(num_list)
average = 0

if sum_of_list > 0:
    average = sum_of_list / size + 0.5
if sum_of_list < 0:
    average = sum_of_list / size - 0.5

num_list.sort()

mid = num_list[int(size / 2)]
max = num_list[size - 1]
min = num_list[0]

mode = min
count_max = 0
count_idx = max - min + 1
count_list = [0 for i in range(count_idx)]

for i in range(size):
    count_list[num_list[i] - min] += 1

for i in range(count_idx):
    if count_list[i] > count_max:
        count_max = count_list[i]
        mode = i

count_list[mode] = 0

for i in range(count_idx):
    if count_list[i] == count_max:
        mode = i
        break

print(int(average))
print(mid)
print(mode + min)
print(max - min)
