#include <stdio.h>
#include <stdlib.h>

int min(int i, int j) {
    if (i > j) {
        return j;
    }
    return i;
}

int max(int i, int j) {
    if (i > j) {
        return i;
    }
    return j;
}

typedef struct tensor {
    int dimension; // order
    int *dimensions;
    int values_dimension;
    float *values;
} Tensor;

int TensorFree(Tensor *T) {
    free(T->dimensions);
    free(T->values);
    T->dimension = -1;
    T->values_dimension = -1;
    return 1;
}

int ArrayIndexToLinear (int *Index, int *dimensions, int dimension) {
    int p = 1, I = 0;
    for (int k = 0; k < dimension; k++) {
        p *= dimensions[k];
    }
    for (int k = 0; k < dimension; k++) {
        p /= dimensions[k];
        I += Index[k]*p;
    }
    return I;
}

int TensorArrayIndexToLinear(int *Index, Tensor T) {
    return ArrayIndexToLinear(Index, T.dimensions, T.dimension);
}

int LinearIndexToArray (int I, int *Index, int *dimensions, int dimension) {
    int p = 1, r = 0;
    for (int k = 0; k < dimension; k++) {
        p *= dimensions[k];
    }

    /*if (*Index == NULL) {
        printf("INDEX CREATION");
        *Index = malloc(sizeof(int)*dimension);
        if (*Index == NULL) {
            printf("Couldn't allocate space for index array.\n");
            return 0;
        }
    }*/

    for (int k = 0; k < dimension; k++) {
        p /= dimensions[k];
        Index[k] = (I-r)/p;
        r += Index[k]*p;
    }

    return 1;
}

int TensorLinearIndexToArray (int I, int *Index, Tensor T) {
    return LinearIndexToArray(I, Index, T.dimensions, T.dimension);
}

void InitTensorByIndex (Tensor T) {
    for (int k = 0; k < T.values_dimension; k++) {
        T.values[k] = k;
    }
}
void InitTensorByZero (Tensor T) {
    for (int k = 0; k < T.values_dimension; k++) {
        T.values[k] = 0;
    }
}

void print_array(float *v, int num) {
    for (int k = 0; k < num; k++) {
        printf("%f ", v[k]);
    }
    printf("\n");
}


void TensorPrint(Tensor T) {
    if (T.dimension == 0) {
        printf("%f\n", T.values[0]);
    }
    else if (T.dimension == 1) {
        for (int i = 0; i < T.dimensions[0]; i++) {
            printf("%f ", T.values[i]);
        }
        printf("\n");
    }
    else if (T.dimension == 2) {
        float temp;
        for (int i = 0; i < T.dimensions[0]; i++) {
            for (int j = 0; j < T.dimensions[1]; j++) {
                temp = T.values[i*T.dimensions[1]+j];
                printf("%f ", temp);
            }
            printf("\n");
        }
    }
    else {
        printf("Too complex to show well...\n\n");
        print_array(T.values, T.values_dimension);
    }
    printf("\n");
}

int DeclaringTensor (Tensor *T, int *dimensions, int dimension) {
    int *temp_dimensions, p = 1;
    float *temp_values;

    temp_dimensions = malloc(sizeof(int)*dimension); // allocating space for Tensor.dimensions
    for (int k = 0; k < dimension; k++) {
        p *= dimensions[k];
    }
    temp_values = malloc(sizeof(float)*p); // allocating space for Tensor.values

    if (temp_dimensions == NULL || temp_values == NULL) {
        printf("Couldn't allocate space for Tensor.\n");
        return 0;
    }
    else {
        T->dimension = dimension;
        T->dimensions = temp_dimensions;
        for (int k = 0; k < dimension; k++) {
            T->dimensions[k] = dimensions[k];
        }
        T->values = temp_values;
        T->values_dimension = p;
    }

    return 1;
}

