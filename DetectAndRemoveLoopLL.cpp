#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // Find if there's a loop. Using Floyd's algorithm to detect loop , Hare and Tortoise method.
        bool toRet = false;
        Node *slowP = head;
        Node *fastP = head;
        while(fastP!=NULL) {
            if(fastP->next!=NULL)
            fastP = fastP->next->next;
            else fastP=NULL;
            slowP=slowP->next;
            if(fastP==slowP){toRet = true;break;}
        }
        // If loop exists remove it
        if(toRet) {
            Node* aP = head;
            Node* first = NULL;
            if(aP == slowP){
                first = slowP;
                aP = head;
            while(aP->next!=first) {
                aP = aP->next;
            }
            aP->next = NULL;
            }
            else {
                while(slowP->next!=aP->next){
                    slowP=slowP->next;
                    aP=aP->next;
                }
                first = slowP->next;
                slowP->next = NULL;
            }
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
