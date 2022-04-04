#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static auto
    twoSum(vector<int>& nums, int target) -> vector<size_t> {
        unordered_map<int, size_t> hash_table;
        for (size_t idx = 0; auto num : nums) {
            if (hash_table.find(target - num) != hash_table.end()) {
                return {idx, hash_table[target - num]};
            }
            hash_table[num] = idx;
            ++idx;
        }
        return {};
    }
};


TEST (twoSum, LeetCodeExample_1) {
    vector<int> nums {2,7,11,15};
    int target = 9;
    auto indices = Solution::twoSum(nums, target);
    EXPECT_EQ(indices.size(), 2);
    EXPECT_EQ (nums[indices[0]] + nums[indices[1]], target);
}
TEST (twoSum, LeetCodeExample_2) {
    vector<int> nums {3,2,4};
    int target = 6;
    auto indices = Solution::twoSum(nums, target);
    EXPECT_EQ(indices.size(), 2);
    EXPECT_EQ (nums[indices[0]] + nums[indices[1]], target);
}
TEST (twoSum, LeetCodeExample_3) {
    vector<int> nums {3,3};
    int target = 6;
    auto indices = Solution::twoSum(nums, target);
    EXPECT_EQ(indices.size(), 2);
    EXPECT_EQ (nums[indices[0]] + nums[indices[1]], target);
}
TEST (twoSum, NoSolution) {
    vector<int> nums {2,7,11,15};
    EXPECT_EQ(Solution::twoSum(nums, 15).size(), 0);
}
TEST (twoSum, EmptyInputContainer) {
    vector<int> nums {};
    EXPECT_EQ(Solution::twoSum(nums, 15).size(), 0);
}


auto main(int argc, char **argv) -> int {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}