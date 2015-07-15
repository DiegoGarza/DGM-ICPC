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

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int size, in, push;
    while(scanf("%d", &size) != EOF){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isStack = true, isQueue = true, isPq = true;
        while(size--){
            scanf("%d%d", &push, &in);
            if(push == 1){
                s.push(in);
                q.push(in);
                pq.push(in);
            }
            else{
                if(s.empty() || s.top() != in) isStack = false;
                if(q.empty() || q.front() != in) isQueue = false;
                if(pq.empty() || pq.top() != in) isPq = false;
                if (!s.empty())
                    s.pop();
                if (!q.empty())
                    q.pop();
                if (!pq.empty())
                    pq.pop();
            }
        }
        if(!isStack && !isQueue && !isPq) printf("impossible\n");
        else if(isStack && !isQueue && !isPq) printf("stack\n");
        else if(!isStack && isQueue && !isPq) printf("queue\n");
        else if(!isStack && !isQueue && isPq) printf("priority queue\n");
        else printf("not sure\n");
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
