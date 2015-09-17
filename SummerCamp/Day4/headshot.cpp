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

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    ifstream in("headshot.in");
    ofstream out("headshot.out");

    //STARTS
    string s;
    in>>s;
    int c = 0;
    while(s[s.length()-1] == '0' && c < s.length()){
        s = '0' + s;
        s.erase(s.length()-1, 1);
        c++;
    }
    double prob0 = 0, prob1 = 0;
    int total = 0;
    vi zeroes;
    F(i,0,s.length()){
        if(s[i] == '1' && total){
            zeroes.push_back(total);
            total = 0;
        }
        else if(s[i] == '0'){
            total++;
        }
    }
    F(i,0,zeroes.size()){
        double curr = (double) zeroes[i];
        prob0 += (curr-1)/curr;
        prob1 += 1/(curr);
    }
    if(prob0 == prob1){
        out<<"EQUAL"<<endl;
    }
    else if(prob0 > prob1){
        out<<"SHOOT"<<endl;
    }
    else {
        out<<"ROTATE"<<endl;
    }
    //END

    return 0;
}
