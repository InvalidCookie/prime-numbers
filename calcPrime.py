start = 2
end = 65535
prime = []

n = start

while n <= end:
    for x in range (1, n):
        if n % x == 0 and x != 1:
            break
        elif x == n - 1:
            prime.append(n)

    n += 1

print(len(prime))
