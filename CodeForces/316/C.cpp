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

char word [300000];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int size, q, place, rep = 0;
    char ch;
    string s;
    cin>>size>>q;
    cin>>s;
    F(i, 0, s.length()){
        word[i] = s[i];
        if(i && word[i] == '.' && word[i-1] == '.') rep++;
    }
    F(i, 0, q){
        cin>>place>>ch;
        place--;
        if(ch != '.' && word[place] == '.'){
            if(word[place-1] == '.' && word[place+1] == '.') rep -= 2;
            else if(word[place-1] == '.' || word[place+1] == '.') rep--;
        }
        else if(ch == '.' && word[place] != '.'){
            if(word[place-1] == '.' && word[place+1] == '.') rep += 2;
            else if(word[place-1] == '.' || word[place+1] == '.') rep++;
        }
        word[place] = ch;
        cout<<rep<<endl;
    }
    //END

    return 0;
}
