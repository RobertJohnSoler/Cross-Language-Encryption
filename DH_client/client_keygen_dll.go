package main

import "C"
import (
	"fmt"
	"net"
)

// IMPORTANT!!! The //export comment is required for CGo to know which function is being imported by C.
// NOTE: C.char means C char, or a char that is readable by C.

//export generateKey
func generateKey() *C.char {
	fmt.Println("Starting connection...")
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		fmt.Println(err)
		return C.CString(err.Error())
	}
	client := NewClient(conn, 128)
	client.keyAgreementClient()
	return C.CString(client.key.String())
}

func main() {}
