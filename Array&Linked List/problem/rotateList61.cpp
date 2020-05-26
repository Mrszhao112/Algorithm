// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

//一道链表的拼接题目 注意控制边界条件
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode* tmp = head;   
        ListNode* end = head;
        int sz = 0;
        while (tmp != NULL) {//计算长度
            tmp = tmp->next;
            ++sz;
        }
        
        k %= sz;//取余防止旋转长度超出链表长度
        if (k == 0) {
            return head;
        }

        tmp = head;
        k = sz - k;//计算需要旋转的地方
        while(--k) {
            tmp = tmp->next;
        }

        end = tmp; //新的链表尾部
        tmp = tmp->next;
        end->next = NULL; 
        end = tmp;

        while (tmp->next != NULL) {//拼接链表
            tmp = tmp->next;
        }
        tmp->next = head;

        return end; //返回链表头
    }
};
///////////////////////////////////////////////////////////////////////////////////
//大佬的clean code 值得学习
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};
