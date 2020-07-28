#include "algorithms.h"
#include "support_functions.h"

//构造器
algorithms::algorithms()
{

}

//析构器
algorithms::~algorithms()
{
}




//算法
//最大公共子序列
void algorithms::lcs(string a, string b)
{
	int dp[30][30];

	for (int i = 0; i <= a.size(); i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j <= b.size(); j++) {
		dp[0][j] = 0;
	}

	int length = -1;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
			else {
				dp[i][j] = 0;
			}

			if (length < dp[i][j])
				length = dp[i][j];
		}
	}

	cout << length << endl;

}

string algorithms::replaceSpace(string s)
{
	if (s.size() == 0)
		return s;

	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			count++;
	}

	char* answer = new char[s.size() + 1 + 2 * count];
	int i = s.size() - 1;
	int j = 2 * count + s.size() - 1;
	answer[j + 1] = '\0';

	while (i >= 0) {
		if (s[i] == ' ') {
			answer[j--] = '0';
			answer[j--] = '2';
			answer[j--] = '%';
		}
		else {
			answer[j--] = s[i];
		}
		i--;
	}

	string s1 = answer;
	return s1;
}

string algorithms::reverseString(string s)
{
	string answer = "";
	reverse(s.begin(), s.end());
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			string sub = s.substr(j, i - j);
			reverse(sub.begin(), sub.end());
			answer += sub + " ";
			j = i + 1;
		}
	}

	if (j < s.size()) {
		string sub = s.substr(j, s.size() - j);
		reverse(sub.begin(), sub.end());
		answer += sub;
	}

	return answer;
}

int algorithms::calDistance(string a, string b)
{
	vector<vector<int>> dp = support_functions::initTwoVector(a.size() + 1, b.size() + 1);
	for (int i = 0; i <= a.size(); i++) {
		dp[i][0] = i;
	}

	for (int j = 0; j <= b.size(); j++) {
		dp[0][j] = j;
	}
	
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = support_functions::min(dp[i - 1][j - 1], support_functions::min(dp[i][j - 1], dp[i - 1][j])) + 1;
			}
		}
	}

	return dp[a.size()][b.size()];
}


//斜向输出数组
void algorithms::x_print_matrix(vector<vector<int>> a, int n)
{
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; i + j < n; j++) {
			cout << a[i + j][j] << " ";
		}
		cout << endl;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			cout << a[i][i + j] << " ";
		}
		cout << endl;
	}
}

//顺时针输出数组
void algorithms::right_time_print_matrix(vector<vector<int>> a, int n)
{
	bool** check = new bool* [n];
	for (int i = 0; i < n; i++) {
		check[i] = new bool[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = true;
		}
	}

	int count = 1;
	int x = 0;
	int y = 0;
	int state = 0;
	check[x][y] = false;
	cout << a[x][y] << " ";
	while (count < n * n) {
		switch (state) {
		case 0:
			if (y + 1 < n) {
				if (check[x][y + 1] == true) {
					y++;
					check[x][y] = false;
					count++;
					cout << a[x][y] << " ";
				}
				else {
					state = 1;
				}
			}
			else {
				state = 1;
			}
			break;

		case 1:
			if (x + 1 < n) {
				if (check[x + 1][y] == true) {
					x++;
					check[x][y] = false;
					count++;
					cout << a[x][y] << " ";
				}
				else {
					state = 2;
				}
			}
			else {
				state = 2;
			}
			break;

		case 2:
			if (y - 1 >= 0) {
				if (check[x][y - 1] == true) {
					y--;
					check[x][y] = false;
					count++;
					cout << a[x][y] << " ";
				}
				else {
					state = 3;
				}
			}
			else {
				state = 3;
			}
			break;

		case 3:
			if (x - 1 >= 0) {
				if (check[x - 1][y] == true) {
					x--;
					check[x][y] = false;
					count++;
					cout << a[x][y] << " ";
				}
				else {
					state = 0;
				}
			}
			else {
				state = 0;
			}
		}


	}

}

//快排
void algorithms::quick_sort(vector<int> a, int left, int right)
{
	if (left > right)
		return;

	int standard = a[left];
	int i = left;
	int j = right;

	while (i < j) {
		while (i < j && a[j] >= standard) {
			j--;
		}

		while (i < j && a[i] <= standard) {
			i++;
		}

		if (i < j) {
			support_functions::swap(a[i], a[j]);
		}
	}
	support_functions::swap(a[i], a[left]);

	quick_sort(a, left, i - 1);
	quick_sort(a, i + 1, right);
}

//三数和为0
void algorithms::three_sum(vector<int> a,int n)
{
	algorithms::quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		int left = i + 1;
		int right = n - 1;

		int target = 0 - a[i];
		while (left < right) {
			int temp = a[left] + a[right];
			
			if (temp == target) {
				cout << a[left] << "  " << a[right] << "  " << a[i] << endl;

				while (left < right && left < n - 1 && a[left] == a[left + 1]) {
					left++;
				}

				while (left < right && right >= 0 && a[right] == a[right - 1]) {
					right--;
				}
				left++;
				right--;
			}
			else if (temp > target) {
					right--;
			}
			else {
				left++;
			}
			
			while (i < n - 1 && a[i] == a[i + 1]) {
				i++;
			}
		}
	}
}

