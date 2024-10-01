//448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n) {
            int index=nums[i]-1;
            if (nums[i] != nums[index]) {
                swap(nums[i], nums[index]);
            }
            else{
                i++;
            }
        }

        // Step 2: Find the missing numbers
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};


//451. Sort Characters By Frequency
class Solution {
    public String frequencySort(String s) {
        StringBuilder answer=new StringBuilder();

        // for storing frequency
        HashMap<Character,Integer>result=new HashMap<>();
        
        for(char ch:s.toCharArray()){
            result.put(ch,result.getOrDefault(ch,0)+1);
        }

        // sort on number of frequencies
        List<Character>list=new ArrayList(result.keySet());
        list.sort((ob1,ob2)->result.get(ob2)-result.get(ob1));
        for(char ch:list){
            for(int i=0;i<result.get(ch);i++){
                answer.append(ch);
            }
        }
        
        return answer.toString();
    }
}