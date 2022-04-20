package main

/*
#include "load_so.h"
#cgo LDFLAGS: -ldl
*/
import "C"
import "fmt"

func test1() {
	fmt.Println("20*30=", C.do_test_so_func(20, 30))
}
