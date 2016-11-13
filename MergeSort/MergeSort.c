#include <stdio.h>

int c = 0;
void printArray(int* array, int length) {
    printf("\n");
    for(int i=0; i<length;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
}

void merge(int* a, int p, int q, int r) {
    
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int lSa[n1+1];
    int rSa[n2+1];
    for (int i=1; i<=n1; i++) {
        lSa[i-1]=a[p+i-1];
    }
    for (int j=1; j<=n1; j++) {
        rSa[j-1]=a[q+j];
    }
    
    lSa[n1] = 32767;
    rSa[n2] = 32767;
    
//    if (c == 1) {
//        printf("C: %d\n",c);
//        printArray(lSa,n1);
//        printArray(rSa,n2);
//    }
    int i=0,j=0;
    for (int k=p; k<=r; k++) {
        if (lSa[i] <= rSa[j]) {
//            printf("lsa[%d]=%d ",i,lSa[i]);
            a[k]=lSa[i++];
        }
        else {
//            printf("rsa[%d]=%d ",j,rSa[j]);
            a[k]=rSa[j++];
        }
//        if (c == 1) {
//            printf("p:%d q:%d r:%d ",p,q,r);
//            printf("k: %d",k);
//            printArray(a,3);
//        }
    }
    printf("第%d一次排序之后 ", (c++)+1);
    printArray(a,5); //输出每次排序之后的结果

}

void mergeSort(int* a, int p, int r) {
    if (p<r) {
        int q = (p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main()
{
    scanf
    int a[5] = {5,4,3,2,1};
    mergeSort(a,0,sizeof(a)/sizeof(int)-1);
    printf("最后归并排序结果");
    printArray(a,5);
    return 0;
    
}
