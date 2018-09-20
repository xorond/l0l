do{
    string shellcodeInput, controller;
    char *_string2, *_string3;

    blue();
	cout << "l0l";
    gray(); 
	cout << ":";
    white();
	cout << "shellcode(";
    red();
	cout << _usetxt;
    white();
	cout << ")";
    blue();
	cout << " > ";
    white();
	getline(cin, shellcodeInput);

    char *usecmd = strdup(shellcodeInput.c_str());
    char *usecmd2 = strdup(shellcodeInput.c_str());
    char *usecmd3 = strdup(shellcodeInput.c_str());

    strcpy(usecmd2,usecmd); 
    strtok(usecmd2, " "); 
    string modulen = str;

    if (strlen(usecmd) == 0 || usecmd[0] == '\r' || usecmd[0] == '\n');
    
    else if (!strcmp(usecmd, "back")){
        goto x;
    }
    else if (!strcmp(usecmd, "help")){
        shellcodeHelp();
    }
    else if (!strcmp(usecmd,"banner")){
        banner();
    }
    else if (!strcmp(usecmd,"exit") || cin.eof()){
        closeApp();
    }
    else if (!strcmp(usecmd, "clear")){
        clear();
    }
    else if (!strcmp(usecmd2,"os")){
        white();
        _string2 =  shorter(usecmd,3);
        if (usecmd[3] == '\0'){
            osCommand();
        } else { 
            system(_string2);
        }
        putchar('\n');
    }
    else if(!strcmp(usecmd, "show _optionons")){
        green();
        cout <<
                "\n\tModule _optionons (" << modulen << "):\n\n"
                "\t\tName\t" << "\tDescription" << "\t\tCurrent Setting\n"
                "\t\t----\t" "\t-----------\t" << "\t---------------\n";

       if(_option == "exec"){
            cout <<
                    "\t\tcommand\t" <<  "\tCommand to execute\t" << args1 << "\n\n";
       }
       else if(_option == "download&exec" || _option == "downloadandexecute"){
            cout <<
                    "\t\tlink\t" <<  "\tSource to download exe\t" << args1 << "\n\n";
       }
       else if(_option == "read" || _option == "chmod"){
            cout <<
                    "\t\tfile\t" <<  "\tFile name&path\t\t" << args1 << "\n\n";
       }
       else if(_option == "tcp_bind"){
            cout <<
                    "\t\tport\t" <<  "\tConnect PORT\t\t" << args1 << "\n\n";
       }
       else if(_option == "reverse_tcp" || _option == "reverse_tcp2"){
            cout <<
                    "\t\thost\t" <<  "\tConnect HOST\t\t" << args1 << "\n"
                    "\t\tport\t" <<  "\tConnect PORT\t\t" << args2 << "\n\n";
       }
       else if(_option == "messagebox"){
            cout <<
                    "\t\tmessage\t" <<  "\tMessage Box Text\t" << args1 << "\n\n";
       }
       else{ cout << "\t\tNo _optionon. Just use generate.\n\n"; }

    }
    else if (!strcmp(usecmd2, "set")){
        white();
        _string2 = shorter(usecmd2,4);
        if (_option == "exec"){
            if (_string2[0] == 'c' && _string2[1] == 'o' && _string2[2] == 'm' && _string2[3] == 'm' && _string2[4] == 'a' && _string2[5] == 'n' && _string2[6] == 'd' && _string2[7] == ' ' ){
                _string3 = shorter(_string2,8);
                args1 = _string3;
                cout << "\ncommand => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if (_option == "download&exec" || _option == "downloadandexecute"){
            if (_string2[0] == 'l' && _string2[1] == 'i' && _string2[2] == 'n' && _string2[3] == 'k' && _string2[4] == ' ' ){
                _string3 = shorter(_string2,5);
                args1 = _string3;
                cout << "\nlink => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "read" || _option == "chmod"){
            if(_string2[0] == 'f' && _string2[1] == 'i' && _string2[2] == 'l' && _string2[3] == 'e' && _string2[4] == ' ' ){
                _string3 = shorter(_string2,5);
                args1 = _string3;
                cout << "\nfile => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "tcp_bind"){
            if(_string2[0] == 'p' && _string2[1] == 'o' && _string2[2] == 'r' && _string2[3] == 't' && _string2[4] == ' '){
                _string3 = shorter(_string2,5);
                args1 = _string3;
                cout << "\nport => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "reverse_tcp" || _option == "reverse_tcp2"){
            if(_string2[0] == 'h' && _string2[1] == 'o' && _string2[2] == 's' && _string2[3] == 't' && _string2[4] == ' ' ){
                _string3 = shorter(_string2,5);
                args1 = _string3;
                cout << "\nhost => " << _string3 << "\n\n";
            }
            else if(_string2[0] == 'p' && _string2[1] == 'o' && _string2[2] == 'r' && _string2[3] == 't' && _string2[4] == ' '){
                _string3 = shorter(_string2,5);
                args2 = _string3;
                cout << "\nport => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "messagebox"){

            if(_string2[0] == 'm' && _string2[1] == 'e' && _string2[2] == 's' && _string2[3] == 's' && _string2[4] == 'a' && _string2[5] == 'g' && _string2[6] == 'e' && _string2[7] == ' ' ){
                _string3 = shorter(_string2,8);
                args1 = _string3;
                cout << "\nmessage => " << _string3 << "\n\n";
            } else { red(); cout << "This _optionon is not available.\n"; }
       }
    }
    else if(!strcmp(usecmd2, "unset")){
        _string2 = shorter(usecmd2,6);
        if(_option == "exec"){
            if( _string2[0] == 'c' && _string2[1] == 'o' && _string2[2] == 'm' && _string2[3] == 'm' && _string2[4] == 'a' && _string2[5] == 'n' && _string2[6] == 'd' ){
                args1 = "None";
            }
            else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "download&exec" || _option == "downloadandexecute"){
            if( _string2[0] == 'l' && _string2[1] == 'i' && _string2[2] == 'n' && _string2[3] == 'k' ){
                args1 = "None";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "read" || _option == "chmod"){
            if( _string2[0] == 'f' && _string2[1] == 'i' && _string2[2] == 'l' && _string2[3] == 'e' ){
                args1 = "None";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "tcp_bind"){
            if(_string2[0] == 'p' && _string2[1] == 'o' && _string2[2] == 'r' && _string2[3] == 't' ){
                args1 = "None";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "reverse_tcp" || _option == "reverse_tcp2"){
            if( _string2[0] == 'h' && _string2[1] == 'o' && _string2[2] == 's' && _string2[3] == 't' ) {
                args1 = "None";
            }
            else if(_string2[0] == 'p' && _string2[1] == 'o' && _string2[2] == 'r' && _string2[3] == 't' ){
                args2 = "None";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
        else if(_option == "messagebox"){
            if( _string2[0] == 'm' && _string2[1] == 'e' && _string2[2] == 's' && _string2[3] == 's' && _string2[4] == 'a' && _string2[5] == 'g' && _string2[6] == 'e' ){
                args1 = "None";
            } else { red(); cout << "This _optionon is not available.\n"; }
        }
    }
    else if(!strcmp(usecmd, "generate")){
        white();
        if(_dif == 1){
            if(args1 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
            else{ genshellcode(_dif, _os, _option, args1, args2); }
        }
        else if(_dif == 2){
            if(args1 == "None" || args2 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
            else{ genshellcode(_dif, _os, _option, args1, args2); }
        }
        else if(_dif == 3){
            if(args1 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
            else{ genshellcode(_dif, _os, _option, args1, args2); }
        }
        else if(_dif == 4){ genshellcode(_dif, _os, _option, args1, args2); }
        else if(_dif == 5){
            if(args1 == "None" || args2 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
            else{ genshellcode(2, _os, _option, args2, args1); }
        }

    }
    else if(!strcmp(usecmd2, "output")){
        white();
        _string2 = shorter(usecmd2,7);
        controller = _string2;

        if(_string2[0] == '\0'){
            outputCommand();
        }else{

            if(controller == "exe" || controller == "c" || controller == "cpp" || controller == "txt" || controller == "raw" || controller == "py" ){

                if(_dif == 1){
                    if(args1 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
                    else{

                        if(_string2[0] == 'e' && _string2[1] == 'x' && _string2[2] == 'e' && _string2[3] == '\0')
                            output(_dif, "exe", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == '\0')
                            output(_dif, "c", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == 'p' && _string2[2] == 'p' && _string2[3] == '\0')
                            output(_dif, "cpp", _os, _option, args1, args2);
                        else if(_string2[0] == 't' && _string2[1] == 'x' && _string2[2] == 't' && _string2[3] == '\0')
                            output(_dif, "txt", _os, _option, args1, args2);
                        else if(_string2[0] == 'r' && _string2[1] == 'a' && _string2[2] == 'w' && _string2[3] == '\0')
                            output(_dif, "raw", _os, _option, args1, args2);
                        else if(_string2[0] == 'p' && _string2[1] == 'y' && _string2[2] == '\0')
                            output(_dif, "py", _os, _option, args1, args2);

                    }

                }
                else if(_dif == 2){
                    if(args1 == "None" || args2 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
                    else{

                        if(_string2[0] == 'e' && _string2[1] == 'x' && _string2[2] == 'e' && _string2[3] == '\0')
                            output(_dif, "exe", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == '\0')
                            output(_dif, "c", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == 'p' && _string2[2] == 'p' && _string2[3] == '\0')
                            output(_dif, "cpp", _os, _option, args1, args2);
                        else if(_string2[0] == 't' && _string2[1] == 'x' && _string2[2] == 't' && _string2[3] == '\0')
                            output(_dif, "txt", _os, _option, args1, args2);
                        else if(_string2[0] == 'r' && _string2[1] == 'a' && _string2[2] == 'w' && _string2[3] == '\0')
                            output(_dif, "raw", _os, _option, args1, args2);
                        else if(_string2[0] == 'p' && _string2[1] == 'y' && _string2[2] == '\0')
                            output(_dif, "py", _os, _option, args1, args2);

                    }

                }
                else if(_dif == 3){
                    if(args1 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
                    else{

                        if(_string2[0] == 'e' && _string2[1] == 'x' && _string2[2] == 'e' && _string2[3] == '\0')
                            output(_dif, "exe", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == '\0')
                            output(_dif, "c", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == 'p' && _string2[2] == 'p' && _string2[3] == '\0')
                            output(_dif, "cpp", _os, _option, args1, args2);
                        else if(_string2[0] == 't' && _string2[1] == 'x' && _string2[2] == 't' && _string2[3] == '\0')
                            output(_dif, "txt", _os, _option, args1, args2);
                        else if(_string2[0] == 'r' && _string2[1] == 'a' && _string2[2] == 'w' && _string2[3] == '\0')
                            output(_dif, "raw", _os, _option, args1, args2);
                        else if(_string2[0] == 'p' && _string2[1] == 'y' && _string2[2] == '\0')
                            output(_dif, "py", _os, _option, args1, args2);

                     }
                }
                else if(_dif == 4){

                        if(_string2[0] == 'e' && _string2[1] == 'x' && _string2[2] == 'e' && _string2[3] == '\0')
                            output(_dif, "exe", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == '\0')
                            output(_dif, "c", _os, _option, args1, args2);
                        else if(_string2[0] == 'c' && _string2[1] == 'p' && _string2[2] == 'p' && _string2[3] == '\0')
                            output(_dif, "cpp", _os, _option, args1, args2);
                        else if(_string2[0] == 't' && _string2[1] == 'x' && _string2[2] == 't' && _string2[3] == '\0')
                            output(_dif, "txt", _os, _option, args1, args2);
                        else if(_string2[0] == 'r' && _string2[1] == 'a' && _string2[2] == 'w' && _string2[3] == '\0')
                            output(_dif, "raw", _os, _option, args1, args2);
                        else if(_string2[0] == 'p' && _string2[1] == 'y' && _string2[2] == '\0')
                            output(_dif, "py", _os, _option, args1, args2);

                }
                else if(_dif == 5){
                    if(args1 == "None" || args2 == "None"){ cout << "\nSet _optionon before generate shellcode.\n\n"; }
                    else{

                        if(_string2[0] == 'e' && _string2[1] == 'x' && _string2[2] == 'e' && _string2[3] == '\0')
                            output(2, "exe", _os, _option, args2, args1);
                        else if(_string2[0] == 'c' && _string2[1] == '\0')
                            output(2, "c", _os, _option, args2, args1);
                        else if(_string2[0] == 'c' && _string2[1] == 'p' && _string2[2] == 'p' && _string2[3] == '\0')
                            output(2, "cpp", _os, _option, args2, args1);
                        else if(_string2[0] == 't' && _string2[1] == 'x' && _string2[2] == 't' && _string2[3] == '\0')
                            output(2, "txt", _os, _option, args2, args1);
                        else if(_string2[0] == 'r' && _string2[1] == 'a' && _string2[2] == 'w' && _string2[3] == '\0')
                            output(2, "raw", _os, _option, args2, args1);
                        else if(_string2[0] == 'p' && _string2[1] == 'y' && _string2[2] == '\0')
                            output(2, "py", _os, _option, args2, args1);

                    }

                }

            }

        }

    }
    else{
        red(); 
		printf("[-] Unknown command: %s\n", usecmd);
    }

}while(1);
