fun main() {
    val myMap = hashMapOf<Int, String>()
    myMap.put(1, "B")
    myMap.put(3, "T")
    myMap.replace(3, "B")
    myMap.remove(3)
    for (i in myMap.entries) {
        println(i)
    }
}