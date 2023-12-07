<?php

class calculator{
    public function calcculateArea(){
        return 0;
    }
}

class Penjumlahan extends calculator{
    private $nilai1;
    private $nilai2;

    public function __construct($nilai1, $nilai2){
        $this->nilai1 = $nilai1;
        $this->nilai2 = $nilai2;
    }

    public function calculateArea(){
        return $this->nilai1 + $this->nilai2;
    }
}

class Perkalian extends calculator{
    private $nilai1;
    private $nilai2;
    public function __construct($nilai1, $nilai2){
        $this->nilai1 = $nilai1;
        $this->nilai2 = $nilai2;
    }  

    public function calculateArea(){
        return $this->nilai1 * $this->nilai2;
    }
}

class Pengurangan extends calculator{
    private $nilai1;
    private $nilai2;
    public function __construct($nilai1, $nilai2){
        $this->nilai1 = $nilai1;
        $this->nilai2 = $nilai2;
    }

    public function calculateArea(){
        return $this->nilai1 - $this->nilai2;
    }
}

class Pembagian extends calculator{
    private $nilai1;
    private $nilai2;
    public function __construct($nilai1, $nilai2){
        $this->nilai1 = $nilai1;
        $this->nilai2 = $nilai2;
    }

    public function calculateArea(){
        return $this->nilai1 / $this->nilai2;
    }
}

//contoh penggunaan

$jumlah = new Penjumlahan(10, 9);
$kali = new Perkalian(10,11);
$kurang = new Pengurangan(10,1);
$bagi = new Pembagian(10,4);

echo "Ini adalah penjumlahan: " . $jumlah->calculateArea() . "<br>";
echo "Ini adalah perkalian: " . $kali->calculateArea() . "<br>";
echo "Ini adalah pengurangan: " . $kurang->calculateArea() . "<br>";
echo "Ini adalah pembagian: " . $bagi->calculateArea() . "<br>";

class mathOperation{
    public function add($a,$b){
        return $a + $b;
    }
}
class advanceMathOperation extends mathOperation{
    public function add($a,$b){
        return 2*parent::add($a , $b);
    }
}
$basicMath=new mathOperation();
echo"Basic Math operation : ".
$basicMath->add(2,6) . "<br> ";

$advanceMath = new advanceMathOperation();
echo"Advance Math operation : ".
$advanceMath->add(5,7) . "<br>"
?>