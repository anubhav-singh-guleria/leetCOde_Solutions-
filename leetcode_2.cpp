/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        vector<int> num1;
        vector<int> num2;
        while(l1!=nullptr){
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2!=nullptr){
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        if(num1.size()!=num2.size()){
            if(num1.size()>num2.size()){
                for(int i = num2.size();i<num1.size();i++){
                    num2.push_back(0);
                }
            }
            else{
                for(int i = num1.size();i<num2.size();i++){
                    num1.push_back(0);
                }
            }
        }
       
        vector<int> num3;
        int carry = 0;
        for(int i = 0;i<num1.size();i++){
            num3.push_back((num1[i]+num2[i]+carry)%10);
            carry = (num1[i]+num2[i]+carry)/10;
        }
        if(carry!=0){
            num3.push_back(carry);
        }
        // reverse(num3.begin(),num3.end());
        ListNode* ans = new ListNode(num3[0]);
        ListNode* temp = ans;
        
        for(int i = 1;i<num3.size();i++){
            temp->next = new ListNode(num3[i]);
            temp = temp->next;
        }
        return ans;
    }
};
