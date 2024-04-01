class Solution {
public:
ListNode* merge(ListNode* h1,ListNode* h2){
    ListNode* head=new ListNode(0);
    ListNode* temp=head;
    while(h1&&h2){
        if(h1->val<h2->val){
            temp->next=h1;
            h1=h1->next;
            temp=temp->next;
        }
        else{
            temp->next=h2;
            h2=h2->next;
            temp=temp->next;
        }
    }
        while(h1){
            temp->next=h1;
            h1=h1->next;
            temp=temp->next;
        }
        while(h2){
            temp->next=h2;
            h2=h2->next;
            temp=temp->next;
        }
        return head->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0){
        //     return NULL;
        // }
        // ListNode* ans=lists[0];
        // for(int i=1;i<lists.size();i++){
        //     ans=merge(ans,lists[i]);
        // }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return ans->next;
    }
};