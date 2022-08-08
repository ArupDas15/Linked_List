/*The below program performs the following operations on a Singly linked List:
  1. Inserting an item in the list.
  2. deleting an item from the list.
  3. Traversing the list

  Author: Arup Das
*/

#include<stdio.h>
#include<stdlib.h>
int NODE_COUNT=0;

struct node{
    int data;
    struct node* next;
};
typedef struct node* Node;

//Function Prototypes
int ChooseMenu();
Node InsertInLinkedList(Node*,int);
Node DeleteNodeFromLinkedList(Node*,int);
void view_SLL(Node);

//Driver function
int main(){
    int position=0;
    Node head=NULL;
    char user_choice;
    do{
        switch(ChooseMenu()){
            case 1:printf("Enter the position to insert the new node: ");
                   scanf("%d",&position);
                   getchar();
                   if(((position==1)&&(head==NULL))||(position<=NODE_COUNT+1)){
                   head=InsertInLinkedList(&head,position);
                   NODE_COUNT++;
                   }
                   else printf("\n\n\tALERT: INVALID POSITION ENTERED!\n");
                   break;
            case 2:printf("Enter the position to delete a new node: ");
                   scanf("%d",&position);
                   getchar();
                   if(position<=NODE_COUNT){
                       head=DeleteNodeFromLinkedList(&head,position);
                       if(NODE_COUNT>0)NODE_COUNT--;
                   }
                   else printf("\n\n\tALERT: INVALID POSITION ENTERED!\n");
                   break;
            case 3:view_SLL(head);
                   break;
            default:printf("INVALID CHOICE ENTERED\n");
                    break;
            }
            printf("Do you want to continue? (Y/N): ");
        scanf("%c",&user_choice);
        getchar();
    }while(user_choice=='Y');
    printf("\n\t####User chose to exit.####\n");
    printf("\n\t****EXITING FROM PROGRAM****\n");

    return 0;
}//End of main()

int ChooseMenu(){
    int choice;
    printf("\n\tMENU\n");
    printf("1. Insert node in a Linked Liast at a specific postion\n");
    printf("2. Delete node from a Linked Liast at a specific postion\n");
    printf("3. Display Linked List\n\n");
    printf("\tEnter Choice: ");
    scanf("%d",&choice);
    getchar();
    return choice;
}
/* We are using a double pointer because the head pointer pointing to the first element in the Linked List
   should ultimately get updated. Had we used just a single pointer and tried to return it to head, then what would
   happen is after the return instruction is executed the resources allocated for the single pointer
   would have released by the called function and as a result the head pointer would not have been updated.
   Here even though we are returning the memory address yet we are returning it like a value which could be
   stored in a temporary space while the had pointer is getting updated.*/

Node InsertInLinkedList(Node* Ptr_to_Head,int position){

    int cnt=1;
    Node new_node=(Node)malloc(sizeof(struct node));
    Node current_node,previous_node;
    current_node=previous_node=NULL;

    printf("Enter new node data: ");
        scanf("%d",&new_node->data);
        getchar();
        new_node->next=NULL;
    if(!new_node){
        printf("\t MEMORY ERROR\n");
        return *Ptr_to_Head;
    }
    else{
         current_node=*Ptr_to_Head;
         if(position==1){
            new_node->next=current_node;
            *Ptr_to_Head=new_node;
          }
          else{
            while((cnt<position)&&(current_node!=NULL)){
            previous_node=current_node;
            current_node=current_node->next;
            cnt++;
            }
            previous_node->next=new_node;
            new_node->next=current_node;
          }
    }
    return *Ptr_to_Head;
}

Node DeleteNodeFromLinkedList(Node* Ptr_to_Head,int position){
    Node current_node=*Ptr_to_Head;
    Node previous_node;
    int cnt=1;

    if(*Ptr_to_Head==NULL){
        printf("SLL is empty.\n\n");
    }
    else{
        if(position==1){
            *Ptr_to_Head=(*Ptr_to_Head)->next;
            printf("Node data to be deleted is: %d\n",current_node->data);
            free(current_node);
        }
        else{
            while((cnt<position)&&(current_node->next!=NULL)){
                cnt++;
                previous_node=current_node;
                current_node=current_node->next;
            }
                previous_node->next=current_node->next;
                printf("Node data to be deleted is: %d\n",current_node->data);
                free(current_node);
        }
    }
    return *Ptr_to_Head;
}

void view_SLL(Node head){
    if(head==NULL){
        printf("\tSLL is not created!\n");
        printf("NODE COUNT=%d\n",NODE_COUNT);
        return;
    }
    else if(head->next==NULL){
        printf("%d -> NULL\n",head->data);
        printf("NODE COUNT=%d\n",NODE_COUNT);
        return;
    }
    else{
        Node current_node=head;
        while(current_node!=NULL){
            printf("%d -> ",current_node->data);
            current_node=current_node->next;

        }
        printf("NULL\n");
        printf("NODE COUNT=%d\n",NODE_COUNT);
    }
}
