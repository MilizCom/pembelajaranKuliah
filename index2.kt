import java.text.ParseException
import java.text.SimpleDateFormat
import java.util.Date
import java.util.TimeZone
import java.util.concurrent.TimeUnit


open class Person{
    
   public var nama  ="samil"
   private var umur = 19
   protected var nim = 9876543
   internal var kelas = 'D'
}
class manusia: Person(){
    fun printer(){
        println(kelas);
    }
}
fun main(){
    var ali = manusia()
    ali.printer()
}