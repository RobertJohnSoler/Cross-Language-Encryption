#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
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
    
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key_chars, iv);    // initialize the AES cipher
    
    char* plaintxt = "hello";
    int inlen = strlen(plaintxt);
    memcpy(input_buffer, plaintxt, strlen(plaintxt));

    EVP_EncryptUpdate(ctx, output_buffer, &outlen, input_buffer, inlen);
    
    printf("Plaintext is %s \n", input_buffer);
    printf("Ciphertext is %s \n", output_buffer);

    EVP_DecryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key_chars, iv);
    unsigned char decrypted_buffer[AES_BLOCK_SIZE];
    EVP_DecryptUpdate(ctx, decrypted_buffer, &outlen, output_buffer, inlen);
    printf("Plaintext is %s \n", decrypted_buffer);

    return 0;
}
