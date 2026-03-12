/*
 * contact_manager.c
 * Contact Manager — A simple C program to manage a list of contacts.
 * Add the add_contact() function so the user can
 * store a new contact with name, phone, and email.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_CONTACTS  50
#define NAME_LEN      50
#define PHONE_LEN     20
#define EMAIL_LEN     50

//Contact struct
struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
};

//Global contact list
struct Contact contacts[MAX_CONTACTS];
int contact_count = 0;

/* ================================================================
   clear_input_buffer()
   Drains leftover characters from stdin after every scanf.
================================================================ */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* ================================================================
   show_menu()
   Prints the main menu options to the console.
================================================================ */
void show_menu(void)
{
    printf("\n========================================\n");
    printf("          CONTACT MANAGER               \n");
    printf("========================================\n");
    printf("  1. Add Contact\n");
    printf("  2. View All Contacts\n");
    printf("  3. Search Contact by Name\n");
    printf("  4. Delete Contact\n");
    printf("  5. Exit\n");
    printf("========================================\n");
    printf("  Enter your choice: ");
}

/* ================================================================
   add_contact()
   Adds a new contact to the contacts array.
   Asks the user for name, phone, and email one by one.
   Uses fgets() to read full strings including spaces.
   strcspn() removes the newline character fgets adds.
   Checks if the contact list is full before adding.
================================================================ */
void add_contact(void)
{
    /* Stop if we have reached the maximum limit */
    if (contact_count >= MAX_CONTACTS) {
        printf("\n  Contact list is full! Cannot add more.\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");

    /* Read name — fgets reads the full line including spaces */
    printf("  Enter name  : ");
    fgets(contacts[contact_count].name, NAME_LEN, stdin);
    /* strcspn finds the position of '\n' and replaces it with '\0' */
    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = '\0';

    // Read phone number 
    printf("  Enter phone : ");
    fgets(contacts[contact_count].phone, PHONE_LEN, stdin);
    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = '\0';

    // Read email address
    printf("  Enter email : ");
    fgets(contacts[contact_count].email, EMAIL_LEN, stdin);
    contacts[contact_count].email[strcspn(contacts[contact_count].email, "\n")] = '\0';

    /* Increment counter — contact is now officially saved */
    contact_count++;

    printf("\n  Contact added successfully!\n");
    printf("  Total contacts: %d\n", contact_count);
}

// Main
int main(void)
{
    int choice;

    /* Welcome banner */
    printf("========================================\n");
    printf("      WELCOME TO CONTACT MANAGER        \n");
    printf("========================================\n");
    printf("  Store and manage your contacts easily.\n");
    printf("  Maximum contacts: %d\n", MAX_CONTACTS);

    // Main loop 
    do {
        show_menu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                printf("\n  [Coming soon] View All Contacts\n");
                break;
            case 3:
                printf("\n  [Coming soon] Search Contact\n");
                break;
            case 4:
                printf("\n  [Coming soon] Delete Contact\n");
                break;
            case 5:
                printf("\n  Goodbye!\n");
                break;
            default:
                printf("\n  Invalid choice! Please enter 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}