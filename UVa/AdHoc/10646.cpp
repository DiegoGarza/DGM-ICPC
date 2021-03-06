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

struct Card{
    int val;
    char face;
    char suit;
};

int main(){
    //FILE *in, *out;
    //in = fopen("input.txt", "r");
    //out = fopen("output.txt", "w+");

    //STARTS
    int n;
    string in;
    cin>>n;

    F(i, n){
        vector<Card> hand(52);
        F(i, 52){
            cin>>in;
            if(in[0] >= '2' && in[0] <= '9'){
                hand[i].val = in[0] - '0';
                hand[i].face = in[0];
            }
            else{
                hand[i].val = 10;
                hand[i].face = in[0];
            }
            hand[i].suit = in[1];
        }

        int y = 0;
        int toRemove = 26;
        F(i, 3){
            int end = toRemove;
            Card aux = hand[toRemove];
            toRemove-=(10-aux.val);
            y+=aux.val;
            hand.erase(hand.begin()+toRemove, hand.begin()+end+1);
            toRemove--;
        }

        printf("Case %d: %c%c\n", i+1, hand[y-1].face, hand[y-1].suit);
    }

    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
