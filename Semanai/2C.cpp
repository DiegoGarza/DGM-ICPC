#include <iostream>
#include <stack>

using namespace std;

bool verifyParenthesis(string pars){
    stack<char> s;

    for(int i = 0; i<pars.length(); i++){
        if(pars[i] == '{' || pars[i] == '(' || pars[i] == '[') {
            s.push(pars[i]);
        }
        else {
            if(s.empty() || (pars[i] == '}' && s.top() != '{') ||
                (pars[i] == '}' && s.top() != '{') ||
                (pars[i] == '}' && s.top() != '{')) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main(){
    cout<<"[(){}]()"<<endl;
    cout<<verifyParenthesis("[(){}]()")<<endl;
    cout<<"[}{["<<endl;
    cout<<verifyParenthesis("[}{[")<<endl;
    return 0;
}
