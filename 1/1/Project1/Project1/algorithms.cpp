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

//斜向输出数组
void algorithms::x_print_matrix(int** a, int n)
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
void algorithms::right_time_print_matrix(int** a, int n)
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
void algorithms::quick_sort(int* a, int left, int right)
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
void algorithms::three_sum(int* a,int n)
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

	for (int i = 0; i < count; i++) {
		fast = fast->getNext();
	}

	while (slow != fast) {
		slow = slow->getNext();
		fast = fast->getNext();
	}

	return slow;
}