#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void InsertOnHead(Node* &Head,int d){
    if (Head==NULL)
    {
        Head = new Node(d);
        Head->next=NULL;
        return;
    }
    Node* n=new Node(d);
    n->next=Head;
    Head=n;   
}
void InsertAtTail(Node* &Head,int d){
    while (Head->next!=NULL)
    {
        Head=Head->next;
    }
    Node* n=new Node(d);
    Head->next=n;
}
int LengthOfList(Node* Head){
    int cnt=0;
    while (Head!=NULL)
    {
        cnt++;
        Head=Head->next;
    }
    return cnt;
}
void InsertInMiddle(Node* &Head,int d,int index){
    Node* g=Head;
    if (Head==NULL or index==0)
    {
        InsertOnHead(Head,d);
        return;
    }
    else if (LengthOfList(Head)<index)
    {
        InsertAtTail(Head,d);
    }
    else{
        int jump=1;
        while (jump<index-1)
        {
            Head=Head->next;
            jump++;
        }
        Node* n=new Node(d);
        n->next=Head->next;
        Head->next=n;
    }
    Head=g;
}
void Deletion(Node* &Head,int Index){
    Node* p=Head;
if (Head==NULL or Index ==0)
{
    return;
}

else if(LengthOfList(Head)<Index)
{
    return;
}
else{
    int jump=1;
    while (jump<Index-1)
    {
        Head=Head->next;
        jump++;
    }
    Node* n=Head->next;
    Head->next=n->next;
    delete n;
}
Head=p;
}
void print(Node* Head){
    while (Head!=NULL)
    {
        cout<<Head->data<<"->";
        Head=Head->next;
    }   
    cout<<endl;
}   
int main(){
    Node* Head=NULL;
    InsertOnHead(Head,4);
    InsertOnHead(Head,3);
    InsertOnHead(Head,2);
    InsertOnHead(Head,1);
    InsertOnHead(Head,0);
    print(Head);
    InsertInMiddle(Head,30,3);
    print(Head);
    Deletion(Head,3);
    print(Head);
}