#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<deque>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//1.移动0
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int m = 0;
//        int n = 0;
//        vector<int> kop;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] == 0)
//            {
//                kop.push_back(i);
//            }
//        }
//        for (int j = 0; j < kop.size(); j++)
//        {
//            for (int i = kop[j] + 1; i < nums.size(); i++)
//            {
//                if (nums[i] != 0)
//                {
//                    nums[kop[j]] = nums[i];
//                    nums[i] = 0;
//                    kop[j] = i;
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> vec = { 4,2,4,0,0,3,0,5,1,0 };
//    s.moveZeroes(vec);
//    return 0;
//}



////2.三数之和
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        set<vector<int>> s;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            int l = i + 1;
//            int r = nums.size() - 1;
//            while (l < r)
//            {
//                if (nums[i] + nums[l] + nums[r] > 0)
//                {
//                    r--;
//                }
//                else if (nums[i] + nums[l] + nums[r] < 0)
//                {
//                    l++;
//                }
//                else
//                {
//                    s.insert({ nums[i],nums[l],nums[r] });
//                    l++;
//                    r--;
//                }
//            }
//        }
//        return vector<vector<int>>(s.begin(), s.end());
//    }
//};




////3.找到字符串中所有字母异位词
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> vec;
//        map<char, int> m1;
//        map<char, int> m2;
//        int n = p.size();
//        for (int i = 0; i < n; i++)
//        {
//            m1[p[i]]++;
//        }
//        for (int i = 0; i < s.size(); i++)
//        {
//            int j = n + i - 1;
//            for (int m = i; m <= j; m++)
//            {
//                m2[s[m]]++;
//            }
//            if (m1 == m2)
//            {
//                vec.push_back(i);
//            }
//            m2.clear();
//        }
//        return vec;
//    }
//};




//4.最长连续序列
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        set<int> s;
//        int mv = 0;
//        int i = 0;
//        for (int j = 0; j < nums.size(); j++)
//        {
//            while (s.count(nums[j] - 1) == 0 && i != j)
//            {
//                s.erase(nums[i]);
//                i++;
//            }
//            mv = max(mv, s.size());
//            s.insert(nums[j]);
//        }
//        return mv;
//    }
//};
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        set<int> s(nums.begin(), nums.end());
//        int cur = 0;
//        int curlen = 1;
//        int mv = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (s.count(nums[i] - 1) == 1)
//            {
//                continue;
//            }
//            else
//            {
//                cur = nums[i];
//                while (s.count(cur + 1) == 1)
//                {
//                    curlen++;
//                    cur++;
//                }
//                mv = max(curlen, mv);
//            }
//            curlen = 1;
//        }
//        return mv;
//    }
//};




//5.和为k的子数组
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        int mv = 0;
//        int i = 0;
//        int m = 0;
//        for (int j = 0; j < nums.size(); j++)
//        {
//            while (nums[j] + mv > k && i != j)
//            {
//                mv -= nums[i];
//                i++;
//            }
//            mv += nums[j];
//            if (mv == k)
//            {
//                m++;
//            }
//        }
//        return m;
//    }
//};
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int m = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int mv = 0;
//            for (int j = i; j < nums.size(); j++)
//            {
//                mv += nums[j];
//                if (mv == k)
//                {
//                    m++;
//                }
//            }
//        }
//        return m;
//    }
//};




////6.滑动窗口最大值
//class Solution {
//public:
//    deque<int> dq;
//    void pop_(int val)
//    {
//        if (!dq.empty() && dq.front() == val)
//        {
//            dq.pop_front();
//        }
//    }
//    void push_(int val)
//    {
//        while (!dq.empty() && val > dq.back())
//        {
//            dq.pop_back();
//        }
//        dq.push_back(val);
//    }
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int> vec;
//        for (int i = 0; i < k; i++)
//        {
//            push_(nums[i]);
//        }
//        for (int i = 1; i < nums.size() - k + 1; i++)
//        {
//            pop_(nums[i - 1]);
//            push_(nums[i + k - 1]);
//            vec.push_back(dq.front());
//        }
//        return vec;
//    }
//};




////7.合并区间
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> vec;
//        vector<int> v;
//        sort(intervals.begin(), intervals.end());
//        int i = 0;
//        bool judge = true;
//        for (i = 0; i < intervals.size(); i++)
//        {
//            v.clear();
//            v.push_back(intervals[i][0]);
//            if (intervals.size() == 1)
//            {
//                judge = false;
//            }
//            while (judge && intervals[i][1] >= intervals[i + 1][0])
//            {
//                i++;
//                if (i == intervals.size() - 1)
//                {
//                    break;
//                }
//            }
//            if (i == intervals.size() - 2)
//            {
//                judge = false;
//            }
//            if (i == 0)
//            {
//                v.push_back(intervals[0][1]);
//            }
//            else if (i != 0 && intervals[i][1] > intervals[i - 1][1])
//            {
//                v.push_back(intervals[i][1]);
//            }
//            else if (i != 0 && intervals[i][1] <= intervals[i - 1][1])
//            {
//                v.push_back(intervals[i - 1][1]);
//            }
//            vec.push_back(v);
//        }
//        return vec;
//    }
//};




////8.旋转数组
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        deque<int> dq(nums.begin(), nums.end());
//        for (int i = 0; i < k; i++)
//        {
//            int num = dq.back();
//            dq.pop_back();
//            dq.push_front(num);
//        }
//        vector<int>vec(dq.begin(), dq.end());
//        nums = vec;
//    }
//};





//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        vector<int> vec;
//        int i = 0;
//        int k = 0;
//        int num = 1;
//        int j = nums.size() - 1;
//        while (i != k || j != k)
//        {
//            if (k == nums.size())
//            {
//                break;
//            }
//            while (i != k)
//            {
//                num = num * nums[i];
//                i++;
//            }
//            while (j != k)
//            {
//                num = num * nums[j];
//                j--;
//            }
//            if (i == k && j == k)
//            {
//                vec.push_back(num);
//                num = 1;
//                k++;
//                i = 0;
//                j = nums.size() - 1;
//            }
//        }
//        return vec;
//    }
//};
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        vector<int> vec;
//        vector<int> left;
//        vector<int> right;
//        left.resize(nums.size());
//        right.resize(nums.size());
//        left[0] = 1;
//        right[nums.size() - 1] = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            left[i] = nums[i-1] * left[i - 1];
//        }
//        for (int i = nums.size() - 2; i >= 0; i--)
//        {
//            right[i] = nums[i+1] * right[i + 1];
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            vec.push_back(left[i] * right[i]);
//        }
//        return vec;
//    }
//};




