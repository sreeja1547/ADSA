#include<stdio.h>
void merge (int arr[],int left, int mid,int right){
	int i,j,k;
	int n1=mid-left+1;
	int n2=right-mid;
	int L[n1],R[n2];
	for(i=0;i<n;i++){
		L[i]=arr[left+i];
	}
	for (j=0;j<n2;j++){
		R[j]=arr[mid+1+j];
	i=0;
	j=0;
	k=left;
	while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
	while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
	}
	}
	while(j<n2){
	arr[k]=R[j]
	j++;
	k++
	}}
	void mergeSort(int arr[],int left,int right){
		if(left<right){
			int mid=left+(right-left)/2;
			mergesort(arr,left,mid);
			mergesort(arr,mid+1,right);
			mergesort(arr,left,mid,right);
		}
	}
int main(){
	int n,i;
	int arr[100];
	printf("Enter the number of elements:");
	scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	printf("enter %d elements");
	for(i=0;i<n;i++){
		
	}
}
