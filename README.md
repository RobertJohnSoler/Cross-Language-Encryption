# Cross-Language-Encryption
This Repo serves as a testing site for encrypting data being sent between two application written in different languages.

### Important Commands:
To buld the .dll and .h file from the golang code, run this command on the root folder:
`go build -o client_keygen.dll -buildmode=c-shared DH_client/DH_client.go DH_client/client_keygen_dll.go`
To compile the C code to use the above .dll file, use this command:
`g++ client.c client_keygen.dll -o client.exe`
Make sure the .dll, .h, and .c files are in the same directory!
