from time import strftime
from logger import logs
from binascii import unhexlify

def RawFile( shellcode):
    sc = unhexlify(shellcode.replace("\\x", ""))
    logs( sc, None)
