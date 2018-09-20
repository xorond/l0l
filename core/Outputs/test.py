# Test

from core.database.generator import *

from core.Outputs.C import *
from core.Outputs.Cplusplus import *
from core.Outputs.Dll import *
from core.Outputs.exe import *
from core.Outputs.python import *
from core.Outputs.txt import *




shellcode = generator( "windows", "messagebox", "asdasdyrkrykrk")

ExeFile(shellcode, "windows")



#RawFile(shellcode)
