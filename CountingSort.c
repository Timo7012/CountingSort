#include<stdio.h>
#include<stdlib.h>

int min_f (int* array,int size){
    int min_var = array[0];
    for (int i = 1; i < size; ++i){
        if (array[i] < min_var)
        {
            min_var = array[i];
        }
    }
            return min_var;
    }

int max_f (int* array,int size){
    int max_var = array[0];
    for (int i = 1; i < size; ++i){
        if (array[i] > max_var)
        {
            max_var = array[i];
        }
    }
    return max_var;
}

void ct_sort(int* array,int size){
    int a_max = max_f(array, size), a_min = min_f(array, size);
    int size_c_array = (a_max - a_min + 1);
    int* count_array = (int*)malloc(size_c_array*sizeof(int));
    for (int i = 0; i < size_c_array; ++i){
        count_array[i] = 0;
    }

    for (int i = 0; i < size; ++i){
        ++count_array[array[i] - a_min];
    }
    int pos = 0;
    for (int i = a_min; i <= a_max; ++i){
        for (int j = 0; j < count_array[i - a_min]; ++j){
            array[pos++] = i;
        }
    }

    free(count_array);
}

int main(){
    int n;
    printf("Size of array:");
    scanf("%d",&n);
    int* array = (int*)malloc(n*sizeof(int));
    printf("Elements of array:");
    for (int i = 0;i < n; ++i){
        scanf("%d", &array[i]);
    }
    ct_sort(array,n);
    for (int i = 0; i < n; ++i){
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
//Counting sort
