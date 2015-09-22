#include <iostream>
#include <string>

using namespace std;

bool evaluateExpressionHelp(string s, int start, int end){
    if(start == end){
        return (s[start] == 'F') ? false : true;
    }
    if(end - start == 1){
        return (s[end] == 'F') ? true : false;
    }
    bool right, left;
    for(int i=start; i<=end; i++){
        if(s[i] == '|') {
            left = evaluateExpressionHelp(s, start, i-1);
            right = evaluateExpressionHelp(s, i+1, end);
            return left || right;
        }
    }
    for(int i=start; i<=end; i++){
        if(s[i] == '&') {
            left = evaluateExpressionHelp(s, start, i-1);
            right = evaluateExpressionHelp(s, i+1, end);
            return left && right;
        }
    }
    return true;
}

bool evaluateExpression(string s){
    return evaluateExpressionHelp(s, 0, s.length() - 1);
}

int main(){
    string s = "F&!V|V";
    cout<<s<<endl<<evaluateExpression(s)<<endl;
    cout<<"Inserte otro string: "<<endl;
    cin>>s;
    cout<<evaluateExpression(s)<<endl;
    return 0;
}
