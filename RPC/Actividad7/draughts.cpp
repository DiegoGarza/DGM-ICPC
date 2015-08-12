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
#include <limits>
#include <fstream>

using namespace std;

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
#define INF (int)2e9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int moves1;

int findMoves(vvi board, int i, int j, int curr){
    board[i][j] = 0;
    int max = 0;
    int moves [2] = {-1, 1};
    F(k, 0, 2){
        F(l, 0, 2){
            int auxi = i+moves[k];
            int auxj = j+moves[l];
            if(auxi >= 0 && auxi < 10 && auxj >=0 && auxj < 10 &&
                board[auxi][auxj] == 2){
                board[auxi][auxj] = 0;
                int aai = auxi+moves[k];
                int aaj = auxj+moves[l];
                if(aai >=0 && aai < 10 && aaj >=0 && aaj < 10 &&
                    board[aai][aaj] == 0){
                        int aux = curr;
                        aux++;
                        aux += findMoves(board, aai, aaj, 0);
                        if(aux>max) max = aux;
                    }
                board[auxi][auxj] = 2;
            }
        }
    }
    return max;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int cases;
    string s;
    cin>>cases;
    while(cases--){
        vvi board(10, vi(10, 0));
        F(i, 0, 10){
            cin>>s;
            F(j, 0, 10){
                if(s[j] == 'W'){
                    board[i][j] = 1;
                }
                else if (s[j] == 'B'){
                    board[i][j] = 2;
                }
            }
        }
        int max = 0;
        F(i, 0, 10){
            F(j, 0, 10){
                if(board[i][j] == 1){
                    vvi auxboard(10, vi(10, 0));
                    F(i, 0, 10){
                        F(j, 0, 10){
                            auxboard[i][j] = board[i][j];
                        }
                    }
                    moves1 = findMoves(auxboard, i, j, 0);
                    if(moves1 > max) max = moves1;
                }
            }
        }
        cout<<max<<endl;
    }
    //END

    return 0;
}
