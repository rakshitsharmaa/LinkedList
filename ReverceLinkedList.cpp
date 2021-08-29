#include<iostream>
using namespace std;

class Node
{

public:
    Node* next;
    int n;
    Node(int n){
        this->n=n;
        next=NULL;
    }
};


void Insert(Node* &Head,int d){
       Node* temp =new Node(d);
       if (Head==NULL)
       {
           Head=temp;
       }
       else{
           Node* temp1=Head;
           while (temp1->next!=NULL)
           {
               temp1=temp1->next;
           }
           temp1->next=temp;

           
       }
       
    }
void Reverce(Node* &Head){
        Node* temp,*current,*next,*prev;
        temp=Head;
        prev=NULL;
        while (temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        Head=prev;
    }
 Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverse(head->next);
        Node* q =head->next;
        q->next=head;
        head->next=NULL;

        // head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
void print(Node* Head){
    while (Head!=NULL)
    {
        cout<<Head->n<<"->";
        Head=Head->next;
    }
    
}

int main(){
    Node* Head=NULL;
    Insert(Head,5);
    Insert(Head,6);
    Insert(Head,7);
    Insert(Head,8);
    Insert(Head,9);
    Insert(Head,10);
    Insert(Head,11);
    Insert(Head,12);
    Insert(Head,13);
    print(Head);
    Reverce(Head);
    print(Head); 
    print(reverse(Head));  
}


