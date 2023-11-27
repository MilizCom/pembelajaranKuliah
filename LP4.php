<?php

class Bentuk {
    protected $warna;

    public function __construct($warna) {
        $this->warna = $warna;
    }

    public function hitungLuas() {
        // Metode ini akan diimplementasikan oleh kelas turunan
    }
}

class Persegi extends Bentuk {
    protected $sisi;

    public function __construct($sisi, $warna) {
        parent::__construct($warna);
        $this->sisi = $sisi;
    }

    public function hitungLuas() {
        $luas = $this->sisi ** 2;
        return $luas;
    }
}

class Lingkaran extends Bentuk {
    protected $radius;

    public function __construct($radius, $warna) {
        parent::__construct($warna);
        $this->radius = $radius;
    }

    public function hitungLuas() {
        $luas = 3.14 * $this->radius ** 2;
        return $luas;
    }
}

// Contoh penggunaan
$persegi_merah = new Persegi(5, 'merah');
$lingkaran_biru = new Lingkaran(3, 'biru');

echo "Luas persegi berwarna " . $persegi_merah->hitungLuas() . "\n";
echo "Luas lingkaran berwarna " . $lingkaran_biru->hitungLuas() . "\n";

?>
