#include <stdio.h>
// This method is only works in Two Dimension Square Metrix
//int n = 4;
int n = 2;

void SMMRecursive(int **a, int **b, int **c,int oXA, int oYA, int oXB, int oYB, int l) {
    if (l == 1) {
//        printf("index%d:(%d,%d)\n",l,oYA,oXB);

        *((int*)c+oYA*n+oXB) =  *((int*)a+oYA*n+oXA)*(*((int*)b+oYB*n+oXB)) + *((int*)a+oYA*n+oXA+1)*(*((int*)b+(oYB+1)*n+oXB));
    } else {
        SMMRecursive(a,b,c,oXA,oYA,oXB,oYB,l/2);
        SMMRecursive(a,b,c,oXA,oYA,oXB+l/2,oYB,l/2);
        SMMRecursive(a,b,c,oXA,oYA+l/2,oXB,oYB,l/2);
        SMMRecursive(a,b,c,oXA,oYA+l/2,oXB+l/2,oYB,l/2);

    }
    
}

int main() {
//    int a[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
//    int b[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1 ,1,1}};
//    int r[4][4];
    int a[2][2]={{1,1},{1,1}};
    int b[2][2]={{1,1},{1,1}};
    int r[2][2];

    SMMRecursive((int**)a,(int**)b,(int**)r,0,0,0,0,n);
    for (int i=0; i<n; i++ ) {
        for (int j=0; j<n; j++) {
            printf("r[%d][%d]=%d ",i,j,r[i][j]);

        }printf("\n");
    }
}

