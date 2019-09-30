package function

fun main(){
    val str1 = "hello "
    val str2 = "world"
    val str3 = "kotlin learners "

    println(str3.add(str1,str2))

    val num1 = 3
    val num2 = 2

    println(num1 greaterThan(num2))
}

fun String.add(str1 : String, str2 :String):String = this+str1+str2

infix fun Int.greaterThan(num2:Int):Int = if(this>num2) this else num2