#include <stdio.h>
#include <conio.h>

int main() {
    int first, last, middle, size, i, sElement;
    int list[100];

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d integer values in ascending order:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter value to be searched: ");
    scanf("%d", &sElement);

    first = 0;
    last = size - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        
middle=(first+last)/2;
        if (list[middle] == sElement) {
            printf("Element %d found at index %d\n", sElement, middle + 1);
            
            break;
        }
        else if (list[middle] < sElement) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
            
        }
    }
    if(first>last)
    printf("Element %d not found in the list\n", sElement);
    return 0;
}

