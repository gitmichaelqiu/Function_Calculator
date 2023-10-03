#include <iostream>
#include <cmath>
#include <string>
#include "Resource/fraction.h"
#include "Resource/function.h"
#include "Resource/fpoint.h"
using namespace frct;
#define FR fraction

#define AUTHORINFO "Author: MickyMike\nProhibit reproduce without permission!\n"
/* ------------------------------------------ */
#define VERSIONINFO "Version: v3.0\n"
#define UPDATEDATE "Update Date: 02 September 2023\n"
#define SUPPORTTYPE "Support Function:\n\t1\tLinear Function\n\t2\tQuadratic Function\n"
/* ------------------------------------------ */

int main(){
    printf("Welcome to function calculator!\nThis programme is coded by MickyMike.\n");
    printf(VERSIONINFO);
    printf("-----mode-----\ninput function type (input 505 to open help page): m\b");
    int mode;
    cin >> mode;
    cin.get();

    if (1 == mode)
        fnc::linear();
    else if (2 == mode)
        fnc::quadratic();
    else if (505 == mode){
        printf("-----help-----\n");
        printf(VERSIONINFO);
        printf(UPDATEDATE);
        printf(SUPPORTTYPE);
        printf(AUTHORINFO);
    }
    else{
        printf("INVALID INPUT!!!\n");
        printf("TYPE 505 TO OPEN THE HELP PAGE!\n");
        return 0;
    }
}