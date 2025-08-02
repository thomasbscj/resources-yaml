#include<stdio.h>
#include"verifyIsTerminated.h"
#define bool char
#define TRUE 1
#define FALSE 0

void verifyIsTerminated(bool *isTerminated){
        bool validRes = FALSE;
        while(!validRes){
            char anws;
            printf("Do you want to make other yaml file? (y/n): ");
            scanf(" %c", &anws);
            if(anws == 'y'||anws == 'Y'){
                validRes = TRUE;
            }else if(anws == 'n'||anws == 'N'){
                validRes = TRUE;
                *isTerminated = TRUE;
            }else{
                printf("Not valid\n");
            }
        }
}