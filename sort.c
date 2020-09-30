// Matt Rallo
// 3-16-2016
// Project 2
// mtrc6d
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

// Prototypes
void copy_array(int a[], int b[], int size); // used so I have the same array for each sort
void selection_sort(int a[], int size);
void insertion_sort(int a[], int size);
void bubble_sort1(int a[], int size); // not counting swaps
void bubble_sort2(int a[], int size); // counting swaps
void quicksort(int a[], int left, int right);
int partition(int a[], int left, int right); //used for quicksort
void mergesort(int a[], int l, int r);
void merge(int a[], int l, int mid, int r); //used for mergesort

int main (void)
{
    int length = 0; // Used for size of array
    printf("Beginning of Program.\n");
    printf("Please enter the size of the array: ");

    scanf("%d", &length); // scanning for size

    int rand_array[length]; // Create an array for Random Numbers
    int i;
    int num; // Used to assign random num
    time_t t; // Used for random
    srand((unsigned) time(&t)); // USed for random number

    for(i=0; i<length; i++) { // Initializing the array
        num = rand() % 10000 + 1; // Numbers 1 ~ 10,000
        rand_array[i] = num;
    }


    int array[length];
    // Creating an array for sorting
    // That way I don't mess with the random number array
    // I copy the array each time so I have the same list for each algorithm


    clock_t start, end; // used to find time
    double time;
    double nano_time;

    printf("\nSORTING ARRAY METHODS OF A RANDOM NUMBER ARRAY\n");

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    selection_sort(array, length);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Selection Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    insertion_sort(array, length); // Sorting list of random numbers
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Insertion Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    bubble_sort1(array, length); // without swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    bubble_sort2(array, length); // counting swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort(swap count) Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    quicksort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Quicksort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(rand_array, array, length); // array is now a copy of rand array
    start = clock();
    mergesort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Mergesort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    // creating a sorted array
    int sort_array[length];
     for(i=0; i<10; i++){
        sort_array[i] = i + 1;
    }

    printf("\nSORTING ARRAY METHODS OF A SORTED ARRAY\n");

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    selection_sort(array, length);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Selection Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    insertion_sort(array, length); // Sorting list of random numbers
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Insertion Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    bubble_sort1(array, length); // without swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    bubble_sort2(array, length); // counting swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort(swap count) Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    quicksort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Quicksort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(sort_array, array, length); // array is now a copy of sort array
    start = clock();
    mergesort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Mergesort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);


    // creating a nearly sorted array
    // Every 10th number is out of place

    int nearly_sort[length];
    for(i=0; i<length; i++){
        nearly_sort[i] = i + 1;
        if(nearly_sort[i]%10 == 0) {
            nearly_sort[i] = length - nearly_sort[i] + 1;
        }
    }


    printf("\nSORTING ARRAY METHODS OF A NEARLY SORTED ARRAY\n");

    copy_array(nearly_sort, array, length); // array is now a copy of nearly sort
    start = clock();
    selection_sort(array, length);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Selection Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(nearly_sort, array, length); // array is now a copy of nearly array
    start = clock();
    insertion_sort(array, length); // Sorting list of random numbers
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Insertion Sort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(nearly_sort, array, length); // array is now a copy of nearly array
    start = clock();
    bubble_sort1(array, length); // without swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(nearly_sort, array, length); // array is now a copy of nearly array
    start = clock();
    bubble_sort2(array, length); // counting swaps
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* BubbleSort(swap count) Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(nearly_sort, array, length); // array is now a copy of nearly array
    start = clock();
    quicksort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Quicksort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    copy_array(nearly_sort, array, length); // array is now a copy of nearly array
    start = clock();
    mergesort(array, 0, length-1);
    end = clock();
    time = ((double)end - start) / CLOCKS_PER_SEC;
    nano_time = time * 1000000000;
    printf("* Mergesort Time: %.6f seconds, %.6f nanoseconds.\n", time, nano_time);

    printf("\nEnd of Program.\n");

    return 0;
}

void copy_array(int a[], int b[], int size){ // b will be a copy of a
    int i;
    for(i = 0; i<size; i++)
        b[i] = a[i];

}

void selection_sort(int a[], int size){
    int i;
    int j;
    int temp;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
        if(a[i] > a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
        }
    }

}

void insertion_sort(int a[], int size){
    int i, j, key;

    for(i=1; i<size; i++) {
        key = a[i];
        j = i - 1;
        while (( a[j] > key) && (j >= 0)) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }


}

void bubble_sort1(int a[], int size) {
    int i, j, swap;

    for(i=0; i < size; i++) {
        for( j=0; j<size-1; j++){
            if(a[j] > a[j+1]){
                swap = a[j+1];
                a[j+1] = a[j];
                a[j] = swap;
            }
        }
    }

}

void bubble_sort2(int a[], int size){  // counting swaps
    int i, j, swap;
    int count = 0;

    for(i=0; i < size; i++) {
        for( j=0; j<size-1; j++){
            if(a[j] > a[j+1]){
                swap = a[j+1];
                a[j+1] = a[j];
                a[j] = swap;
                count++;
            }
        }
        if(count == 0)
            break;
    }


}

void quicksort(int a[], int left, int right) {
    if( left < right ) {
        int p;
        p = partition(a, left, right);
        quicksort(a, left, p - 1);
        quicksort(a, p + 1, right);
    }



}

int partition(int a[], int left, int right) {
    int i, j, pivot, swap;
    pivot = a[right];
    i = left-1;
    for(j = left; j < right; j++){
        if(a[j] <= pivot){
            i = i + 1;
            swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }
    swap = a[i+1];
    a[i+1] = a[right];
    a[right] = swap;
    return i+1;
}

void mergesort(int a[], int l, int r){ // l is left, r is right
    if (l < r) {
        int mid = (r + l) /2; //middle
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

void merge(int a[], int l, int mid, int r){
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Temp arrays
    int L[n1];
    int R[n2];

    // copy to arrays
    for( i=0; i<n1; i++) {
        L[i] = a[l+i]; // that's not a 1 but a "L"
    }
    for( j =0; j<n2; j++){
        R[j] = a[mid+1+j];
    }

    i =0;
    j =0;
    k = l;

   while (i<n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

