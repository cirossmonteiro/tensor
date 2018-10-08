# tensor
tensor computation

Suppose you want an 3-order tensor, then you type:

```
Tensor T;
int ind1 = 3, ind2 = 4, ind3 = 5;
int dim[] = {ind1, ind2, ind3};
DeclaringTensor(&T, dim, 3);
```

If you want to begin with only zeros:
```
InitTensorByZero(T);
```

```
typedef struct tensor {
    int dimension; // order
    int *dimensions;
    int values_dimension;
    float *values;
} Tensor

int DeclaringTensor (Tensor *T, int *dimensions, int dimension)  // allocate memory

int TensorFree(Tensor *T) // deallocate memory

int ArrayIndexToLinear (int *Index, int *dimensions, int dimension) // transform array of indexes into linear index

int TensorArrayIndexToLinear(int *Index, Tensor T) // transform array of indexes (from Tensor variable) into linear index

int LinearIndexToArray (int I, int *Index, int *dimensions, int dimension) // transform linear index into arry of indexes

int TensorLinearIndexToArray (int I, int *Index, Tensor T) // transform linear index into array of indexes (from Tensor dimensions)

void InitTensorByIndex (Tensor T) // Tensor values by index

void InitTensorByZero (Tensor T) // Tensor has only zeros

void TensorPrint(Tensor T) // printf of Tensor values

int TensorSum (Tensor T1, Tensor T2, Tensor T3)

int TensorScalar (Tensor T, float S) // Tensor x scalar

int TensorProduct (Tensor T1, Tensor T2, Tensor T3)

int TensorExpandArray(int *I, int N, int i, int j, int k) // add 'k' to array I in positions 'i' and 'j'

int TensorContraction(Tensor T1, Tensor T2, int i, int j)
```
