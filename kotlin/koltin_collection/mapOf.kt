fun main(){
    val myMap = mapOf<Any,String>(1 to "Kotlin",2 to "Programming Language")
    for(i in myMap.entries){
        println(i)
    }
}