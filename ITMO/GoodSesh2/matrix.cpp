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

FILE *in, *out;

void displayMatrix(int i, int j, vector<vector <int> > bSol){
    if(i==j){
        fprintf(out, "A");
    }

    else{
        fprintf(out, "(");
        displayMatrix(i, bSol[i][j], bSol);
        displayMatrix(bSol[i][j] + 1, j, bSol);
        fprintf(out, ")");
    }
}

int main(){
    in = fopen("matrix.in", "r");
    out = fopen("matrix.out", "w+");

    //STARTS
    int size, trash;
    fscanf(in, "%d", &size);
    vector<int> mats(size+1);
    vector<vector<int> > sol(size, vector<int>(size));
    vector<vector<int> > bSol(size, vector<int>(size));

    fscanf(in, "%d", &mats[0]);
    F(i, size-1){
        fscanf(in, "%d", &trash);
        fscanf(in, "%d", &mats[i+1]);
    }
    fscanf(in, "%d", &mats[size]);

    int i = 0, j = 0;
    int auxj=0;
    while(!(i==0 && j>=size)){
        // cout<<i<<","<<j<<" ";
        if(i==j){
            sol[i][j] = 0;
        }
        else{
            int min, aux, mink;
            for(int k=i; k<j; k++){
                aux = sol[i][k] + sol[k+1][j] + mats[i]*mats[k+1]*mats[j+1];
                if (k==i){
                    min = aux;
                    mink = k;
                }
                else{
                    if(min>aux){
                        min = aux;
                        mink = k;
                    }
                }
            }
            bSol[i][j] = mink;
            sol[i][j] = min;
        }
        i++;
        j++;
        if(j>=size){
            auxj++;
            j=auxj;
            i=0;
        }
    }

    // F(i, size){
    //     F(j, size){
    //         cout<<sol[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //
    // F(i, size){
    //     F(j, size){
    //         cout<<bSol[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    displayMatrix(0, size-1, bSol);
    fprintf(out, "\n");
    //END

    fclose(in);
    fclose(out);
    return 0;
}
