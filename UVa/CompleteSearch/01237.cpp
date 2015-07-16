#include <iostream>
#include <cstdio>

using namespace std;

struct car{
    string name;
    int l;
    int h;
    car() : name(""), l(0), h(0) {}
    car(string s, int a, int b) : name(s), l(a), h(b) {}
};

car db [10005];

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int size;
        cin>>size;
        string s;
        int l, h, i;
        for(i=0; i<size; i++){
            cin>>s>>l>>h;
            db[i] = car(s, l, h);
        }
        int queries, in;
        cin>>queries;
        while(queries--){
            cin>>in;
            int cars = 0, ans;
            i = 0;
            while(cars < 2 && i < size){
                if(db[i].h >= in && db[i].l <= in){
                    ans = i;
                    cars++;
                }
                i++;
            }
            if(cars == 1) cout<<db[ans].name<<endl;
            else cout<<"UNDETERMINED"<<endl;
        }
        if(cases)
            cout<<endl;
    }

    return 0;
}
