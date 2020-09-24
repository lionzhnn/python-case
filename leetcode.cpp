#include <iostream>
#include<sstream>
#include<vector>
#include<string>
#include <cstdio>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};
class Solution {
public:
	//1
	vector<int> twoSum(vector<int>& nums, int target) {
		int indexi, indexj;
		vector<int> result;
		for (auto i = nums.cbegin(); i != nums.cend(); i++) {
			indexi = i - nums.cbegin();
			auto temp = find(i + 1, nums.cend(), target - (*i));
			if (temp != nums.cend()) {
				indexj = temp - nums.cbegin();
				break;
			}
		}
		result.assign({ indexi,indexj });
		return result;
	}
	//7.整数反转
	int reverse(int x) {
		bool flag = (x < 0) ? true : false;
		x = abs(x);
		vector<int> number;
		while (x > 0) {
			number.push_back(x % 10);
			x /= 10;
		}
		int result = 0;
		for (auto value : number) {
			//溢出，返回0
			//如果result大于最大值/10,那么result*10一定会溢出
			if (result > (pow(2, 31) / 10))
				return 0;
			result = result * 10 + value;
		}
		return flag ? (-1 * result) : result;
	}
	//9.回文数
	bool isPalindrome_first(int x) {
		if (x < 0)
			return false;
		x = abs(x);
		vector<int> number;
		while (x > 0)
		{
			number.push_back(x % 10);
			x /= 10;
		}
		auto i = number.begin();
		auto j = number.rbegin();
		for (; i != number.end(); i++, j++) {
			if (*i != *j)
				return false;
		}
		return true;
	}
	bool isPalindrome_second(int x) {
		//x为负数或各位数为0，则不可能为回文
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		int Pal_x = 0;
		//逆转x的后半部分与前部分做比较
		//当pal_x >= x表示到了一半
		while (x > Pal_x) {
			Pal_x = Pal_x * 10 + x % 10;
			x /= 10;
		}
		return (x == Pal_x || x == Pal_x / 10);
	}
	//13. 罗马数字转整数
	int romanToInt(string s) {
		int result = 0;
		map<char, int> dic = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
		for (auto i = s.begin(); i != s.end(); i++) {
			if ((i != (s.end() - 1)) && dic[*i] < dic[*(i + 1)]) {
				result += dic[*(i + 1)] - dic[*i];
				i++;
			}
			else
				result += dic[*i];
		}
	}
	//14. 最长公共前缀
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		string result;
		string first = strs[0];
		int index = 0;
		for (auto value : first) {
			for (auto i = strs.begin() + 1; i != strs.end(); i++) {
				if (index > ((*i).size() - 1)) {
					return result;
				}
				if ((index < (*i).size()) && (*i)[index] != value) {
					return result;
				}
			}
			index++;
			result += value;
		}
		return result;
	}
	//20. 有效的括号
	bool isValid(string s) {
		stack<char> temp;
		for (auto value : s) {
			if (temp.empty())
				temp.push(value);
			else {
				switch (value) {
				case ')':
					if (temp.top() == '(')
						temp.pop();
					else
						temp.push(value);
					break;
				case ']':
					if (temp.top() == '[')
						temp.pop();
					else
						temp.push(value);
					break;
				case '}':
					if (temp.top() == '{')
						temp.pop();
					else
						temp.push(value);
					break;
				default:
					temp.push(value);
					break;
				}
			}
		}
		return (temp.empty());
	}
	//21. 合并两个有序链表
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode*ptr = head;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				ptr->next = new ListNode(l1->val);
				ptr = ptr->next;
				l1 = l1->next;
			}
			else {
				ptr->next = new ListNode(l2->val);
				ptr = ptr->next;
				l2 = l2->next;
			}
		}
		if (l1)
			ptr->next = l1;
		if (l2)
			ptr->next = l2;
		return head->next;
	}
	//26. 删除排序数组中的重复项
	int removeDuplicates_first(vector<int>& nums) {
		auto index = unique(nums.begin(), nums.end());
		nums.erase(index, nums.end());
		return nums.size();
	}
	int removeDuplicates_second(vector<int>& nums) {
		int i = 0;
		int j = i + 1;
		while (j < nums.size()) {
			if (nums[i] != nums[j])
				nums[++i] = nums[j];
			j++;
		}
		nums.erase(nums.begin() + i + 1, nums.end());
		return i + 1;
	}
	//27. 移除元素
	int removeElement(vector<int>& nums, int val) {
		auto i = nums.begin();
		while (i != nums.end()) {
			if (*i == val)
				i = nums.erase(i);
			else
				i++;
		}
		return nums.size();
	}
	//28 实现 strStr()
	int strStr(string haystack, string needle) {
		if (haystack.size()<needle.size()) {
			return -1;
		}
		if (needle.empty()) {
			return 0;
		}
		auto i = haystack.begin();
		bool flag = false;
		int cmpSize = needle.size();
		decltype(needle.begin()) index;
		while (i != haystack.end() - cmpSize+1) {
			if (*i == needle[0]) {
				string temp(i, i + cmpSize);
				if (temp == needle)
					return i - haystack.begin();
			}
			i++;
		}
		return -1;
	}
	//35 搜索插入位置
	int searchInsert(vector<int>& nums, int target) {
		vector<int>::size_type begin = 0, end = nums.size() - 1,mid=(begin+end)/2;
		while (end >= begin) {
			if (target <= nums[begin]) {
				return begin;
			}
			if (target > nums[end]) {
				return end + 1;
			}
			if (target == nums[end] && target>nums[end - 1]) {
				return end;
			}
			mid = (begin + end) / 2;
			if (target < nums[mid]) {
				if (target > nums[mid - 1])
					return mid;
				else
					end = mid - 1;
			}
			else if (target > nums[mid]) {
				if (target < nums[mid + 1])
					return mid+1;
				else
					begin=mid+1;
			}
			else {
				if (target > nums[mid - 1])
					return mid;
				end = mid-1;
			}
		}
		return 0;
	}
    // 38. 外观数列
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		}
		string before_str("1");
		string result;
		int index = 1, curCount;
		char curChar;
		while (index < n) {
			curChar = before_str[0];
			curCount = 1;
			result = "";
			for (auto i = before_str.begin()+1; i != before_str.end(); i++) {
				if (*i == curChar) {
					curCount += 1;
				}
				else {
					result += char(curCount+'0')+curChar;
					curChar = *i;
					curCount = 1;
				}
			}
			result = result +  char(curCount + '0') + curChar;; //加上最后一个字符的数目
			before_str = result;
			index++;
		}
		return result;
	}
	//53. 最大子序和
	int maxSubArray(vector<int>& nums) {

		int max = nums[0];
		int curMax = max;
		for (auto i = nums.begin() + 1; i != nums.end(); i++) {
			curMax = (curMax + *i)>*i ? curMax + *i : *i;
			max = curMax>max ? curMax : max;
		}
		return max;
	}
	//58. 最后一个单词的长度
	//从左向右
	int lengthOfLastWord(string s) {
		string curWord = "";
		string result;
		for (auto i = s.begin(); i != s.end(); i++) {
			if (isspace(*i)) {
				if(!curWord.empty())
					result = curWord;
				curWord = "";
			}
			else
				curWord = curWord + *i;
		}
		if (!isspace(*(s.end() - 1))) {
			result = curWord;
		}
		return result.size();
	}
	//从右向左
	int lengthOfLastWord_second(string s) {
		int i = s.size() - 1;
		while (i >=0 && isspace(s[i])) {
			i--;
		}
		int end = i;
		while (i >= 0 && !isspace(s[i])) {
			i--;
		}
		int start = i;
		return end - start;
	}
};
string pinjie(vector<string> vec) {
	if (vec.empty())
		return "";
	string result;
	for (auto i = vec.begin(); i != vec.end()-1; i++) {
		result = result + *i + "-";
	}
	result += *(vec.end() - 1);
	return result;
}
void high_feature(int i, vector<vector<string>> &feature,vector<string> &temp_result,vector<string> &result) {
	if (i >= feature.size()) {
		result.push_back(pinjie(temp_result));
		return;
	}
	for (auto index = 0; index < feature[i].size(); index++) {
		temp_result.push_back(feature[i][index]);
		high_feature(i + 1, feature,temp_result,result);
		temp_result.pop_back();
	}
}
int stringInput() {
	int n, ans = 0;
	vector<vector<string>> feature;
	vector<string> result;
	vector<string> temp_result;
	string temp;
	string line;
	char input_temp[100];
	while (cin >> n)
	{
		int line_number = n;
		while (line_number && getline(cin, line)) {
			vector<string> temp_string;
			if (line.size() == 0)
				continue;
			line_number--;
			istringstream in(line);
			while (in >> temp) {
				temp_string.push_back(temp);
			}
			feature.push_back(temp_string);
		}
		high_feature(0, feature, temp_result, result);
		for (auto value : result)
			cout << value << endl;
	}
	return 0;
}
