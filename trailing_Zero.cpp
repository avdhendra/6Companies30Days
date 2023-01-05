#include<bits/stdc++.h>
using namespace std;
/**
 * to Get some zeros we need to generate 10s
 * 10=5*2
 * Here the number that gives us 10 are only 2 and 5
 * 
 * Secondly in Some numbers like 25 125 we may have many 5s 
*/
//O(N)
int trailingZeros(int n){
    int count = 0;
    //Since we have so many 2's because of even numbers
    //It is enough to count only 5's
    for (int i = 1; i <= n;i++){
        if(i%5==0){
            //check for power of 5
            int pow5 = i;
            while((pow5%5)==0){
                pow5 = pow5 / 5;
                count++;
            }
        }
    }
    return count; //count the number of 5s

}

//O(log(n))
int trailingZero2(int n){
    int count = 0;
    while(n>0){
        count - count + n / 5;
        n = n / 5;
    }
    return count;
}




int main(){

}