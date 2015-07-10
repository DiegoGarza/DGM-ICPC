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

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

struct lily{
    int min;
    int max;
    int total;
    lily() : min(INF), max(-1), total(0) {}
    bool isCorrect(){
        if(max == -1){
            return true;
        }
        return max - min + 1 == total;
    }
};

int main(){
    FILE *in, *out;
    in = fopen("turtles.in", "r");
    out = fopen("turtles.out", "w+");

    //STARTS
    int h, w, total = 0;

    fscanf(in, "%d%d", &h, &w);
    vector<lily> rows(h);
    vector<lily> cols(w);

    int lilies;
    fscanf(in, "%d", &lilies);

    int x, y;
    bool correctBefore;
    while(lilies--){
        fscanf(in, "%d%d", &x, &y);
        x--;
        y--;

        correctBefore = rows[x].isCorrect();
        if(rows[x].min > y){
            rows[x].min = y;
        }
        if(rows[x].max < y){
            rows[x].max = y;
        }
        rows[x].total++;

        //Check for conflicts
        if(correctBefore && !rows[x].isCorrect()){
            total++;
        }
        else if(!correctBefore && rows[x].isCorrect()){
            total--;
        }

        correctBefore = cols[y].isCorrect();
        if(cols[y].min > x){
            cols[y].min = x;
        }
        if(cols[y].max < x){
            cols[y].max = x;
        }
        cols[y].total++;

        //Check for conflicts
        if(correctBefore && !cols[y].isCorrect()){
            total++;
        }
        else if(!correctBefore && cols[y].isCorrect()){
            total--;
        }
    }

    if(total==0){
        fprintf(out, "YES\n");
    }
    else{
        fprintf(out, "NO\n");
    }

    int newLilies;
    fscanf(in, "%d", &newLilies);

    while(newLilies--){
        fscanf(in, "%d%d", &x, &y);
        x--;
        y--;

        correctBefore = rows[x].isCorrect();
        if(rows[x].min > y){
            rows[x].min = y;
        }
        if(rows[x].max < y){
            rows[x].max = y;
        }
        rows[x].total++;

        //Check for conflicts
        if(correctBefore && !rows[x].isCorrect()){
            total++;
        }
        else if(!correctBefore && rows[x].isCorrect()){
            total--;
        }

        correctBefore = cols[y].isCorrect();
        if(cols[y].min > x){
            cols[y].min = x;
        }
        if(cols[y].max < x){
            cols[y].max = x;
        }
        cols[y].total++;

        //Check for conflicts
        if(correctBefore && !cols[y].isCorrect()){
            total++;
        }
        else if(!correctBefore && cols[y].isCorrect()){
            total--;
        }

        if(total==0){
            fprintf(out, "YES\n");
        }
        else{
            fprintf(out, "NO\n");
        }
    }

    // F(i, rows.size()){
    //     fprintf(out, "%d %d %d\n", rows[i].min, rows[i].max, rows[i].total);
    // }
    //
    // F(i, cols.size()){
    //     printf("%d %d %d\n", cols[i].min, cols[i].max, cols[i].total);
    // }

    //END

    fclose(in);
    fclose(out);
    return 0;
}
