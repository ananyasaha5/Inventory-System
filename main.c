#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
struct Prod{
    int id;
    int quantity;
    float price;
    char name[100];
    
};

struct Prod inventory[MAX];
int count=0;

void addProd(){
    if(count>=MAX){
        printf("Inventory is Full!\n");
        return;
    }
    
    printf("Enter Product ID:");
    scanf("%d",&inventory[count].id);
    printf("Enter Product name:");
    scanf(" %[^\n]",inventory[count].name);
    printf("Enter Quantity:");
    scanf("%d",&inventory[count].quantity);
    printf("Enter Price:");
    scanf("%f",&inventory[count].price);
    
    count++;
    printf("Product Added successfully!\n");
}

void DisplayProd(){
    if(count==0){
        printf("Inventory is Empty!\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    for(int i=0;i<count;i++){
        printf("ID: %d || Name: %s || Quantity: %d || Price: %.2f\n",
               inventory[i].id,inventory[i].name,inventory[i].quantity,inventory[i].price);
    }
    printf("\n");
}

void SearchProd(){
    int id, found=0;
    printf("Enter ID to be searched:");
    scanf("%d",&id);
    
    for(int i=0;i<count;i++){
        if(inventory[i].id==id){
            printf("Item Found: ID: %d || Name: %s || Quantity: %d || Price: %.2f\n",
               inventory[i].id,inventory[i].name,inventory[i].quantity,inventory[i].price);
               found=1;
               break;
        }
    }
    if (!found){
        printf("Item not found!\n");
    }
    printf("\n");
}   

void DelProd(){
    int id,found=0;
    printf("Enter ID to be deleted:");
    scanf("%d",&id);
    
    for(int i=0;i<count;i++){
        if(inventory[i].id==id){
            for(int j=i;j<count-1;j++){
                inventory[j]=inventory[j+1];
            }
            count--;
            found=1;
            printf("Product Deleted successfully!\n");
            break;
        }
    }
    if(!found){
        printf("Product not found!\n");
    }
}

int main(){
    int choice;
    
    while(1){
        printf("Inventory Manangement System\n");
        printf("1) Add Product\n2) Desiplay Products\n3) Search Product\n4) Delete Product\n5) Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: addProd(); break;
            case 2: DisplayProd(); break;
            case 3: SearchProd(); break;
            case 4: DelProd(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
        
    }
    return 0;
}
