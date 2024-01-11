<?php

interface Mie {
    public function getName();
    public function getCookingInstructions();
}

abstract class AbstractMie implements Mie {
    protected $namamie;
    public function __construct($namamie) {
        $this->namamie = $namamie;
    }

    public function getName() {
        return $this->namamie;
    }

    abstract public function getCookingInstructions();
}

class MieGoreng extends AbstractMie {
    public function __construct() {
        parent::__construct('Mie Goreng');
    }

    public function getCookingInstructions() {
        return "1. Rebus mie dalam air mendidih selama 3-5 menit.\n2. Goreng mie dengan bumbu dan tambahan lainnya.";
    }
}

class MieKuah extends AbstractMie {
    public function __construct() {
        parent::__construct('Mie Kuah');
    }

    public function getCookingInstructions() {
        return "1. Rebus mie dalam kaldu hingga matang.\n2. Sajikan mie dalam mangkuk dengan kuah dan tambahan seperti sayuran.";
    }
}

$mieGoreng = new MieGoreng();
$mieKuah = new MieKuah();

echo "Jenis Mie: " . $mieGoreng->getName() . "\n";
echo "Cara Memasak:\n" . $mieGoreng->getCookingInstructions() . "\n\n";

echo "Jenis Mie: " . $mieKuah->getName() . "\n";
echo "Cara Memasak:\n" . $mieKuah->getCookingInstructions() . "\n";
?>
