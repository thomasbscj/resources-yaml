#include<stdio.h>

#ifndef RESOURCE_FUNCTIONS_H

#define RESOURCE_FUNCTIONS_H

enum Resource {
    DEPLOY,
    SERVICE,
    CRONJOB,
    INGRESS,
};

void deployFunction(FILE *target);
void serviceFunction(FILE *target);   
void cronJobFunction(FILE *target);
void ingressFunction(FILE *target);

#endif