#include<bits/stdc++.h>
using namespace std;
//1. Way
int evalRPN(vector<string>&token){
    stack<long> stk;
    for(auto str:token){
        if(str.size()>1||isdigit(str[0])){
            stk.push(stoi(str));
        }else{
            auto b = stk.top();
            stk.pop();
            auto a = stk.top();
            stk.pop();
            //case for operations
            if (str[0] == '+')
            {
                stk.push(a + b);
            }
            else if (str[0] == '-')
            {
                stk.push(a - b);

            }
            else if (str[0] == '*')
            {

                stk.push(a * b);
            }
            else
            {
                stk.push(a / b);
            }

            
        }
    }
    return stk.top();

}

//2nd Way
int evalRPN2(vector<string>&tokens)
{
    stack<long> stk;
    for (auto str : tokens)
    {
        if (str == "*" || str == "+" || str == "-"|| str=="/"){
            auto op2 = stk.top();
            stk.pop();
            auto op1 = stk.top();
            stk.pop();
            if (str == "+")
            {
                stk.push(op1 + op2);
            }
            else if (str == "-")
            {
                stk.push(op1 - op2);
            }
            else if (str == "*")
            {

                stk.push(op1 * op2);
            }
            else
            {
                stk.push(op1/ op2);
            }
        }else{
            stringstream ss(str);
            int data;
            ss >> data;
            stk.push(data);
        }
 }
 return stk.top();
}



int main(){
    int a;
    cin >> a;
    while(a--){
        cout << "Hello World"
             << "\n";
    }
}