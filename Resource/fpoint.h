#pragma once
#include <iostream>
#include "fraction.h"
using namespace frct;
using namespace std;
#define FR fraction

void get_point(FR &ans, int lbn, char lbc){
    printf("point%d.%c = ", lbn, lbc);

    string ip;
    getline(cin, ip);
    
    bool frctMode = false, decMode=false, neg=false;
    double ip1=0, ip2=0;
    int decDig = 0;
    for (int i=0; i<ip.length(); i++){
        if (ip[i] == '/'){
            frctMode = true;
            continue;
        }

        if (ip[i] == '.'){
            decMode = true;
            continue;
        }

        if (ip[i] == '-')
        {
            neg = !neg;
            continue;
        }

        if (!frctMode){
            ip1 *= 10;
            ip1 += ip[i]-'0';
            if (decMode)
                ++decDig;
        }

        if (frctMode){
            ip2 *= 10;
            ip2 += ip[i]-'0';
        }
    }

    if (frctMode){
        ans.up = ip1;
        ans.down = ip2;
        ans.simp();
    }
    else{
        double tmp;
        if (decDig == 0){
            ans.up = ip1;
            ans.down = 1;
        }
        else{
            tmp = ip1;
            int tmp2 = pow(10, decDig);
            tmp /= tmp2;
            double_to_frct(tmp, ans);
        }
    }

    if (neg){
        ans.up = 0-ans.up;
        ans.simp();
    }
}