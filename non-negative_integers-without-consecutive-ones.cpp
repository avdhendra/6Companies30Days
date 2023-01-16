 #include<bits/stdc++.h>
 using namespace std;
 int findIntegers(int n) {
        int fib[31]; //we need to take 31 space because we have range of 10^9
        fib[0]=1; // ---> 0 1
        fib[1]=2; //  --> 00 11 
        for(int i=2;i<30;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        int ans=0;
        int count=30;
        int prev_bit_one=0;
        while(count>=0){
            //check at which place the set bit is present
            if(n&(1<<count)){
                ans+=fib[count];
                //if two bits are consecutively set then 11 then return the ans because the number is it self have the consecutive ones
                if(prev_bit_one){
                    return ans;
                }
                //if the prev_bit is not 1 then set the prev_bit to 1 because in this count u get the set bit
                prev_bit_one=1;
            }else{
                prev_bit_one=0;
                
            }
            count--;
        }
        
        return ans+1; //ans +1 because we get the ans as fib[i-1]+fib[i-2] as fibonacci and we add one for the number itself because the number //dont have the consecutive set bits 
        
    }

int main(){
    
}