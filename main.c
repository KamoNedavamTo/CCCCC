#include <stdio.h>
#include <string.h>



struct Contact {
    char name[10];
    char phone[13];
};

struct Contact contacts[100];
int numContacts = 0;


void displayContacts();
void searchContact();


int main() {
    strcpy(contacts[numContacts].name, "Jakub Honza ");
    strcpy(contacts[numContacts].phone, "+420875935568 ");
    numContacts++;

    strcpy(contacts[numContacts].name, "Petr Onen ");
    strcpy(contacts[numContacts].phone, "+420785564987 ");
    numContacts++;


    int choice;
    do {
        printf("\nTelefonon seznam\n");
        printf("1. Kontakty\n");
        printf("2. Vyhledej podle 1. pismena\n");
        printf("3. Konec\n");
        printf("Tvoje volba: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayContacts();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printf("Bye bye\n");
                return 0;
            default:
                printf("Spatna volba blbe\n");
        }
    } while (choice != 3);

    return 0;

}


void displayContacts() {
    if (numContacts == 0) {
        printf("Mas prazdny seznam\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s\n Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}


void searchContact() {
    char searchLetter;
    printf("Zadej 1. pismena jmena: ");
    scanf(" %c", &searchLetter);

    printf("Kontakty zacinaji s '%c':\n", searchLetter);
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name[0] == searchLetter) {
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Takove kontakty neexistuji\n");
    }
}
