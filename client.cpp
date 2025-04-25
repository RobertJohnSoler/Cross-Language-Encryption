#include <stdio.h>
#include <openssl/evp.h>
#include "client_keygen.h"

#define AES_BLOCK_SIZE 16

int main(){

    char *key = generateKey();
    printf("Shared key is %s. \n", key);

    unsigned char input_buffer[AES_BLOCK_SIZE];
    unsigned char output_buffer[AES_BLOCK_SIZE];
    unsigned char *key_chars = (unsigned char* ) key;     // AES encryption key
    unsigned char iv[] = "some random IV value";            // AES initialization value
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();             // create the AES cipher
    int outlen;
    int inlen = sizeof(char);
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key_chars, iv);    // initialize the AES cipher
    EVP_EncryptUpdate(ctx, output_buffer, &outlen, input_buffer, inlen);
    return 0;
}
