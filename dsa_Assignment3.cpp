#include<iostream>
#define max 5
using namespace std;
class queue
{
 int a[max];
 int front,rear;
 
 public :
 
 queue()
 {
 front=-1;
 rear=-1;
 
 }
 
 int isempty()
 {
 if(rear==-1||front==-1)
 return 1;
 else
 return 0;
 
 }
 
 int isfull()
 {
 if((rear+1)%max==front)
 return 1;
 else
 return 0;
 
 }
 void enqueue(int value);
 void dequeue();
 void display();
};
int main()
{
 int value,choice;
 queue q;
 do
 {
 cout<<"\nSelect any one operation:\n 1.Enqueu\n 2.Dequeue\n 3.Display\n 4.Exit\n";
 cin>>choice;
 switch(choice)
 {
 case 1:cout<<"Enter value to be Inserted into queue\n";
 cin>>value;
 q.enqueue(value);
 break;
 case 2:q.dequeue();
 break;
 case 3:q.display();
 break;
 case 4:cout<<"Exit\n";
 break;
 default:cout<<"Wrong choice\n";
 break;
 }
 } while(choice!=4);
}
void queue::enqueue(int value)
{
 int x;
 x=isfull();
 if(x==1)
 cout<<"Queue is already full..cannot insert motre elements\n";
 else
 if(front==-1 && rear==-1)
 {
 front=0;
 rear=0;
 
 }
 
 else
 if(rear==max-1 && front!=0)
 rear=0;
 
 else
 {
 rear=(rear+1)%max;
 
 }
 
 a[rear]=value;
 
}
void queue::dequeue()
{
 int x;
 x=isempty();
 if(x==1)
 cout<<"Queue is empty...Cannot delete element\n";
 else
 if(front==rear)
 {
 cout<<"Deleted element is="<<a[front]<<"\n";
 front=-1;
 rear=-1;
 
 }
 
 else
 if(front==max-1)
 {
 cout<<"Deleted element is="<<a[front]<<"\n";
 front=0;
 
 }
 
 else
 {
 cout<<"Deleted element is ="<<a[front]<<"\n";
 front++;
 }
}
void queue::display()
{
 int i;
 if(front==-1)
 cout<<"Queue is empty\n";
 
 else
 {
 i=front;
 while(i!=rear);
 {
 cout<<a[i]<<"\t";
 i=(i+1)%max;
 
 }
 }
}