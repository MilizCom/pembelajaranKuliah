<?php
class univ{
    public $fak;
    public $univ;
    public $jur;
    public $jumlah_mahasiswa;
    
    public function __construct($fak, $univ, $jur, $jumlah_mahasiswa){
        $this->fak = $fak;
        $this->univ = $univ;
        $this->jur = $jur;
        $this->jumlah_mahasiswa = $jumlah_mahasiswa;
    }
    public function infouniv(){
        echo "<table><tr>";
        echo "fakultas: ".$this->fak."<br>universitas: ".$this->univ."<br>jur: ".$this->jur."<br>jumlah mahasiswa: " .$this->jumlah_mahasiswa."<br><br>";
        echo "</tr></table>";
    }
}
  
