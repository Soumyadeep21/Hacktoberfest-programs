fun main(){
    val myList = listOf(2,3,5,10,20)
    val smallNumber=myList.filter{it>3}.map { it+it*it/10 }
    for(i in smallNumber){
        println(i)
    }
}