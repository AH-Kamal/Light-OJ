#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        LL ax, ay, bx, by, cx, cy, dx, dy; cin>>ax>>ay>>bx>>by>>cx>>cy;
        LL len = abs(ax-bx), width = abs(ay-by);/// length of lines
        LL area = abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
        if(bx > ax) dx = cx - len;
        else dx = cx + len;
        if(by > ay) dy = cy - width;
        else dy = cy + width;
        printf("Case %d: %d %d %d\n", t, dx, dy, area);
    }
}
