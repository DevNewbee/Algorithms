#include <stdio.h>
int c=0;
void printArray(int* array, int length) {
    printf("\n");
    for(int i=0; i<length;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
}

int* findMaxCrossingSubarray(int* a, int low, int mid, int high) {
    
    int leftSum=0x80000000;
    int sum=0;
    int maxLeft = mid;
    for (int i=mid; i>=low; i--) {
        sum+=a[i];
        if (sum>leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum=0x80000000;
    sum=0;
    int maxRight = mid;
    for (int i=mid+1; i<=high; i++) {
        sum+=a[i];
        if (sum>rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }
    int data[3] = {maxLeft, maxRight, leftSum+rightSum};
    return data;
}
int* findMaxSubarray(int* a, int low, int high) {
//    int *a = data[0];
//    int low = data[1];
//    int high = data[2];

    if(high==low) {
        int data[3] ={ low,high,a[low]};
        return data;
    } else {
      
        int mid = (low+high)/2;
        int *dataLeft = findMaxSubarray(a, low, mid);
        printf("这是第%d次递归", c++);
        printArray(dataLeft, 3);

        int *dataRight = findMaxSubarray(a, mid+1, high);
        int *dataCross = findMaxCrossingSubarray(a, low, mid, high);
        if (dataLeft[2]>dataRight[2]&&dataLeft[2]>dataCross[2]) {
            return dataLeft;
        } else if (dataRight[2]>dataLeft[2]&&dataRight[2]>dataCross[2]) {
            return dataRight;
        } else {
            return dataCross;
        }
    }
    
}

int main()
{
    int a[] = {1,-2,3,4,5,9};
    int* data = findMaxSubarray(a, 0, sizeof(a)/sizeof(int)-1);
    printArray(data, 3);
    return 0;
    
}

