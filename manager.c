#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr,*cptr;

    fptr = fopen("password.txt","r");
    cptr = fopen("man.txt","w");
    char ch;

    printf("The file was decrypted : \n");

    if(fptr == NULL){
        printf("Cannot open");
    }

    if(cptr==NULL){
        printf("Cannot open");
    }

    while(1){
        ch = fgetc(fptr);
        if(ch == EOF){
            break;
        }
        else{
            ch = ch - 100;
            fputc(ch,cptr);
        }
    }

    while(1){
        ch = fgetc(cptr);
        if(ch == EOF){
            break;
        }
        else{
            printf("%c",ch);
        }
    }

}