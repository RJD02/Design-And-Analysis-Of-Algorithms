def solve():
    n, p, f = input().split(" ")
    n = int(n)
    p = int(p)
    f = int(f)
    morning = list(input().split(" "))
    evening = list(input().split(" "))
    #  print(morning, evening)
    #  morning = [int(x) for x in morning]
    for i in range(len(morning)):
        morning[i] = int(morning[i])
        evening[i] = int(evening[i])
    #  evening = [int(x) for x in evening]
    morning.sort(); evening.sort()
    #  print(morning)
    #  print(evening)
    count = 0
    for i in range(len(morning)):
        if morning[i] + evening[len(evening) - i - 1] > p:
            count += morning[i] + evening[len(evening) - i - 1] - p
    print(count * f)

solve()
