#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*tail=NULL;
void insert(int data)
{
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if(head==NULL)
    {
        head=tail=nn;
    }
    else
    {
        tail->next=nn;
        tail=nn;
    }
}
void insertion()
{
    struct node*sorted=NULL;
    struct node*cur=head;
    while(cur!=NULL)
    {
        struct node*next=cur->next;
        if(sorted==NULL||sorted->data>cur->data)
        {
            cur->next=sorted;
            sorted=cur;
        }
        else
        {
            struct node*temp=sorted;
            while(temp->next!=NULL&&temp->next->data<cur->data)
            {
                temp=temp->next;
            }
            cur->next=temp->next;
            temp->next=cur;
        }
        cur=next;
    }
    head=sorted;
}
void display()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(data);
    }
    display();
    insertion();
    display();
}
