#include <stdio.h>
#include "client_keygen.h"

int main(){
    char* key = generateKey();
    printf("Shared key is %s. \n", key);
    return 0;
}

// need to account for cpp go file