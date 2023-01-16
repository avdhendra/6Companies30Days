/**
 1/(n+1)+(n-1)/(n+1)*1/2

 =(n+1)/2*(n+1)=1/2
*/

#include <bits/stdc++.h>

using namespace std;// easy

/*
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of the passengers will:

Take their own seat if it is still available, and
Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.



Example 1:

Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.



*/
double nthPersonGetsNthSeat(int n)
{
    if (n == 1)
        return double(1);
    else
    {

        return double(0.5000);
    }
}
int main(){

}