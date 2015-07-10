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

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){
    FILE *in, *out;
    in = fopen("moosick.in", "r");
    out = fopen("moosick.out", "w+");

    //STARTS
    int s, c;

    fscanf(in, "%d", &s);

    vi song(s);

    F(i, s){
        fscanf(in, "%d", &song[i]);
    }

    fscanf(in, "%d", &c);

    vi chord(c);

    F(i, s){
        fscanf(in, "%d", &chord[i]);
    }

    sort(chord.begin(), chord.end());
    vi ans;

    for(int i=0; i<=s-c; i++){
        //cout<<"Checking: "<<song[i]<<endl;
        vi aux;
        for(int j=i; j<i+c; j++){
            aux.push_back(song[j]);
        }

        sort(aux.begin(), aux.end());

        int diff = aux[0] - chord[0];
        int j;
        for(j=1; j<chord.size(); j++){
            //cout<<diff<<endl;
            if(diff != aux[j] - chord[j]){
                break;
            }
        }

        if(j==chord.size()){
            ans.push_back(i+1);
        }

        aux.clear();
    }

    sort(ans.begin(), ans.end());

    fprintf(out, "%d\n", (int) ans.size());

    F(i, ans.size()){
        fprintf(out, "%d\n", ans[i]);
    }

    //END

    fclose(in);
    fclose(out);
    return 0;
}
