#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int bookID;
    char title[50];
    char author[50];
    int year;
};

struct Book library[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter book ID: ");
        scanf("%d", &newBook.bookID);
        printf("Enter title: ");
        scanf("%s", newBook.title);
        printf("Enter author: ");
        scanf("%s", newBook.author);
        printf("Enter publication year: ");
        scanf("%d", &newBook.year);

        library[numBooks] = newBook;
        numBooks++;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full.\n");
    }
}

void removeBook() {
    int bookID, found = 0;
    printf("Enter book ID to remove: ");
    scanf("%d", &bookID);

    for (int i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            for (int j = i; j < numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            numBooks--;
            found = 1;
            printf("Book removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void displayBooks() {
    if (numBooks == 0) {
        printf("No books in the library.\n");
    } else {
        printf("****** Book Details ******\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Book ID: %d\n", library[i].bookID);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Publication Year: %d\n", library[i].year);
            printf("---------------------------\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("**********************************************\n");
        printf("*          Library Management System         *\n");
        printf("**********************************************\n");
        printf("* 1. Add Book                               *\n");
        printf("* 2. Remove Book                            *\n");
        printf("* 3. Display All Books                      *\n");
        printf("* 4. Exit                                   *\n");
        printf("**********************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            displayBooks();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