int TensorSum (Tensor T1, Tensor T2, Tensor T3) {
    // check for dimensions in each Tensor
    if (T1.dimension != T2.dimension || T1.values_dimension != T2.values_dimension) {
        //printf("%d, %d, %d, %d", T1.dimensions, T2.dimensions, T1.values_dimension, T2.values_dimension);
        printf("Tensors with different dimensions.\n");
        return 0;
    }
    for (int k = 0; k < T1.dimension; k++) {
        if (T1.dimensions[k] != T2.dimensions[k]) {
            printf("Tensors with different dimensions.\n");
            return 0;
        }
    }

    // declaring *T3
    /*
    if (DeclaringTensor(T3, T1.dimensions, T1.dimension) != 1) {
        printf("Couldn't allocate space for Tensor operation.\n");
        return 0;
    }*/

    for (int k = 0; k < T1.values_dimension; k++) {
        T3.values[k] = T1.values[k]+T2.values[k];
    }

    return 1;
}

int TensorScalar (Tensor T, float S) {
    for (int k = 0; k < T.values_dimension; k++) {
        T.values[k] *= S;
    }
    return 1;
}

int TensorProduct (Tensor T1, Tensor T2, Tensor T3) {
    // required: T1, T2 declared

    int *I, *J, *K, n; // indexes for T1 and T2
    int *L;

    // declaring T3 - bad idea
    /*
    if (T3->dimension = -1) {
        L = malloc(sizeof(int)*(T1.dimension+T2.dimension));
        for (int k = 0; k < T1.dimension; k++) {
            L[k] = T1.dimensions[k];
        }
        for (int k = 0; k < T2.dimension; k++) {
            L[k+T1.dimension] = T2.dimensions[k];
        }
        DeclaringTensor (T3, L, T1.dimension+T2.dimension);
        free(L);
        L = NULL;
        return 0;
    }*/

    // allocate space for T3 index_array
    I = malloc(sizeof(int)*T1.dimension);
    J = malloc(sizeof(int)*T2.dimension);
    K = malloc(sizeof(int)*(T1.dimension+T2.dimension));

    for (int i = 0; i < T1.values_dimension; i++) {
        for (int j = 0; j < T2.values_dimension; j++) {
            // convert both integers from T1,T2 to index_arrays
            TensorLinearIndexToArray(i, I, T1);
            TensorLinearIndexToArray(j, J, T2);
            // concatenate both indexes
            for (int k = 0; k < T1.dimension; k++) {
                K[k] = I[k];
            }
            for (int k = 0; k < T2.dimension; k++) {
                K[k+T1.dimension] = J[k];
            }
            // compute integer index for index_array from T3
            n = TensorArrayIndexToLinear (K, T3);
            T3.values[n] = T1.values[i]*T2.values[j];
        }
    }

    free(I);
    free(J);
    free(K);
    I = J = K = NULL;

    return 1;
}

// expand indexes array of N elements to  N+2 elements
int TensorExpandArray(int *I, int N, int i, int j, int k) {
    /*
        expand indexes array of N elements to  N+2 elements
        insert int 'k' in positions 'i' and 'j' in array I
    */
    int *I1, i1 = min(i,j), j1 = max(i,j);

    // make new array to join old and new indexes
    I1 = malloc((N+2)*sizeof(int));
    for (int l = 0; l < i1; l++) {
        I1[l] = I[l];
    }
    I1[i1] = k;
    for (int l = i1+1; l < j1; l++) {
        I1[l] = I[l-1];
    }
    I1[j1] = k;
    for (int l = j1+1; l < N+2; l++) {
        I1[l] = I[l-2];
    }

    // copy to old array with new indexes
    I = realloc(I, (N+2)*sizeof(int));
    for (int l = 0; l < N+2; l++) {
        I[l] = I1[l];
    }
    free(I1);

    return 0;
}

int TensorContraction(Tensor T1, Tensor T2, int i, int j) {
    int *I;
    int s;
    int n = T1.dimensions[i];
    int m;
    int sizeI = T2.dimension*sizeof(int);
    if (T1.dimensions[i] != T1.dimensions[j]) {
        printf("bad indexes for contraction\n");
        return 0;
    }

    I = malloc(sizeI);

    // T2 already declared
    for (int k = 0; k < T2.values_dimension; k++) {
        s = 0;
        for (int l = 0; l < n; l++) {
            TensorLinearIndexToArray(k, I, T2);
            TensorExpandArray(I,T2.dimension, i, j, l);
            m = TensorArrayIndexToLinear(I, T1);
            s += T1.values[m];
            I = realloc(I, sizeI);
        }
        T2.values[k] = s;
    }

}
