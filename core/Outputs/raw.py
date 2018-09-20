from header import *


def RawFile( shellcode):
    shellcode = unhexlify(shellcode.replace("\\x", ""))
    logs( shellcode, None)
