#include<stdio.h>
#include<string.h>
#include"resourceFunctions.h"
#define MAX_INPUT_SIZE 100
#define MAX_ENUM_INPUT_SIZE 8
#define bool char
#define string char
#define TRUE 1
#define FALSE 0
enum Resource {
    DEPLOY,
    SERVICE,
    CRONJOB,
    INGRESS,
};
void deployFunction(FILE *target){
    printf("Deploy triggered\n");
}
void serviceFunction(FILE *target){
    printf("Service triggered\n");
}
void cronJobFunction(FILE *target){
    printf("CronJob triggered\n");

}
void ingressFunction(FILE *target){
    printf("Ingress triggered\n");
}