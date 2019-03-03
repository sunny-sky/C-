#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// key������value�������е�����
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int numToFind = target - nums[i];
			// ����������map�У���������
			if (hash.find(numToFind) != hash.end()) {
				return { hash[numToFind], i };
			}

			// û�ҵ��Ļ�����num����map
			hash[nums[i]] = i;
		}
		return {};
	}
};