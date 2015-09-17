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

    ifstream in("java_c.in");
    ofstream out("java_c.out");

    //STARTS
    string s;
    bool isJava = false;
    bool isC = false;
    in>>s;
    if((s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_' || s[s.length()-1] == '_'){
        out<<"Error!"<<endl;
        return 0;
    }
    F(i,0,s.length()){
        if(s[i] == '_') isC = true;
    }
    F(i,0,s.length()){
        if(s[i] >= 'A' && s[i] <= 'Z') isJava = true;
    }
    if(isC && isJava) {
        out<<"Error!"<<endl;
        return 0;
    }
    int one = 0;
    if(isC){
        string aux = "";
        F(i,0,s.length()){
            if(s[i] != '_') one++;
            if(s[i] == '_'){
                int ye = 0;
                while(s[i] == '_') {
                    ye++;
                    i++;
                }
                if(ye > 1) {
                    out<<"Error!"<<endl;
                    return 0;
                }
                if(i<s.length() && one) {
                    aux += s[i] - 32;
                }
                else {
                    aux += s[i];
                }
            }
            else aux += s[i];
        }
        out<<aux<<endl;
        return 0;
    }
    string aux = "";
    F(i,0,s.length()){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            aux += '_';
            aux += s[i] + 32;
        }
        else aux += s[i];
    }
    out<<aux<<endl;
    //END

    return 0;
}
