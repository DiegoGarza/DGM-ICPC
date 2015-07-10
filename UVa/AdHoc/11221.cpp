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
    string s;
    int n;
    cin>>n;
    F(i, n){
        if(i==0){
            cin.ignore();
        }
        getline(cin, s);
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != '?' && s[i] != '!' && s[i] != ',' && s[i] != '.'
                    && s[i] != ' ' && s[i] != '(' && s[i] != ')'){
                ans+=s[i];
            }
        }
        int size = ans.length();
        //cout<<sqrt(size)<<"     "<<size<<endl;
        bool notPal = false;
        if(sqrt(size) == (int) (sqrt(size))){
            size = (int) sqrt(size);
            vvi square(size, vi(size));
            int k =0;
            F(i, size){
                F(j, size){
                    square[i][j] = ans[k];
                    k++;
                }
            }
            int limitLeft = 0;
            int limitRight = size-1;
            while(limitLeft < limitRight && !notPal){
                int leftJ = limitLeft;
                int leftI = limitLeft;
                int rightJ = limitRight;
                int rightI = limitRight;
                while(leftJ <= limitRight){
                    if(!(square[limitLeft][leftJ] == square[leftI][limitLeft] &&
                        square[limitLeft][leftJ] == square[limitRight][rightJ] &&
                        square[limitLeft][leftJ] == square[rightI][limitRight])){
                            notPal = true;
                            break;
                        }
                    leftJ++;
                    leftI++;
                    rightJ--;
                    rightI--;
                }
                limitLeft++;
                limitRight--;
            }
        }
        else{
            notPal = true;
        }
        if(notPal){
            cout<<"Case #"<<i+1<<":\nNo magic :("<<endl;
        }
        else{
            cout<<"Case #"<<i+1<<":\n"<<size<<endl;
        }
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