//9.反转链表
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* p = head;
//        vector<int> vec;
//        while (p != nullptr)
//        {
//            vec.push_back(p->val);
//            p = p->next;
//        }
//        ListNode* q = new ListNode(vec[vec.size() - 1]);
//        ListNode* head1 = q;
//        for (int i = vec.size() - 2; i >= 0; i--)
//        {
//            ListNode* m = new ListNode(vec[i]);
//            head1->next = m;
//            head1 = head1->next;
//        }
//        return q;
//    }
//};
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (!head || !head->next) {
//            return head;
//        }
//        ListNode* newHead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//        return newHead;
//    }
//};





//10.回文链表
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if (head == nullptr)
//        {
//            return true;
//        }
//        static ListNode* p = head;
//        if (isPalindrome(head->next) == true)
//        {
//            if (p->val == head->val)
//            {
//                p = p->next;
//                return true;
//            }
//            else
//            {
//                p = p->next;
//                return false;
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
//};
//class Solution {
//    ListNode* frontPointer;
//public:
//    bool recursivelyCheck(ListNode* currentNode) {
//        if (currentNode != nullptr) {
//            if (!recursivelyCheck(currentNode->next)) {
//                return false;
//            }
//            if (currentNode->val != frontPointer->val) {
//                return false;
//            }
//            frontPointer = frontPointer->next;
//        }
//        return true;
//    }
//
//    bool isPalindrome(ListNode* head) {
//        frontPointer = head;
//        return recursivelyCheck(head);
//    }
//};





//11.合并有序链表
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* cur1 = list1;
//        ListNode* pre = new ListNode();
//        pre->next = list1;
//        ListNode* cur2 = list2;
//        if (cur1 == nullptr && cur2 == nullptr)
//        {
//            return nullptr;
//        }
//        if (cur1 == nullptr)
//        {
//            return cur2;
//        }
//        if (cur2 == nullptr)
//        {
//            return cur1;
//        }
//        ListNode* node = cur1->val <= cur2->val ? cur1 : cur2;
//        while (cur1 != nullptr && cur2 != nullptr)
//        {
//            if (cur1->val <= cur2->val)
//            {
//                pre->next = cur1;
//                pre = pre->next;
//                cur1 = cur1->next;
//            }
//            else
//            {
//                pre->next = cur2;
//                pre = pre->next;
//                cur2 = cur2->next;
//            }
//        }
//        if (cur1 == nullptr)
//        {
//            pre->next = cur2;
//        }
//        if (cur2 == nullptr)
//        {
//            pre->next = cur1;
//        }
//        return node;
//    }
//};
//class Solution {
//public:
//    ListNode* pre = new ListNode();
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr && list2 == nullptr)
//        {
//            return nullptr;
//        }
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        if (list2 == nullptr)
//        {
//            return list1;
//        }
//        if (list1->val <= list2->val)
//        {
//            pre->next = mergeTwoLists(list1->next, list2);
//        }
//        else
//        {
//            pre->next = mergeTwoLists(list1, list2->next);
//        }
//        return pre->next;
//    }
//};




////12.两数相加
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* node = new ListNode();
//        ListNode* node1 = node;
//        if (l1 == nullptr && l2 == nullptr)
//        {
//            return node;
//        }
//        int ans = 0;
//        while (l1 != nullptr && l2 != nullptr)
//        {
//            if (l1->val + l2->val + ans >= 10)
//            {
//                node->next = new ListNode(l1->val + l2->val + ans - 10);
//                node = node->next;
//                ans = 0;
//                ans++;
//            }
//            else
//            {
//                node->next = new ListNode(l1->val + l2->val + ans);
//                node = node->next;
//                ans = 0;
//            }
//            l1 = l1->next;
//            l2 = l2->next;
//        }
//        while (l1 == nullptr&&l2!=nullptr)
//        {
//            if (l2->val + ans >= 10)
//            {
//                node->next = new ListNode(l2->val + ans - 10);
//                node = node->next;
//                ans = 0;
//                ans++;
//            }
//            else
//            {
//                node->next = new ListNode(l2->val+ans);
//                ans = 0;
//                node = node->next;
//            }
//            l2 = l2->next;
//        }
//        while (l2 == nullptr&&l1!=nullptr)
//        {
//            if (l1->val + ans >= 10)
//            {
//                node->next = new ListNode(l1->val + ans - 10);
//                node = node->next;
//                ans = 0;
//                ans++;
//            }
//            else
//            {
//                node->next = new ListNode(l1->val+ans);
//                ans = 0;
//                node = node->next;
//            }
//            l1 = l1->next;
//        }
//        if (l2 == nullptr && l1 == nullptr && ans == 1)
//        {
//            node->next = new ListNode(1);
//        }
//        return node1->next;
//    }
//};




////13.两两交换链表中的节点
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr)
//        {
//            return nullptr;
//        }
//        if (head->next == nullptr)
//        {
//            return head;
//        }
//        swapPairs(head->next->next);
//        int num = head->next->val;
//        head->next->val = head->val;
//        head->val = num;
//        return head;
//    }
//};




////14.排序链表
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        ListNode* p = head;
//        while (p->next != nullptr)
//        {
//            p = p->next;
//        }
//        return Mergesort(head, p);
//    }
//    ListNode* Mergesort(ListNode* begin, ListNode* end)
//    {
//        if (begin == end)
//        {
//            return begin;
//        }
//        if (begin->next == end)
//        {
//            begin->next = nullptr;
//            return resort(begin, end);
//        }
//        ListNode* mid = begin;
//        ListNode* p = begin;
//        while (p != nullptr && p->next != nullptr)
//        {
//            p = p->next->next;
//            mid = mid->next;
//        }
//        ListNode* mid1 = mid->next;
//        mid->next = nullptr;
//        ListNode* node1 = Mergesort(begin, mid);
//        ListNode* node2 = Mergesort(mid1, end);
//        ListNode* node = resort(node1, node2);
//        return node;
//    }
//    ListNode* resort(ListNode* node1, ListNode* node2)
//    {
//        if (node1 == nullptr && node2 == nullptr)
//        {
//            return nullptr;
//        }
//        if (node1 == nullptr)
//        {
//            return node2;
//        }
//        if (node2 == nullptr)
//        {
//            return node1;
//        }
//        if (node1->val <= node2->val)
//        {
//            ListNode* l1 = resort(node1->next, node2);
//            node1->next = l1;
//            return node1;
//        }
//        else
//        {
//            ListNode* l2 = resort(node1, node2->next);
//            node2->next = l2;
//            return node2;
//        }
//    }
//};
//int main()
//{
//    ListNode* node1 = new ListNode(-8);
//    ListNode* node2 = new ListNode(0);
//    ListNode* node3 = new ListNode(11);
//    ListNode* node4 = new ListNode(5);
//    ListNode* node5 = new ListNode(67);
//    /*ListNode* node3 = new ListNode(9);
//    ListNode* node4 = new ListNode(9);
//    ListNode* node5 = new ListNode(9);
//    ListNode* node6 = new ListNode(9);
//    ListNode* node7 = new ListNode(9);*/
//
//
//    ListNode* node10 = new ListNode(9);
//    ListNode* node20 = new ListNode(2);
//    /*ListNode* node30 = new ListNode(9);
//    ListNode* node40 = new ListNode(9);*/
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    /*node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;*/
//
//    node10->next = node20;
//    /*node20->next = node30;
//    node30->next = node40;*/
//    /*node3->next = node4;*/
//    /*node4->next = node5;*/
//    Solution s;
//    s.sortList(node1);
//    return 0;
//}



////15.对称二叉树
//class Solution {
//public:
//    vector<int> v1;
//    vector<int> v2;
//    vector<int> left(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            v1.push_back(-1);
//            return v1;
//        }
//        left(node->left);
//        left(node->right);
//        v1.push_back(node->val);
//        return v1;
//    }
//    vector<int> right(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            v2.push_back(-1);
//            return v2;
//        }
//        right(node->right);
//        right(node->left);
//        v2.push_back(node->val);
//        return v2;
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)
//        {
//            return true;
//        }
//        return left(root) == right(root) ? true : false;
//    }
//};





////16.二叉树最大直径
//class Solution {
//public:
//    int mv = 0;
//    vector<int> vec;
//    int diameterOfBinaryTree(TreeNode* root) {
//        return high(root) - 1 > Tree(root, 0) ? high(root) - 1 : Tree(root, 0);
//    }
//private:
//    int Tree(TreeNode* node, int k)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            for (int i = 0; i < vec.size(); i++)
//            {
//                if (k - vec[i] > mv)
//                {
//                    mv = k - vec[i];
//                }
//            }
//            vec.push_back(k);
//        }
//        Tree(node->left, k - 1);
//        Tree(node->right, k + 1);
//        return mv;
//    }
//    int high(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        int l = high(node->left);
//        int r = high(node->right);
//        return l > r ? l + 1 : r + 1;
//    }
//};





////17.二叉树的层序遍历
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> nums;
//        vector<int> vec;
//        int h = high(root);
//        for (int i = 0; i < h; i++)
//        {
//            nums.push_back(order(root, i, vec));
//            vec.clear();
//        }
//        return nums;
//    }
//private:
//    vector<int> order(TreeNode* node, int i, vector<int>& vec)
//    {
//        if (i == 0 && node != nullptr)
//        {
//            vec.push_back(node->val);
//            return vec;
//        }
//        if (node == nullptr)
//        {
//            return vec;
//        }
//        order(node->left, i - 1, vec);
//        order(node->right, i - 1, vec);
//        return vec;
//    }
//    int high(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        int left = high(node->left);
//        int right = high(node->right);
//        return left > right ? left + 1 : right + 1;
//    }
//};




