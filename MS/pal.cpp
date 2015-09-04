#include <iterator>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while(cin>>s) {
        map<char, int> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
        }
        int odd = 0;
        for(map<char,int>::iterator it = m.begin(); it != m.end(); it++){
            if((it->second)&1) odd++;
        }
        int ansi = odd;
        for(map<char,int>::iterator it = m.begin(); odd > 1 && it != m.end(); it++){
            if((it->second)&1) {
                (it->second) = (it->second) - 1;
                odd--;
            }
        }
        string ans = "";
        for(map<char,int>::iterator it = m.begin(); it != m.end(); it++){
            while(it->second) {
                ans += it->first;
                (it->second)--;
            }
        }
        s = ans;
        sort(s.begin(), s.end());
        set<string> st;
        do{
            string aux = s;
            reverse(aux.begin(), aux.end());
            if(aux == s) st.insert(s);
        } while(next_permutation(s.begin(), s.end()));
        cout<<((ansi == 0) ? 0 : ansi-1)<<","<<st.size()<<endl;
    }

    return 0;
}
