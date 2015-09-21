#include <iostream>
#include <string>

using namespace std;

char* replaceSpaces(string s){
    char *ans = new char[s.length()+1];
    int i;
    for(i = 0; i < s.length(); i++) {
        (s[i] == ' ') ? ans[i] = '#' : ans[i] = s[i];
    }
    ans[i + 1] = '\0';
    return ans;
}

int main(){
    string a;
    getline(cin, a);
    cout<<replaceSpaces(a)<<endl;
    return 0;
}
