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

    //STARTS
    string s, message, aux, ans;
    set<string> dict;
    while(cin>>s, s!="#"){
        dict.insert(s);
    }
    cin.ignore();
    int max = 0, matches;
    getline(cin, message);
    aux = message;
    F(i, 1, 28){
        matches = 0;
        F(j, 0, aux.length()){
            if(aux[j] == ' ') aux[j] = 'A';
            else if(aux[j] == 'Z') aux[j] = ' ';
            else {
                aux[j] += 1;
            }
        }
        stringstream ss(aux);
        istream_iterator<string> it(ss);
        istream_iterator<string> end;
        vector<string> res(it, end);
        F(j, 0, res.size()){
            if(dict.find(res[j]) != dict.end()) matches++;
        }
        if(matches > max) {
            max = matches;
            ans = aux;
        }
    }
    stringstream ss(ans);
    istream_iterator<string> it(ss);
    istream_iterator<string> end;
    vector<string> res(it, end);
    int curr = 0;
    F(i, 0, res.size()){
        if(curr && curr + res[i].length() < 60) {
            cout<<" ";
            curr++;
        }
        curr += res[i].length();
        if(curr <= 60) cout<<res[i];
        else {
            cout<<endl;
            curr = 0;
            i--;
        }
    }
    cout<<endl;
    //END

    return 0;
}
