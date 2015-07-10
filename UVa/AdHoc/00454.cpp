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

struct Word{
    string correct, sorted;
};

bool comp(const pair<string, string>& a, const pair<string, string>& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int n;
    string s;
    cin>>n;
    cin.ignore();
    cin.ignore();
    while(n--){
        vector<Word> words;
        while(getline(cin, s)){
            if(s == ""){
                break;
            }
            string aux = "";
            for(int i=0; i<s.length(); i++){
                if(s[i] != ' '){
                    aux+=s[i];
                }
            }
            sort(aux.begin(), aux.end());
            Word word;
            word.correct = s;
            word.sorted = aux;
            words.push_back(word);
        }

        vector<pair <string, string> > ans;

        F(i, words.size()){
            for(int j = i+1; j<words.size(); j++){
                if(words[i].sorted == words[j].sorted){
                    if(words[i].correct < words[j].correct)
                        ans.push_back(make_pair(words[i].correct, words[j].correct));
                    else
                        ans.push_back(make_pair(words[j].correct, words[i].correct));
                }
            }
        }

        sort(ans.begin(), ans.end(), comp);

        F(i, ans.size()){
            cout<<ans[i].first<<" = "<<ans[i].second<<endl;
        }
        
        if(n!=0)
            cout<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
