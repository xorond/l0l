void banner() {
    
    int _pshellcode = 48,
        _pencoders = 0,
	_pinjector = 0,
        _pbackdoors = 6,
        _pdifferentOs = 11;

    srand(time(NULL));
    int _r = rand() % 5 + 1 ;
    char _temp;
    FILE *_file;
    
    if(_r == 1) {
        _file = fopen("core/banner/logo1.txt","r");
    } 
    else if(_r == 2){
        _file = fopen("core/banner/logo2.txt", "r");
    }
    else if(_r == 3){
        _file = fopen("core/banner/logo3.txt", "r");
    }
    else if(_r == 4){
        _file = fopen("core/banner/logo4.txt", "r");
    }
    else if(_r == 5){
        _file = fopen("core/banner/logo5.txt", "r");
    }

    rlutil::setColor(12);
    
    while( (_temp = fgetc(_file)) != EOF )
        putchar(_temp);
		;
    
    fclose(_file);

    putchar('\n');

    rlutil::setColor(2);
    printf("        =[ l0l            -");
    rlutil::setColor(12);
    printf("  BETA                               ");
    rlutil::setColor(2);
    printf("]\n");

    printf(" + -- --=[ %d shellcode   -", _pshellcode);
    rlutil::setColor(12);
    printf("  %d Different OS                    ", _pdifferentOs);
    rlutil::setColor(2);
    printf("]\n");


    printf(" + -- --=[ %d encoders     -", _pencoders);
    rlutil::setColor(12);
    printf("  (Shellcodes/executable files)      ");
    rlutil::setColor(2);
    printf("]\n");


    printf(" + -- --=[ %d injector     -", _pinjector);
    rlutil::setColor(12);
    printf("  (PE,ELF,DLL,RAR,DEB etc...)        ");
    rlutil::setColor(2);
    printf("]\n");

    printf(" + -- --=[ %d backdoors    -", _pbackdoors);
    rlutil::setColor(12);
    printf("  (ReverseShell)                     ");
    rlutil::setColor(2);
    printf("]\n");

    printf(" + -- --=[ Open Source    :");
    rlutil::setColor(12);
    printf("  https://github.com/roissy/l0l      ");
    rlutil::setColor(2);
    printf("]\n\n");
    
}
