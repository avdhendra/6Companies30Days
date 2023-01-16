#include<bits/stdc++.h>
using namespace std;
int increasingTriplet(vector<int>&nums){
    int n=nums.size();
    if(n<3){
        return false; //if size of array is less than 3 then we need to return false  
    }
    int left = INT_MAX;
    int mid = INT_MAX;
    for (int i = 0; i < n;i++){
 //if nums[i] is greater than mid means nums[i] is also greater than left means
/*two  element before index i is less than nums[i] and that are left and mid we find that it sataisfy
the condition of triplet so we return true
*/       
        if(nums[i]>mid){
            return true;
        }
  /*if nums[i] is greater than left and less than mid then it is clear that we find b in a<b<c because it is quite possible
  that c can be INT_MAX
  */      
        
        else if(nums[i]<left && nums[i]<mid){
            mid = nums[i];
        }
/**If nums[i] less than left then we update the value of left to nums[i] because we find a smaller element than it previous value*/



        else if(nums[i]<left){
            left = nums[i];
        }
    }

    //whole array is traversed so there is no triplet then we return false
    return false;
}
int main(){

}