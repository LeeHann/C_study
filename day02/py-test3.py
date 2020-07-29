n1 = int(input())
n2 = int(input())
n3 = n1 * n2

print(n1 * (n2%10))
n2 = n2 - (n2%10)
print(n1 * (n2%100)/10)
n2 = n2 - (n2%100)
print(n1 * (n2/100))
print(n3)