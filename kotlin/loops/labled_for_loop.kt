package loops

fun main(){

    outerLoop@ for(i in 1..3)
        for(j in 1..3)
            if(i == 2 && j == 2){
                continue@outerLoop
            }else{
                println("$i $j")
            }
}