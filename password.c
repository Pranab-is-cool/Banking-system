#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt();
void decrypt();

int main()
{
    int choice, type;
    FILE *fptr, *cptr;

    char pass[50], site[50];

    printf("Welcome to the system:\n");
    printf("If you want to add new password press 1 and if you want to get the password you stored press 2: ");
    scanf("%d", &choice);

    if (choice == 1)
    {   

    cptr = fopen("man.txt", "w");

    fptr = fopen("password.txt", "w+");

        printf("Enter the site name: \n");
        printf(">> ");
        scanf("%s", site);

        printf("Enter the password: \n");
        printf(">> ");
        scanf("%s", pass);

        fprintf(fptr, "SITE : %s \nPASSWORD : %s \n\n", site, pass);
        fclose(fptr);
        fclose(cptr);

        printf("Press 1 to complete the process ");
        scanf("%d", &type);
        printf("The file was encrypted : \n");

        if (type == 1)
        {
            encrypt();
        }
    }
}

void encrypt()
{
    char ch;
    FILE *fptr, *cptr;

    fptr = fopen("password.txt", "r");
    cptr = fopen("man.txt", "w");

    if (fptr == NULL)
    {
        printf("Cannot open");
        exit(0);
    }

    if (cptr == NULL)
    {
        printf("Cannot open");
        exit(1);
    }

    while (1)
    {
        ch = fgetc(fptr);
        if (ch == EOF)
        {
            break;
        }
        else
        {
            ch = ch + 100;
            fputc(ch, cptr);
        }
    }
    fclose(fptr);
    fclose(cptr);

    remove("password.txt");
    rename("man.txt", "password.txt");
    system("touch man.txt");
}

