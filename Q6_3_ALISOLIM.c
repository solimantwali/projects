#include <stdio.h>
#include <stdlib.h>
#define ENTRY_TYPE long long int

long long int mult(long long int n, long long int m){
    long long int prod = 0, count = 0; 
    while (m){ 
        if (m % 2 == 1) {prod += n << count;}
        count++; 
        m /= 2; 
    } 
    return prod; 
} 

ENTRY_TYPE* mat_mux(ENTRY_TYPE* A, ENTRY_TYPE *B, char* size_A[2], char* size_B[2]){
    if((int)*size_A[1] == (int)*size_B[0]){
        //printf("congrats fucker. correct dim for mtx mult\n");
        //printf("B[%d] is: %lld\n", 0, B[0]);
        int n = *size_A[1];
        int m = *size_A[0];
        int p = *size_B[1];
        ENTRY_TYPE* iroA = calloc(n, sizeof(ENTRY_TYPE));
        ENTRY_TYPE* jcoB = calloc(n, sizeof(ENTRY_TYPE));
        ENTRY_TYPE * Q = calloc(m*p, sizeof(ENTRY_TYPE));
        for(int k = 0; k< m*p ; k++){
            int rownum = (k/p)*n;
            int colnum = k%p;
            //printf("rownum is %d, colnum is %d\n", rownum, colnum);
            for(int t = 0; t<n ; t++){
                iroA[t] = A[rownum+t];
                jcoB[t] = B[colnum+t*p];
                //printf("mf index is %d\n", colnum+t*p);
                //printf("iroA[%d] is %d\n", t, iroA[t]); 
                //printf("jcoB[%d] is %d\n", t, jcoB[t]);
                Q[k] += mult(iroA[t],jcoB[t]);
            }
            //printf("\n\n");
        }
        free(iroA);
        free(jcoB);
        return Q;
    } 
    else {return 0;}
}

int main(void){
    // Matrix A
    char m = 2, p = 2, n = 3;
    //printf("prod is %d\n", m*n);
    ENTRY_TYPE * mtx_A = calloc(m*n,sizeof(ENTRY_TYPE));
    ENTRY_TYPE * mtx_B = calloc(p*n,sizeof(ENTRY_TYPE));
    
    for(int i = 0; i< m*n ; i++){
        mtx_A[i] = i+1;
    }

    for(int i = 0; i< p*n ; i++){
        mtx_B[i] = 6 + i+1;
    }

    //printf("\n");
    for(int i = 0; i< m*n ; i++){
        //printf("%lld ", mtx_A[i]);
    }
    //printf("\n");
    for(int i = 0; i< p*n ; i++){
        //printf("%lld ", mtx_B[i]);
    }
    //printf("\n");

    char* AS[2];
    char* BS[2];
    AS[0] = &m;
    AS[1] = &n;
    BS[0] = &n;
    BS[1] = &p;
    int rass = *AS[1];

    //printf("%d %d\n", (int)*AS[0], rass);
    //printf("%lld\n", mult(69,100));


    ENTRY_TYPE * QQ = mat_mux(mtx_A, mtx_B, AS, BS);
    for(int i = 0; i<m*p; i++){
        printf("%lld ", QQ[i]);
    }
    free(QQ);
}