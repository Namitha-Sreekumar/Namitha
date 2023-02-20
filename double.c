#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node * prev;
  struct node * next;
  int data;
};
struct node * head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
   int choice=0;
   while (choice!=9)
   {
      printf("\n**********MAIN MENU**********\n");
      printf("\nChoose one option from the following list\n");
      printf("\n1.Insert at the beginning\n 2.Insert at the last\n 3.Insert at any random location\n 4.delete form the beginning\n 5.delete form the last\n 6.delete the node of the given data \n 7.search\n 8.show\n 9.exit\n");
      printf("Enter ur choice: \n");
      scanf("\n%d",&choice);
      switch(choice)
      {
         case 1:
              insertion_beginning();
              break;
         case 2:
              insertion_last();
              break;
         case 3:
              insertion_specified();
              break;
         case 4: 
              deletion_beginning();
              break;
         case 5:
              deletion_last();
              break;
         case 6:
              deletion_specified();
              break;
         case 7:
              search();
              break;
         case 8:
              display();
              break;
         case 9:
              exit(0);
              break;
         default:
              printf("Please enter valid choice: ");
      }
   }
}
void insertion_beginning()
{
   struct node * ptr;
   int item;
   ptr=(struct node *)malloc(sizeof (struct node));
   if(ptr==NULL)
   {
      printf("\n Overflow");
   }
   else
   {
     printf("\nEnter item value: ");
     scanf("%d",&item);
     if(head==NULL)
     {
        ptr->next=NULL;
        ptr->prev=NULL;
        ptr->data=item;
        head=ptr;
     }
     else
     {
        ptr->data=item;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
     }
     printf("\nNode Insertion\n");
   }
}
void insertion_last()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node*)malloc(sizeof (struct node));
   if(ptr==NULL)
   {
      printf("\nOverflow\n");
   }
   else
   {
      printf("Enter the value: ");
      scanf("%d",&item);
      ptr->data=item;
      if(head==NULL)
      {
         ptr->next=NULL;
         ptr->prev=NULL;
         head=ptr;
      }
      else
      {
         temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=ptr;
         ptr->prev=temp;
         ptr->next=NULL;
      }
    }
    printf("\nNode inserted\n");
}
void insertion_specified()
{
    struct node *ptr,*temp;
    int item,loc,i;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
       printf("\n Overflow\n");
    }
    else
    {
       temp=head;
       printf("\nEnter the location: ");
       scanf("%d",&loc);
       for(i=1;i<loc;i++)
       {
          temp=temp->next;
          if(temp==NULL)
          {
             printf("\n There are lessthan %d elements",loc);
             return;
          }
       }
       printf("Enter value: ");
       scanf("%d",&item);
       ptr->data=item;
       ptr->next=temp->next;
       ptr->prev=temp;
       temp->next=ptr;
       temp->next->prev=ptr;
       printf("\nNode inserted\n");
    }
}
void deletion_beginning()
{
    struct node *ptr;
    if(head==NULL)
    {
       printf("\n Underflow");
    }
    else if (head->next==NULL)
    {
       head=NULL;
       free(head);
       printf("\n Node deleted");
    }
    else
    {
       ptr=head;
       head=head->next;
       head->prev=NULL;
       free(ptr);
       printf("\nnode deleted");
    }
}
void deletion_last()
{
    struct node *ptr;
    if(head==NULL)
    {
       printf("\nUnderflow");
    }
    else if(head->next==NULL)
    {
       head=NULL;
       free(head);
       printf("\nNode deleted\n");
    }
    else
    {
      ptr=head;
      while(ptr->next!=NULL)
      { 
          ptr=ptr->next;
      }        
      ptr->prev->next=NULL;
      free (ptr);
      printf("\nNode deleted");
    }
}
void deletion_specified()
{
   struct node *ptr,*temp;
   int val;
   printf("\nEnter the data after which the node is to be deleted: ");
   scanf("%d",&val);
   ptr=head;
   while(ptr->data!=val)
     ptr=ptr->next;
   if(ptr->next==NULL)
   {
      printf("\n Can't delete\n");
   }
   else if(ptr->next->next==NULL)
   {
       ptr->next=NULL;
   }
   else
   {
       temp=ptr->next;
       ptr->next=temp->next;
       temp->next->prev=ptr;
       free(temp);
       printf("\nNode deleted\n");
   }
}
void display()
{
   struct node *ptr;
   printf("\nPrinting values....\n");
   ptr=head;
   while(ptr!=NULL)
   {
       printf("%d \n",ptr->data);
       ptr=ptr->next;
   }
}
void search() 
{  
   struct node *ptr;
   int item,i=0,flag;
   ptr=head;
   if(ptr==NULL)
   {
      printf("\nEmpty list\n");
   }
   else
   {
       printf("\nEnter item which you want to search?\n");
       scanf("%d",&item);
       while(ptr!=NULL)
       {
           if(ptr->data==item)
           { 
               printf("\nItem found at location %d",i+1);
               flag=0;
               break;
           }
           else
           {
              flag=1;
           }
           i++;
           ptr=ptr->next;
       }
       if(flag==1)
       {
           printf("\nItem not found \n");
       }
   }
}









      