////18.重建二叉搜索树
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* node = Array(nums, 0, nums.size() - 1);
//        return node;
//    }
//private:
//    TreeNode* Array(vector<int>& nums, int i, int j)
//    {
//        if (i > j)
//        {
//            return nullptr;
//        }
//        if (i == j)
//        {
//            return new TreeNode(nums[i]);
//        }
//        int mid = (i + j) / 2;
//        TreeNode* mid1 = new TreeNode(nums[mid]);
//        mid1->left = Array(nums, i, mid - 1);
//        mid1->right = Array(nums, mid + 1, j);
//        return mid1;
//    }
//};




////19.验证二叉搜索树
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr)
//        {
//            return true;
//        }
//        if (isValidBST(root->left) == false || isValidBST(root->right) == false)
//        {
//            return false;
//        }
//        if (leftjudge(root->left, root) == false && rightjudge(root->right, root) == false)
//        {
//            return false;
//        }
//        if (leftjudge(root->left, root)==false|| rightjudge(root->right, root) == false)
//        {
//            return false;
//        }
//        return true;
//    }
//private:
//    bool leftjudge(TreeNode* node1, TreeNode* node2)
//    {
//        if (node1 == nullptr)
//        {
//            return true;
//        }
//        if (node1->val >= node2->val)
//        {
//            return false;
//        }
//        else
//        {
//            return leftjudge(node1->left, node2) && leftjudge(node1->right, node2);
//        }
//    }
//    bool rightjudge(TreeNode* node1, TreeNode* node2)
//    {
//        if (node1 == nullptr)
//        {
//            return true;
//        }
//        if (node1->val <= node2->val)
//        {
//            return false;
//        }
//        else
//        {
//            return rightjudge(node1->left, node2) && rightjudge(node1->right, node2);;
//        }
//    }
//};
//int main()
//{
//    TreeNode* node1 = new TreeNode(32);
//    TreeNode* node2 = new TreeNode(26);
//    TreeNode* node3 = new TreeNode(47);
//    TreeNode* node4 = new TreeNode(19);
//    TreeNode* node5 = new TreeNode(56);
//    TreeNode* node6 = new TreeNode(27);
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node4->right = node6;
//    node3->right = node5;
//    Solution s;
//    vector<int> nums = { -10,-3,0,5,9 };
//    s.isValidBST(node1);
//    return 0;
//}




////20.二叉搜索树第k小的元素
//class Solution {
//public:
//    vector<int> vec;
//    int kthSmallest(TreeNode* root, int k) {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        kthSmallest(root->left, k);
//        vec.push_back(root->val);
//        kthSmallest(root->right, k);
//        return vec[k - 1];
//    }
//};




////21.二叉树的右视图
//class Solution {
//public:
//    vector<int> vec;
//    int ans;
//    vector<int> rightSideView(TreeNode* root) {
//        for (int i = 0; i < high(root); i++)
//        {
//            levelorder(root, i);
//            ans = 0;
//        }
//        return vec;
//    }
//private:
//    void levelorder(TreeNode* node, int k)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        if (k == 0 && ans == 0)
//        {
//            vec.push_back(node->val);
//            ans = 1;
//        }
//        levelorder(node->right, k - 1);
//        levelorder(node->left, k - 1);
//    }
//    int high(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        int left = high(node->left);
//        int right = high(node->right);
//        return left > right ? left + 1 : right + 1;
//    }
//};




////22.二叉树展开为链表
//class Solution {
//public:
//    int ans = 0;
//    TreeNode* root1 = nullptr;
//    TreeNode* root2 = nullptr;
//    void flatten(TreeNode* root) {
//        if (root == nullptr)
//        {
//            return;
//        }
//        preorder(root);
//        root = root2;
//    }
//private:
//    void preorder(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        if (ans == 0)
//        {
//            root1 = new TreeNode(node->val);
//            root2 = root1;
//            ans = 1;
//        }
//        else
//        {
//            TreeNode* node1 = new TreeNode(node->val);
//            root1->left = nullptr;
//            root1->right = node1;
//            root1 = root1->right;
//        }
//        preorder(node->left);
//        preorder(node->right);
//    }
//};
//int main()
//{
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(5);
//    TreeNode* node4 = new TreeNode(3);
//    TreeNode* node5 = new TreeNode(4);
//    TreeNode* node6 = new TreeNode(6);
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->right = node6;
//    Solution s;
//    s.flatten(node1);
//    return 0;
//}





////23.前序遍历后序遍历重建二叉树
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        TreeNode* node = creat(preorder, inorder);
//        return node;
//    }
//private:
//    TreeNode* creat(vector<int>& preorder, vector<int>& inorder)
//    {
//        if (preorder.size() == 0)
//        {
//            return nullptr;
//        }
//        TreeNode* node = new TreeNode(preorder[0]);
//        if (preorder.size() == 1)
//        {
//            return node;
//        }
//        int idx = 0;
//        for (; idx < inorder.size(); idx++)
//        {
//            if (inorder[idx] == preorder[0])
//            {
//                break;
//            }
//        }
//        vector<int> leftin(inorder.begin(), inorder.begin() + idx);
//        vector<int> rightin(inorder.begin() + idx + 1, inorder.end());
//        vector<int> leftpre(preorder.begin()+1, preorder.begin() + leftin.size()+1);
//        vector<int> rightpre(preorder.begin() + leftin.size() + 1, preorder.end());
//        node->left = creat(leftpre, leftin);
//        node->right = creat(rightpre, rightin);
//        return node;
//    }
//};




////24.路径总和3
//class Solution {
//public:
//    int num = 0;
//    int pathSum(TreeNode* root, int targetSum) {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        sum(root,targetSum);
//        return num;
//    }
//private:
//    void sum(TreeNode* root,int targetSum)
//    {
//        if (root == nullptr)
//        {
//            return;
//        }
//        int m = path(root, 0, targetSum);
//        num += m;
//        sum(root->left, targetSum);
//        sum(root->right, targetSum);
//    }
//    int path(TreeNode* root, int sum, int target)
//    {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        sum += root->val;
//        int count = (sum == target) ? 1 : 0;
//        count += path(root->left, sum, target);
//        count += path(root->right, sum, target);
//        return count;
//    }
//};
//int main()
//{
//    /*vector<int> preorder = { 3,9,20,15,7 };
//    vector<int> inorder = { 9,3,15,20,7 };*/
//    Solution s;
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(5);
//    TreeNode* node3 = new TreeNode(-3);
//    TreeNode* node4 = new TreeNode(3);
//    TreeNode* node5 = new TreeNode(2);
//    TreeNode* node6 = new TreeNode(11);
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->right = node6;
//    s.pathSum(node1, 8);
//    return 0;
//}




////25.电话号码的字母组合
//class Solution {
//public:
//    vector<string> str2;
//    unordered_set<string> s1;
//    string s;
//    vector<string> letterCombinations(string digits) {
//        unordered_map<char, string> m;
//        m['2'] = "abc";
//        m['3'] = "def";
//        m['4'] = "ghi";
//        m['5'] = "jkl";
//        m['6'] = "mno";
//        m['7'] = "pqrs";
//        m['8'] = "tuv";
//        m['9'] = "wxyz";
//        for (int i = 0; i < digits.size(); i++)
//        {
//            str2.push_back(m[digits[i]]);
//        }
//        backtracking(str2, 0);
//        vector<string> str1(s1.begin(), s1.end());
//        return str1;
//    }
//    bool isanswer(vector<string>& str,string s)
//    {
//        for (int i = 0; i < str.size(); i++)
//        {
//            if (str[i].find(s[i]) != string::npos)
//            {
//                
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    void backtracking(vector<string>& str, int k)
//    {
//        if (k == str.size() && isanswer(str,s))
//        {
//            s1.insert(s);
//            return;
//        }
//        for (int i = k; i < str.size(); i++)
//        {
//            for (int j = 0; j < str[i].size(); j++)
//            {
//                s += str[i][j];
//                backtracking(str, k + 1);
//                s.pop_back();
//            }
//        }
//    }
//};
//int main()
//{
//    Solution s;
//    s.letterCombinations("22");
//    return 0;
//}




