/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    
    var xors=0;
    
    for(let i=0;i<nums.length;i++){
  
        xors=xors^nums[i];
        
    }
    return xors;
    
    
};