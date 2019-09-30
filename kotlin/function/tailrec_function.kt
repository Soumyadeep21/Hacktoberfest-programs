package function

import java.math.BigInteger

fun main() = println(fibonacci(10000, BigInteger("1"),BigInteger("0")))

tailrec fun fibonacci(n:Int, a: BigInteger,b:BigInteger):BigInteger = if(n==0) b else fibonacci(n-1,a+b,a)