#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool uniqueChars(string s){
    if(s.length() > 52) return false;
    int place;
    bitset<52> map;
    for(int i = 0; i < s.length(); i++){
        place = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 26 : s[i] - 'a';
        if (!map[place]) map[place] = 1;
        else return false;
    }
    return true;
}

int main(){
    string a;
    cin>>a;
    cout<<uniqueChars(a)<<endl;
    return 0;
}
