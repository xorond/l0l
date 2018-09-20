// Shellcode Functions..

void genshellcode(int argp, string os, string type, string a1, string a2)
{
    string session;

    session="from core.database.generator import *\n";
    session += "input = \"";
    session += a1;
    session += "\"\n";
    session += "os = \"";
    session += os;
    session += "\"\n";
    session += "shelltype = \"";
    session += type;
    session += "\"\n\n";

    if( argp == 1 ){
        session += "shellcode = generator( os, shelltype, input)\n";
    }
    else if( argp == 2 ){

        session += "input2 = \"";
        session += a2;
        session += "\"\n";

        session += "shellcode = generator( os, shelltype, input, input2)\n";

    }
    else if( argp == 3 ){

        session += "input2 = \"";
        session += a2;
        session += "\"\n";
        session += "shellcode = generator( os, shelltype, argv=input, argv2=input2)\n";

    }
    else if( argp == 4 ){

        session += "shellcode = generator( os, shelltype )\n";

    }
        session +=
                    "b = shellcode.split(\"\\\\\")\n"
                    "x = 1\n"
                    "p = (len(b)/15)+1\n"
                    "loplop = 1\n"
                    "for i in range((len(b)/15)+1):\n"
                        "\tj = b[x:x+15]\n"
                        "\tline = \"\"\n"
                        "\tfor k in range(len(j)):\n"
                            "\t\tline += \"\\\\\"+j[k]\n"
                        "\tif p != loplop:\n"
                            "\t\tprint '\t\"'+line+'\"+'\n"
                        "\telse:\n"
                            "\t\tprint '\t\"'+line+'\";'\n"
                        "\tx += 15\n"
                        "\tloplop += 1";


    char filename[] = "session.py";
    std::ofstream outfile (filename);
    outfile << session;
    outfile.close();

    cout << "\n";

    #ifdef nt
        system("python session.py");
    #else
        system("python2 session.py");
    #endif


    putchar('\n');
    remove("session.py");


}

void output(int argp, string outype, string os, string type, string a1, string a2)
{
    string session;

    session="from core.database.generator import *\n"
            "from core.Outputs.C import *\n"
            "from core.Outputs.Cplusplus import *\n"
            "from core.Outputs.Dll import *\n"
            "from core.Outputs.exe import *\n"
            "from core.Outputs.python import *\n"
            "from core.Outputs.txt import *\n\n";

    session += "input = \"";
    session += a1;
    session += "\"\n";
    session += "os = \"";
    session += os;
    session += "\"\n";
    session += "shelltype = \"";
    session += type;
    session += "\"\n\n";

    if( argp == 1 ){
        session += "shellcode = generator( os, shelltype, input)\n";
    }
    else if( argp == 2 ){

        session += "input2 = \"";
        session += a2;
        session += "\"\n";
        session += "shellcode = generator( os, shelltype, input, input2)\n";

    }
    else if( argp == 3 ){

        session += "input2 = \"";
        session += a2;
        session += "\"\n";
        session += "shellcode = generator( os, shelltype, argv=input, argv2=input2)\n";

    }
    else if( argp == 4 ){

        session += "shellcode = generator( os, shelltype )\n\n";

    }


    if( os == "linux_x86" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "linux_x64" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "linux" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "linux_arm" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "linux_mips" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "osx86" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "osx64" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "freebsd_x86" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "freebsd_x64" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    else if( os == "windows" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=True)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }
            else if( outype == "dll" ){  session += "DllFile( shellcode )\n"; }

            //..
        }

    }

    else if( os == "solarisx86" ){

        if( outype == "exe" ){
            session += "ExeFile( shellcode, OS=\"";
            session += os;
            session += "\")\n";
        }
        else{

            if( outype == "c" ){  session += "CFile( shellcode )\n"; }
            else if( outype == "cpp" ){  session += "CplusplusFile( shellcode, win=False)\n"; }
            else if( outype == "txt" ){  session += "TxtFile( shellcode )\n"; }
            else if( outype == "raw" ){  session += "RawFile( shellcode )\n"; }
            else if( outype == "py" ){  session += "PyFile( shellcode )\n"; }

        }

    }

    green();

    char filename[] = "session.py";
    std::ofstream outfile(filename);
    outfile << session;
    outfile.close();

    putchar('\n');

    #ifdef nt
        system("python session.py");
    #else
        system("python2 session.py");
    #endif
	
    putchar('\n');
    
	remove("session.py");
	
}
