n1 = int(input())
n2 = int(input())
n3 = n1 * n2

for i in range(1, 4) :
    print(n1 * (n2%10))
    n2 = n2//10
print(n3)