//给定rand5函数生成rand7
int algorithms::rand5_to_rand7()
{
	int a = rand() % 5;
	int b = rand() % 5;

	int c = a * 5 + b;

	while (c == 22 || c == 23 || c == 24 || c == 25) {
		a = rand() % 5;
		b = rand() % 5;
		c = a * 5 + b;
	}

	return c % 7 + 1 ;
}

//在一个向右递增，向下递增的二维数组找到目标
bool algorithms::findInIncreaseTwo(vector<vector<int>> a, int target)
{
	if (a.size() == 0)
		return false;

	if (a[0].size() == 0)
		return false;

	int x_length = a.size();
	int y_length = a[0].size();

	int i = 0;
	int j = y_length - 1;

	while (i < x_length && j >= 0) {
		if (target == a[i][j]) {
			return true;
		}else if (a[i][j] < target) {
				i++;
		}
		else {
			j--;
		}
	}

	return false;
}

int algorithms::maxSumArray(vector<int> a)
{
	vector<int>dp = support_functions::initOneVector(a.size());
	dp[0] = a[0];
	int max_ = a[0];
	for (int i = 1; i < a.size(); i++) {
		dp[i] = support_functions::max(a[i], dp[i - 1] + a[i]);
		max_ = support_functions::max(dp[i], max_);
	}
	return max_;
}

vector<vector<int>> algorithms::mergeInterval(vector<vector<int>> a)
{
	sort(a.begin(), a.end());
	vector<vector<int>>ans;
	int i = 0;
	while(i < a.size()){
		int t = a[i][1];
		int j = i + 1;

		while (j < a.size() && a[j][0] <= t) {
			t = support_functions::max(a[j][1], t);
			j++;
		}

		ans.push_back({ a[i][0],t });
		i = j;
	}

	return ans;
}

//链表相关

//判断是否有环
bool algorithms::judgeRing(Node *head)
{
	if (head == NULL || head->getNext() == NULL)
		return false;

	Node* slow = head;
	Node* fast = head;

	do{
		slow = slow->getNext();
		fast = fast->getNext()->getNext();

		if (slow == fast) {
			return true;
		}
	} while (fast != NULL && fast->getNext() != NULL);

	return false;
}


//找环节点
Node* algorithms::cross_node(Node *head)
{
	Node* slow = head;
	Node* fast = head;

	do {
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	} while (slow != fast);

	int count = 0;
	
	do {
		fast = fast->getNext();
		count++;
	} while (slow != fast);

	fast = head;
	slow = head;
	for (int i = 0; i < count; i++) {
		fast = fast->getNext();
	}

	while (slow != fast) {
		slow = slow->getNext();
		fast = fast->getNext();
	}

	return slow;
}

//合并有序链表
Node* algorithms::merget_list(Node *l1, Node *l2)
{
	if (l1 == NULL)
		return l2;

	if (l2 == NULL)
		return l1;

	Node* p = NULL;
	if (l1->getVal() < l2->getVal()) {
		p = l1;
		p->setNext(merget_list(l1->getNext(), l2));
	}
	else {
		p = l2;
		p->setNext(merget_list(l1, l2->getNext()));
	}

	return p;
}

//反转链表_递归
Node* algorithms::RecReverseLink(Node *head)
{
	if (head->getNext() == NULL)
		return head;

	Node* temp = RecReverseLink(head->getNext());
	head->getNext()->setNext(head);
	head->setNext(NULL);

	return temp;
}

Node* algorithms::IteReverseLink(Node* head)
{
	Node* p = NULL;
	Node* temp = head;
	Node* temp1 = head->getNext();

	while (temp) {
		temp->setNext(p);
		p = temp;
		temp = temp1;

		if (temp == NULL)
			break;

		temp1 = temp1->getNext();
	}

	return p;
}

//倒数第K个节点
Node* algorithms::lastKNode(Node *head,int k)
{
	Node* fast = head;

	for (int i = 0; i < k; i++) {
		fast = fast->getNext();
	}

	while (fast != NULL) {
		head = head->getNext();
		fast = fast->getNext();
	}

	return head;
}

//重排链表
void algorithms::reorderList(Node* head)
{
	if (head == NULL || head->getNext() == NULL || head->getNext()->getNext() == NULL)
		return;

	Node* slow = head;
	Node* fast = head;

	while (fast && fast->getNext()) {
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}

	Node* temp = slow->getNext();
	slow->setNext(NULL);

	Node* lasthead = IteReverseLink(temp);
	temp = head;
	Node* temp1 = head->getNext();
	Node* lastnext = lasthead->getNext();
	while (lasthead) {
		lasthead->setNext(temp1);
		temp->setNext(lasthead);
		lasthead = lastnext;

		if (lasthead == NULL)
			break;

		lastnext = lastnext->getNext();
		temp = temp1;
		temp1 = temp1->getNext();
	}
}

