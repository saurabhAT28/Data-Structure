// Prefix to postfix conversion using stack
#include<iostream>
#include <bits/stdc++.h> 
#include<stack>
using namespace std;

string prePost(string s){
    string temp="";
    stack<string>st;
    reverse(s.begin(),s.end());

    for(int i=0;i<s.length();i++){
        if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
            string o=st.top();
            st.pop();
            string p=st.top();
            st.pop();
            temp=o+p+s[i];

            st.push(temp);
        }
        else{
            st.push(string(1, s[i])); 
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"***Prefix to Postfix convertor***"<<endl;
    cout<<"Enter the expression: ";
    cin>>s;
    cout<<"Postfix: "<<prePost(s);
    return 0;
}




