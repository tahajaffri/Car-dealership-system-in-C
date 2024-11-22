#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

struct details {
    char make[100];
    char model[100];
    int year;
    double price;
    float mileage;
} cars[MAX_CARS];

void getDetails(struct details *car);
void printDetails(const struct details *car, int index);
void searchByMake(struct details *cars, int count, const char *make);
void searchByModel(struct details *cars, int count, const char *model);

int main() {
    int choice, count = 0 ,i ;
    char input[100];

    printf("--------------------- Welcome to Car Dealership! ---------------------\n");

    do {
        printf("\n1. Add a car\n");
        printf("2. Display available cars\n");
        printf("3. Search cars by make\n");
        printf("4. Search cars by model\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        system("cls");

        switch (choice) {
            case 1:
                if (count < MAX_CARS) {
                    printf("\nEnter details of the car:\n");
                    getDetails(&cars[count]);
                    printf("\nCar %d added Successfully!\n",count+1);
                    count++;
                } else {
                    printf("\nOops! Maximum car addition limit reached!\n");
                }
                    system("cls");
                break;
            case 2:
                if (count == 0) {
                    printf("\nNo cars available to display.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printDetails(&cars[i], i);
                        }

                getchar();
                system("cls");
                }
                break;
            case 3:
                printf("\nEnter car make to search: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                searchByMake(cars, count, input);
                getchar();
                system("cls");
                break;
            case 4:
                printf("\nEnter car model to search: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                searchByModel(cars, count, input);
                break;
            case 5:
                system("cls");
                printf("\nThank you for using Car Dealership!\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void getDetails(struct details *car) {
    printf("Enter make: ");
    scanf("%s", car->make);
    printf("Enter model: ");
    scanf("%s", car->model);
    printf("Enter year: ");
    scanf("%d", &car->year);
    printf("Enter price: ");
    scanf("%lf", &car->price);
    printf("Enter mileage: ");
    scanf("%f", &car->mileage);
}

void printDetails(const struct details *car, int index) {
    printf("--------------------- Car %d ---------------------\n", index + 1);
    printf("Make: %s\n", car->make);
    printf("Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
    printf("Price: %.2lf\n", car->price);
    printf("Mileage: %.2f\n", car->mileage);
}

void searchByMake(struct details *cars, int count, const char *make) {
    int found = 0,i;
    for (i = 0; i < count; i++) {
        if (strcasecmp(cars[i].make, make) == 0) {
            printDetails(&cars[i], i);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo cars found with make '%s'.\n", make);
    }
}

void searchByModel(struct details *cars, int count, const char *model) {
    int found = 0,i;
    for (i = 0; i < count; i++) {
        if (strcasecmp(cars[i].model, model) == 0) {
            printDetails(&cars[i], i);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo cars found with model '%s'.\n", model);
    }
}
