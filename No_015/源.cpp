#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;

			while (front < back)
			{
				int sum = nums[front] + nums[back];

				// 寻找以nums[i]开始的解
				if (sum < target)
				{
					front++;
				}
				else if (sum > target)
				{
					back--;
				}
				else
				{
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[front];
					triplet[2] = nums[back];
					res.push_back(triplet);

					// 处理第二个数重复，避免重复解
					while (front < back && nums[front] == triplet[1])
					{
						front++;
					}

					// 处理第三个数重复问题
					while (front < back && nums[back] == triplet[2])
					{
						back--;
					}
				}
				// 处理第一个数重复问题
				while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				{
					i++;
				}
			}
		}
		return res;
	}
};