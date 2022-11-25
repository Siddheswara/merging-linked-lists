#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
}*first,*second,*third;
void create(int a[],int n){
    node *last,*t;
    first=new node;
    first->data=a[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=a[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}
void create1(int a[],int n){
    node *last,*t;
    second=new node;
    second->data=a[0];
    second->next=nullptr;
    last=second;
    //first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=a[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}

void display(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
        
    }
    cout<<endl;
}
void concat(node *p,node *q){
    node *ptr;
    while(p){
    ptr=p;
    p=p->next;
    }
    ptr->next=q;
}
void merge(node *p,node *q){
    node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
        
    }
    else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
      while(p!=NULL&&q!=NULL){
          if(p->data>q->data){
              last->next=q;
              last=q;
              q=q->next;
              last->next=NULL;
              
          }
         else{
              last->next=p;
              last=p;
              p=p->next;
              last->next=NULL;
              
          }
      }
      if(p!=NULL)last->next=p;
      else if(q!=NULL) last->next=q;
    }
    

int main()
{//node *second;
 
 int a[]={10,20,30,40,50,60,70,80,90,100};
 int b[]={19,29,39,49,59,69,79,89,99};
 create(a,10);
create1(b,9);
 display(first);
cout<<endl;
display(second);
 

 merge(first,second);
 display(third);


    return 0;
}