#pragma once
#include <cmath>
#include <iostream>
using namespace std;

const int PRECISION = 100000000;

int gcd(int n, int m){
    if (m == 0)
        return n;
    else
        return gcd(m, n%m);
}

namespace frct{
    struct fraction{
        int up, down;

        fraction(){};
        fraction(int _up, int _down){
            this -> up = _up;
            this -> down = _down;
        }

        void simp(){
            if (down < 0){
                up *= -1;
                down *= -1;
            }

            if (up == 0)
                down = 1;
            
            int _gcd = gcd(abs(up), abs(down));
            up /= _gcd;
            down /= _gcd;
        }

        void output(bool brckt = false){
            if (this->up < 0)
                printf("-");

            if (brckt && this->down != 1)
                printf("(");

            printf("%d", abs(this->up));
            if (this->down != 1){
                printf("/%d", this->down);
                if (brckt)
                    printf(")");
            }
        }

        bool canBeDec(){
            int n = this->down;
            for (int i=2; i <= n; i++)
                while (n%i == 0){
                    if (i != 2 && i != 5)
                        return false;
                    n /= i;
                }
            
            return true;
        }
    };

    void int_to_frct(int n, fraction &m){
        m.up = n;
        m.down = 1;
        m.simp();
    }

    void double_to_frct(double n, fraction &m){
        n *= PRECISION;
        m.up = n;
        m.down = PRECISION;
        m.simp();
    }

    bool operator==(fraction n, fraction m){
        n.simp(); m.simp();
        return n.up == m.up && n.down == m.down;
    }

    bool operator!=(fraction n, fraction m){
        return !(n == m);
    }

    fraction operator+(fraction n, fraction m){
        fraction ans;
        ans.up = n.up * m.down + m.up * n.down;
        ans.down = n.down * m.down;
        ans.simp();
        return ans;
    }

    fraction operator-(fraction n, fraction m){
        fraction ans;
        ans.up = n.up * m.down - m.up * n.down;
        ans.down = n.down * m.down;
        ans.simp();
        return ans;
    }

    fraction operator*(fraction n, fraction m){
        fraction ans;
        ans.up = n.up * m.up;
        ans.down = n.down * m.down;
        ans.simp();
        return ans;
    }

    fraction operator/(fraction n, fraction m){
        fraction ans;
        ans.up = n.up*m.down;
        ans.down = n.down*m.up;
        ans.simp();
        return ans;
    }

    struct fxy{
        fraction x, y;
    };

    bool operator==(fxy n, fxy m){
        return n.x == m.x && n.y == m.y;
    }
    
    bool operator!=(fxy n, fxy m){
        return !(n == m);
    }

    fraction fabs(fraction n){
        fraction tmp = n;
        tmp.up = abs(tmp.up);
        return tmp;
    }

    struct fxyz{
        fraction x, y, z;
    };    
}