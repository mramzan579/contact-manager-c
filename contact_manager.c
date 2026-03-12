/*
 * contact_manager.c
 * Contact Manager in C
 * Add the view_contacts() function so the user can
 * see all stored contacts in a clean formatted list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Constants ──────────────────────────────────────────────── */
#define MAX_CONTACTS  50
#define NAME_LEN      50
#define PHONE_LEN     20
#define EMAIL_LEN     50

/* ── Contact struct ─────────────────────────────────────────── */
struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
};

/* ── Global contact list ────────────────────────────────────── */
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
   Reads name, phone, and email using fgets().
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
   Each contact is displayed with its number, name, phone,
   and email in a clean readable format.
   Shows a message if no contacts have been added yet.
================================================================ */
void view_contacts(void)
{
    int i;

    printf("\n--- All Contacts ---\n");

    /* Check if the list is empty */
    if (contact_count == 0) {
        printf("  No contacts found. Add some contacts first.\n");
        return;
    }

    printf("  Total contacts: %d\n", contact_count);

    /* Loop through every stored contact and print its details */
    for (i = 0; i < contact_count; i++) {
        printf("\n  Contact %d:\n", i + 1);
        printf("    Name  : %s\n", contacts[i].name);
        printf("    Phone : %s\n", contacts[i].phone);
        printf("    Email : %s\n", contacts[i].email);
        printf("  ----------------------------------------\n");
    }
}

/* ── Main */
int main(void)
{
    int choice;

    /* Welcome banner */
    printf("========================================\n");
    printf("      WELCOME TO CONTACT MANAGER        \n");
    printf("========================================\n");
    printf("  Store and manage your contacts easily.\n");
    printf("  Maximum contacts: %d\n", MAX_CONTACTS);

    /* Main loop */
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