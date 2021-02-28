def solve():
	n, p, f = input().split(" ")
	n = int(n)
	p = int(p)
	f = int(f)
	mo = input().rstrip()
	morning = list(mo.split(" "))
	morning = [int(x) for x in morning]
	# print(morning)
	ev = input().rstrip()
	evening = list(ev.split(" "))
	evening = [int(x) for x in evening]
	# print(evening)
	morning.sort(); evening.sort(reverse = True)
	count = 0
	for i in range(len(morning)):
		if morning[i] + evening[i] > p:
			count += morning[i] + evening[i] - p
	print(count * f)

solve()
