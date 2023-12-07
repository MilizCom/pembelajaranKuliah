<?php
include_once('../Univ/gas.php');

    $orang1 = new univ("Saintek","uin"," TI",10);
    $orang2 = new univ("Saintek","uin","SI",19);
    $orang3 = new univ("Saintek","NTI","MTK",4);
    $orang4 = new univ("Saintek","UNIPAT","TArbia",6);
    $orang5 = new univ("Saintek","UNM","arsy",1);
    $orang6 = new univ("Saintek","UNHAS","mesin",78);

    $orang1->infouniv();
    $orang2->infouniv();
    $orang3->infouniv();
    $orang4->infouniv();
    $orang5->infouniv();
    $orang6->infouniv();


?>