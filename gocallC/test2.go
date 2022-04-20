package main

/*
#include "test_so.h"
#cgo LDFLAGS: test_so.so
*/
import "C"
import "fmt"

func test2() {
	fmt.Println("20*30=", C.test_so_func(20, 30))
}
