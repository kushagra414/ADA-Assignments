#include <stdio.h>
#include <string.h>

void merge(char Name[], int l, int mid, int h){
    int N1 = mid-l+1;
    int N2 = h-mid;
    int L[N1],R[N2];
    for(int i=0;i<N1;i++)
        L[i]=Name[l+i];

    for(int j=0;j<N2;j++)
        R[j]=Name[mid+1+j];

    int i,j,k=l;
    for(i=0,j=0;i<N1&&j<N2;)
        if(L[i]<=R[j])
            Name[k++]=L[i++];
        else
            Name[k++]=R[j++];

    while(i<N1)
        Name[k++]=L[i++];
    while(j<N2)
        Name[k++]=R[j++];
}

void mergeSort(char Name[], int l, int h){
    int mid = l+(h-l)/2;
    if(l<h){
        mergeSort(Name,l,mid);
        mergeSort(Name,mid+1,h);
        //Call Merge Algo when array cannot be further partitioned
        merge(Name,l,mid,h);
    }
}

int main() {
    int T;
    printf("Enter Number of Test Cases\n");
    scanf("%d",&T);
    while(T--){
        int N1,N2;
        char firstName[50],secondName[50];
        printf("Enter your First Name : ");
        scanf("%s",firstName);
        printf("Enter your Second Name : ");
        scanf("%s",secondName);
        N1=strlen(firstName);
        N2=strlen(secondName);
        mergeSort(firstName,0,N1-1);
        mergeSort(secondName,0,N1-1);
        for(int i=0;i<N1;i++)
            printf("%c",firstName[i]);
        printf(" ");
        for(int i=0;i<N2;i++)
            printf("%c",secondName[i]);
        printf("\n");
    }
	return 0;
}
