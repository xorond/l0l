#------------------Bombermans Team---------------------------------#
#Author  : B3mB4m
#Concat  : b3mb4m@protonmail.com
#Project : https://github.com/b3mb4m/Shellsploit
#LICENSE : https://github.com/b3mb4m/Shellsploit/blob/master/LICENSE
#------------------------------------------------------------------#

def binarytodecimal( number):
	number = str(number)[::-1]
	total = 0
	for x in xrange(0, len(str(number))):
		total = total + int(number[x])*(2**x)
	return total

def binarytooctal( number):
	number = binarytodecimal( number)
	return decimaltooctal( number)

def binarytoohex( number):
	number = binarytodecimal( number)
	return decimaltohex( number)

def octaltodecimal( number):
	number = str(number)[::-1]
	total = 0
	for x in xrange(0, len(str(number))):
		total = total + int(number[x])*(8**x)
	return total

def octaltobinary( number):
	number = octaltodecimal( number)
	return decimaltobinary( number)

def octaltohex( number):
	number = octaltodecimal( number)
	return decimaltohex( number)

def hextodecimal( number):
	number = number[::-1]
	total = 0
	for x in xrange(0, len(str(number))):
		if   str(number[x]).upper() == "A":  total = total + int(10)*(16**x);
		elif str(number[x]).upper() == "B":  total = total + int(11)*(16**x);
		elif str(number[x]).upper() == "C":  total = total + int(12)*(16**x);
		elif str(number[x]).upper() == "D":  total = total + int(13)*(16**x);
		elif str(number[x]).upper() == "E":  total = total + int(14)*(16**x);
		elif str(number[x]).upper() == "F":  total = total + int(15)*(16**x);
		else:	total = total + int(number[x])*(16**x)
	return total

def hextobinary( number):
	number = hextodecimal( number)
	return decimaltobinary( number)

def hextooctal( number):
	number = hextodecimal( number)
	return decimaltooctal( number)

def decimaltobinary( number):
	list = []
	while number >= 1:
		list.append(str(number % 2))
		number = number / 2
	return "".join(list[::-1])

def decimaltooctal( number):
	list = []
	while number >= 1:
		list.append(str(number % 8))
		number = number / 8
	return "".join(list[::-1])

def decimaltohex( number):
	number = int(number)
	list = []
	while number >= 1:
		if   number % 16 == 10:  list.append("a")
		elif number % 16 == 11:  list.append("b")
		elif number % 16 == 12:  list.append("c")
		elif number % 16 == 13:  list.append("d")
		elif number % 16 == 14:  list.append("e")
		elif number % 16 == 15:  list.append("e")
		else: list.append(str(number % 16))
		number = number / 16
	return str("".join(list[::-1]))
