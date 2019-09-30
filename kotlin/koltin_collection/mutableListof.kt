fun main(){
    val myList = mutableListOf(2,3,4)
    myList.add(0,12)
    myList.add(1,14)
    myList.add(41)
    myList.add(1,233)
    for(i in myList){
        println(i)
    }
}