////26.组合总和
//class Solution {
//public:
//      vector<int> vec;
//      set<vector<int>> s;
//      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//          backtracking(candidates, 0, 0, target);
//          vector<vector<int>> ans(s.begin(), s.end());
//          return ans;
//      }
//private:
//    void backtracking(vector<int>& candidates, int sum, int k, int target)
//    {
//        if (sum == target)
//        {
//            sort(vec.begin(), vec.end());
//            s.insert(vec);
//            return;
//        }
//        for (int i = 0; i < candidates.size()&&candidates[i]+sum<=target; i++)
//        {
//            vec.push_back(candidates[i]);
//            sum += candidates[i];
//            backtracking(candidates, sum, k + 1 , target);
//            vec.pop_back();
//            sum -= candidates[i];
//        }
//    }
//};
//int main()
//{
//    vector<int> nums = { 2,3,5 };
//    Solution s;
//    s.combinationSum(nums, 8);
//    return 0;
//}





////27.括号生成
//class Solution {
//public:
//    vector<string> str;
//    string str1;
//    int open = 0;
//    int close = 0;
//    vector<string> generateParenthesis(int n) {
//        backtracking(2*n, 0);
//        return str;
//    }
//private:
//    bool isparent(string str1)
//    {
//        stack<char> s;
//        for (int i = 0; i < str1.size(); i++)
//        {
//            if (str1[i] == '(')
//            {
//                s.push(str1[i]);
//            }
//            if (str1[i] == ')')
//            {
//                if (s.empty())
//                {
//                    return false;
//                }
//                else
//                {
//                    s.pop();
//                }
//            }
//        }
//        if (!s.empty())
//        {
//            return false;
//        }
//        else
//        {
//            return true;
//        }
//    }
//    void backtracking(int n, int i)
//    {
//        if (i == n && isparent(str1))
//        {
//            str.push_back(str1);
//        }
//        if (i >= n)
//        {
//            return;
//        }
//        if (open > n / 2)
//        {
//            return;
//        }
//        if (close > open)
//        {
//            return;
//        }
//        str1 += '(';
//        open++;
//        backtracking(n, i + 1);
//        open--;
//        str1.pop_back();
//        str1 += ')';
//        close++;
//        backtracking(n, i + 1);
//        close--;
//        str1.pop_back();
//    }
//};
//int main()
//{
//    Solution s;
//    s.generateParenthesis(3);
//    return 0;
//}





////28.单词匹配
//class Solution {
//public:
//    string str;
//    bool judge = false;
//    vector<vector<int>> vec;
//    bool exist(vector<vector<char>>& board, string word) {
//        if (board.empty() || board[0].empty())
//        {
//            return false;
//        }
//        int n = word.size();
//        vector<vector<bool>> arr(board.size(), vector<bool>(board[0].size(), true));
//        findA(board, word[0]);
//        if (vec.empty())
//        {
//            return judge;
//        }
//        for (int i = 0; i < vec.size(); i++)
//        {
//            str.clear();
//            judge = false;
//            fill(arr.begin(), arr.end(), vector<bool>(board[0].size(), true));
//            backtracking(board, 0, n, vec[i][0], vec[i][1],word,arr);
//            if (judge)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//private:
//    void backtracking(vector<vector<char>>& board, int k, int n, int i, int j,string word, vector<vector<bool>>& arr)
//    {
//        if (k == n)
//        {
//            if (str == word)
//            {
//                judge = true;
//                return;
//            }
//            return;
//        }
//        if (k == 0)
//        {
//            str += board[i][j];
//            arr[i][j] = false;
//            k++;
//        }
//        //向下
//        if (i + 1 < board.size() && arr[i + 1][j] == true)
//        {
//            str += board[i + 1][j];
//            arr[i + 1][j] = false;
//            backtracking(board, k + 1, n, i + 1, j,word,arr);
//            str.pop_back();
//            arr[i + 1][j] = true;
//        }
//        //向上
//        if (i - 1 >= 0 && arr[i - 1][j] == true)
//        {
//            str += board[i - 1][j];
//            arr[i - 1][j] = false;
//            backtracking(board, k + 1, n, i - 1, j,word,arr);
//            str.pop_back();
//            arr[i - 1][j] = true;
//        }
//        //向右
//        if (j + 1 < board[0].size() && arr[i][j + 1] == true)
//        {
//            str += board[i][j + 1];
//            arr[i][j + 1] = false;
//            backtracking(board, k + 1, n, i, j + 1,word,arr);
//            str.pop_back();
//            arr[i][j + 1] = true;
//        }
//        //向左
//        if (j - 1 >= 0 && arr[i][j - 1] == true)
//        {
//            str += board[i][j - 1];
//            arr[i][j - 1] = false;
//            backtracking(board, k + 1, n, i, j - 1,word,arr);
//            str.pop_back();
//            arr[i][j - 1] = true;
//        }
//    }
//    void findA(vector<vector<char>>& board, char s1)
//    {
//        for (int i = 0; i < board.size(); i++)
//        {
//            for (int j = 0; j < board[0].size(); j++)
//            {
//                if (board[i][j] == s1)
//                {
//                    vec.push_back({ i,j });
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    vector<vector<char>> vec = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
//    string word = "ABCCED";
//    Solution s;
//    s.exist(vec, word);
//    return 0;
//}





////29.分割回文串
//class Solution {
//public:
//    vector<vector<string>> vec1;
//    vector<string> vec;
//    vector<vector<string>> partition(string s) {
//        backtrack(s, 0);
//        return vec1;
//    }
//private:
//    void backtrack(string s, int i)
//    {
//        if (i == s.size())
//        {
//            if (ishuiwen(vec))
//            {
//                vec1.push_back(vec);
//            }
//            return;
//        }
//        for (int k = i; k < s.size(); k++)
//        {
//            vec.push_back(s.substr(i, k - i + 1));
//            backtrack(s, k + 1);
//            vec.pop_back();
//        }
//    }
//    bool ishuiwen(vector<string>& s)
//    {
//        for (int i = 0; i < s.size(); i++)
//        {
//            string s1 = s[i];
//            reverse(s[i].begin(), s[i].end());
//            if (s[i] != s1)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    Solution s;
//    string str = "aab";
//    s.partition(str);
//    return 0;
//}




////30.不同路径
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>>dp(m, vector<int>(n, 1));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i - 1 < 0 && j - 1 < 0)
//                {
//                    dp[i][j] = 1;
//                }
//                else if (i - 1 < 0)
//                {
//                    dp[i][j] = dp[i][j - 1];
//                }
//                else if (j - 1 < 0)
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//                else
//                {
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                }
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};




////31.不同路径2
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        vector<vector<int>>dp(m, vector<int>(n, 1));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (obstacleGrid[i][j] == 1)
//                {
//                    dp[i][j] = 0;
//                }
//            }
//        }
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                if (obstacleGrid[i][j] == 1)
//                {
//                    continue;
//                }
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};





////32.不同的二叉搜索树
//class Solution {
//public:
//    int numTrees(int n) {
//        vector<int> dp(n + 1);
//        dp[0] = 1;
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                dp[i] += dp[j] * dp[i - j - 1];
//            }
//        }
//        return dp[n];
//    }
//};





////33.最后一块石头的重量2
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        int sum = 0;
//        for (int num : stones)
//        {
//            sum += num;
//        }
//        int target = sum / 2;
//        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
//        for (int j = stones[0]; j <= target; j++)
//        {
//            dp[0][j] = stones[0];
//        }
//        for (int i = 1; i < stones.size(); i++)
//        {
//            for (int j = 1; j <= target; j++)
//            {
//                if (j < stones[i])
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
//                }
//            }
//        }
//        return abs(dp[stones.size() - 1][target] - sum + target);
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> stones = { 31,26,33,21,40 };
//    s.lastStoneWeightII(stones);
//    return 0;
//}





