#include <iostream>
#include "rlutil.h"
using namespace std;

int main(int argc, char* argv[]){

do{

    int control, i;
    rlutil::resetColor(); rlutil::setColor(7);
    printf("Enter number ->");
    cin >> control;

    if(control > 8191){

        cout << "Max 8191 :C" << endl;

    }

    else if(control == 0){
        printf("\nmokoko .d\n");
        exit(0);
    }
    else{

        for(i=0;i<=control;i++){
            cout << "Color digit:" << i << endl;
            rlutil::setColor(i);
        }

    }

}while(1);

    rlutil::setColor(7);
    return 0;
}
