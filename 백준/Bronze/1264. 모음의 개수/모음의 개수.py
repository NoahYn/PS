while True :
	s = input()
	if (s == '#') : break
	cnt = 0
	cnt += s.count("a")
	cnt += s.count("A")
	cnt += s.count("e")
	cnt += s.count("E")
	cnt += s.count("i")
	cnt += s.count("I")
	cnt += s.count("o")
	cnt += s.count("O")
	cnt += s.count("u")
	cnt += s.count("U")
	print(cnt)