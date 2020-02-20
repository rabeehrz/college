from functools import reduce
t = int(input())
for j in range(t):
    p = int(input())
    arr = [int(x) for x in input().split()]
    b = sorted(arr, reverse=True)
    maxi = min(b[0], 1)
    print("Case #"+ int(j)+ ":", end = "")
    print(maxi, end=" ")
    for i in range(len(b)):
        q = min(b[i], i+1)
        maxi = max(maxi, q)
        print(maxi, end=" ")
    print("")
        