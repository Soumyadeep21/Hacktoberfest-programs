fun main(){
    val myList = listOf(2,3,4,10,23,24)
//    val myPredicate = {num:Int -> num>10}
    val check1 = myList.all { it>20 }
//    val check2 = myList.any(myPredicate)
//    val check3 = myList.count(myPredicate)
    val check4 = myList.find { it>2 }
    println(check1)
//    println(check2)
//    println(check3)
    println(check4)
}