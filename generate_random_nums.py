import random

randlist = []
_range = int(input("which range : "))
r_start = random.randint(-10000, 10)
r_end = random.randint(11, 10000)
randlist = random.sample(range(r_start, r_end), _range)
for num in randlist:
    print(num, end=' ')

