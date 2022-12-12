A = .1
B = .2
C = .3

result_one = (A+B)+C
result_two = A+(B+C)

print("Result for (A+B)+C: " + str(result_one))
print("Result for A+(B+C): " + str(result_two))

print(result_one == result_two)
