import scala.collection.JavaConversions._

object Solution {

  def solution(A: Array[Int]): Int = {
    println(A.mkString(","));
    var sum: Long = 0;
    A.foreach( sum += _);
    var current: Int = 0;
    for (i <- 0 until A.length){
      val right = sum - A(i) - current;
      if ((right - current) == 0){
        return i;
      }
      current += A(i)
    }
    -1
  }

}

object Code extends App{
    println(Solution.solution(Array(-1, 3, -4, 5, 1, -6, 2, 1)));
    println();
    println();
    println(Solution.solution(Array(0, -2147483648, -2147483648)));
    println();
    println();
    println(Solution.solution(Array(1,1,-1)));
    println();
    println();
    println(Solution.solution(Array(0,-1,1)));
    println();
    println();
    println(Solution.solution(Array(-1,0,0)));
    println();
    println();
    println(Solution.solution(Array(0,1,-1)));
}

