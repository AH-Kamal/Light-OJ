#include <bits/stdc++.h>
using namespace std;
#define     pb  push_back

vector<int> lps;

void createLPS(string pat)
{
    lps.pb(0);
    int i = 0, j = 1;
    for ( ; pat[j]; ){
        if (pat[i] == pat[j]){
            lps.pb(i+1);
            ++i, ++j;
        }
        else{
            if (i != 0) i = lps[i-1];
            else {
                ++j;
                lps.pb(0);
            }
        }
    }
}

int main(){
    int sz, T; cin>>T;
    string text, pat;
    for (int t = 1; t <= T; t++){
        cin>>text;
        pat = text;
        reverse(pat.begin(), pat.end());
        pat += '#' + text;

        createLPS(pat);
        int sz = text.size();
        int total = 2*sz - lps[lps.size()-1];
        printf("Case %d: %d\n", t, total);

        lps.clear();
    }
}

