<?php

class Buku {
  
    public $judul;
    public $penulis;
    public $tahunTerbit;
}


$buku1 = new Buku();
$buku1->judul = "Judul Buku 1";
$buku1->penulis = "Penulis 1";
$buku1->tahunTerbit = 2020;

$buku2 = new Buku();
$buku2->judul = "Judul Buku 2";
$buku2->penulis = "Penulis 2";
$buku2->tahunTerbit = 2021;

echo "Informasi Buku 1:<br>";
echo "Judul: " . $buku1->judul . "<br>";
echo "Penulis: " . $buku1->penulis . "<br>";
echo "Tahun Terbit: " . $buku1->tahunTerbit . "<br>";
echo "<br>";

echo "Informasi Buku 2:<br>";
echo "Judul: " . $buku2->judul . "<br>";
echo "Penulis: " . $buku2->penulis . "<br>";
echo "Tahun Terbit: " . $buku2->tahunTerbit . "<br>";
echo "<br>";
?>
