//215. Kth Largest Element in an Array
import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        // Create a min-heap with a capacity of k
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(k);

        // Iterate through all elements in the array
        for (int num : nums) {
            minHeap.add(num); // Add the current element to the heap
            
            // If heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.remove();
            }
        }

        // The root of the heap will be the Kth largest element
        return minHeap.peek();
    }
}

//2336. Smallest Number in Infinite Set
class SmallestInfiniteSet {
public:
    int curr;
    set<int>s;

    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        // if set is not empty
        if(s.size()){
            int res=*s.begin();
            s.erase(res);
            return res;
        }
        // set empty
        else{
            curr++;
            return curr-1;
        }
    }

    void addBack(int num) {
        if(curr>num){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */