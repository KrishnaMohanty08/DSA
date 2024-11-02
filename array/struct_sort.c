#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  char name[100];
  int salary;
}Employee;

int swap(Employee *a,Employee *b){
    Employee temp =*a;
    *a =*b;
    *b=temp;
}

void sortEmployee(Employee *employee,int count){
  for(int i=0;i<count;i++){
        for(int j=0;j<count;j++){
            if(employee[j].salary<employee[j+1].salary){
                swap(&employee[j],&employee[j+1]);
            }
        }
    }
}

void getdetails(Employee *employee,int count){
    for(int i=0;i<count;i++){
        printf("Enter the Employee id :");
        scanf("%d",&employee[i].id);
        printf("Enter the Employee name :");
        scanf("%s",employee[i].name);
        printf("Enter the Employee salary :");
        scanf("%d",&employee[i].salary);
    }
}

void printdetails(Employee *employee, int count){
    for(int i=0;i<count;i++){
        printf("\n[%d,%s,%d]",employee[i].id,employee[i].name,employee[i].salary);
    }
}
int main(){
    int n=3;
    int *emp=(int*)malloc(n*sizeof(int));
    
    getdetails(emp,n);
    
    sortEmployee(emp,n);
    
    printf("The sorted array is");
    printdetails(emp,n);
    
}