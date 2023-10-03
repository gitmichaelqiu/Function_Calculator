#pragma once
#include "fraction.h"
#define FR fraction
using namespace frct;

namespace unk{
    struct xy{
        double x, y;
    };

    bool operator==(xy n, xy m){
        return n.x == m.x && n.y == m.y;
    }
}

namespace slv{
    fxy ftwoUoneT(FR a1, FR b1, FR c1, FR a2, FR b2, FR c2){
        fxy ans;
        ans.x = (c1*b2 - c2*b1) / (a1*b2 - a2*b1);
        ans.y = (c1*a2 - c2*a1) / (b1*a2 - b2*a1);

        return ans;
    }

    // 求解三元一次方程组
    fxyz fthreeUoneT(FR a1, FR b1, FR c1, FR d1,
        FR a2, FR b2, FR c2, FR d2,
        FR a3, FR b3, FR c3, FR d3) {
        // 计算系数矩阵的行列式D
        FR D = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
        D.simp();
        
        if (D.up != 0) {
            // 计算将第一列替换为d1, d2, d3后的行列式Dx
            FR Dx = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
            
            // 计算将第二列替换为d1, d2, d3后的行列式Dy
            FR Dy = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
            
            // 计算将第三列替换为d1, d2, d3后的行列式Dz
            FR Dz = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);
            
            // 计算方程组的解
            FR x = Dx / D;
            FR y = Dy / D;
            FR z = Dz / D;
            
            fxyz xyz;
            xyz.x = x;
            xyz.y = y;
            xyz.z = z;
            
            return xyz;
        } else {
            // 方程组无解或有无穷多个解
            fxyz xyz;
            FR fZero;
            fZero.up = 0;
            fZero.down = 1;
            xyz.x = xyz.y = xyz.z = fZero;
            
            return xyz;
        }
    }
}