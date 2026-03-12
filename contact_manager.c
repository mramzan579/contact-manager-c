/*
 * contact_manager.c
 *
 * A console-based Contact Manager written in C.
 * The user can add, view, search, and delete contacts.
 * All contacts are stored in an array of structs.
 *
 * Compile : gcc contact_manager.c -o contact_manager
 * Run     : ./contact_manager
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
/* Groups all information about one contact into a single unit.
   This is the core data structure of the entire program. */
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
   Prevents input bugs when switching between numbers and strings.
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

/* ================================================================
   add_contact()
   Adds a new contact to the contacts array.
   Reads name, phone, and email using fgets().
   strcspn() removes the newline fgets adds at the end.
================================================================ */
void add_contact(void)
{
    if (contact_count >= MAX_CONTACTS) {
        printf("\n  Contact list is full! Cannot add more.\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");

    printf("  Enter name  : ");
    fgets(contacts[contact_count].name, NAME_LEN, stdin);
    contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = '\0';

    printf("  Enter phone : ");
    fgets(contacts[contact_count].phone, PHONE_LEN, stdin);
    contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = '\0';

    printf("  Enter email : ");
    fgets(contacts[contact_count].email, EMAIL_LEN, stdin);
    contacts[contact_count].email[strcspn(contacts[contact_count].email, "\n")] = '\0';

    contact_count++;

    printf("\n  Contact added successfully!\n");
    printf("  Total contacts: %d\n", contact_count);
}

/* ================================================================
   view_contacts()
   Prints all contacts currently stored in the array.
   Shows a message if no contacts have been added yet.
================================================================ */
void view_contacts(void)
{
    int i;

    printf("\n--- All Contacts ---\n");

    if (contact_count == 0) {
        printf("  No contacts found. Add some contacts first.\n");
        return;
    }

    printf("  Total contacts: %d\n", contact_count);

    for (i = 0; i < contact_count; i++) {
        printf("\n  Contact %d:\n", i + 1);
        printf("    Name  : %s\n", contacts[i].name);
        printf("    Phone : %s\n", contacts[i].phone);
        printf("    Email : %s\n", contacts[i].email);
        printf("  ----------------------------------------\n");
    }
}

/* ================================================================
   search_contact()
   Searches for a contact by name using strstr().
   Partial searches work — typing "ram" finds "Muhammad Ramzan".
   Prints all contacts that match the search term.
================================================================ */
void search_contact(void)
{
    char search[NAME_LEN];
    int  i;
    int  found = 0;

    printf("\n--- Search Contact ---\n");

    if (contact_count == 0) {
        printf("  No contacts to search. Add some contacts first.\n");
        return;
    }

    printf("  Enter name to search: ");
    fgets(search, NAME_LEN, stdin);
    search[strcspn(search, "\n")] = '\0';

    for (i = 0; i < contact_count; i++) {
        if (strstr(contacts[i].name, search) != NULL) {
            printf("\n  Match found:\n");
            printf("    Name  : %s\n", contacts[i].name);
            printf("    Phone : %s\n", contacts[i].phone);
            printf("    Email : %s\n", contacts[i].email);
            printf("  ----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("\n  No contact found with that name.\n");
    }
}

/* ================================================================
   delete_contact()
   Deletes a contact by its number in the list.
   First calls view_contacts() so the user can see the numbers.
   After the user picks a number the function uses the shift
   technique to fill the gap:
     — every contact after the deleted one moves one step back
     — contact_count is reduced by one
   This keeps the array compact with no empty holes in the middle.
================================================================ */
void delete_contact(void)
{
    int i;
    int choice;

    /* Show all contacts first so the user knows what to delete */
    view_contacts();

    /* Nothing to delete if list is empty */
    if (contact_count == 0) return;

    printf("\n  Enter contact number to delete: ");
    scanf("%d", &choice);
    clear_input_buffer();

    /* Make sure the number is valid */
    if (choice < 1 || choice > contact_count) {
        printf("\n  Invalid contact number!\n");
        return;
    }

    /* Convert from 1-based display number to 0-based array index */
    choice = choice - 1;

    /*
     * Shift technique:
     * Copy each contact one position backward starting from
     * the deleted position. This overwrites the deleted contact
     * and closes the gap in the array.
     *
     * Example — deleting contact at index 1 (contact 2):
     *   Before: [A] [B] [C] [D]
     *   After:  [A] [C] [D]
     */
    for (i = choice; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    /* Reduce count — the last slot is now a duplicate and ignored */
    contact_count--;

    printf("\n  Contact deleted successfully!\n");
    printf("  Total contacts remaining: %d\n", contact_count);
}

/* ================================================================
   main()
   Entry point. Prints the welcome banner and runs the program
   in a loop until the user selects Exit.
================================================================ */
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
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("\n========================================\n");
                printf("  Goodbye! Thanks for using Contact Manager.\n");
                printf("========================================\n\n");
                break;
            default:
                printf("\n  Invalid choice! Please enter 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}