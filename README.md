# SoalShiftSisop20_modul3_D01
1. Membuat sebuah game berbasis text terminal mirip dengan Pokemon GO.
  Ketentuan permainan sebagai berikut:
  a. Menggunakan IPC-shared memory, thread, fork-exec.
  b. Kalian bebas berkreasi dengan game ini asal tidak konflik dengan
     requirements yang ada. (Contoh: memberi nama trainer, memberi notifikasi
     kalau barang di shop sudah penuh, dan lain-lain).
  c. Terdapat 2 code yaitu soal2_traizone.c dan soal2_pokezone.c.
  d. soal2_traizone.c mengandung fitur:
     i. Normal Mode (3 Menu)
        1. Cari Pokemon
        2. Pokedex
        3. Shop
    ii. Capture Mode (3 Menu)
        1. Tangkap
        2. Item 
        3. Keluar
  e. soal2_pokezone.c mengandung fitur:
     i. Shutdown game
    ii. Jual Item (Gunakan Thread)
   iii. Menyediakan Random Pokemon (Gunakan Thread)
        1. Setiap tipe pokemon memiliki peluang 1/8000 untuk jadi shiny pokemon.
        2. Shiny Pokemon meningkatkan escape rate sebesar +5%
        3. Setiap 1 detik thread ini akan mengkalkulasi random ulang lagi untuk nantinya diberikan ke soal2_traizone.
        
  Source code :
  ```
  
  ```
        
2. Membuat TapTap Game, game online berbasis text console. 
Terdapat 2 program yaitu tapserver.c dan tapplayer.c
Syarat :
- Menggunakan Socket, dan Thread
Hint :
- fwrite, fread
Spesifikasi Game :

CLIENT SIDE

Screen 1 :
  1. Login
  2. Register
  Choices : {your input}
  ★ Pada screen 1 kalian dapat menginputkan “login”, setelah menekan enter
  anda diminta untuk menginputkan username dan password seperti berikut

Screen 1 :
  1. Login
  2. Register
  Choices : login
  Username : { ex : qiqi }
  Password : { ex : aku nggak marah!! }
  ★ Jika login berhasil maka akan menampilkan pesan “login success”, jika gagal
  akan menampilkan pesan “login failed” (pengecekan login hanya mengecek
  username dan password, maka dapat multi autentikasi dengan username dan
  password yang sama)
  ★ Pada screen 1 kalian juga dapat menginputkan “register”, setelah menekan
  enter anda diminta untuk menginputkan username dan password sama
  halnya seperti login
  ★ Pada register tidak ada pengecekan unique username, maka setelah register
  akan langsung menampilkan pesan “register success” dan dapat terjadi
  double account
  ★ Setelah login berhasil maka anda berpindah ke screen 2 dimana
  menampilkan 2 fitur seperti berikut.

Screen 2 :
  1. Find Match
  2. Logout
  Choices : {your input}
  ★ Pada screen 2 anda dapat menginputkan “logout” setelah logout anda akan
  kembali ke screen 1
  ★ Pada screen 2 anda dapat menginputkan “find”, setelah itu akan
  menampilkan pesan “Waiting for player ...” print terus sampai menemukan
  lawan
  ★ Jika menemukan lawan maka akan menampilkan pesan “Game dimulai
  silahkan tap tap secepat mungkin !!”
  ★ Pada saat game dimulai diberikan variable health = 100,dan anda dapat
  men-tap (menekan space pada keyboard tanpa harus menekan enter)
  ★ Pada saat anda men-tap maka akan menampilkan pesan “hit !!”, dan pada
  lawan healthnya akan berkurang sebanyak 10 kemudian pada lawan
  menampilkan pesan status healthnya sekarang. (conclusion : anda tidak bisa
  melihat status health lawan)
  ★ Jika health anda <= 0 maka akan menampilkan pesan “Game berakhir kamu
  kalah”, apabila lawan anda healthnya <= 0 maka akan menampilkan pesan
  ”Game berakhir kamu menang”
  ★ Setelah menang atau kalah maka akan kembali ke screen 2

SERVER SIDE

  ★ Pada saat program pertama kali dijalankan maka program akan membuat file
  akun.txt jika file tersebut tidak ada. File tersebut digunakan untuk menyimpan
  username dan password
  ★ Pada saat user berhasil login maka akan menampilkan pesan “Auth success” jika
  gagal “Auth Failed”
  ★ Pada saat user sukses meregister maka akan menampilkan List account yang
  terdaftar (username dan password harus terlihat)
  
  Source code :
  ```
  
  ```
  
3. Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.

  ● Semisal program dijalankan:
  ```
  # File kategori terletak di /home/izone/kategori
  $ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip
  #Hasilnya adalah sebagai berikut
  /home/izone
  |-jpg
  |--file1.jpg
  |-c
  |--file2.c
  |-zip
  |--file3.zi
  ```
  ● Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
  dikategorikan sebanyak yang user inginkan seperti contoh di atas.
  ● Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
  melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
  maka dia akan disimpan dalam folder “Unknown”.
  ● Program kategori ini juga menerima perintah (*) seperti di bawah;
  ```
  $ ./kategori \*
  ```
  ● Artinya mengkategori seluruh file yang ada di working directory ketika
  menjalankan program C tersebut.
  ● Selain hal itu program C ini juga menerima opsi -d untuk melakukan kategori
  pada suatu directory. Untuk opsi -d ini, user hanya bisa menginput 1 directory
  saja, tidak seperti file yang bebas menginput file sebanyak mungkin.
  ```
  $ ./kategori -d /path/to/directory/
  ```
  ● Hasilnya perintah di atas adalah mengkategorikan file di /path/to/directory dan
  hasilnya akan disimpan di working directory di mana program C tersebut
  berjalan (hasil kategori filenya bukan di /path/to/directory).
  ● Program ini tidak rekursif. Semisal di directory yang mau dikategorikan, atau
  menggunakan (*) terdapat folder yang berisi file, maka file dalam folder
  tersebut tidak dihiraukan, cukup file pada 1 level saja.
  ● Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan
  secara paralel sehingga proses kategori bisa berjalan lebih cepat. Dilarang
  juga menggunakan fork-exec dan system.
  ● Silahkan download soal3.zip sebagai percobaan. Namun silahkan
  dicoba-coba sendiri untuk kemungkinan test case lainnya yang mungkin
  belum ada di soal3.zip.
  
  Source code : 
  ```
  
  ```
4. Memecahkan teka - teki yang ada di pillar.

- Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada
  batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:
  
  1. Buatlah program C dengan nama "4a.c", yang berisi program untuk
  melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
  matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
  nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
  2. Tampilkan matriks hasil perkalian tadi ke layar.

- Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya
  adalah:

  1. Buatlah program C kedua dengan nama "4b.c". Program ini akan
  mengambil variabel hasil perkalian matriks dari program "4a.c" (program
  sebelumnya), dan tampilkan hasil matriks tersebut ke layar.
  (Catatan!: gunakan shared memory)
  2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
  tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan
  format seperti matriks.

  Contoh: misal array 
```
  [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...],
```
  maka:
```
  1   2   6   24
  120 720 ... ...
  ...
```
  (Catatan! : Harus menggunakan Thread dalam penghitungan aktorial)
  
- Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan
  teka-teki berikut!

  1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak
  memiliki hubungan terhadap program yang lalu.
  2. Pada program ini, Norland diminta mengetahui jumlah file dan
  folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
  IPC, Norland mengerjakannya dengan semangat.
  (Catatan! : Harus menggunakan IPC Pipes)
  
  Source code :
  ```
  
  ```
