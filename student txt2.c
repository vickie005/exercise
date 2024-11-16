//program to read name and marks of n students

	#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char name[50];
    int marks;
    int i;
    FILE *fptr;

    // Open file in write mode
    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read name and marks of 5 students
    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);

        // Write name and marks to file
        fprintf(fptr, "Name: %s, Marks: %d\n", name, marks);
    }
     printf("Data successfully written to students.txt\n");
    // Close the file
    fclose(fptr);

    //Return 0 to indicate successful completion of the program

    return 0;
}


	