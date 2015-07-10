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

void rotateMatrix(vvi& mat){
    int size = mat.size();
    vvi aux(size, vi(size));
    for(int i=0, k = size-1; i<size; i++, k--){
        for(int j=0, l = 0; j<size; j++, l++){
            aux[l][k] = mat[i][j];
        }
    }
    F(i, size){
        F(j, size){
            mat[i][j] = aux[i][j];
        }
    }
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int N, n;
    while(cin>>N>>n, (n||N)){
        vvi big(N, vi(N));
        vvi small(n, vi(n));
        vi rots(4, 0);
        string s;
        F(i, N){
            cin>>s;
            F(j, s.length()){
                big[i][j] = s[j];
            }
        }
        F(i, n){
            cin>>s;
            F(j, s.length()){
                small[i][j] = s[j];
            }
        }

        F(i, N-n+1){
            F(j, N-n+1){
                F(m, 4){
                    bool isC = true;
                    for(int k = i; k<n+i && isC; k++){
                        for(int l = j; l<n+j; l++){
                            if(big[k][l] != small[k-i][l-j]){
                                isC = false;
                                break;
                            }
                        }
                    }
                    rotateMatrix(small);
                    if(isC) rots[m]++;
                }
            }
        }
        F(i, 4){
            cout<<rots[i];
            if(i!=3)
                cout<<" ";
        }
        cout<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
