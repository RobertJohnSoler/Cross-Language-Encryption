package main

import "C"
import (
	"fmt"
	"net"
)

func generateKey() *C.char {
	fmt.Println("Starting connection...")
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		fmt.Println(err)
		return C.CString(err.Error())
	}
	client := NewClient(conn, 128)
	client.keyAgreementClient()
	fmt.Println("Agreed key is ", client.key.String())
	return C.CString(client.key.String())
}

func main() {}
