// Linux x86

else if(!strcmp(str, "linux86/exec")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x86";
    _option = "exec";
}

else if(!strcmp(str, "linux86/download&execute")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 3;
    _os = "linux_x86";
    _option = "download&exec";
}

else if(!strcmp(str, "linux86/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux_x86";
    _option = "bin_sh";
}

else if(!strcmp(str, "linux86/read")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x86";
    _option = "read";
}

else if(!strcmp(str, "linux86/chmod")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x86";
    _option = "chmod";
}

else if(!strcmp(str, "linux86/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x86";
    _option = "tcp_bind";
}

else if(!strcmp(str, "linux86/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "linux_x86";
    _option = "reverse_tcp";
}

else if(!strcmp(str, "linux86/cd_eject")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux_x86";
    _option = "cd_eject";
}

// Linux x64

else if(!strcmp(str, "linux64/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux_x64";
    _option = "bin_sh";
}

else if(!strcmp(str, "linux64/read")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x64";
    _option = "read";
}

else if(!strcmp(str, "linux64/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_x64";
    _option = "tcp_bind";
}

else if(!strcmp(str, "linux64/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "linux_x64";
    _option = "reverse_tcp";
}

// Linux x86_64

else if(!strcmp(str, "linux/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux";
    _option = "bin_sh";
}

else if(!strcmp(str, "linux/read")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux";
    _option = "read";
}

else if(!strcmp(str, "linux/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux";
    _option = "tcp_bind";
}

else if(!strcmp(str, "linux/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "linux";
    _option = "reverse_tcp";
}

// Linux ARM

else if(!strcmp(str, "linux_arm/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux_arm";
    _option = "bin_sh";
}

else if(!strcmp(str, "linux_arm/exec")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_arm";
    _option = "exec";
}

else if(!strcmp(str, "linux_arm/chmod")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_arm";
    _option = "chmod";
}

else if(!strcmp(str, "linux_arm/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 5;
    _os = "linux_arm";
    _option = "reverse_tcp";
}

// Linux MIPS

else if(!strcmp(str, "linux_mips/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "linux_mips";
    _option = "bin_sh";
}

else if(!strcmp(str, "linux_mips/chmod")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_mips";
    _option = "chmod";
}

else if(!strcmp(str, "linux_mips/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "linux_mips";
    _option = "tcp_bind";
}

// Solaris x86

else if(!strcmp(str, "solarisx86/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "solarisx86";
    _option = "bin_sh";
}

else if(!strcmp(str, "solarisx86/read")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "solarisx86";
    _option = "read";
}

else if(!strcmp(str, "solarisx86/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "solarisx86";
    _option = "reverse_tcp";
}

else if(!strcmp(str, "solarisx86/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "solarisx86";
    _option = "tcp_bind";
}

//Windows

else if(!strcmp(str, "windows/exec")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "windows";
    _option = "exec";
}

else if(!strcmp(str, "windows/messagebox")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "windows";
    _option = "messagebox";
}

else if(!strcmp(str, "windows/download&execute")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 3;
    _os = "windows";
    _option = "downloadandexecute";
}

else if(!strcmp(str, "windows/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "windows";
    _option = "reverse_tcp";
}

else if(!strcmp(str, "windows/tcp_bind")){
    _usetxt = str;
    _type = "shellcode"; _os = "windows";
    _dif = 1;
    _os = "windows";
    _option = "tcp_bind";
}

// OSX x86

else if(!strcmp(str, "osx86/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "osx86";
    _option = "bin_sh";
}

else if(!strcmp(str, "osx86/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "osx86";
    _option = "tcp_bind";
}

else if(!strcmp(str, "osx86/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode"; 
	_os = "osx86";
    _dif = 2;
    _os = "osx86";
    _option = "reverse_tcp";
}

// OSX x64

else if(!strcmp(str, "osx64/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "osx64";
    _option = "bin_sh";
}

else if(!strcmp(str, "osx64/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "osx64";
    _option = "tcp_bind";
}

else if(!strcmp(str, "osx64/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "osx64";
    _option = "reverse_tcp";
}

// FreeBSD x86

else if(!strcmp(str, "FreeBSDx86/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "freebsd_x86";
    _option = "bin_sh";
}

else if(!strcmp(str, "FreeBSDx86/read")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "freebsd_x86";
    _option = "read";
}

else if(!strcmp(str, "FreeBSDx86/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "freebsd_x86";
    _option = "tcp_bind";
}

else if(!strcmp(str, "FreeBSDx86/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 5;
    _os = "freebsd_x86";
    _option = "reverse_tcp";
}

else if(!strcmp(str, "FreeBSDx86/reverse_tcp2")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 5;
    _os = "freebsd_x86";
    _option = "reverse_tcp2";
}

else if(!strcmp(str, "FreeBSDx86/exec")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "freebsd_x86";
    _option = "exec";
}

// FreeBSD x64

else if(!strcmp(str, "FreeBSDx64/binsh")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 4;
    _os = "freebsd_x64";
    _option = "bin_sh";
}

else if(!strcmp(str, "FreeBSDx64/tcp_bind")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "freebsd_x64";
    _option = "tcp_bind";
}

else if(!strcmp(str, "FreeBSDx64/reverse_tcp")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 2;
    _os = "freebsd_x64";
    _option = "reverse_tcp";
}

else if(!strcmp(str, "FreeBSDx64/exec")){
    _usetxt = str;
    _type = "shellcode";
    _dif = 1;
    _os = "freebsd_x64";
    _option = "exec";
}
