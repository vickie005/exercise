//program on members of an array in c structures

#include <stdio.h>
#include <stdlib.h>

#define NUM_PERSONS 3

// Define the structure for a Person
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

void writeToFile(Person persons[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(persons, sizeof(Person), count, file);
    fclose(file);
}

void readFromFile(Person persons[], int count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fread(persons, sizeof(Person), count, file);
    fclose(file);
}

void displayPersons(Person persons[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", persons[i].id);
        printf("Name: %s\n", persons[i].name);
        printf("Age: %d\n\n", persons[i].age);
    }
}

int main() {
    // Array of persons to write to the file
    Person persons[NUM_PERSONS] = {
        {1, "Alice", 30},
        {2, "Bob", 25},
        {3, "Charlie", 35}
    };

    const char *filename = "persons.dat";

    // Write array to file
    writeToFile(persons, NUM_PERSONS, filename);

    // Clear array data to demonstrate reading from file
    Person personsFromFile[NUM_PERSONS] = {0};

    // Read array from file
    readFromFile(personsFromFile, NUM_PERSONS, filename);

    // Display persons read from the file
    printf("Data read from file:\n");
    displayPersons(personsFromFile, NUM_PERSONS);

    return 0;
}
