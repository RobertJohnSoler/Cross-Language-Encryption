#include <stdio.h>
#include "client_keygen.h"

int main(){
    char* key = generateKey();
    printf("%s \n", key);
    return 0;
}