////34.目标和
//class Solution {
//public:
//    int count = 0;
//    int findTargetSumWays(vector<int>& nums, int target) {
//        backtracking(nums, 0, target, 0);
//        return count;
//    }
//    void backtracking(vector<int> nums, int i, int target, int sum)
//    {
//        if (i == nums.size())
//        {
//            if (sum == target)
//            {
//                count++;
//            }
//            return;
//        }
//        backtracking(nums, i + 1, target, sum + nums[i]);
//        backtracking(nums, i + 1, target, sum - nums[i]);
//    }
//};





////35.0和1
//class Solution {
//public:
//    int func1(string s)
//    {
//        int cnt = 0;
//        for (char c : s)
//        {
//            if (c == '0')
//            {
//                cnt++;
//            }
//        }
//        return cnt;
//    }
//    int func2(string s)
//    {
//        int cnt = 0;
//        for (char c : s)
//        {
//            if (c == '1')
//            {
//                cnt++;
//            }
//        }
//        return cnt;
//    }
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
//        for (int i = func1(strs[0]); i <= m; i++)
//        {
//            for (int j = func2(strs[0]); j <= n; j++)
//            {
//                dp[0][i][j] = 1;
//            }
//        }
//        for (int i = 1; i < strs.size(); i++)
//        {
//            for (int j = 0; j <= m; j++)
//            {
//                for (int k = 0; k <= n; k++)
//                {
//                    if (func1(strs[i]) <= j && func2(strs[i]) <= k)
//                    {
//                        dp[i][j][k] = dp[i - 1][j - func1(strs[i])][k - func2(strs[i])] + 1;
//                    }
//                    else
//                    {
//                        dp[i][j][k] = dp[i - 1][j][k];
//                    }
//                }
//            }
//        }
//        return dp[strs.size() - 1][m][n];
//    }
//};
//int main()
//{
//    Solution s;
//    vector<string> strs = { "10", "0", "1"};
//    s.findMaxForm(strs, 1, 1);
//    return 0;
//}





////36.零钱兑换2
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        vector<int>dp(amount + 1, 0);
//        dp[0] = 1;
//        for (int i = 0; i < coins.size(); i++)
//        {
//            for (int j = coins[i]; j <= amount; j++)
//            {
//                dp[j] += dp[j - coins[i]];
//            }
//        }
//        return dp[amount];
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> vec = { 2,3,5 };
//    s.change(5, vec);
//    return 0;
//}





////37.组合总和4
//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<int> dp(target + 1, 0);
//        dp[0] = 1;
//        for (int j = 0; j <= target; j++)
//        {
//            for (int i = 0; i < nums.size(); i++)
//            {
//                if (j >= nums[i])
//                {
//                    dp[j] += dp[j - nums[i]];
//                }
//            }
//        }
//        return dp[target];
//    }
//};
//int main()
//{
//    vector<int> vec = { 1,2,3 };
//    Solution s;
//    s.combinationSum4(vec, 4);
//    return 0;
//}





////38.单词拆分
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        vector<bool>dp(s.size() + 1, false);
//        dp[0] = true;
//        for (int j = 0; j <= s.size(); j++)
//        {
//            for (int i = 0; i < wordDict.size(); i++)
//            {
//                if (j >= wordDict[i].size() && dp[j - wordDict[i].size()] == true && wordDict[i] == s.substr(j - wordDict[i].size(), wordDict[i].size()))
//                {
//                    dp[j] = true;
//                }
//            }
//        }
//        return dp[s.size()];
//    }
//};
//int main()
//{
//    vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
//    string s = "catsandog";
//    Solution s1;
//    s1.wordBreak(s, wordDict);
//    return 0;
//}





////39.打家劫舍
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        vector<int> dp(nums.size() + 1, 0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp[nums.size()-1];
//    }
//};
//int main()
//{
//    vector<int> nums = { 2,1,1,2 };
//    Solution s;
//    s.rob(nums);
//    return 0;
//}





////40.打家劫舍2
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        vector<int> dp1(nums.size() - 1, 0);
//        vector<int> dp2(nums.size() - 1, 0);
//        if (nums.size() == 1)
//        {
//            return nums[0];
//        }
//        if (nums.size() == 2)
//        {
//            return max(nums[0], nums[1]);
//        }
//        dp1[0] = nums[0];
//        dp1[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < nums.size() - 1; i++)
//        {
//            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
//        }
//        dp2[0] = nums[1];
//        dp2[1] = max(nums[1], nums[2]);
//        for (int i = 2; i < nums.size() - 1; i++)
//        {
//            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i + 1]);
//        }
//        return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
//    }
//};
//int main()
//{
//    vector<int> nums = { 2,3,2 };
//    Solution s;
//    s.rob(nums);
//    return 0;
//}





////41.买卖股票的最佳时机1
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<vector<int>>dp(2, vector<int>(prices.size(), 0));
//        dp[0][0] = prices[0];
//        dp[1][0] = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[0][i] = min(dp[0][i - 1], prices[i]);
//            dp[1][i] = max(dp[1][i - 1], prices[i] - dp[0][i]);
//        }
//        return dp[1][prices.size() - 1];
//    }
//};






////42.买卖股票最佳时机含冷冻期
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
//        dp[0][0] = -prices[0];
//        dp[0][1] = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
//            if (dp[i][1] == dp[i - 1][1] && dp[i - 1][1] != dp[i - 1][0] + prices[i] && i != prices.size() - 1)
//            {
//                dp[i][0] = dp[i - 1][0];
//                dp[i][1] = dp[i - 1][1];
//                continue;
//            }
//        }
//        return dp[prices.size() - 1][1];
//    }
//};





////43.买卖股票最佳时机含手续费
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
//        dp[0][0] = -prices[0];
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
//        }
//        return dp[prices.size() - 1][1];
//    }
//};
//int main()
//{
//    vector<int> nums = { 1, 3, 2, 8, 4, 9 };
//    Solution s;
//    s.maxProfit(nums,2);
//    return 0;
//}





////44.最长递增子序列
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        vector<int> dp(nums.size(), 1);
//        vector<vector<int>> dp1();
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                if (nums[j] < nums[i])
//                {
//                    dp[i] = max(dp[j] + 1, dp[i]);
//                }
//            }
//        }
//        int maxval = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            maxval = max(dp[i], maxval);
//        }
//        return maxval;
//    }
//};





////45.最长连续递增子序列
//class Solution {
//public:
//    int findLengthOfLCIS(vector<int>& nums) {
//        vector<int> dp(nums.size(), 1);
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i - 1] < nums[i])
//            {
//                dp[i] = max(dp[i - 1] + 1, dp[i]);
//            }
//        }
//        int val = 0;
//        for (int num : dp)
//        {
//            val = max(val, num);
//        }
//        return val;
//    }
//};





////46.最长重复子序列
//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
//        for (int i = 0; i < nums1.size(); i++)
//        {
//            for (int j = 0; j < nums2.size(); j++)
//            {
//                if (nums1[i] == nums2[j])
//                {
//                    dp[i][j] = 1;
//                    if (i >= 1 && j >= 1)
//                    {
//                        dp[i][j] += dp[i - 1][j - 1];
//                    }
//                }
//                else
//                {
//                    if (j >= 1)
//                    {
//                        dp[i][j] = dp[i][j - 1];
//                    }
//                }
//            }
//        }
//        return dp[nums1.size() - 1][nums2.size() - 1];
//    }
//};





////47.最长公共子序列
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
//        for (int i = 0; i < text1.size(); i++)
//        {
//            for (int j = 0; j < text2.size(); j++)
//            {
//                if (text1[i] == text2[j])
//                {
//                    dp[i][j] = 1;
//                    if (i >= 1 && j >= 1)
//                    {
//                        dp[i][j] = dp[i - 1][j - 1] + 1;
//                    }
//                }
//                else
//                {
//                    if (i >= 1 && j >= 1)
//                    {
//                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                    }
//                    else if (i >= 1)
//                    {
//                        dp[i][j] = dp[i - 1][j];
//                    }
//                    else if (j >= 1)
//                    {
//                        dp[i][j] = dp[i][j - 1];
//                    }
//                }
//            }
//        }
//        return dp[text1.size() - 1][text2.size() - 1];
//    }
//};






