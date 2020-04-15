import math

PI = 3.1415
line = input().split(' ')
radius, helium = int(line[0]), int(line[1])
volume = 4 / 3 * PI * radius ** 3
print(math.floor(helium / volume))
