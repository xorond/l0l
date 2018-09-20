/*

 l0l - The Exploit Development Kit

 < Author: roissy >
 < Greetz: b3mb4m, ExitStars, musluman, Oguz Bektas (xorond), Hamit Abis >
 < Version: BETA >
 < License: MIT LICENSE >
 < Contact : roissy@protonmail.com > 

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

using namespace std;

#include "core/core.c"

int main(void)
{

    signal(SIGINT, ctrlcCatch);
    
    banner(); 
    
    do 
    {	x: 
		char *str;
        string mainInput="";
        
        blue();
        printf("l0l > ");

        white(); 
        getline(cin, mainInput);

        char* command = strdup(mainInput.c_str());
        strtok(command, " ");
        
        if (strlen(command) == 0 || command[0] == '\r' || command[0] == '\n');
        
        else if (!strcmp(command,"help")) {
            help();
        }

        else if (!strcmp(command,"banner")) {
            banner();
        }

        else if (!strcmp(command,"clear")) {
            clear();
        }

        else if (!strcmp(command,"exit") || cin.eof()) {
            closeApp();
        }

        else if (!strcmp(command, "use")) {
            
            int _dif; 
            string _usetxt, _type, _os, _option;
            str =  shorter(command,4);
            
            if(command[4] == '\0') {

                useCommand();

            } else {
				
                if(!strcmp(str, "inj")) {
                    _usetxt = str; 
                    _type = "injector";
                }
                
                else if(!strcmp(str, "encd")) { 
                    _usetxt = str; 
                    _type = "encoder"; 
                }

                #include "core/shellcodes/s_modules.cpp"

                #include "core/backdoors/b_modules.cpp"

                else {

                    red(); 
                    printf("[-] Unknown module: %s\n", str);
                    
                    goto x;
                }

                if (_type == "injector") {
                
                    #include "core/injectors/i_console.cpp"
                
                }

                else if (_type == "encoder") {
                
                    #include "core/encoders/e_console.cpp"
                
                }

                else if (_type == "shellcode") {
                
                    string args1 = "None", args2 = "None";
                    #include "core/shellcodes/s_console.cpp"
                
                }

                else if (_type == "backdoor") {

                    string parsermodule = _usetxt;
                    char* parsmodule = strdup(parsermodule.c_str());
                    parsermodule = shorter(parsmodule,10);

                    string lhost = "None", lport = "None";
                    #include "core/backdoors/b_console.cpp"
                
                }
            }
        }

        else if (!strcmp(command, "os")) {
        
            white();
            str = shorter(command,3);

            if(command[3] == '\0') {
                osCommand();
            } else {
                system(str);
            }

            putchar('\n');
        
        }

        else if (!strcmp(command,"show")) {
            
            str = shorter(command,5);
            
            if (command[6] == '\0') {

                showCommand();
            
            } else {

                green();

                if (!strcmp(str, "encoders")) {
                    encoderlist();
                } 
                
                else if (!strcmp(str, "injectors")) {
                    injectorList();
                } 
                
                else if (!strcmp(str, "shellcodes")) {
                    shellcodeList();
                } 
                
                else if (!strcmp(str, "backdoors")) {
                    backdoorList();
                } 
                
                else {
                    red(); 
                    printf("[-] Unknown type: %s\n", str);
                }

            }
		
		}
		
	else {
            
            red(); 
            printf("[-] Unknown command: %s\n", command);
        
	}

    } while(1);

    return 0;
}
