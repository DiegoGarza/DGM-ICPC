#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
    //STARTS
    int n = 0, m, intI, intI2;
    // int knap [1001][1000];
    vector<pair<int,pair<int, int> > > wc;

    cin>>m;
    cin.ignore();

    string s;
    int num;
    while(cin>>s) {
        int aux = 0, count = 0;
        for(int j = 0; j<s.length(); j++){
            if(count == 0 && s[j] == ','){
                istringstream ss(s.substr(aux, j));
                ss >> num;
                count++;
                aux = j + 1;
            }
            else if(count == 1 && s[j] == ','){
                istringstream ss(s.substr(aux, j - 1));
                ss >> intI;
                aux = j + 1;
            }
        }
        istringstream ss(s.substr(aux, s.length()));
        ss >> intI2;
        wc.push_back(make_pair(intI2, make_pair(intI, num)));
        n++;
    }
    sort(wc.begin(), wc.end());
    vector<vector <int> > knap(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(wc[i-1].first<=j){
                knap[i][j] = Max(knap[i-1][j], knap[i-1][j-wc[i-1].first] + wc[i-1].second.first);
            }
            else{
                knap[i][j] = knap[i-1][j];
            }
        }
    }

    vector<int> st;
    int i = n;
    int j = m;
    int t = 0;
    double ans = (double) knap[n][m];
    for(int i=n; i>0; i--){
        if(knap[i][j] > knap[i-1][j]){
            st.push_back(wc[i-1].second.second);
            t += wc[i-1].first;
            j -= wc[i-1].first;
            wc[i-1].second.second = -1;
        }
    }
    // for(int i=0; i<st.size(); i++){
    //     cout<<st[i]<<endl;
    // }
    int star;
    if(m > t){
        for(int i=0; i<wc.size(); i++){
            if(wc[i].second.second != -1){
                ans += (double) wc[i].second.first * (((double)m - (double) t) / (double) (wc[i].first));
                st.push_back(wc[i].second.second);
                star = wc[i].second.second;
                break;
            }
        }
    }
    cout<<(int)floor(ans)<<endl;
    sort(st.begin(), st.end());
    for(int i=0; i<st.size(); i++){
        if(i) cout<<",";
        if(star == st[i]) cout<<st[i]<<"*";
        else cout<<st[i];
    }
    cout<<endl;

    //END
    return 0;
}
