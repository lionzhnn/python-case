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
     ListNode(int x) : val(x), next(NULL) {}
 };


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 class CQueue {
 public:
	 stack<int> stack_in;
	 stack<int> stack_out;
	 CQueue() {
	 }
	 void appendTail(int value) {
		 stack_in.push(value);
	 }

	 int deleteHead() {
		 if (stack_out.empty()) {
			 while (!stack_in.empty()) {
				 stack_out.push(stack_in.top());
				 stack_in.pop();
			 }
		 }
		 if (stack_out.empty())
			 return -1;
		 else {
			 int result = stack_out.top();
			 stack_out.pop();
			 return result;
		 }
	 }
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
//剑指 Offer 11. 旋转数组的最小数字
	int minArray(vector<int>& numbers) {
		int begin = 0, end = numbers.size() - 1, mid ;
		while (begin < end) {
			mid = begin+(end-begin) / 2;
			if (numbers[mid] < numbers[end])
				end = mid;
			else if (numbers[mid] > numbers[end])
				begin = mid + 1;
			else
				end -= 1;
		}
		return numbers[begin];
	}
	//剑指 Offer 10- I. 斐波那契数列
	int fib_one(int n) {
		vector<int> fib_n{0,1};
		for (int i = 2; i <= n; i++) {
			fib_n.push_back(fib_n[i - 1]+fib_n[i - 2]);
		}
		return fib_n[n];
	}
	int fib_two(int n) {
		if (n <= 1)
			return n;
		int index = 2, one = 0, two = 1, result;
		while (index <= n) {
			result = (one + two) % 1000000007;
			one = two;
			two = result;
			index++;
		}
		return result;
	}
	//剑指 Offer 10- II. 青蛙跳台阶问题
	int numWays(int n) {
		if (n <= 1)
			return 1;
		int index = 2, one = 1, two = 1, result;
		while (index <= n) {
			result = (one + two) % 1000000007;
			one = two;
			two = result;
			index++;
		}
		return result;
	}
	//剑指 Offer 07. 重建二叉树 递归方法 
	void TreeTraverse_level(TreeNode* root) {
		if (!root)
			return;
		queue<TreeNode*> traverse;
		traverse.push(root);
		while (!traverse.empty()) {
			TreeNode* first = traverse.front();
			traverse.pop();
			cout << first->val << " ";
			if (first->left)
				traverse.push(first->left);
			if (first->right)
				traverse.push(first->right);
		}
		cout << endl;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;
		int root_value = preorder[0];
		vector<int>::iterator index = inorder.begin();
		while (*index != root_value)
			index++;
		vector<int> r_inorder,r_preorder,l_inorder,l_preorder;
		//左子树中序
		copy(inorder.begin(), index , back_inserter(l_inorder));
		//右子树中序
		copy(index + 1, inorder.end() , back_inserter(r_inorder));
		//左子树前序
		copy(preorder.begin()+1, preorder.begin()+l_inorder.size()+1, back_inserter(l_preorder));
		//右子树前序
		copy(preorder.begin() + l_inorder.size()+1, preorder.end() , back_inserter(r_preorder));
		TreeNode* root = new TreeNode(*index);
		root->left = buildTree(l_preorder, l_inorder);
		root->right = buildTree(r_preorder, r_inorder);
		return root;
	}
	//使用map优化拷贝，减少运行时间
	TreeNode* buildTree_second(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return nullptr;
		map<int, int> in_order_map;
		for (int i = 0; i < inorder.size(); i++) {
			in_order_map[inorder[i]] = i;
		}
		TreeNode* root = buildTree_index(preorder, inorder, in_order_map, 0, preorder.size() - 1, 0, preorder.size() - 1);
		return root;
	}
	TreeNode* buildTree_index(vector<int>& preorder, vector<int>& inorder,map<int,int> &in_order_map,int pre_begin,int pre_end,int in_begin,int in_end) {
		//没有元素
		if (pre_begin > pre_end)
			return nullptr;
		int root_value = preorder[pre_begin], root_index = in_order_map[root_value];
		TreeNode* root = new TreeNode(root_value);
		//只有一个元素
		if (pre_begin == pre_end)
			return root;
		else {
			root->left = buildTree_index(preorder, inorder, in_order_map, pre_begin+1, pre_begin-in_begin+root_index, in_begin, root_index - 1);
			root->right = buildTree_index(preorder, inorder, in_order_map, pre_begin - in_begin + root_index + 1, pre_end, root_index + 1, in_end);
		}
		return root;
	}
	//剑指 Offer 06. 从尾到头打印链表
	vector<int> reversePrint(ListNode* head) {
		vector<int> result;
		while (head) {
			result.insert(result.begin(), head->val);
		}
		return result;
	}
	//剑指 Offer 05. 替换空格
	string replaceSpace(string s) {
		if (s.empty())
			return "";
		string temp;
		for (char value : s) {
			if (isspace(value))
				temp += "%20";
			else
				temp += value;
		}
		return temp;
	}
	//剑指 Offer 04. 二维数组中的查找
	bool findNumberInArray(vector<int> &matrix, int target) {
		auto begin = matrix.begin();
		auto end = matrix.end()-1;
		while (end >= begin) {
			auto mid = begin + (end - begin) / 2;
			if (target < *begin)
				return false;
			if (target > *end)
				return false;
			if (target == *begin || target == *end || target == *mid)
				return true;
			if (target < *mid)
				end = mid - 1;
			else
				begin = mid + 1;
		}
		return false;
	}
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		for (vector<int> & value : matrix) {
			if (value.empty())
				return false;
			if (findNumberInArray(value, target))
				return true;
		}
		return false;
	}
	//剑指 Offer 03. 数组中重复的数字
	int findRepeatNumber(vector<int>& nums) {
		set<int> temp;
		for (auto value : nums) {
			if (temp.find(value) == temp.end()) {
				temp.insert(value);
			}
			else {
				return value;
			}
		}
		return -1;

	}
	//剑指 Offer 12. 矩阵中的路径 回溯法
	bool find_path(vector<vector<char>>& board, string &word, vector<vector<bool>>&flag, int word_index, int begin_x, int begin_y) {
		if (begin_x < 0 || begin_x >= board.size() || begin_y < 0 || begin_y >= board[0].size())
			return false;
		if (word_index == word.size() - 1 && flag[begin_x][begin_y] && board[begin_x][begin_y] == word[word_index])
			return true;
		else if (word_index < word.size() && flag[begin_x][begin_y] && board[begin_x][begin_y] == word[word_index]) {
			//剪枝已经找过的路径
			flag[begin_x][begin_y] = false;
			vector<vector<bool>> temp_flag = flag;
			bool result = find_path(board, word, temp_flag, word_index + 1, begin_x, begin_y - 1)
				|| find_path(board, word, temp_flag, word_index + 1, begin_x, begin_y + 1)
				|| find_path(board, word, temp_flag, word_index + 1, begin_x - 1, begin_y)
				|| find_path(board, word, temp_flag, word_index + 1, begin_x + 1, begin_y);
			if (!result)
				flag[begin_x][begin_y] = true;
			return result;
		}
		//剪枝不满足的情况
		return false;

	}
	bool exist(vector<vector<char>>& board, string &word) {
		vector<pair<int, int>> begin_index;
		vector<vector<bool>> flag, temp_flag;
		for (int i = 0; i < board.size(); i++) {
			vector<bool> temp;
			for (int j = 0; j < board[0].size(); j++) {
				temp.push_back(true);
				//找到开始与单词首字母相同的下标，可能不止一个
				if (board[i][j] == word[0])
					begin_index.push_back(make_pair(i, j));
			}
			//初始标志位设为false
			flag.push_back(temp);
		}
		for (int i = 0; i < begin_index.size(); i++) {
			pair<int, int> temp_index = begin_index[i];
			temp_flag = flag;
			bool temp_result = find_path(board, word, temp_flag, 0, temp_index.first, temp_index.second);
			if (temp_result)
				return true;
		}
		return false;
	}

	//剑指 Offer 13. 机器人的运动范围
	int get(int x) {
		int result = 0;
		while (x>0)
		{
			result = result + x % 10;
			x = x / 10;
		}
		return result;
	}
	int moving(vector<vector<bool>> &mark, int m, int n, int k, int curR, int curC) {
		if (curR < 0 || curR >= m || curC < 0 || curC >= n || !mark[curR][curC])
			return 0;
		else {
			int curK = get(curR) + get(curC);
			if (curK > k || curK < 0)
				return 0;
			mark[curR][curC] = false;
			int result = 1+moving(mark,m, n, k,  curR, curC - 1) + moving(mark,m, n, k, curR, curC + 1)
				+ moving(mark,m, n, k,  curR - 1, curC) + moving(mark,m, n, k, curR + 1, curC);
			return result;
		}
	}
	int movingCount(int m, int n, int k) {
		const int array_m = m;
		const int array_n = n;
		vector<vector<bool>> mark;
		for (int i = 0; i < m; i++) {
			vector<bool> temp(n, true);
			mark.push_back(temp);
		}
		return moving(mark, m, n, k, 0, 0);
	}

	//剑指 Offer 14- I. 剪绳子
	//动态规划
	int cuttingRope(int n) {
		vector<vector<int>> dp;
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			if (i == 0) {
				for (int j = 0; j < n; j++)
					temp.push_back(j + 1);
			}
			else{
				temp = vector<int>(n, 0);
			}
			dp.push_back(temp);
		}
		int result = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i; j < 3; j++) {
				int find_max = 0;
				//数学证明，绳子长度为e时，得到的乘积最大，因为长度需要为整数，故取绳子长度尽量为3
				for (int k = 1; k <= (j + 1) / 2 && k <= 3; k++) {
					find_max = max(find_max, k*dp[i - 1][j-k]);
				}
				dp[i][j] = find_max;
				result = (result >= dp[i][j] ? result : dp[i][j]);
			}
		}
		return result;
	}
	//数学
	int cuttingRope_two(int n) {
		if (n <= 3)
			return n - 1;
		int a = n / 3, b = n % 3; 
		if (b == 0)
			return pow(a,1.0/3);
		else if (b == 1)
			return int(pow(a-1,1.0/3)) * 4;
		else
			return int(pow(a,1.0/3)) * 2;
	}

	//剑指 Offer 14- II. 剪绳子 II
	int cuttingRope_II(int n) {
		if (n <= 3) return n - 1;
		if (n == 4) return 4;
		long res = 1;
		while (n > 4)
		{
			res *= 3;
			res %= 1000000007;
			n -= 3;
		}
		// 最后n的值只有可能是：2、3、4。而2、3、4能得到的最大乘积恰恰就是自身值
		// 因为2、3不需要再剪了（剪了反而变小）；4剪成2x2是最大的，2x2恰巧等于4
		return res * n % 1000000007;
	}

	//剑指 Offer 15. 二进制中1的个数
	int hammingWeight(uint32_t n) {
		int a, result = 0;
		while (n>0) {
			a = n % 2;
			n = n / 2;
			result = a ? result + 1 : result;
		}
		return result;
	}

	//剑指 Offer 16. 数值的整数次方
	double power(double x, int n) {
		if (n == 1)
			return x;
		double result = power(x, n / 2);
		if (n % 2) {
			result = result*result*x;
		}
		else
			result = result*result;
		return result;
	}
	double myPow(double x, int n) {
		int a = abs(n);
		bool b = n < 0 ? true : false;
		if (a % 2)
			return x*power(x, a - 1);
		else
			return power(x, a);
	}

	//剑指 Offer 17. 打印从1到最大的n位数
	vector<int> printNumbers(int n) {
		int x = 1;
		int index = pow(10, n);
		vector<int> result;
		while (x < index) {
			result.push_back(x);
			x++;
		}
		return result;
	}

	//正则项匹配
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i < n; i++) {
			//如果p的第i+1个字符也就是p.charAt(i)是"*"的话，
			//那么他就可以把p的第i个字符给消掉（也就是匹配0次）。
			//我们只需要判断p的第i-1个字符和s的前0个字符是否匹
			//配即可。比如p是"a*b*"，如果要判断p的第4个字符
			//"*"和s的前0个字符是否匹配，因为字符"*"可以消去
			//前面的任意字符，只需要判断p的"a*"和s的前0个字
			//符是否匹配即可
			if (p[i] == '*' && dp[0][i - 1]) {
				dp[0][i + 1] = true;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (p[j] == s[i] || p[j] == '.') {
					dp[i + 1][j + 1] = dp[i][j];
				}
				else if (p[j] == '*') {
					//递归公式
					if (p[j-1] == s[i] || p[j-1] == '.') {
						dp[i + 1][j + 1] = dp[i][j + 1];
					}
					dp[i + 1][j + 1] = dp[i + 1][j + 1] | dp[i + 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
	//双端队列
	vector<int> exchange(vector<int>& nums) {
		vector<int> result;
		for (auto i = nums.begin(); i != nums.end(); i++) {
			if (*i % 2) {
				result.insert(result.begin(), *i);
			}
			else {
				result.push_back(*i);
			}
		}
		for (auto i = result.begin(); i != result.end(); i++)
			cout << *i << endl;
		return result;
	}
	//双端指针
	vector<int> exchange_two(vector<int>& nums) {
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			while (i < j && (nums[i] % 2 ))
				i++;
			while (i < j && (nums[j] % 2 == 0))
				j--;
			int temp = nums[j]; nums[j] = nums[i]; nums[i] = temp;
		}
		return nums;
	}

	//双端队列
	ListNode* getKthFromEnd(ListNode* head, int k) {
		queue<ListNode*> nodes;
		ListNode *ptr = head;
		while (ptr) {
			if (nodes.empty())
				nodes.push(ptr);
			else if (nodes.size() < k)
				nodes.push(ptr);
			else {
				nodes.pop();
				nodes.push(ptr);
			}
			ptr = ptr->next;
		}
		return (nodes.size()<k)? nullptr: nodes.front();
	}
	//双指针
	ListNode* getKthFromEnd_ptr(ListNode* head, int k) {
		ListNode *first = head, *second = head;
		for (int i = 0; i<k && first; i++) {
			first = first->next;
		}
		while (first) {
			first = first->next;
			second = second->next;
		}
		return second;
	}
	//循环
	int size = 0;
	ListNode* getKthFromEnd_three(ListNode* head, int k) {
		if (head == nullptr)
			return head;
		ListNode *node = getKthFromEnd(head->next, k);
		if (++size == k)
			return head;
		return node;
	}

	//剑指 Offer 24. 反转链表
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head=NULL, *ptr;
		while (head) {
			ptr = head->next;
			head->next = new_head;
			new_head = head;
			head = ptr;
		}
		return new_head;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *result, *ptr = result;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				result->next = new ListNode(l1->val);
				l1 = l1->next;
				result = result->next;
			}
			else {
				result->next = new ListNode(l2->val);
				l2 = l2->next;
				result = result->next;
			}
		}
		if (l1) {
			result->next = l1;
		}
		if (l2) {
			result->next = l2;
		}
		return ptr->next;
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<vector<bool>> flag(matrix.size(), vector<bool>(matrix[0].size(), true));
		vector<int> result;
		int index_i = 0, index_j = 0;
		while (index_i >= 0 && index_i < matrix.size() && index_j >= 0 && index_j < matrix[0].size() && flag[index_i][index_j]) {
			flag[index_i][index_j] = false;
			result.push_back(matrix[index_i][index_j]);
			//left
			index_j += 1;
			while (index_j < matrix[0].size() && flag[index_i][index_j]) {
				flag[index_i][index_j] = false;
				result.push_back(matrix[index_i][index_j]);
				index_j += 1;
			}
			index_j -= 1;
			//down
			index_i += 1;
			while (index_i < matrix.size() && flag[index_i][index_j]) {
				flag[index_i][index_j] = false;
				result.push_back(matrix[index_i][index_j]);
				index_i += 1;
			}
			index_i -= 1;
			//left
			index_j -= 1;
			while (index_j >=0 && flag[index_i][index_j]) {
				flag[index_i][index_j] = false;
				result.push_back(matrix[index_i][index_j]);
				index_j -= 1;
			}
			index_j += 1;
			//left
			index_i -= 1;
			while (index_i >= 0 && flag[index_i][index_j]) {
				flag[index_i][index_j] = false;
				result.push_back(matrix[index_i][index_j]);
				index_i -= 1;
			}
			index_i += 1;
		}
	}
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int i = 0, j = 0;
		stack<int> temp;
		for (auto i = pushed.begin(); i != pushed.end(); i++) {
			temp.push(*i);
			while (!temp.empty() && (temp.top() == popped[j])) {
				temp.pop();
				j++;
			}
		}
		return temp.empty();
	}
	//剑指 Offer 32 - I. 从上到下打印二叉树
	vector<int> levelOrder(TreeNode* root) {
		queue<TreeNode*> print_queue;
		vector<int> result;
		print_queue.push(root);
		while (!print_queue.empty()) {
			TreeNode* temp = print_queue.front();
			print_queue.pop();
			if (temp)
				continue;
			else {
				result.push_back(temp->val);
				print_queue.push(temp->left);
				print_queue.push(temp->right);
			}
		}
		return result;
	}
	//剑指 Offer 32 - II.从上到下打印二叉树 II
	vector<vector<int>> levelOrder_II(TreeNode* root) {
		queue<pair<TreeNode*, int>> print_queue;
		vector<int> result;
		vector<vector<int>> final_result;
		print_queue.push(make_pair(root, 0));
		int cur_level = 0;
		while (!print_queue.empty()) {
			pair<TreeNode*,int> temp = print_queue.front();
			print_queue.pop();
			if (temp.second != cur_level) {
				cur_level = temp.second;
				final_result.push_back(result);
				result.clear();
			}
			if (!temp.first)
				continue;
			else {
				result.push_back(temp.first->val);
				print_queue.push(make_pair(temp.first->left, cur_level + 1));
				print_queue.push(make_pair(temp.first->right, cur_level + 1));
			}			
		}
		return final_result;
	}
	//剑指 Offer 32 - III. 从上到下打印二叉树 III
	vector<vector<int>> levelOrde_III(TreeNode* root) {
		stack<pair<TreeNode*, int>> cur_stack;
		stack<pair<TreeNode*, int>> next_stack;
		vector<int> result;
		vector<vector<int>> final_result;
		cur_stack.push(make_pair(root, 1));
		int cur_level = 1;
		while (!cur_stack.empty()) {
			pair<TreeNode*, int> temp = cur_stack.top();
			cur_stack.pop();
			if (temp.second != cur_level) {
				cur_level = temp.second;
				final_result.push_back(result);
				result.clear();
			}
			if (!temp.first) {
				//当前层打印完毕，替换为下一层
				if (cur_stack.empty()) {
					next_stack.swap(cur_stack);
				}
				continue;
			}
			else {
				result.push_back(temp.first->val);
				if (cur_level % 2) {
					next_stack.push(make_pair(temp.first->left, cur_level + 1));
					next_stack.push(make_pair(temp.first->right, cur_level + 1));
				}
				else {
					next_stack.push(make_pair(temp.first->right, cur_level + 1));
					next_stack.push(make_pair(temp.first->left, cur_level + 1));

				}
			}
			//当前层打印完毕，替换为下一层
			if (cur_stack.empty()) {
				next_stack.swap(cur_stack);
			}
		}
		return final_result;
	}

	//剑指 Offer 33. 二叉搜索树的后序遍历序列
	bool verifyPostorder(vector<int>& postorder) {
		//为空 返回真
		if (postorder.empty())
			return true;
		return recur(postorder, 0, postorder.size() - 1);
	}
	bool recur(vector<int>& postorder, int left, int root) {
		if (left == root)
			return true;
		int left_end = left;
		while ((left_end< root) && (postorder[left_end] < postorder[root]))
			left_end += 1;
		int right_end = left_end;
		while ((right_end< root) && (postorder[right_end] > postorder[root]))
			right_end += 1;
		if (right_end != root)
			return false;
		//只有左子树
		if (left_end == right_end)
			return recur(postorder, left, left_end - 1);
		//只有右子树
		if (left_end == left)
			return recur(postorder, left_end, right_end - 1);
		//左右子树都有
		return recur(postorder, left, left_end - 1) && recur(postorder, left_end, right_end - 1);
	}

	//剑指 Offer 34. 二叉树中和为某一值的路径
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> result;
		vector<vector<int>> final_result;
		path(root, sum, result, final_result, 0);
		return final_result;

	}
	void path(TreeNode *root, int sum, vector<int> result, vector<vector<int>> &final_result, int temp) {
		if (!root)
			return;
		if (!root->left && !root->right && ((temp + root->val) == sum)) {
			result.push_back(root->val);
			final_result.push_back(result);
			result.pop_back();
			return;
		}
		result.push_back(root->val);
		path(root->left, sum, result, final_result, temp + root->val);
		path(root->right, sum, result, final_result, temp + root->val);
	}

	//剑指 Offer 35. 复杂链表的复制
	Node* copyRandomList(Node* head) {
		map<Node*, int> node_set;
		map<int, Node*> new_node_set;
		vector<int> order;
		Node* ptr = head;
		int index = 1;
		node_set[NULL] = 0;
		//原来节点地址编号
		while (ptr) {
			node_set[ptr] = index;
			index++;
			ptr = ptr->next;
		}
		ptr = head;
		index = 1;
		new_node_set[0] = NULL;
		Node* new_link = new Node(0);
		Node *qtr = new_link;
		//找到各节点random对应的编号
		while (ptr) {
			order.push_back(node_set[ptr->random]);
			qtr->next = new Node(ptr->val);
			new_node_set[index] = qtr->next;
			qtr = qtr->next;
			ptr = ptr->next;
			index++;
		}
		//重新赋值random
		qtr = new_link->next;
		for (auto i = order.begin(); i != order.end(); i++) {
			qtr->random = new_node_set[*i];
			qtr = qtr->next;
		}
		return new_link->next;

	}

	//剑指 Offer 36. 二叉搜索树与双向链表
	D_Node* treeToDoublyList(D_Node* root) {
		D_Node *pre = NULL, *head = NULL;
		recur(root, pre, head);
		head->left = pre;
		pre->right = head;
		return head;
	}
	void recur(D_Node *cur, D_Node*& pre, D_Node*& head) {
		if (!cur)
			return;
		recur(cur->left, pre, head);
		if (pre) {
			cur->left = pre;
			pre->right = cur;
			pre = cur;
		}
		else {
			head = cur;
			pre = cur;
		}
		recur(cur->right, pre, head);
	}

	//剑指 Offer 38. 字符串的排列
	vector<string> permutation(string s) {
		vector<string> res;
		recur(s, 0, res);
		return res;

	}
	void recur(string s, int index,vector<string> &res) {
		if (index == (s.size() - 1)) {
			res.push_back(s);
		}
		set<char> unique;
		//依次固定index上字符
		for (int i = index; i < s.size(); i++) {
			if (unique.find(s[index]) == unique.end()) {
				unique.insert(s[i]);
				swap(s, index, i);
				recur(s, index + 1, res);
				swap(s, i, index);
			}
		}
	}
	void swap(string &s, int index1, int index2) {
		char temp = s[index1];
		s[index1] = s[index2];
		s[index2] = temp;
	}

	//剑指 Offer 39. 数组中出现次数超过一半的数字
	bool cmp(pair<int, int> num1, pair<int, int> num2) {
		return num1.second > num2.second;
	}
	int majorityElement(vector<int>& nums) {
		map<int, int> nums_set;
		for (auto i = nums.begin(); i!= nums.end(); i++) {
			if (nums_set.find(*i) == nums_set.end()) {
				nums_set[*i] = 1;
			}
			else {
				nums_set[*i] += 1;
			}
			if (nums_set[*i] > (nums.size() / 2))
				return *i;
		}
	}

	//剑指 Offer 40. 最小的k个数
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		//默认最大堆
		priority_queue<int> nums_k;
		vector<int> res;
		for (auto i = arr.begin(); i != arr.end(); i++) {
			if (nums_k.size() < k)
				nums_k.push(*i);
			else {
				if (*i < nums_k.top()) {
					nums_k.pop();
					nums_k.push(*i);
				}
			}
		}
		for (int i = 0; i < nums_k.size(); i++) {
			res.push_back(nums_k.top());
			nums_k.pop();
		}
		return res;

	}
};
