<?php
interface action{
    public function attack();
    public function skill() ;
    public function heal();
    public function hit($damage);
}
class objek implements action{
    var int $health ;
    var int $energy ;
    var int $power ;
    public function __construct($health, $energy, $power) {
        $this->health = $health;
        $this->energy = $energy;
        $this->power = $power;
    }
    public function attack(){
        $this->energy++;
        return $this->power;
    }
    public function skill() {
        return $this->calculateSkill(2); 
    }
    public function heal(){
        if ($this->energy>=1){
            $this->health += 20;
            $this->energy--;
        }else{
            print("no energy");
        }
    }
    private function calculateSkill($multiplier) {
        if ($this->energy >= 1) {
            $result = $this->power * $multiplier;
            $this->energy--;
            return $result;
        } else if ($this->energy<=0) {
            print("\nno energy");
            return 0;
        }
    }
    public function hit($damage){
        $this->health -= $damage;
        if ($this->health < 0) {
            $this->health = 0;
        }
    }
}
print("Welcome to game\n
            press enter to continue!\n\n");
trim(fgets(STDIN));
    
$enemy = new objek(100,3,10);
$player = new objek(100,3,10);

function suit($pilihan1, $pilihan2) {
    // Mengecek hasil suit
    if ($pilihan1 == $pilihan2) {
        return "Hasil: Seri!";
        
    } elseif (($pilihan1 == 'batu' && $pilihan2 == 'gunting') || 
              ($pilihan1 == 'gunting' && $pilihan2 == 'kertas') || 
              ($pilihan1 == 'kertas' && $pilihan2 == 'batu')) {
        return "win";
    
    } else {
        return "Hasil: Pemain 2 Menang!";
    }
}
function random() {
    $pilihan = ['batu', 'kertas', 'gunting'];
        $j = mt_rand(0, 2);
    return $pilihan[$j];
}
ulang:
print("healt: {$player->health}\n");
print("energy: {$player->energy}\n");
print("enemy_healt: {$enemy->health}\n");
$suit;
    
$pilihan = ['batu', 'kertas', 'gunting'];
print("masukkan pilihan anda\n0.batu\n1.kertas\n2.gunting\n");
$suit = trim(fgets(STDIN));
if ($suit!=0&&$suit!=1&&$suit!=2){
    goto ulang;
}

if(suit($pilihan[$suit],random())=="win"){
    print("anda menang!\n");
    print("pilih aksi \n1.basic_attack\n2.skill attack\n3.heal");
    $pilian = trim(fgets(STDIN));
    if($pilian==1){
        $enemy->hit($player->attack());
    }else if ($pilian==2){
        $enemy->hit($player->skill());
    }else if ($pilian==3){
        $player->heal();
    }
    else{
        goto ulang;
    }
}else{
    print ("anda kalah\n");
    $player->hit($enemy->attack());
}
if($enemy->health<=0){
    print("\nSELAMAT ANDA MENANG\n");
    return 0;
} else if($player->health<=0){
    print("\nGAME OVER\n");
    return 0;
}
goto ulang;
