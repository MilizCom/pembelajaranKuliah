<?php
class Database{
    private $host;
    private $username;
    private $password;
    private $database;
    private $fun;
    
    public function __construct($host, $username, $password, $database){
        $this->host = $host;
        $this->username = $username;
        $this->password = $password;
        $this->database = $database;
        $this->connect();
    }
    private function connect(){
        $this->fun = new mysqli($this->host, $this->username, $this->password, $this->database);
        if ($this->fun){
            echo "Terhubuing connection";
        } else {
            echo "gagal masuk";
        }
    }
    public function getConnection(){
        return $this->fun;
    }
}
$db = new Database("localhost","root","","tb_mahasiswa");
$connection = $db->getConnection();
