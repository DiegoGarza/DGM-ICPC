#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> genLCP(string s){
    vector<int> lcp (s.length(), 0);
    int i = 0, j = 1;
    while(j < s.length()){
        if(s[i] == s[j]){
            i++;
            lcp[j] = i;
            j++;
        }
        else {
            if (i != 0) {
                i = lcp[i-1];
            }
            else {
                lcp[j] = 0;
                j++;
            }
        }
    }
    return lcp;
}

void kmpSearch(string haystack, string needle) {
    vector<int> lcp = genLCP(needle);

    int i = 0, j = 0;
    while(i < haystack.length()) {
        if(needle[j] == haystack[i]){
            i++;
            j++;
        }
        if(j == needle.length()) {
            printf("Found at %d\n", i - j);
            j = lcp[j - 1];
        }
        else if(i < haystack.length() && needle[j] != haystack[i]){
            if(j != 0) {
                j = lcp[j - 1];
            }
            else {
                i = i + 1;
            }
        }
    }
}

int main(){
    string s, n;
    cin>>s>>n;
    kmpSearch(s, n);
}
