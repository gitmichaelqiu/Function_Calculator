#pragma once
#include "fraction.h"
#include "fpoint.h"
#include "fmath.h"
#include <iostream>
using namespace std;
using namespace frct;
#define FR fraction

namespace fnc{
    void linear(){
        printf("-----linear------\n");
        printf("-----input-----\n");
        FR p1x, p1y, p2x, p2y;
        FR FRone;
        FRone.up = 1; FRone.down = 1;

        // input
        get_point(p1x, 1, 'x');
        get_point(p1y, 1, 'y');
        get_point(p2x, 2, 'x');
        get_point(p2y, 2, 'y');

        // solve
        fxy kb;
        kb = slv::ftwoUoneT(p1x, FRone, p1y, p2x, FRone, p2y);
        
        // output
        printf("-----function-----\n");
        if (kb.x.up == 0 && kb.y.up == 0){
            printf("(");
            p1x.output();
            printf(", ");
            p1y.output();
            printf(")\n");
            return; 
        }
        else if (p1y == p2y){
            printf("y = ");
            p1y.output();
            printf("\n");
            return;
        }
        else if (p1x == p2x){
            printf("x = ");
            p1x.output();
            printf("\n");
            return;
        }

        printf("k = ");
        kb.x.output();
        if (kb.x.canBeDec() && kb.x.down != 1)
            cout << " = " << (double)kb.x.up/kb.x.down;

        printf(", b = ");
        kb.y.output();
        if (kb.y.canBeDec() && kb.y.down != 1)
            cout << " = " << (double)kb.y.up/kb.y.down;

        printf("\n");
        return;
    }

    FR symPoint(FR ori, FR mid){
        FR FRtwo;
        FRtwo.up = 2;
        FRtwo.down = 1;
        FR tmp = ori - mid;

        if (tmp.up > 0)
            return mid - fabs(tmp);
        else
            return mid + fabs(tmp);
    }

    void quadratic(){
        printf("-----quadratic-----\n");
        printf("tips: input one same point twice to mark the vertex.\n");
        printf("-----input------\n");

        fxy p1, p2, p3;
        get_point(p1.x, 1, 'x'); get_point(p1.y, 1, 'y');
        get_point(p2.x, 2, 'x'); get_point(p2.y, 2, 'y');
        get_point(p3.x, 3, 'x'); get_point(p3.y, 3, 'y');

        FR FRone;
        FRone.up = 1; FRone.down = 1;
        fxyz abc;
        
        if (p1 != p2 && p2 != p3)
            abc = slv::fthreeUoneT(p1.x*p1.x, p1.x, FRone, p1.y,
            p2.x*p2.x, p2.x, FRone, p2.y,
            p3.x*p3.x, p3.x, FRone, p3.y);
        else{
            FR FRzero;
            FRzero.up = 0; FRzero.down = 1;
            FR sym;
            if (p1 == p2){
                sym = symPoint(p3.x, p1.x);
                abc = slv::fthreeUoneT(p1.x*p1.x, p1.x, FRone, p1.y,
                p3.x*p3.x, p3.x, FRone, p3.y,
                sym*sym, sym, FRone, p3.y);
            }
            else if (p1 == p3){
                sym = symPoint(p2.x, p1.x);
                abc = slv::fthreeUoneT(p1.x*p1.x, p1.x, FRone, p1.y,
                p2.x*p2.x, p2.x, FRone, p2.y,
                sym*sym, sym, FRone, p2.y);
            }
            else if (p2 == p3){
                sym = symPoint(p1.x, p2.x);
                abc = slv::fthreeUoneT(p2.x*p1.x, p2.x, FRone, p2.y,
                p1.x*p1.x, p1.x, FRone, p1.y,
                sym*sym, sym, FRone, p1.y);
            }
        }

        FR FRzero;
        FRzero.up = 0; FRzero.down = 1;
        if (abc.x == FRzero && abc.y == FRzero && abc.z == FRzero){
            printf("This quadratic function DOES NOT EXIST!\n");
            return;
        }

        printf("y = ");
        
        if (abc.x.up == -1 && abc.x.down == 1)
            printf("-");
        else if (!(abc.x.up == 1 && abc.x.down == 1))
            abc.x.output(true);

        printf("x^2 ");

        if (abc.y.up < 0){
            printf("- ");
            abc.y = fabs(abc.y);

            if (!(abc.y.up == 1 && abc.y.down == 1))
                abc.y.output(true);
        }
        else if (!(abc.y.up == 1 && abc.y.down == 1))
        {
            printf("+ ");
            abc.y.output(true);
        }

        printf("x ");

        if (abc.z.up < 0){
            printf("- ");
            abc.z = fabs(abc.z);
            abc.z.output();
        }
        else{
            printf("+ ");
            abc.z.output();
        }
        printf("\n");
    }   
}