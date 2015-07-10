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
    FILE *in, *out;
    in = fopen("lis.in", "r");
    out = fopen("lis.out", "w+");

    //STARTS
    int size;

    fscanf(in, "%d", &size);

    vector<int> lis(size);
    vector<int> val(size);
    vector<int> dir(size);
    vector<bool> end(size);

    F(i, size){
        fscanf(in, "%d", &lis[i]);
    }

    int max = 0;
    int maxI = 0;
    F(i, size){
        bool foundMin = false;
        int min=-1;
        int minDir;
        for(int j=0; j<i; j++){
            if(lis[j]<lis[i]){
                if(min<val[j]){
                    foundMin = true;
                    min = val[j];
                    minDir = j;
                }
            }
        }
        if(foundMin){
            val[i] = val[minDir]+1;
            dir[i] = minDir;
        }
        else {
            val[i] = 1;
            end[i] = true;
        }
        if(val[i]>max){
            max = val[i];
            maxI = i;
        }
    }

    stack<int> ans;
    while(!end[maxI]){
        ans.push(lis[maxI]);
        maxI = dir[maxI];
    }
    ans.push(lis[maxI]);

    fprintf(out, "%d\n", ans.size());

    while(!ans.empty()){
        fprintf(out, "%d ", ans.top());
        ans.pop();
    }
    fprintf(out, "\n");

    // cout<<"lis:"<<endl;
    // F(i, size){
    //     cout<<lis[i]<<" ";
    // }
    // cout<<endl;
    //
    // cout<<"val:"<<endl;
    // F(i, size){
    //     cout<<val[i]<<" ";
    // }
    // cout<<endl;
    //
    // cout<<"dir:"<<endl;
    // F(i, size){
    //     cout<<dir[i]<<" ";
    // }
    // cout<<endl;
    //
    // cout<<"end:"<<endl;
    // F(i, size){
    //     cout<<end[i]<<" ";
    // }
    // cout<<endl;

    //END

    fclose(in);
    fclose(out);
    return 0;
}
