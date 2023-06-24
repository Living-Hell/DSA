#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
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