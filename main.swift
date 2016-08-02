import Cocoa
/* My first program in Swift */
func input() -> NSString {
    var keyboard = NSFileHandle.fileHandleWithStandardInput()
    var inputData = keyboard.availableData
    return NSString(data: inputData, encoding:NSUTF8StringEncoding)!
}
println("digite primer numero")
var cadena1 = input()

println("digite segundo numero")
var cadena2 = input()

var num1 = cadena1.integerValue
var num2 = cadena2.integerValue

var resultado = num1 * num2

print("La multiplicacion de los dos numeros es: \(resultado)")