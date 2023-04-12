str = input()
num = len(str)
ans = 0
for i in range(num) :
	if (str[i] >= '0' and str[i] <= '9') :
		ans = ans * 16 + int(str[i])  
	elif (str[i] == 'A') :
		ans = 16 * ans + 10
	elif (str[i] == 'B') :
		ans = 16 * ans + 11
	elif (str[i] == 'C') :
		ans = 16 * ans + 12
	elif (str[i] == 'D') :
		ans = 16 * ans + 13
	elif (str[i] == 'E') :
		ans = 16 * ans + 14
	elif (str[i] == 'F') :
		ans = 16 * ans + 15

print(ans)