////48.不相交的线
//class Solution {
//public:
//    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        for (int i = 1; i <= nums1.size(); i++)
//        {
//            for (int j = 1; j <= nums2.size(); j++)
//            {
//                if (nums1[i - 1] == nums2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[nums1.size()][nums2.size()];
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums1 = { 2,5,1,2,5 };
//    vector<int> nums2 = { 10,5,2,1,5,2 };
//    s.maxUncrossedLines(nums1, nums2);
//    return 0;
//}





////49.最大子数组的和
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        vector<int> dp(nums.size(), 0);
//        dp[0] = nums[0];
//        int result = dp[0];
//        for (int i = 1; i < nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            result = max(result, dp[i]);
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums = { 5,4,-1,7,8 };
//    s.maxSubArray(nums);
//    return 0;
//}





////50.判断子序列
//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
//        if (s.size() > t.size())
//        {
//            return false;
//        }
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[s.size()][t.size()] == s.size();
//    }
//};
//int main()
//{
//    Solution s;
//    s.isSubsequence("abc", "ahbgdc");
//    return 0;
//}





////51.不同的子序列
//class Solution {
//public:
//    int numDistinct(string s, string t) {
//        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
//        for (int i = 0; i < s.size(); i++)
//        {
//            dp[i][0] = 1;
//        }
//        for (int j = 1; j < t.size(); j++)
//        {
//            dp[0][j] = 0;
//        }
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//                }
//                else
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        return dp[s.size()][t.size()];
//    }
//};
//int main()
//{
//    Solution s;
//    s.numDistinct("rabbbit", "rabbit");
//    return 0;
//}






////52.两个字符串的删除操作
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return word1.size() - dp[word1.size()][word2.size()] + word2.size() - dp[word1.size()][word2.size()];
//    }
//};






////53.编辑距离
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        for (int i = 0; i <= word1.size(); i++)
//        {
//            dp[i][0] = i;
//        }
//        for (int j = 0; j <= word2.size(); j++)
//        {
//            dp[0][j] = j;
//        }
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                else
//                {
//                    dp[i][j] = min({ dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1 });
//                }
//            }
//        }
//        return dp[word1.size()][word2.size()];
//    }
//};
//int main()
//{
//    Solution s;
//    s.minDistance("intention", "execution");
//    return 0;
//}






////54.回文子串
//class Solution {
//public:
//    bool huiwen(string s1)
//    {
//        string s2 = s1;
//        reverse(s1.begin(), s1.end());
//        return s1 == s2;
//    }
//    int countSubstrings(string s) {
//        int result = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            for (int j = i; j < s.size(); j++)
//            {
//                if (huiwen(s.substr(i, j - i + 1)))
//                {
//                    result++;
//                }
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    s.countSubstrings("aabaa");
//    return 0;
//}





////55.最长回文子序列
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            for (int j = i; j < s.size(); j++)
//            {
//                if (s[i] == s[j])
//                {
//                    if (j == i)
//                    {
//                        dp[i][j] = 1;
//                    }
//                    else
//                    {
//                        dp[i][j] = dp[i + 1][j - 1] + 2;
//                    }
//                }
//                else
//                {
//                    dp[i][j] = dp[i][j - 1];
//                }
//            }
//        }
//        return dp[0][s.size() - 1];
//    }
//};
//int main()
//{
//    Solution s;
//    s.longestPalindromeSubseq("bbbabbb");
//    return 0;
//}







////56.最长递增子序列(求具体的值)
//class Solution
//{
//public:
//    vector<vector<int>> longestcreasing(vector<int>& nums)
//    {
//        vector<int> lis(nums.size(),-1);
//        vector<int> dp(nums.size(), 0);
//        vector<vector<int>> ans;
//        dp[0] = 1;
//        int result1 = 0;
//        vector<int> result2;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
//                {
//                    dp[i] = dp[j] + 1;
//                    lis[i] = j;
//                    if (result1 == dp[i])
//                    {
//                        result2.push_back(i);
//                    }
//                    if (result1 < dp[i])
//                    {
//                        result1 = dp[i];
//                        result2.clear();
//                        result2.push_back(i);
//                        lis[i] = j;
//                    }
//                }
//            }
//        }
//        for (int i = 0; i < result2.size(); i++)
//        {
//            ans.emplace_back();
//            for (int j = result2[i]; j != -1; j = lis[j])
//            {
//                ans[i].push_back(nums[j]);
//            }
//            reverse(ans[i].begin(), ans[i].end());
//        }
//        return ans;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums = { 4,7,5 };
//    s.longestcreasing(nums);
//    return 0;
//}






//57.摆动序列
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        vector<int>dp(nums.size(), 0);
//        if (nums.size() == 0)
//        {
//            return 0;
//        }
//        if (nums.size() == 1)
//        {
//            return 1;
//        }
//        dp[0] = 1;
//        if (nums[0] == nums[1])
//        {
//            dp[1] = 1;
//        }
//        else
//        {
//            dp[1] = 2;
//        }
//        for (int i = 2; i < nums.size(); i++)
//        {
//            for (int j = 1; j < i; j++)
//            {
//                if (dp[i - 1] == 1)
//                {
//                    if (nums[i - 1] == nums[i])
//                    {
//                        dp[i] = 1;
//                    }
//                    else
//                    {
//                        dp[i] = 2;
//                    }
//                    break;
//                }
//                if ((nums[j] - nums[j - 1]) * (nums[i] - nums[j]) < 0)
//                {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//                else
//                {
//                    dp[i] = max(dp[i], dp[j]);
//                }
//            }
//        }
//        return dp[nums.size() - 1];
//    }
//};





////58.买卖股票最佳时机2
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int cur = 0;
//        int result = 0;
//        for (int i = 0; i < prices.size() - 1; i++)
//        {
//            cur = prices[i + 1] - prices[i];
//            if (cur < 0)
//            {
//
//            }
//            else
//            {
//                result += cur;
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int>nums = { 1,2,3,4,5 };
//    s.maxProfit(nums);
//    return 0;
//}






////59.跳跃游戏
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int j = 0;
//        int len = 0;
//        int num = 0;
//        int j1 = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            len = i;
//            while (j < nums.size() - 1 && j + nums[j] != j)
//            {
//                j = nums[i] + i;
//                i = j;
//            }
//            if (j >= nums.size() - 1)
//            {
//                return true;
//            }
//            if (j + nums[j] == j)
//            {
//                num++;
//            }
//            i = len;
//            if (i + 1 == num && nums[i] == 0 && j1 == j)
//            {
//                return false;
//            }
//            j1 = j;
//            j = 0;
//        }
//        return false;
//    }
//};






