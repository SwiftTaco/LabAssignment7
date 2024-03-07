#include <stdio.h>

//create struct so we can store 2 values together
typedef struct element{
    int data;
    int numswaps;
}element;

//function to swap 2 elements
void swap(element* a, element* b)
{
    element temp = *a;
    *a = *b;
    *b = temp;
    a->numswaps++;
    b->numswaps++;
}

//bubble sort function
int bubble_sort(element arr[], int number)
{   
    //intitialize total swaps
    int total = 0;
    for(int i = 0; i < number - 1; i++)
    {
        for(int j = 0; j < number - i - 1; j++)
        {
            if(arr[j].data > arr[j + 1].data)
            {
                swap(&arr[j], &arr[j + 1]);
                total++;
            }
        }
    }
    //return total swaps
    return total;
}

//selection sort function
int selection_sort(element arr[], int number)
{
    //initialize total swaps
    int total = 0;
    for(int i = 0; i < number - 1; i++)
    {
        int min_idx = i; 
        for(int j = i + 1; j < number; j++)
        {
            if(arr[j].data < arr[min_idx].data)
            {
                min_idx = j;
            }
        }
        if(min_idx != i)
        {
            swap(&arr[i], &arr[min_idx]);
            total++;
        }
    }
    //return total swaps
    return total;
}


int main()
{
    //I used the same arrays just made ones in respect to their swap formula
    element arraybubble[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    element array2bubble[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};  
    element arrayselection[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    element array2selection[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};  

    //this calls the sort function to return the total amount of swaps 
    int totalswapsbubble = bubble_sort(arraybubble, 9);
    int totalswapsbubble2 = bubble_sort(array2bubble, 9);
    int totalswapsselection = selection_sort(arrayselection, 9);
    int totalswapsselection2 = selection_sort(array2selection, 9);

    //print out the data to terminal
    printf("array1 bubble sort:\n");

    for(int i = 0; i < 9; i++)
    {
        printf("%d: %d\n", arraybubble[i].data, arraybubble[i].numswaps);
    }

    printf("%d\n\narray2 bubble sort:\n", totalswapsbubble);

    for(int i = 0; i < 9; i++)
    {
        printf("%d: %d\n", array2bubble[i].data, array2bubble[i].numswaps);
    }
    
    printf("%d\n\narray1 selection sort:\n", totalswapsbubble2);

    for(int i = 0; i < 9; i++)
    {
        printf("%d: %d\n", arrayselection[i].data, arrayselection[i].numswaps);
    }

    printf("%d\n\narray2 selection sort:\n", totalswapsselection);

    for(int i = 0; i < 9; i++)
    {
        printf("%d: %d\n", array2selection[i].data, array2selection[i].numswaps);
    }

    printf("%d", totalswapsselection2);


}