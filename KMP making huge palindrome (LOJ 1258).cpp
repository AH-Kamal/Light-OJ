#include <bits/stdc++.h>
using namespace std;
#define LIM 1000050


string text, pat;
int sz, lps[LIM], lps2[LIM];

void create_lps(){
    int i = 0, j;
    for(j = 1; j < sz; j++){
        if(pat[i] == pat[j]){
            lps[j] = i+1;
            i++;
        }
        else{
            while(1){
                if(i <= 0) break;
                i = lps[i-1];
                if(pat[i] == pat[j]){
                    lps[j] = i+1;
                    ++i;
                    break;
                }
            }
        }
    }
}

void check(){
    int i = 0, j;
    for(j = 0; j < sz; j++){
        if(pat[i] == text[j]){
            lps2[j] = i+1;
            i++;
        }
        else{
            while(1){
                if(i <= 0) break;
                i = lps[i-1];
                if(pat[i] == text[j]){
                    lps2[j] = i+1;
                    ++i;
                    break;
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        cin>>text;
        pat = text;
        reverse(pat.begin(), pat.end());
        sz = text.size();
        for(int i = 0; i <= sz; i++) lps[i] = 0;
        create_lps(); /// for pattern
        for(int i = 0; i <= sz; i++) lps2[i] = 0;
        check();
//        for(int i = 0; i < sz; i++) cout<<i<<"h "<<lps[i]<<' ';
//        cout<<"\n\n";
//        for(int i = 0; i < sz; i++) cout<<lps2[i]<<' ';
//        cout<<"\n\n";
        int matched = lps2[sz-1];
        //cout<<matched<<'\n';
        int notMatched = sz-matched;
        //cout<<(matched+(notMatched)*2)<<'\n';
        int res = (matched+(notMatched)*2);
        printf("Case %d: %d\n", t, res);
    }
}
