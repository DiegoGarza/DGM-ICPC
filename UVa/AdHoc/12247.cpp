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

bool pComp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first > b.first;
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int a, b, c, x, y;
    while(scanf("%d %d %d %d %d", &a, &b, &c, &x, &y)){
        if(!(a||b||c||x||y)){
            break;
        }
        vector<pair<int, int> > v(5);
        vector<int> used(53, 0);
        v[0] = make_pair(a, 1);
        used[a] = 1;
        v[1] = make_pair(b, 1);
        used[b] = 1;
        v[2] = make_pair(c, 1);
        used[c] = 1;
        v[3] = make_pair(x, 0);
        used[x] = 1;
        v[4] = make_pair(y, 0);
        used[y] = 1;
        sort(v.begin(), v.end(), pComp);
        int losses = 0;
        while(v.size() != 1){
            if(v[0].second == 1){
                int i = 0;
                if(v[1].second == 1){
                    i++;
                }
                v.erase(v.begin()+i, v.begin()+i+1);
                while(v[i].second != 0){
                    i++;
                }
                v.erase(v.begin()+i, v.begin()+i+1);
                losses++;
            }
            else{
                v.erase(v.begin(), v.begin()+1);
                int i = v.size() - 1;
                while(v[i].second != 1){
                    i--;
                }
                v.erase(v.begin()+i, v.begin()+i+1);
            }
            // F(i, v.size()){
            //     printf("%d %d", v[i].first, v[i].second);
            // }
            // printf("\n");
        }
        if(losses == 2){
            printf("-1\n");
        }
        else if(losses == 0){
            int i = 1;
            while(used[i] == 1){
                i++;
            }
            printf("%d\n", i);
        }
        else{
            while(used[v[0].first] == 1 && v[0].first <= 52){
                v[0].first++;
            }
            if(v[0].first == 53){
                printf("-1\n");
            }
            else{
                printf("%d\n", v[0].first);
            }
        }
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
