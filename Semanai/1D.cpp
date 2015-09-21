#include <iostream>
#include <string>
#include <iterator>
#include <map>

using namespace std;

bool isPermutation(string a, string b){
    if(a.length() != b.length()) return false;
    map<char, int> m;
    for(int i=0; i < a.length(); i++){
        m[a[i]]++;
        m[b[i]]--;
    }
    for(map<char, int>::iterator it = m.begin(); it != m.end(); it++){
        if(it->second) return false;
    }
    return true;
}

int main() {
    string a, b;
    cin>>a>>b;
    cout<<isPermutation(a,b)<<endl;
    return 0;
}
