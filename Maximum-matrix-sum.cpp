#include<bits/stdc++.h>
using namespace std;
//easy and intresting
long long maxMatrixSum(vector<vector<int>>&matrix){
    int row=matrix.size();
    int col = matrix[0].size();
    //we need to find the min number in the matrix and also 
    //count of negative numbers in the matrix
    int small = INT_MAX, count = 0;
    long long int sum = 0;
    for (int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            int val = matrix[i][j];
            //finding the smallest absolute value in the matrix
            small = min(small, abs(val));
            
            if(val<0){
                count++;
            }
            //finding the sum of all the values
            sum+=abs(val);

        }
    }
    //if even number of negatives then just return sum
    if(count%2==0){
        return sum;
    }else{
        return sum - 2 * small;
    }
}
int main(){
    vector<vector<int>> mat = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << maxMatrixSum(mat) << "\n";
}