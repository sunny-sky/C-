#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// key是数，value是向量中的索引
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int numToFind = target - nums[i];
			// 待查数若在map中，返回他们
			if (hash.find(numToFind) != hash.end()) {
				return { hash[numToFind], i };
			}

			// 没找到的话，把num放入map
			hash[nums[i]] = i;
		}
		return {};
	}
};