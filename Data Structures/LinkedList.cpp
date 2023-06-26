#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* bottom;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
        bottom = NULL;
    }
};

class LinkedList{
    public:
    //Function to print the linked list
    void printList(Node *node){
        while(node){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;
    }

    //Function to reverse a given linked list of n nodes
    //Iterative - Using stack
    Node* reverseListItr(Node *node){
        Node *rev; Node *temp;
        rev = temp;
        stack<int> st;
        while(node){
            st.push(node->data);
            node = node->next;
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            temp->next = new Node(top);
            temp = temp->next;
        }
        return rev->next;        
    }
    //Iterative2 - Using 3 pointers
    Node* reverseListItr2(Node *head){
        Node* prev = NULL; Node* curr = head; Node* next = head->next;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
    //Recursive solution
    Node* reverseListRec(Node *head){
        if(head == NULL || head->next == NULL) return head;
        Node* newHead = reverseListRec(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

    //Given a linked list of size N. The task is to reverse every k nodes in the linked list.
    Node *reverse(Node *head, int k){ 
        stack<int> st;
        Node* temp = new Node(0); Node* ans = temp;
        while(head!= NULL){
            for(int i=0; i<k and head!= NULL; i++){
                st.push(head->data);
                head = head->next;
            }
            while(!st.empty()){
                int top = st.top(); st.pop(); 
                Node* t = new Node(top); 
                temp->next = t;
                temp = temp->next;
            }
        }
        return ans->next;
    }

    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow != fast) return;
        
        slow = head;
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }

    //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow != fast) return -1;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast->data;
    }

    //Function to remove duplicates from sorted linked list.
    Node *removeDuplicatesSorted(Node *head){
        Node* temp = head; Node* curr = head;   
        while(temp){
            while(temp and temp->data == curr->data) temp = temp->next;
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }

    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicatesUnsorted( Node *head) {
        set<int> st;
        Node* temp = head; Node* curr = head;
        while(temp){
            st.insert(curr->data);
            while(temp and st.find(temp->data) != st.end()) 
                temp = temp->next;
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }

    //Function to move the last element to the front of the Linked List and return the list.
    Node *moveToFront(Node *head){
        if(!head->next) return head;
        Node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        Node* st = new Node(temp->next->data);
        st->next = head;
        temp->next = NULL;
        return st;
    }

    //Function to add 1 to a number N represented in Linked list such that each node corrsponds to a digit of the number
    Node* addOne(Node *head){
        stack<Node*> st;
        Node* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        Node* top = st.top();
        st.pop();
        if(top->data <9) top->data++;
        else{
            top->data = 0;
            while(!st.empty() and st.top()->data == 9){
                st.top()->data = 0;
                st.pop();
            }
            if(st.empty()){
                Node* t = new Node(1);
                t->next = head;
                return t;
            }
            st.top()->data++;
        }
        return head;
    }

    //Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second){
        Node* t1 = first; Node* t2 = second;
        stack<Node*> st1, st2;
        while(t1){
            st1.push(t1);
            t1 = t1->next;
        }
        while(t2){
            st2.push(t2);
            t2 = t2->next;
        }
        int carry=0;
        while(!st1.empty() and !st2.empty()){
            Node* top1 = st1.top(); st1.pop();
            Node* top2 = st2.top(); st2.pop();
            int sum = top1->data + top2->data + carry;
            if(sum>9){
                carry = 1;
                sum %= 10;
            }
            else carry=0;
            top1->data = sum; top2->data = sum;
        }
        if(carry){
            if(st1.empty() and st2.empty()){
                Node* t = new Node(1);
                    t->next = first;
                    return t;
            }
            if(st1.empty()){
                swap(st1,st2);
                swap(first,second);
            }
            Node* top = st1.top(); st1.pop();
            if(top->data<9) top->data++;
            else{
                top->data = 0;
                while(!st1.empty() and st1.top()->data == 9){
                    st1.top()->data = 0;
                    st1.pop();
                }
                if(st1.empty()){
                    Node* t = new Node(1);
                    t->next = first;
                    return t;
                }
                else st1.top()->data++;
            }
            return first;
        }
        return st1.empty() ? second : first;
    }
    
    //Given the head of a singly linked list, return the middle node of the linked list.If there are two middle nodes, return the second middle node.
    Node* middleNode(Node* head) {
        Node* slow = head; Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists.
    Node* findIntersection(Node* head1, Node* head2){
        Node* t1 = head1; Node* t2 = head2;
        Node* ans = new Node(0); Node* temp = ans;
        while(t1 != NULL and t2 != NULL){
            if(t1->data == t2->data){
                Node* t = new Node(t1->data);
                temp->next = t;
                temp = temp->next;
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->data > t2->data) 
                t2 = t2->next;
            else t1 = t1->next;
        }
        return ans->next;
    }

    //Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2){
        Node* temp = head2;
        while(temp->next) temp = temp->next;
        temp->next = head2;
        Node* slow = head1; Node* fast = head1;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow != fast) return -1;
        slow = head1;
        while(fast != slow and slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }

    /* Should return true if linked list is circular, else false */
    bool isCircular(Node *head){
        Node* temp = head;
        while(temp){
            temp = temp->next;
            if(temp == head) return 1;
        }
        return 0;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        Node* slow = head; Node* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* rev = reverseListRec(slow);
        while(rev != head and rev and head){
            if(rev->data != head->data)
                return 0;
            rev = rev->next;
            head = head->next;
        }
        return 1;
    }

    //  function which splits the circular linked list.  head is pointer to head Node of given lined list.  
    //head1_ref1 and *head_ref2 are pointers to head pointers of resultant two halves.
    void splitList(Node *head, Node **head1_ref, Node **head2_ref){
        Node* slow = head; Node* fast = head->next;
        while(fast != head and fast->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        *head1_ref = head;
        *head2_ref = slow->next;
        slow->next = *head1_ref;
        Node* temp = *head2_ref;
        while(temp->next != head) temp = temp->next;
        temp->next = *head2_ref;
    }

    //Function to merge two sorted linked list.
    Node* sortedMerge(Node* head1, Node* head2)  {  
        Node* ans = new Node(0);
        Node* temp = ans;
        while(head1 and head2){
            if(head1->data <= head2->data){
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        if(!head1) temp->next = head2;
        else temp->next = head1;
        return ans->next;
    }

    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head or !head->next) return head;
        Node* slow = head; Node* fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* first = head;
        Node* second = slow->next;
        slow->next = NULL;
        first = mergeSort(first);
        second = mergeSort(second);
        return sortedMerge(first,second);
    }

    //Given a doubly linked list of n elements. The task is to reverse the doubly linked list.
    Node* reverseDLL(Node * head){
        Node* curr = head; Node* temp = head->next; 
        while(temp){
            if(curr == head) curr->next = NULL;
            curr->prev = temp;
            temp->prev = temp->next;
            temp->next = curr;
            curr = temp;
            temp = temp->prev;
        }
        return curr;
    }

    //Function to Sort the given Linked List using quicksort
    void quickSortHelper(Node* head, Node* tail){
        if(!head or !tail or head == tail) return;
        Node* pivot = head;
        Node* curr = head; Node* next = curr->next;
        while(next != tail->next){
            if(next->data < pivot->data){
                swap(curr->next->data, next->data);
                curr = curr->next;
            }
            next = next->next;
        }
        swap(pivot->data,curr->data);
        quickSortHelper(head,curr);
        quickSortHelper(curr->next,tail);
    }
    void quickSort(struct Node **headRef) {
        Node* head = *headRef;
        if(!head or !head->next) return;
        Node* tail = head;
        while(tail->next) tail = tail->next;
        quickSortHelper(head,tail);
    }

    /* Function to delete a given node from the list */
    void deleteNode(struct Node **Head, int key){
        Node* head = *Head;
        Node* temp = head->next;
        while(temp){
            if(temp->next->data == key){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    /* Function to reverse the linked list */
    void reverse(struct Node** Head){
        Node* head = *Head;
        Node* curr = head;
        Node* nxt = head->next;
        while(nxt != head){
            Node* temp = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = temp;
        }
        nxt->next = curr;
        *Head = curr;
    }

    //Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a 
    //doubly-linked list whose sum is equal to given value target.
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        vector<pair<int, int>> ans;
        Node* end = head;
        while(end->next) end = end->next;
        while(head->data < end->data){
            if(head->data + end->data == target){ 
                ans.push_back({head->data , end->data});
                head = head->next;
                end = end->prev;
            }
            else if(head->data + end->data < target) head = head->next;
            else end = end-> prev;
        }
        return ans;
    }

    //Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. 
    //Count distinct triplets in the list that sum up to given integer X.
    int countTriplets(Node* head, int x) { 
        Node* temp = head;
        Node* rev = new Node(0); Node* r = rev;
        while(temp){
            Node* t = new Node(temp->data);
            r->next = t;
            r = r->next;
            temp = temp->next;
        }
        rev = reverseListRec(rev->next);
        int ans=0;
        while(head->next){
            int val = x - head->data;
            Node* temp = head->next;
            Node* revt = rev;
            while(temp->data < revt->data){
                if(temp->data + revt->data == val){
                    ans++;
                    temp = temp->next;
                    revt = revt->next;
                }
                else if(temp->data + revt->data < val)
                    temp = temp->next;
                else
                    revt = revt->next;
            }
            head = head->next;
        }
        return ans;
    } 

    //Function to rotate a linked list.
    Node* rotate(Node* head, int k){
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = head;
        temp = head;
        while(--k) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }

    /*  Function which returns the  root of the flattened linked list. */
    Node* sortedMergeFlatten(Node* head1, Node* head2)  {  
        Node* ans = new Node(0);
        Node* temp = ans;
        while(head1 and head2){
            if(head1->data <= head2->data){
                temp->bottom = head1;
                head1 = head1->bottom;
                temp = temp->bottom;
            }
            else{
                temp->bottom = head2;
                head2 = head2->bottom;
                temp = temp->bottom;
            }
        }
        if(!head1) temp->bottom = head2;
        else temp->bottom = head1;
        return ans->bottom;
    }
    Node *flatten(Node *root){
        if(!root or !root->next) return root;
        Node* temp = root;
        Node* merger = flatten(temp->next);
        temp = sortedMerge(temp,merger);
        return temp;
    }

    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* z = new Node(-1);
        Node* o = new Node(-1);
        Node* t = new Node(-1);
        Node* tz = z;
        Node* to = o;
        Node* tt = t;
        while(head){
            if(head->data == 0){
                tz->next = head;
                tz = tz->next;
            }
            else if(head->data == 1){
                to->next = head;
                to = to->next;
            }
            else{
                tt->next = head;
                tt = tt->next;
            }
            head = head->next;
        }
        if(o->next) tz->next = o->next;
        else tz->next = t->next;
        to->next = t->next;
        tt->next = NULL;
        return z->next;
    }

    //You are given a special linked list with N nodes where each node has a next pointer pointing to its 
    //next node. You are also given M random pointers, where you will be given M number of pairs denoting 
    //two nodes a and b  i.e. a->arb = b (arb is pointer to random node).
    Node *copyList(Node *head){
        Node* temp = head;
        while(temp){
            Node* t = new Node(temp->data);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            temp->next->arb = temp->arb == NULL ? NULL : temp->arb->next;
            temp = temp->next->next;
        }
        
        Node* ans = head->next;
        Node* cpy = ans;
        temp = head;
        while(temp){
            temp->next = temp->next->next;
            cpy->next = cpy->next ? cpy->next->next : NULL;
            cpy = cpy->next;
            temp = temp->next;
        }
        return ans;
    }

    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k){
        Node* ans = new Node(-1);
        Node* copy = ans;
        bool valid=1;
        while(valid){
            Node* min = new Node(INT_MAX);
            int ind=0;
            for(int i=0; i<k; i++){
                if(arr[i] and arr[i]->data<min->data){
                    min = arr[i];
                    ind = i;
                }
            }
            copy->next = min;
            copy = copy->next;
            arr[ind] = arr[ind]->next;
            valid=0;
            for(int i=0; i<k; i++) if(arr[i]!=NULL) valid=1;
        }
        return ans->next;
    }

    /*The method multiplies two  linked lists l1 and l2and returns their product*/
    long long  multiplyTwoLists (Node* l1, Node* l2){
        long long num1=0, num2=0, ans=1;
        long long mod = 1000000007;
        while(l1){
            num1 = num1*10 + l1->data;
            num1 %= mod;
            l1 = l1->next;
        }
        while(l2){
            num2 = num2*10 + l2->data;
            num2 %= mod;
            l2 = l2->next;
        }
        ans = (num1*num2)%mod;
        return ans;
    }

};

int main(){
    LinkedList ll;
    Node *head = NULL;
    Node *temp = NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        if(i==0){
            head = new Node(data);
            temp = head;
        }
        else{
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    ll.printList(head);
    Node *rev = ll.reverseListItr(head);
    ll.printList(rev);
    return 0;
}