package main

import "fmt"

func main() {
   var num int
   fmt.Printf("Digite un numero entero : ")
   fmt.Scanf("%d\n",&num)
   
    if num < 0 {
        fmt.Print(num, " es negativo")
    } else {
        fmt.Print(num, " es postivo")
    } 
}