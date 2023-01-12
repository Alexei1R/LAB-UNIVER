#include "Log.h"
#include "macros.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_ADDR_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_HOURS_LEN 20

struct Supermarket {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDR_LEN];
    char phone[MAX_PHONE_LEN];
    char hours[MAX_HOURS_LEN];
    float sales_volume;
};

// Function prototypes
void dynamic_memory_allocation(struct Supermarket** array, int* size);
void enter_elements(struct Supermarket* array, int size);
void display_elements(struct Supermarket* array, int size);
void add_element(struct Supermarket** array, int* size);
void change_element(struct Supermarket* array, int size);
void search_element(struct Supermarket* array, int size);
void sort_array(struct Supermarket* array, int size);
void remove_element(struct Supermarket** array, int* size);
void free_memory(struct Supermarket** array);


int main() {
	Log::Init();

    int size = 0;
    struct Supermarket* array = NULL;

    int choice;
    
    
    do {
        LOG_CRITICAL("\nOptions menu:");
        printf("\n");
        LOG_TRACE("1. Dynamic memory allocation for array of structures\n");
        LOG_TRACE("2. Entering tableau elements from the keyboard\n");
        LOG_TRACE("3. Display the tableau elements on the screen\n");
        LOG_TRACE("4. Adding a new element at the end\n");
        LOG_TRACE("5. Changing the tableau element\n");
        LOG_TRACE("6. Searching for array element\n");
        LOG_TRACE("7. Sorting the painting\n");
        LOG_TRACE("8. Removing the indicated element from the array\n");
        LOG_TRACE("9. Freeing the memory allocated for the table\n");
        LOG_INFO("0. Exit the program\n");


        LOG_WARN("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            dynamic_memory_allocation(&array, &size);
            break;
        case 2:
            enter_elements(array, size);
            break;
        case 3:
            display_elements(array, size);
            break;
        case 4:
            add_element(&array, &size);
            break;
        case 5:
            change_element(array, size);
            break;
        case 6:
            search_element(array, size);
            break;
        case 7:
            sort_array(array, size);
            break;
        case 8:
            remove_element(&array, &size);
            break;
        case 9:
            free_memory(&array);
            break;
        case 0:
            printf("Exiting the program...\n");
            break;
        default:
            LOG_CRITICAL("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;


}



// Function definitions
void dynamic_memory_allocation(struct Supermarket** array, int* size) {
    printf("Enter the number of elements you want to allocate memory for: ");
    scanf("%d", size);

    *array = (struct Supermarket*)malloc(*size * sizeof(struct Supermarket));
    if (*array == NULL) {
        printf("Error allocating memory!\n");
    }
}

void enter_elements(struct Supermarket* array, int size) {
    if (array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("\nEnter element %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", array[i].name);
        printf("Address: ");
        scanf("%s", array[i].address);
        printf("Phone: ");
        scanf("%s", array[i].phone);
        printf("Hours: ");
        scanf("%s", array[i].hours);
        printf("Sales volume: ");
        scanf("%f", &array[i].sales_volume);
    }
}

void display_elements(struct Supermarket* array, int size) {
    if (array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    LOG_INFO("\n\n\n\n\Displaying elements:\n");
    for (int i = 0; i < size; i++) {
        LOG_WARN("\nElement {0}:\n", i + 1);
        LOG_WARN("Name: {0}\n", array[i].name);
        LOG_WARN("Address: {0}\n", array[i].address);
        LOG_WARN("Phone: {0}\n", array[i].phone);
        LOG_WARN("Hours: {0}\n", array[i].hours);
        LOG_WARN("Sales volume: {0}\n", array[i].sales_volume);
    }
}

void add_element(struct Supermarket** array, int* size) {
    if (*array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    *size += 1;
    *array = (struct Supermarket*)realloc(*array, *size * sizeof(struct Supermarket));
    if (*array == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    printf("\nEnter element %d:\n", *size);
    printf("Name: ");
    scanf("%s", (*array)[*size - 1].name);
    printf("Address: ");
    scanf("%s", (*array)[*size - 1].address);
    printf("Phone: ");

    scanf("%s", (*array)[*size - 1].phone);
    printf("Hours: ");
    scanf("%s", (*array)[*size - 1].hours);
    printf("Sales volume: ");
    scanf("%f", &(*array)[*size - 1].sales_volume);
}

void change_element(struct Supermarket* array, int size) {
    if (array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    int index;
    printf("\nEnter the index of the element you want to change: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Error: Invalid index!\n");
        return;
    }

    printf("\nEnter the new element:\n");
    printf("Name: ");
    scanf("%s", array[index].name);
    printf("Address: ");
    scanf("%s", array[index].address);
    printf("Phone: ");
    scanf("%s", array[index].phone);
    printf("Hours: ");
    scanf("%s", array[index].hours);
    printf("Sales volume: ");
    scanf("%f", &array[index].sales_volume);
}

void search_element(struct Supermarket* array, int size) {
    if (array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("\nEnter the name of the element you want to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, name) == 0) {
            printf("\nElement found at index %d:\n", i);
            printf("Name: %s\n", array[i].name);
            printf("Address: %s\n", array[i].address);
            printf("Phone: %s\n", array[i].phone);
            printf("Hours: %s\n", array[i].hours);
            printf("Sales volume: %.2f\n", array[i].sales_volume);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Element not found!\n");
    }
}

void sort_array(struct Supermarket* array, int size) {
    if (array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    // Insertion sort
    for (int i = 1; i < size; i++) {
        struct Supermarket temp = array[i];
        int j = i - 1;
        while (j >= 0 && strcmp(array[j].name, temp.name) > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void remove_element(struct Supermarket** array, int* size) {
    if (*array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    int index;
    printf("\nEnter the index of the element you want to remove: ");
    scanf("%d", &index);
    if (index < 0 || index >= *size) {
        printf("Error: Invalid index!\n");
        return;
    }

    // Shift elements to the left to overwrite the element to be removed
    for (int i = index; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    *size -= 1;
    *array = (struct Supermarket*)realloc(*array, *size * sizeof(struct Supermarket));
    if (*array == NULL) {
        printf("Error allocating memory!\n");
    }
}

void free_memory(struct Supermarket** array) {
    if (*array == NULL) {
        printf("Error: Memory has not been allocated!\n");
        return;
    }

    free(*array);
    *array = NULL;
}