/*
 * contact_manager.c
 * Contact Manager — Commit 1
 * Set up the project structure, define the Contact struct,
 * and build the main menu system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//─ Constants 
#define MAX_CONTACTS  50    // maximum number of contacts allowed in the system
#define NAME_LEN      50   // maximum length of a contact's name
#define PHONE_LEN     20    // maximum length of a phone number
#define EMAIL_LEN     50    // maximum length of an email address

//Contact struct
/* Groups all information about one contact into a single unit.
   This is the core data structure of the entire program. */
struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
};

// Global contact list 
struct Contact contacts[MAX_CONTACTS];  /* holds all contacts    */
int contact_count = 0;                  /* how many are stored   */

/* ================================================================
   clear_input_buffer()
   Drains leftover characters from stdin after every scanf.
   Prevents input bugs when switching between reading numbers
   and strings.
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
   Called at the start of every loop in main().
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

// Main function — entry point of the program
int main(void)
{
    int choice;

    /* Welcome banner */
    printf("========================================\n");
    printf("      WELCOME TO CONTACT MANAGER        \n");
    printf("========================================\n");
    printf("  Store and manage your contacts easily.\n");
    printf("  Maximum contacts: %d\n", MAX_CONTACTS);

    /* Main loop — keeps running until user picks Exit */
    do {
        show_menu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                printf("\n  [Coming soon] Add Contact\n");
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