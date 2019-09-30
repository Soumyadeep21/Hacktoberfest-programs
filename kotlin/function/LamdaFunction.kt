package function

import java.util.*

fun main(){

    val add = {i : Int , j : Int -> i + j}
    val sub = {i:Int,j:Int -> i - j}

    val reader = Scanner(System.`in`)

    println("num1: ")
    val num1 = reader.nextInt()
    println("num1: ")
    val num2 = reader.nextInt()
    println("choice: ")
    val choice = reader.nextInt()

    val result = when(choice){
        1 -> add(num1,num2)
        2 -> sub(num1,num2)
        else -> 0
    }

    println("result = $result")
}
