#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        LL ax, ay, bx, by, cx, cy; cin>>ax>>ay>>bx>>by>>cx>>cy;
        LL len = abs(ax-bx), width = abs(ay-by);/// length of lines
        LL dx, dy;
        LL area = abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
        (bx > ax) ? dx = cx - len : dx = cx + len;
        (by > ay) ? dy = cy - width : dy = cy + width;
        printf("Case %d: %d %d %d\n", t, dx, dy, area);
    }
}