////60.跳跃游戏2
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        vector<int> dp(nums.size(), INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                if (j + nums[j] >= i)
//                {
//                    dp[i] = min(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        return dp[nums.size() - 1];
//    }
//};





////61.k次取反后最大化数组的最小值
//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] < 0)
//            {
//                nums[i] = -nums[i];
//                k--;
//                if (k == 0)
//                {
//                    break;
//                }
//                continue;
//            }
//            if (nums[i] >= 0 && k != 0)
//            {
//                while (k != 0)
//                {
//                    if (i >= 1 && nums[i] > nums[i - 1])
//                    {
//                        nums[i-1] = -nums[i-1];
//                    }
//                    else
//                    {
//                        nums[i] = -nums[i];
//                    }
//                    k--;
//                }
//            }
//        }
//        while (k != 0)
//        {
//            nums[nums.size() - 1] = -nums[nums.size() - 1];
//            k--;
//        }
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//        }
//        return sum;
//    }
//};





////62.加油站
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        vector<int> vec;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            vec.push_back(gas[i] - cost[i]);
//        }
//        int i = 0;
//        while (i!=vec.size())
//        {
//            if (vec[i] > 0)
//            {
//                int cap = 0;
//                int j = i;
//                while (cap >= 0)
//                {
//                    cap += vec[j];
//                    if (cap < 0)
//                    {
//                        break;
//                    }
//                    if ((j+1)%vec.size() == i)
//                    {
//                        return i;
//                    }
//                    j = (j + 1) % vec.size();
//                }
//            }
//            i++;
//        }
//        return -1;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> gas = { 1,2,3,4,5 };
//    vector<int> cost = { 3,4,5,1,2 };
//    s.canCompleteCircuit(gas, cost);
//    return 0;
//}







////63.分发糖果
//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        vector<int> vec(ratings.size(), 1);
//        int result = 0;
//        for (int i = 1; i < ratings.size(); i++)
//        {
//            if (ratings[i] > ratings[i - 1])
//            {
//                vec[i] = vec[i - 1] + 1;
//            }
//        }
//        for (int i = ratings.size() - 1; i >= 1; i--)
//        {
//            if (ratings[i] < ratings[i - 1] && vec[i - 1] <= vec[i])
//            {
//                vec[i - 1] = vec[i] + 1;
//            }
//        }
//        for (int i = 0; i < vec.size(); i++)
//        {
//            result += vec[i];
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v = { 1,3,4,5,2 };
//    s.candy(v);
//    return 0;
//}






////64.柠檬水找零
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills) {
//        unordered_map<int,int> map;
//        map[5] = 0;
//        map[10] = 0;
//        map[20] = 0;
//        for (int i = 0; i < bills.size(); i++)
//        {
//            map[bills[i]]++;
//            if (bills[i] - 5 == 5)
//            {
//                map[5]--;
//            }
//            if (bills[i] - 5 == 15 && map[10] < 1)
//            {
//                map[5] -= 3;
//            }
//            if (bills[i] - 5 == 15 && map[10] >= 1)
//            {
//                map[10]--;
//                map[5]--;
//            }
//            if (map[5] < 0 || map[10] < 0)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> bills = { 5,5,5,5,20,20,5,5,5,5 };
//    s.lemonadeChange(bills);
//    return 0;
//}







////65.用最少的箭射爆气球
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(), points.end(), [](vector<int>& u, vector<int>& v) {
//            return u[0] < v[0] || (u[0] == v[0] && u[1] < v[1]);
//            });
//        int result = 1;
//        int s3 = points[0][1];
//        for (int i = 1; i < points.size(); i++)
//        {
//            if (points[i][0] > points[i - 1][1])
//            {
//                result++;
//            }
//            else
//            {
//                points[i][1] = min(points[i][1], points[i - 1][1]);
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<vector<int>> points = { {10,16} ,{2,8},{1,6},{7,12} };
//    s.findMinArrowShots(points);
//    return 0;
//}





////66.无重叠区间
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), [](vector<int>& u, vector<int>& v) {
//            return u[0] < v[0] || (u[0] == v[0] && u[1] < v[1]);
//            });
//        int result = 0;
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i][0] < intervals[i - 1][1])
//            {
//                result++;
//                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<vector<int>> points = { {1,2},{1,3},{2,3},{3,4} };
//    s.eraseOverlapIntervals(points);
//    return 0;
//}





////67.划分字母区间
//class Solution {
//public:
//    vector<int> partitionLabels(string s) {
//        vector<int> result;
//        vector<int> start;
//        vector<int> end;
//        bool flag = false;
//        for (int i = 0; i < s.size(); i++)
//        {
//            for (int k = 0; k < start.size(); k++)
//            {
//                if (s[start[k]] == s[i] && i != 0)
//                {
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag)
//            {
//                flag = false;
//                continue;
//            }
//            start.push_back(i);
//            for (int j = s.size(); j >= i; j--)
//            {
//                if (s[j] == s[i])
//                {
//                    end.push_back(j);
//                    break;
//                }
//            }
//        }
//        for (int i = 0; i < start.size() - 1; i++)
//        {
//            if (start[i + 1] < end[i])
//            {
//                start[i + 1] = start[i];
//                end[i + 1] = max(end[i], end[i + 1]);
//            }
//            if (start[i + 1] > end[i])
//            {
//                result.push_back(end[i] - start[i] + 1);
//                continue;
//            }
//        }
//        result.push_back(end[start.size() - 1] - start[start.size() - 1] + 1);
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    string s1 = "ababcbaddeeff";
//    s.partitionLabels(s1);
//    return 0;
//}





////68.单调递增的数字
//class Solution {
//public:
//    int monotoneIncreasingDigits(int n) {
//        vector<int> nums;
//        while (n>0)
//        {
//            nums.push_back(n % 10);
//            n /= 10;
//        }
//        reverse(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            if (nums[i] > nums[i + 1])
//            {
//                if (i == 0)
//                {
//                    nums[i]--;
//                    fill(nums.begin() + i + 1, nums.end(), 9);
//                }
//                else
//                {
//                    int j = 0;
//                    for (j = i; j > 0; j--)
//                    {
//                        if (nums[j] - 1 >= nums[j - 1])
//                        {
//                            nums[j]--;
//                            fill(nums.begin() + j + 1, nums.end(), 9);
//                            break;
//                        }
//                    }
//                    if (j == 0)
//                    {
//                        nums[0]--;
//                        fill(nums.begin() + j + 1, nums.end(), 9);
//                    }
//                }
//            }
//        }
//        reverse(nums.begin(), nums.end());
//        int num = 0;
//        int k1 = 1;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            num += nums[i] * k1;
//            k1 *= 10;
//        }
//        return num;
//    }
//};
//int main()
//{
//    Solution s;
//    s.monotoneIncreasingDigits(1000000000);
//    return 0;
//}





////69.岛屿数量
//int result = 0;
//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//queue<pair<int, int>> que;
//void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int N, int M)
//{
//    que.push({ i,j });
//    visited[i][j] = true;
//    while (!que.empty())
//    {
//        pair<int, int> m = que.front();
//        que.pop();
//        for (int k = 0; k < 4; k++)
//        {
//            int nextx = m.first + dir[k][0];
//            int nexty = m.second + dir[k][1];
//            if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M)
//            {
//                continue;
//            }
//            if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
//            {
//                visited[nextx][nexty] = true;
//                que.push({ nextx,nexty });
//            }
//        }
//    }
//}
//int main()
//{
//    int N = 4;
//    int M = 5;
//    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
//    vector<vector<bool>> visited(N, vector<bool>(M, false));
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < M; j++)
//        {
//            if (grid[i][j] == 1 && visited[i][j] == false)
//            {
//                bfs(grid, visited, i, j,N,M);
//                result++;
//            }
//        }
//    }
//    cout << result << endl;
//    return 0;
//}







////70.岛屿的最大面积
//int result1 = 0;
//int result0 = 0;
//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m)
//{
//    for (int k = 0; k < 4; k++)
//    {
//        int nextx = i + dir[k][0];
//        int nexty = j + dir[k][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
//        {
//            continue;
//        }
//        if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
//        {
//            visited[nextx][nexty] = true;
//            result1++;
//            dfs(grid, visited, nextx, nexty, n, m);
//        }
//    }
//}
//int main()
//{
//    int n = 4;
//    int m = 5;
//    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
//    vector<vector<bool>> visited(n, vector<bool>(m, false));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (grid[i][j] == 1 && visited[i][j] == false)
//            {
//                visited[i][j] = true;
//                result1++;
//                dfs(grid, visited, i, j, n, m);
//                result0 = max(result1, result0);
//                result1 = 0;
//            }
//        }
//    }
//    cout << result0 << endl;
//    return 0;
//}





