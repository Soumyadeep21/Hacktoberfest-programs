package function

fun main(){

    val scanner = Scanner(System.`in`)
    println("Enter a number: ")
    val a = scanner.nextInt()
    println("Enter another number: ")
    val b = scanner.nextInt()
    val greaterValue = a greaterValue b
    println(greaterValue)
}

infix fun Int.greaterValue(other:Int): Int = if(this>other) this else other