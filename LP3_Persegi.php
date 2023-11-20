<?php
class LuasPersegi {
    // Variabel panjang dan lebar persegi panjang
    private $panjang;
    private $lebar;

    // Constructor untuk menginisialisasi panjang dan lebar
    public function __construct($panjang, $lebar) {
        $this->panjang = $panjang;
        $this->lebar = $lebar;
    }   

    // Method untuk menghitung luas persegi panjang
    public function hitungLuas() {
        return $this->panjang * $this->lebar;
    }
}

// Membuat objek LuasPersegi
$persegi = new LuasPersegi(5.0, 3.0);

// Memanggil method hitungLuas
$luas = $persegi->hitungLuas();

// Menampilkan hasil perhitungan
echo "Luas Persegi Panjang: $luas";
?>
