<?php
    class kora2 {
        public $ketinggian;
        public function cekmasuk(){
            if ($this->ketinggian < 170){
                echo "anda tidak bisa masuk";
            }
            else{
                echo "silahkan masuk";
            }
        }
    } 

    $penumpang1 = new kora2();
    $penumpang1->ketinggian = 100;
    $penumpang1->cekmasuk();
?>