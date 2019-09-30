package function

fun main(){
    add(2,4)
    println(add1(4,6))
    println(add2(6,7))
}

// void function
fun add(a:Int, b:Int){
    val c = a+b
    println("$c")
}

// return type function
fun add1(a:Int, b:Int):Int{
    return a+b
}

// optimized version

fun add2(a:Int, b:Int):Int = a+b