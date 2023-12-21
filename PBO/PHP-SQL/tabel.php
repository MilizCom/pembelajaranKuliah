<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <table border="1">
        <thead>
            <tr>
                <th>No</th>
                <th>Nim</th>
                <th>Nama</th>
                <th>jurusan</th>
                <th>Jenis Kelamin</th>
                <th>Alamat</th>
                <th>Ket</th>
            </tr>
        </thead>
        <tbody>
            <?php
                require_once "PHP-SQL.php";
                $sql = $connection->query("SELECT * FROM mahasiswa");
                if (mysqli_num_rows($sql)){
                    $no =1;
                    foreach($sql as $data){?>
                        <tr style="text-align: center">
                            <td><?=$no?></td>
                            <td><?php echo $data['nim']?></td>
                            <td><?=$data['nama_mahasiswa']?></td>
                            <td><?=$data['jurusan']?></td>
                            <td><?=$data['jk']?></td>
                            <td><?=$data['Alamat']?></td>
                            <td>
                                <a href="">Hapus</a> || <a href="">Edit</a>
                            </td>
                        </tr>
            <?php
                    $no++; } }
            ?>

        </tbody>
    </table>
</body>
</html>