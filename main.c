#include <stdio.h>
#include <stdlib.h>
#include "linear algebra.c"

int TensorRandomByOrder(Tensor *T, int n) {
    int *I;
    I = malloc(n*sizeof(int));
    for (int k = 0; k < n; k++) {
        I[k] = 2;
    }
    DeclaringTensor(T, I, n);
    InitTensorByIndex(*T);
    free(I);
    return 1;
}

void run_test() {
    Tensor teste1, teste2, teste3, teste4;
    Tensor RandomT;
    int dim[] = {3,4};
    int dim2[] = {4,3};
    int dim3[] = {3,4,4,3};
    int dim4[] = {3,3};
    int r;

    r = DeclaringTensor(&teste1, dim, 2);
    r = DeclaringTensor(&teste2, dim2, 2);
    r = DeclaringTensor(&teste3, dim3, 2+2);
    r = DeclaringTensor(&teste4, dim4, 2);
    InitTensorByIndex(teste1);
    InitTensorByIndex(teste2);

    r = TensorProduct(teste1, teste2, teste3);
    r = TensorContraction(teste3, teste4, 1, 2);

    TensorRandomByOrder(&RandomT, 10);

    //print_array(teste3.values, 144);
    TensorPrint(teste1);
    //print_array(teste1.values, 12);
    TensorPrint(teste2);
    TensorPrint(teste4);

    TensorFree(&teste1);
    TensorFree(&teste2);
    TensorFree(&teste3);
}

int main() {
    run_test();
    return 0;
}
