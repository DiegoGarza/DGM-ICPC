#include <iostream>
#include <string>

using namespace std;

char* compress(string s){
    char* ans = new char[s.length()+1];
    int count = 1, pos = 0;
    char prev = s[0];
    for(int i = 1; i <= s.length(); i++, count++){
        if(i == s.length() || s[i] != prev){
            if(count != 1) {
                ans[pos++] = prev;
                int curr = 0;
                char num [3];
                while(count) {
                    num[curr++] = ((char)(count % 10) + '0');
                    count /= 10;
                }
                for(int i = curr - 1; i >= 0; i--){
                    ans[pos++] = num[i];
                }
            }
            else {
                ans[pos++] = prev;
            }
            prev = s[i];
            count = 0;
        }
    }
    ans[pos] = '\0';
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<compress(s)<<endl;
    return 0;
}
