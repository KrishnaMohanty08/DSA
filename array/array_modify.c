#include <stdio.h>
#include <stdlib.h>

void insert(int* arr,int* n,int pos,int item) {

    for (int i = (*n); i > pos; i--) {
        *(arr+i) = *(arr+i-1);
    }
    arr[pos] = item;
}

int del(int* arr,int* n,int pos) {
  
    for(int i=0;i<=(*n);i++){
      if(pos<=i){
        *(arr+i)=*(arr+i+1);
      }
    }(*n)--;
}

int update(int *arr,int* n,int pos,int item){

      arr[pos]=item;
}


int main() {
    int *N, item, pos;
    printf("Enter the number of elements: ");
    scanf("%d", N);
    printf("Enter the position and item to insert: ");
    scanf("%d %d", &pos, &item);

    int Arr[]={2,4,6,8,1};

    int* pArr = Arr; 
    //insert(pArr,N,pos,item);
    //del(pArr,N,pos);
    //update(pArr,N,pos,item);

    printf("Updated array: \n");
    for (int i = 0; i <*N; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");

    return 0;
}