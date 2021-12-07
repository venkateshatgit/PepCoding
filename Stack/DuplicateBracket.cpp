#include <bits/stdc++.h>
using namespace std;

bool duplicateB(string s){
    
    stack <char> charStack;
    for(int i=0; i<s.size(); ++i){
        if(s[i]==')'){

            if(charStack.top()=='(')
                return true;

            while(true){
                if(charStack.top()=='('){
                    charStack.pop();
                    break;
                }
                charStack.pop();
            }
        }
        else
            charStack.push(s[i]);
    }
    
    return false;
}

int main(){
    string s;
    cin>>s;
    
    if(duplicateB(s)){
        cout<<"true"<<endl;
    }
    else
        cout<<"false"<<endl;
        
    return 0;
}