int getNthFromLast(Node *head, int n)
{
       // Your code here
       int l = 0;
       Node* temp = head;
       while(temp!=NULL) {
           l++;
           temp = temp->next;
       }
       if(n>l)return -1;
       else {
           temp = head;
           int diff = l-n;
           while(diff>0) {
               temp = temp->next;
               diff--;
           }
           return temp->data;
       }
}

int main() {
  Node* head = createLL(); // Finish function
  int n;
  cin>>n;
  cout<<getNthFromLast(head, n);
  return 0;
}
