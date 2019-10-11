import math
T=int(input(""))
if T>64:
    exit(0)
while T>0 and T<65:
    n,k=map(int, input().split())
    if n>128 or n<1:
        exit(0)
    if k>1024 or k<1:
        exit(0)
    a=map(int, input().split())
    ai=list(a)
    for i in ai:
        if i>1024:
            exit(0)
    if ai!=sorted(ai):
        exit(0)
    c=0
    for i in range(0,n):
        if ai[i+1]-ai[i]>=k:
            c+=(math.ceil((ai[i+1]-ai[i])/k)-1)

            if i+1==n-1:
                break

    print(c)
    T=T-1
