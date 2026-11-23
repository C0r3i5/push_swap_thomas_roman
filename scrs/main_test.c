#include "ft_bubble_sort.c"

#include <stdio.h>
#include <string.h>


// Hilfsfunktion: Kopiert die Originaldaten vor jedem Testlauf neu
void run_test(const char *name, void (*sort_fn)(int *, int), const int *orig, int n)
{
    int kopie[n];
    memcpy(kopie, orig, n * sizeof(int));

    sort_fn(kopie, n);

    printf("%-22s -> ", name);
    print_array(kopie, n);
}

int main(void)
{
    int original[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(original) / sizeof(original[0]);

    printf("Original:              -> ");
    print_array(original, n);

    run_test("Bubble Sort", bubble_sort, original, n);
    run_test("Insertion Sort", insertion_sort, original, n);
    run_test("Selection Sort", selection_sort, original, n);
    run_test("Min/Max Extraction", minmax_extraction_sort, original, n);

    return 0;
}