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
#define STREQUAL(s1, s2) (strcmp((s1), (s2)) == 0)

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
    while(!isTerminated){
        printf("\nFow which kubernetes resource do you want to create a .yaml?: ");
        string resource_type[MAX_ENUM_INPUT_SIZE];
        scanf(" %s", &resource_type);
        if(STREQUAL(resource_type, "deploy")||STREQUAL(resource_type, "Deploy")){
            deployFunction(targetFile);
        }else if(STREQUAL(resource_type, "service")||STREQUAL(resource_type, "Service")){
            serviceFunction(targetFile);
        }else if(STREQUAL(resource_type, "cronjob")||STREQUAL(resource_type, "cronJob")||STREQUAL(resource_type, "CronJob")||STREQUAL(resource_type, "Cronjob")){
            cronJobFunction(targetFile);
        }else if(STREQUAL(resource_type, "ingress")||STREQUAL(resource_type, "Ingress")){
            ingressFunction(targetFile);
        }else{
            printf("\n Invalid resource. Available resources are: deploy, service, cronjob, ingress\n");
            return 1;
        }

        verifyIsTerminated(&isTerminated);
    }
printf("Thx for using kymlgen :)\n");
return 0;

}