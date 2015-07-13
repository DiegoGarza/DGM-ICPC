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
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    //STARTS
    int cases;
    string s;
    infile>>cases;
    infile.ignore();
    infile.ignore();
    while(cases--){
        vector<Result> results;
        while(getline(infile, s)){
            if(s == "") break;
            stringstream ss(s);
            istream_iterator<string> it(ss);
            istream_iterator<string> end;
            vector<string> res(it, end);
            vi v(res.size());
            int aux;
            F(i, res.size()){
                if(res[i] == "I"){
                    v[i] = -2;
                }
                else if(res[i] == "C"){
                    v[i] = -1;
                }
                else if(res[i] == "E" || res[i] == "U" || res[i] == "R"){
                    v[1] = v[2] = v[3] = 0;
                }
                else {
                    istringstream stoi(res[i]);
                    stoi >> v[i];
                }
            }
            results.push_back(Result(v[0], v[1], v[2], v[3]));
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
                solved.clear();
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
                currentTeam = results[i].team;
                prob = tim = 0;
            }
        }
        sort(ans.begin(), ans.end(), comp2);
        F(i, ans.size()){
            outfile<<ans[i].team<<" "<<ans[i].problem<<" "<<ans[i].time<<endl;
        }
        outfile<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
