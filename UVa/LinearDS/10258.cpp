#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <fstream>

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

struct Result{
    int team;
    int problem;
    int time;
    int res;
    Result(int a, int b, int c, int d) {
        team = a;
        problem = b;
        time = c;
        res = d;
    }
};

bool comp(const Result& a, const Result& b){
    if(a.team == b.team){
        if(a.problem == b.problem){
            if(a.time == b.time){
                return a.res < b.res;
            }
            return a.time < b.time;
        }
        return a.problem < b.problem;
    }
    return a.team < b.team;
}

bool comp2(const Result& a, const Result& b){
    if(a.problem == b.problem){
        if(a.time == b.time){
            return a.team < b.team;
        }
        return a.time < b.time;
    }
    return a.problem > b.problem;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    //STARTS
    int cases;
    string s;
    cin>>cases;
    cin.ignore();
    cin.ignore();
    while(cases--){
        vector<Result> results;
        while(getline(cin, s)){
            if(s == "") break;
            stringstream ss(s);
            int a,b,c, daux;
            char d;
            ss>>a>>b>>c>>d;
            if (d == 'C') daux = -1;
            else if (d == 'I') daux = -2;
            else daux = 0;
            results.push_back(Result(a,b,c,daux));
        }

        sort(results.begin(), results.end(), comp);
        vector<Result> ans;
        int currentTeam = results[0].team;
        int i = 0;
        int prob = 0, tim = 0, cprob = results[0].problem;
        int penalty = 0;
        set<int> solved;
        while(i < results.size()){
            if(cprob != results[i].problem){
                cprob = results[i].problem;
                penalty = 0;
            }
            if(results[i].res == -2){
                penalty++;
            }
            if(results[i].res == -1 && solved.find(results[i].problem) == solved.end()){
                solved.insert(results[i].problem);
                prob++;
                tim += results[i].time + penalty * 20;
            }
            i++;
            if(currentTeam != results[i].team || i >= results.size()){
                ans.push_back(Result(currentTeam, prob, tim, 0));
                solved.clear();
                if (i < results.size())
                    currentTeam = results[i].team;
                penalty = prob = tim = 0;
            }
        }
        sort(ans.begin(), ans.end(), comp2);
        F(i, ans.size()){
            cout<<ans[i].team<<" "<<ans[i].problem<<" "<<ans[i].time<<endl;
        }
        if(cases != 0)
            cout<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
