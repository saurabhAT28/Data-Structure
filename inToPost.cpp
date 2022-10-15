#include <iostream>
#include <stack>
#include <string>
using namespace std;

int preced(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    st.push('#');

    string postfix = "";
    string::iterator it;

    for(it = s.begin(); it!=s.end(); it++) {
      if(isalnum(char(*it)))
         postfix += *it;      
      else if(*it == '(')
         st.push('(');
      else if(*it == '^')
         st.push('^');
      else if(*it == ')') {
         while(st.top() != '#' && st.top() != '(') {
            postfix += st.top(); 
            st.pop();
         }
         st.pop();         
      }else {
         if(preced(*it) > preced(st.top()))
            st.push(*it); 
         else {
            while(st.top() != '#' && preced(*it) <= preced(st.top())) {
               postfix += st.top();       
               st.pop();
            }
            st.push(*it);
         }
      }
   }
    while (st.top() != '#')
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout<<"POSTFIX: "<<infixToPostfix(s)<<endl;

    return 0;
}