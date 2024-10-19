//Trapping rain water
class Solution {
    public int trap(int[] height) {
       // find left max height and right max height
        // then calculate the amount of water trapped
        // math.min(left[i],right[i])-height[i] 

        int n=height.length;
        int left[]=new int[n];
        int right[]=new int[n];

        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=Math.max(left[i-1],height[i]);
        }

        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=Math.max(right[i+1],height[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=Math.min(left[i],right[i])-height[i];
        }
        return ans;
    }
}


//Summary Ranges
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> list = new ArrayList();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            if (start != nums[i]) {
                list.add("" + start + "->" + nums[i]);
            } else {
                list.add("" + start);
            }
        }
        return list;
    }
}