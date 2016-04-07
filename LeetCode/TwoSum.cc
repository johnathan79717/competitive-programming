class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		vector<int> sorted = numbers;
		sort(sorted.begin(), sorted.end());
		auto head = sorted.begin();
		auto tail = sorted.end() - 1;
		while(*head <= *tail) {
			int val = *head + *tail;
			if(val < target)
				head++;
			else if(val > target)
				tail--;
			else
				break;
		}
		int index1 = find(numbers.begin(), numbers.end(), *head) - numbers.begin() + 1;
		int index2 = numbers.rend() - find(numbers.rbegin(), numbers.rend(), *tail);
		pair<int, int> ans = minmax(index1, index2);
		return vector<int>({ ans.first, ans.second });
	}
};