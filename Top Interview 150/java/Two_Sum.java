import java.util.HashMap;
import java.util.Map;

public class Two_Sum {
    
    public static void main(String[] args) {
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        int[] output1 = twoSum(nums1, target1);
        System.out.println(output1[0] + " " + output1[1]);

        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        int[] output2 = twoSum(nums2, target2);
        System.out.println(output2[0] + " " + output2[1]);

        int[] nums3 = {3, 3};
        int target3 = 6;
        int[] output3 = twoSum(nums3, target3);
        System.out.println(output3[0] + " " + output3[1]);
    }

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] {map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
