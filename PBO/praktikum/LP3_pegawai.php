<?php
class Pegawai {
    // Variabel nama dan gaji pokok karyawan
    private $nama;
    private $gajiPokok;

    // Constructor untuk menginisialisasi nama dan gaji pokok
    public function __construct($nama, $gajiPokok) {
        $this->nama = $nama;
        $this->gajiPokok = $gajiPokok;
    }

    // Metode untuk mendapatkan nama karyawan
    public function getNama() {
        return $this->nama;
    }

    // Metode untuk mendapatkan gaji pokok karyawan
    public function getGajiPokok() {
        return $this->gajiPokok;
    }
}

// Membuat objek Pegawai
$karyawan = new Pegawai("John Doe", 5000.0);

// Menampilkan informasi karyawan
echo "Nama Karyawan: " . $karyawan->getNama() . "\n";
echo "Gaji Pokok: " . $karyawan->getGajiPokok() . "\n";
?>