////71.孤岛总面积
//int result = 0;
//int cnt = 1;
//bool flag = true;
//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n,int m)
//{
//    for (int k = 0; k < 4; k++)
//    {
//        int nextx = x + dir[k][0];
//        int nexty = y + dir[k][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
//        {
//            flag = false;
//            continue;
//        }
//        if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
//        {
//            cnt++;
//            visited[nextx][nexty] = true;
//            dfs(grid, visited, nextx, nexty, n, m);
//        }
//    }
//}
//int main()
//{
//    int n = 4;
//    int m = 5;
//    vector<vector<bool>> visited(n, vector<bool>(m, false));
//    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (visited[i][j] == false && grid[i][j] == 1)
//            {
//                visited[i][j] = true;
//                dfs(grid, visited, i, j, n, m);
//                if (flag == true)
//                {
//                    result += cnt;
//                }
//                cnt = 1;
//                flag = true;
//            }
//        }
//    }
//    cout << result << endl;
//    return 0;
//}





//72.沉没孤岛
//#include<iostream>
//#include<vector>
//bool flag = true;
//bool flag1 = false;
//bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m)
//{
//    if (i < 0 || i >= n || j < 0 || j >= m)
//    {
//        flag = false;
//        return false;
//    }
//    if (grid[i][j] == 0)
//    {
//        return flag;
//    }
//    else
//    {
//        if (grid[i][j] == 1 && visited[i][j] == false)
//        {
//            visited[i][j] = true;
//            dfs(grid, visited, i + 1, j, n, m);
//            dfs(grid, visited, i - 1, j, n, m);
//            dfs(grid, visited, i, j - 1, n, m);
//            dfs(grid, visited, i, j + 1, n, m);
//        }
//    }
//    return flag;
//}
//int main()
//{
//    int n = 10;
//    int m = 10;
//    vector<vector<int>> grid = { 
//        {0,1,1,0,0,0,1,0,0,0},
//        {0,1,0,0,0,0,1,1,1,0},
//        {1,1,0,1,0,1,1,0,0,0},
//        {0,0,0,1,1,1,1,0,1,0},
//        {1,0,1,1,0,1,0,0,1,1},
//        {1,0,1,0,0,1,1,1,0,1},
//        {1,0,0,1,0,0,0,1,0,1},
//        {1,1,0,1,1,1,0,1,1,0},
//        {1,1,0,1,1,1,0,0,1,1},
//        {0,0,0,0,0,1,0,1,1,0 }
//    };
//    vector<vector<bool>> visited(n, vector<bool>(m, false));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            flag = true;
//            if (grid[i][j] == 1 && visited[i][j] == false)
//            {
//                flag1 = dfs(grid, visited, i, j, n, m);
//            }
//            if (flag1 == true)
//            {
//                grid[i][j] = 0;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m - 1; j++)
//        {
//            cout << grid[i][j] << " ";
//        }
//        cout << grid[i][m-1];
//        cout << endl;
//    }
//}





////73.高山流水
//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& judge, int i, int j, int n, int m)
//{
//    judge[i][j] = true;
//    for (int k = 0; k < 4; k++)
//    {
//        int nextx = i + dir[k][0];
//        int nexty = i + dir[k][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
//        {
//            continue;
//        }
//        if (grid[i][j] <= grid[nextx][nexty] && judge[nextx][nexty] == false)
//        {
//            dfs(grid, judge, nextx, nexty, n, m);
//        }
//    }
//}
//int main()
//{
//    int n = 5;
//    int m = 5;
//    vector<vector<bool>>first(n, vector<bool>(m, false));
//    vector<vector<bool>>second(n, vector<bool>(m, false));
//    vector<vector<int>> result;
//    vector<vector<int>> grid = { {1,3,1,2,4},{1,2,1,3,2},{2,4,7,2,1},{4,5,6,1,1},{1,4,1,2,1} };
//    for (int i = 0; i < n; i++)
//    {
//        dfs(grid, first, i, 0, n, m);
//        dfs(grid, second, i, m - 1, n, m);
//    }
//    for (int j = 0; j < m; j++)
//    {
//        dfs(grid, first, 0, j, n, m);
//        dfs(grid, second, n - 1, j, n, m);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (first[i][j] == true && second[i][j] == true)
//            {
//                result.push_back({ i,j });
//            }
//        }
//    }
//    for (int i = 0; i < result.size(); i++)
//    {
//        cout << result[i][0] << " " << result[i][1] << endl;
//    }
//    return 0;
//}





//74.建造最大人工岛
//int area = 1;
//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m)
//{
//    visited[i][j] = true;
//    for (int k = 0; k < 4; k++)
//    {
//        int nextx = i + dir[k][0];
//        int nexty = j + dir[k][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
//        {
//            continue;
//        }
//        if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1)
//        {
//            area++;
//            dfs(grid, visited, nextx, nexty, n, m);
//        }
//    }
//}
//int main()
//{
//    int n = 2;
//    int m = 2;
//    int flag = true;
//    int maxval = 0;
//    vector<vector<bool>>visited(n, vector<bool>(m, false));
//    vector<int> areas;
//    vector<vector<int>> grid = { {1,1},{0,-1} };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (grid[i][j] == 1 && visited[i][j] == false)
//            {
//                area = 1;
//                dfs(grid, visited, i, j, n, m);
//                if (i >= 2 && grid[i - 2][j] == 1)
//                {
//                    maxval = max(maxval, areas.back() + area + 1);
//                }
//                if (j >= 2 && grid[i][j - 2] == 1)
//                {
//                    maxval = max(maxval, areas.back() + area + 1);
//                }
//                if (i >= 1 && j >= 1 && grid[i - 1][j - 1] == 1)
//                {
//                    maxval = max(maxval, areas.back() + area + 1);
//                }
//                areas.push_back(area);
//            }
//            if (grid[i][j] == 0)
//            {
//                flag = false;
//            }
//        }
//    }
//    if (areas.size() == 1 && flag == false)
//    {
//        cout << areas[0] + 1;
//    }
//    else if (areas.size() == 1 && flag == true)
//    {
//        cout << areas[0];
//    }
//    else
//    {
//        cout << maxval;
//    }
//    return 0;
//}





//vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
//int mcount = 1;
//int mark = 2;
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m)
//{
//    visited[i][j] = true;
//    for (int k = 0; k < 4; k++)
//    {
//        int nextx = i + dir[k][0];
//        int nexty = j + dir[k][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
//        {
//            continue;
//        }
//        if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1)
//        {
//            grid[nextx][nexty] = mark;
//            mcount++;
//            dfs(grid, visited, nextx, nexty, n, m);
//        }
//    }
//}
//int main()
//{
//    int n = 4;
//    int m = 5;
//    int result = 0;
//    unordered_map<int, int> map;
//    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
//    vector<vector<bool>>visited(n, vector<bool>(m, false));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (grid[i][j] == 1 && visited[i][j] == false)
//            {
//                grid[i][j] = mark;
//                dfs(grid, visited, i, j, n, m);
//                map[mark] = mcount;
//                mcount = 1;
//                mark++;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            int scount = 1;
//            if (grid[i][j] == 0)
//            {
//                unordered_set<int> visitedset;
//                for (int k = 0; k < 4; k++)
//                {
//                    int nearx = i + dir[k][0];
//                    int neary = j + dir[k][1];
//                    if (nearx < 0 || nearx >= n || neary < 0 || neary >= m)
//                    {
//                        continue;
//                    }
//                    if (visitedset.count(grid[nearx][neary]))
//                    {
//                        continue;
//                    }
//                    if (grid[nearx][neary] >= 2)
//                    {
//                        scount += map[grid[nearx][neary]];
//                        visitedset.insert(grid[nearx][neary]);
//                    }
//                }
//            }
//            result = max(result, scount);
//        }
//    }
//    cout << result;
//    return 0;
//}






//75.岛屿周长
int scount = 0;
vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m)
{
    visited[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int nextx = x + dir[k][0];
        int nexty = y + dir[k][1];
        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
        {
            scount++;
            continue;
        }
        if (grid[nextx][nexty] == 0)
        {
            scount++;
            continue;
        }
        if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
        {
            dfs(grid, visited, nextx, nexty, n, m);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>grid(n, vector<int>(m, 0));
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == false)
            {
                dfs(grid, visited, i, j, n, m);
            }
        }
    }
    cout << scount;
    return 0;
}