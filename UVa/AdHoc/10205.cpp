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

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int n, dirt, shuffles;

    cin>>n;
    cin.ignore();

    string cards [] = {
        "2 of Clubs",
        "3 of Clubs",
        "4 of Clubs",
        "5 of Clubs",
        "6 of Clubs",
        "7 of Clubs",
        "8 of Clubs",
        "9 of Clubs",
        "10 of Clubs",
        "Jack of Clubs",
        "Queen of Clubs",
        "King of Clubs",
        "Ace of Clubs",
        "2 of Diamonds",
        "3 of Diamonds",
        "4 of Diamonds",
        "5 of Diamonds",
        "6 of Diamonds",
        "7 of Diamonds",
        "8 of Diamonds",
        "9 of Diamonds",
        "10 of Diamonds",
        "Jack of Diamonds",
        "Queen of Diamonds",
        "King of Diamonds",
        "Ace of Diamonds",
        "2 of Hearts",
        "3 of Hearts",
        "4 of Hearts",
        "5 of Hearts",
        "6 of Hearts",
        "7 of Hearts",
        "8 of Hearts",
        "9 of Hearts",
        "10 of Hearts",
        "Jack of Hearts",
        "Queen of Hearts",
        "King of Hearts",
        "Ace of Hearts",
        "2 of Spades",
        "3 of Spades",
        "4 of Spades",
        "5 of Spades",
        "6 of Spades",
        "7 of Spades",
        "8 of Spades",
        "9 of Spades",
        "10 of Spades",
        "Jack of Spades",
        "Queen of Spades",
        "King of Spades",
        "Ace of Spades"
    };

    while(n--){
        vi deck(52);
        F(i, 52){
            deck[i] = i;
        }

        cin>>shuffles;

        vvi shuffle (shuffles, vi (52));
        int in;
        F(i, shuffles){
            F(j, 52){
                cin>>in;
                shuffle[i][j] = in-1;
            }
        }

        string line;
        cin.ignore();
        getline(cin, line);
        int k;
        while(!line.empty())
        {
            //if (line == "") break;

            istringstream ss(line);
            ss >> k;

            vi aux(52);
            F(i,52){
                aux[i] = deck[shuffle[k-1][i]];
            }
            F(i, 52){
                deck[i] = aux[i];
            }

            getline(cin, line);
        }

        F(i, 52){
            cout<<cards[deck[i]]<<endl;
        }
        if(n!=0)
            cout<<endl;
    }


    //END

    // fclose(in);
    // fclose(out);
    // return 0;
}
