#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    int r_length(Node* temp){
        if(temp==NULL)
          return 0;
        else{
            return 1 + r_length(temp->next);
        }  
    }
    int length(){
        return r_length(head);
    }
    void insert_back(int val){
        Node* temp;
        temp=new Node;
        temp->data=val;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            Node* temp2=head;
            while(temp2->next!=NULL){
                temp2=temp2->next;
            }
            temp2->next=temp;
        }
    }
    void insert_start(int val){
        Node* temp;
        temp=new Node;
        temp->data=val;
        temp->next=NULL;
        if(head==NULL){
           head=temp;
        }else{
            temp->next=head;
            head=temp;
        }
    }
    void insert_pos(int val,int pos){
        
        if(pos<0 || pos>length()){
            return;
        }
        
        if(pos==0){
            insert_start(val);
        }else if(pos==length()){
            insert_back(val);
        }else{
            Node* temp=head;
            Node* newNode=new Node;
            newNode->data=val;
            newNode->next=NULL;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
             newNode->next=temp->next;
             temp->next=newNode;
        }
    }
    void del_key(int key){
        Node* temp=head;
        Node* prev=NULL;
        if(temp==NULL)
          return;
        if(head->data==key){
            head=head->next;
            delete temp;
            return;
        }else{
        while(temp!=NULL && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
           {
               cout<<"Key not found"<<endl;
               return;
           }
        prev->next=temp->next;
        delete temp;
        }
    } 
    void del_pos(int pos){
       Node* temp=NULL;
      if(pos<0 && pos>length())
         return;  
      if(pos==0){
          temp=head;
          head=head->next;
          delete temp;
          return;
      }    
      Node* prev=head;
      for(int i=0;i<pos-1;i++){
          prev=prev->next;
      }
      if(prev==NULL || prev->next==NULL)
         return;
      temp=prev->next;
      prev->next=temp->next;
      delete temp;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void remove_duplicates(){
        Node *p=head;
        Node* q=head->next;
        while (q){
           if(p->data!=q->data){
               p=q;
               q=q->next;
           }else{
               p->next=q->next;
               delete q;
               q=p->next;
           }
        }
    }
    bool is_sorted(){
        int x=INT_MIN;
        Node* temp=head;
        while(temp){
            if(temp->data<x)
              return false;
            else{
                x=temp->data;
                temp=temp->next;
            }  
        }
        return true;
    }
    void r_reverse(Node*q,Node*p){
        if(p){
           r_reverse(p,p->next);
           p->next=q;
        }
        else{
            head=q;
        }
    }
    void reverse(){
          r_reverse(NULL,head);
    }
    void s_reverse(){
        Node*p=head;
        Node*q=NULL;
        Node*r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;

    }
    int r_duplicates(Node *head,int key){
        Node* temp=head;
        static int x=0;
        if(temp==NULL)
          return 0;
        if(temp->data==key)  
            return 1+r_duplicates(temp->next,key);
        return r_duplicates(temp->next,key);  
    }
   int duplicates(int key){
         return r_duplicates(head,key);
   } 
};
int main(){
    LinkedList ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll.insert_back(x);
    }
    ll.display();
    ll.s_reverse();
    ll.display();
    if(ll.is_sorted())
      cout<<"Yes"<<endl;
    else 
       cout<<"No"<<endl;  
    //ll.del_pos(7);
   // ll.display();
    //int len=ll.length();
    cout<<ll.duplicates(1)<<endl;
    return 0;
}