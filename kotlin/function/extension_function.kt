package function

fun main(){

    val student = Student()
    println(student.hasPassed(57))
    println(student.getScholarship(67))
}

fun Student.getScholarship(marks:Int) : Boolean = marks > 60

class Student{
    fun hasPassed(marks : Int) : Boolean = marks > 40
}