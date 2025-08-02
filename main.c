#include<stdio.h>
#include<string.h>
#include<fstab.h>
#include"resourceFunctions.h"
#include"verifyIsTerminated.h"
#define MAX_INPUT_SIZE 500
#define MAX_ENUM_INPUT_SIZE 8
#define bool char
#define string char
#define TRUE 1
#define FALSE 0
#define strbool char
#define STREQUAL 1
#define STRDIF 2

enum Resource {
    DEPLOY,
    SERVICE,
    CRONJOB,
    INGRESS,
};

int main(int argc, char **argv){
    if(argc == 1){
        printf("\n----- Kubernetes resources .yaml creation app -----\n\nError: no arguments provided.\n\nMust pass 1 argument: path to make file\n");
        return -1;
    }
    string filePath[MAX_INPUT_SIZE];
    strcpy(filePath, argv[1]);
    FILE *targetFile = fopen(filePath, "w");
    bool isTerminated = FALSE;
    while(isTerminated != FALSE){
        printf("\nFow which resource do you want to create a .yaml?: ");
        string resource_type[MAX_ENUM_INPUT_SIZE];
        scanf(" %s", &resource_type);
        if(strcmp(resource_type, "deploy") == STREQUAL){
            deployFunction(targetFile);
        }else if(strcmp(resource_type, "service") == STREQUAL){
            serviceFunction(targetFile);
        }else if(strcmp(resource_type, "cronjob") == STREQUAL){
            cronJobFunction(targetFile);
        }else if(strcmp(resource_type, "ingress") == STREQUAL){
            ingressFunction(targetFile);
        }else{
            printf("\n Invalid resource. Available resources are: deploy, service, cronjob, ingress\n");
        }

        verifyIsTerminated(&isTerminated);
    }
return 0;

}