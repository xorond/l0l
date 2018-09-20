do 
{
    string encoderInput;
    char *str2;

    blue(); 
    cout << "l0l";
    gray();
    cout << ":";
    white();
    cout << "encoder(";
    red();
    cout << _usetxt;
    white();
    cout << ")";
    blue();
    cout << " > ";
    white();
    getline(cin, encoderInput);
    
    char* usecmd = strdup(encoderInput.c_str());

    if (strlen(usecmd) == 0 || usecmd[0] == '\r' || usecmd[0] == '\n');

    else if (!strcmp(usecmd, "back")) {
        goto x;
    }
    else if (!strcmp(usecmd, "help")) {
        injectorHelp();
    }
    else if (!strcmp(usecmd,"banner")) {
        banner();
    }
    else if (!strcmp(usecmd,"exit") || cin.eof()) {
        closeApp();
    }
    else if (!strcmp(usecmd, "clear")) {
        clear();
    }
    else if (!strcmp(usecmd,"os")) {
        white();
        str2 =  shorter(usecmd,3);
        if (usecmd[3] == '\0'){
            osCommand();
        } else {
            system(str2);
        }
        putchar('\n');
    }
    else {
        red(); printf("[-] Unknown command: %s\n", usecmd);
    }
    
} while(1);
