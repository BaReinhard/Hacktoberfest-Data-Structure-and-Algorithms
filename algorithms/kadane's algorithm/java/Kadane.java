import java.util.*;
import java.lang.*;
import java.io.*;
class Kadane{
	public static void main (String[] args){
		int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		System.out.println(maxSubArray(nums));
	}
    public static int maxSubArray(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        int sum = 0;
        int max = nums[0];
        for(int i=0;i<nums.length;i++){
            sum = sum + nums[i];
            max = Math.max(max,sum);
            if(sum<0){
                sum = 0;
            }

        }
        return max;
    }
}
