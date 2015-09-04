#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int c = 0;

bool isHappy(int n) {
    set<int> s;
    int aux;
    while(true){
        c++;
        if(n == 1) return true;
        if(s.find(n) != s.end()) {
            return false;
        }
        else {
            s.insert(n);
        }
        aux = 0;
        while(n){
            aux += (int) pow((double) (n%10), 2.0);
            n/=10;
        }
        n = aux;
    }
}

int main() {
    int in;
    for(int i=0; i<10; i++){
        cin>>in;
        c = 0;
        if(isHappy(in)) cout<<"happy ";
        else cout<<"unhappy ";
        cout<<c-1<<endl;
    }
    return 0;
}
