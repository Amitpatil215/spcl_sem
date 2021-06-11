//Patil Amit Gurusidhappa, 19104004, B11>>
// Quick sort used

// Worst-case space complexity: O(n)
// Worst-case performance: O(n2)
// Average performance: O(n log n)

#include <stdio.h>
#include <stdlib.h>

void quicksort(float number[], int first, int last)
{
    int i, j, pivot;
    float temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int i, count;
    float *number;
    printf("How many tracks are there (Min 5): ");
    scanf("%d", &count);
    if (count < 5)
    {
        printf("at lease 5 tracks should be there");
        return 0;
    }
    printf("Given timings %d of athlete: ", count);

    // Dynamically allocate memory using malloc()
    number = (float *)calloc(count, sizeof(float));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (number == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (i = 0; i < count; i++)
        scanf("%f", &number[i]);
    quicksort(number, 0, count - 1);
    printf("The Sorted Order is: \n");
    for (i = 0; i < count; i++)
        printf(" %.2f", number[i]);
    printf("\n");
    printf("The winner is on track 5 with timing as %.2f \n", number[4]);
    printf("The winner is on track 1 with timing as %.2f\n ", number[0]);

    // average

    float sum = 0;
    float avg = 0;
    for (i = 0; i < count; i++)
    {
        sum = sum + number[i];
    }
    avg = sum / count;
    printf("Average time taken by all the athletes::%.2f \n", avg);
    return 0;
}