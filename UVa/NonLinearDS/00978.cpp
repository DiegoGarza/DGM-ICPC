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
#include <iterator>
#include <fstream>

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){

    //STARTS
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int bg, greenSize, blueSize, in;
        scanf("%d %d %d", &bg, &greenSize, &blueSize);
        multiset<int, greater<int> > green, blue;
        while(greenSize--){
            scanf("%d", &in);
            green.insert(in);
        }
        while(blueSize--){
            scanf("%d", &in);
            blue.insert(in);
        }
        while(!green.empty() && !blue.empty()){
            vi gFighters, bFighters;
            int aBg = Min(bg, Min((int) green.size(), (int) blue.size()));
            for(int i=0; i<aBg; i++){
                int gFighter, bFighter;
                gFighter = *(green.begin());
                bFighter = *(blue.begin());
                green.erase(green.begin());
                blue.erase(blue.begin());
                if(gFighter > bFighter) gFighters.push_back(gFighter - bFighter);
                else if(bFighter > gFighter) bFighters.push_back(bFighter - gFighter);
            }
            F(i, gFighters.size()){
                green.insert(gFighters[i]);
            }
            F(i, bFighters.size()){
                blue.insert(bFighters[i]);
            }
        }
        multiset<int, greater<int> >::iterator it;
        if(!green.empty()){
            printf("green wins\n");
            it = green.begin();
            while(it != green.end()){
                printf("%d\n", *it);
                it++;
            }
        }
        else if(!blue.empty()){
            printf("blue wins\n");
            it = blue.begin();
            while(it != blue.end()){
                printf("%d\n", *it);
                it++;
            }
        }
        else printf("green and blue died\n");
        if(cases)
            printf("\n");
    }
    //END

    return 0;
}
