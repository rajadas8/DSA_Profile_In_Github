//Write a program to create a Double linked list of n nodes and perform the following menu-based operations on it using function:
//1.Insert an element at the beginning
//2.Insert an element at the end
//3.Insert an element at any position
//4.Delete an Element From Beginning.
//5.Delete an Element From End.
//6.Delete an Element From Any Position.
//7.Sorting with Ascending Order.
//8.Sorting with Descending Order.
//9.Traverse
//10.Count number of nodes
//11. Search an element
//12.Reverse
//13.Exit
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
};
void insertElement(struct Node** start,int data){
    struct Node* q = *start;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*start == NULL){
        *start = temp;
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next = temp;
        temp->prev = q;
    }
}
void insertAtBeg(struct Node** start,int data){
    struct Node* q = *start;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*start == NULL){
        *start = temp;
    }
    else{
        temp->next = *start;
        (*start)->prev = temp;
        *start = temp;
    }
}
void insertAtEnd(struct Node** start,int data){
    struct Node* q = *start;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*start == NULL){
        *start = temp;
    }
    else{
        while(q->next!=NULL){
            q = q->next;
        }
        q->next = temp;
        temp->prev = q;
    }
}
void insertAtPosition(struct Node** start,int data,int pos){
    struct Node* q = *start;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*start == NULL || pos == 1){
        temp->next = *start;
        (*start)->prev = temp;
        *start = temp;
    }
    else{
        for(int i=1;i<pos-1;i++){
            q = q->next;
        }
        temp->next = q->next;
        q->next->prev = temp;
        q->next = temp;
        temp->prev = q;
    }
}
void deleteAtBeg(struct Node** start){
    struct Node* temp = *start;
    struct Node* q = *start;
    if(*start == NULL){
        return;
    }
    else if((*start)->next == NULL){
        *start = NULL;
        free(temp);
    }
    else{
        q = temp->next;
        *start = q;
        free(temp);
    }
}
void deleteAtEnd(struct Node** start){
    struct Node* temp = *start;
    struct Node* q = *start;
    if(*start == NULL){
        return;
    }
    else if((*start)->next == NULL){
        *start = NULL;
        free(temp);
    }
    else{
        temp = temp->next;
        while(q->next->next != NULL){
            q = q->next;
            temp = temp->next;
        }
        q->next = NULL;
        free(temp);
    }
}
void deleteAtPos(struct Node** start,int pos){
    struct Node* q = *start;
    struct Node* temp = *start;
    if(*start == NULL){
        return;
    }
    else if((*start)->next == NULL || pos == 1){
        *start = NULL;
        free(temp);
    }
    else{
        temp = temp->next;
        for(int i=1;i<pos-1;i++){
            q = q->next;
            temp = temp->next;
        }
        q->next = temp->next;
        temp->next->prev = q;
        free(temp);
    }
}
void ascendSort(struct Node** start){
    struct Node* p1 = *start;
    struct Node* p2 = *start;
    int temp;
    for(p1=*start;p1->next!=NULL;p1=p1->next){
        for(p2=p1->next;p2!=NULL;p2=p2->next){
            if(p1->val > p2->val){
                temp = p1->val;
                p1->val = p2->val;
                p2->val = temp;
            }
        }
    }
}
void descendSort(struct Node** start){
    struct Node* p1 = *start;
    struct Node* p2 = *start;
    int temp;
    for(p1=*start;p1->next!=NULL;p1=p1->next){
        for(p2=p1->next;p2!=NULL;p2=p2->next){
            if(p1->val < p2->val){
                temp = p1->val;
                p1->val = p2->val;
                p2->val = temp;
            }
        }
    }
}
int countNode(struct Node* head){
    struct Node* temp = head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
int search(struct Node* head,int data){
    struct Node* temp = head;
    int count=1;
    while(temp!=NULL){
        if(temp->val == data){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}
void reverse(struct Node** start){
    if((*start==NULL)||((*start)->next==NULL)){
        return;
    }
    struct Node* prevptr = NULL;
    struct Node* currptr = *start;
    struct Node* nextptr = NULL;
    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    *start = prevptr;
}
void display(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head = NULL;
    int n;
    printf("Enter The Total Number of Nodes of The Given Double Linked List:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int ele;
        printf("Enter %d Element:\n",i+1);
        scanf("%d",&ele);
        insertElement(&head,ele);
    }
    printf("The Given Double Linked List are:\n");
    display(head);
    printf("\nMENU\n");
    printf("1.Insert The Element At The Beginning.\n");
    printf("2.Insert Element At The End.\n");
    printf("3.Insert Element At The Specific Position.\n");
    printf("4.Delete An Element From Beginning.\n");
    printf("5.Delete An Element From End.\n");
    printf("6.Delete An Element From Any Position.\n");
    printf("7.Sorting With Ascending Order.\n");
    printf("8.Sorting With Descending Order.\n");
    printf("9.Traverse The Double Linked List.\n");
    printf("10.Count Total Number Of Nodes.\n");
    printf("11.Search an Element.\n");
    printf("12.Reverse\n");
    printf("13.Exit\n");
    while(1){
        int x,y,z,t,s,a,pos;
        int choice = 0;
        printf("Enter The Choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter The Element for Inserting at Beginning:\n");
            scanf("%d",&x);
            insertAtBeg(&head,x);
            printf("Element Inserted\n");
            printf("Current Double Linked List are:\n");
            display(head);
            break;
            case 2:
            printf("Enter The Element for Inserting at End:\n");
            scanf("%d",&y);
            insertAtEnd(&head,y);
            printf("Element Inserted\n");
            printf("Current Double Linked List are:\n");
            display(head);
            break;
            case 3:
            printf("Enter The Element for The Any Specific Position:\n");
            scanf("%d",&z);
            printf("Enter The Position:\n");
            scanf("%d",&pos);
            insertAtPosition(&head,z,pos);
            printf("Element Inserted\n");
            printf("Current Double Linked List are:\n");
            display(head);
            break;
            case 4:
            deleteAtBeg(&head);
            printf("The Current Double Linked List after Deleting Element From Beginning:\n");
            display(head);
            break;
            case 5:
            deleteAtEnd(&head);
            printf("The Current Double Linked List after Deleting Element From End:\n");
            display(head);
            break;
            case 6:
            printf("Enter The Position From Which Element will be Deleted:\n");
            scanf("%d",&pos);
            deleteAtPos(&head,pos);
            printf("The Current Double Linked List after Deleting Element at Position:\n");
            display(head);
            break;
            case 7:
            ascendSort(&head);
            printf("The Current Double Linked List after Ascending Order Sorting:\n");
            display(head);
            break;
            case 8:
            descendSort(&head);
            printf("The Current Double Linked List after Descending Order Sorting:\n");
            display(head);
            break;
            case 9:
            printf("Traverse Of The Double Linked List:\n");
            display(head);
            break;
            case 10:
            t = countNode(head);
            printf("Total Number of Nodes Of The Current Double Linked List are: %d\n",t);
            break;
            case 11:
            printf("Enter The Element for Searching:\n");
            scanf("%d",&s);
            a = search(head,s);
            printf("Element found at %d Position\n",a);
            break;
            case 12:
            reverse(&head);
            printf("The Reverse of The Double Linked List are:\n");
            display(head);
            break;
            case 13:
            printf("Exiting...\n");
            return 0;
            break;
            default:
            printf("Invalid Number!\n");
            break;
        }
    }
    return 0;
}