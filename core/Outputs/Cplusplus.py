import time
from header import *

#For windows.
def CplusplusFile( shellcode, win=False):
    if win == True:
        db = """//Project : https://github.com/roissy/l0l
//This file created with l0l ..
//%s - %s
//Compile : gcc shell.c -o shell.exe


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


int main(void)
{
	char *shellcode = "%s";
	DWORD why_must_this_variable;
	BOOL ret = VirtualProtect (shellcode, strlen(shellcode),
	PAGE_EXECUTE_READWRITE, &why_must_this_variable);

	if (!ret) {
		printf ("VirtualProtect");
		return EXIT_FAILURE;
	}


	((void (*)(void))shellcode)();
	return EXIT_SUCCESS;
}

		""" % ( strftime("%d/%m/%Y"), strftime("%H:%M:%S"), shellcode)

# For different os.
    else:
        db = """//Project : https://github.com/roissy/l0l
//This file created with l0l ..
//%s - %s
//Compile : g++ -fno-stack-protector -z execstack shell.cpp -o shell

unsigned char shellcode[] = "%s";

int main(){
	int (*func)() = (int(*)())shellcode;
	func();
}

		""" % (strftime("%d/%m/%Y"), strftime("%H:%M:%S"), shellcode)


    logs( db, "cpp")



