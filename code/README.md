Kode  program Arduino yang mengontrol gerakan motor DC menggunakan Bluetooth. Berikut adalah penjelasan singkat tentang kode tersebut:

1. Baris 4-10: Mendefinisikan library yang akan digunakan, yaitu SoftwareSerial untuk komunikasi serial melalui pin digital dan AFMotor untuk mengontrol motor DC.

2. Baris 12-15: Mendefinisikan objek SoftwareSerial dengan nama btSerial. Objek ini digunakan untuk berkomunikasi dengan modul Bluetooth.

3. Baris 16-19: Mendefinisikan objek AF_DCMotor untuk mengontrol masing-masing motor DC. Dalam contoh ini, terdapat empat motor yang diberi nama banKiriAtas, banKiriBawah, banKananBawah, dan banKananAtas.

4. Baris 20-21: Mendefinisikan variabel Aturkecepatan yang digunakan untuk mengatur kecepatan motor.

5. Baris 23-28: Fungsi setup() yang akan dieksekusi sekali saat Arduino pertama kali dinyalakan. Pada bagian ini, baud rate untuk komunikasi Serial dan btSerial diatur menjadi 9600.

6. Baris 30-39: Fungsi maju() untuk menggerakkan semua motor ke depan (maju).

7. Baris 41-50: Fungsi mundur() untuk menggerakkan semua motor ke belakang (mundur).

8. Baris 52-61: Fungsi BelokKanan() untuk menggerakkan motor-motor kiri ke depan dan motor-motor kanan ke belakang, sehingga menghasilkan gerakan belok ke kanan.

9. Baris 63-72: Fungsi BelokKiri() untuk menggerakkan motor-motor kiri ke belakang dan motor-motor kanan ke depan, sehingga menghasilkan gerakan belok ke kiri.

10. Baris 74-82: Fungsi Berhenti() untuk menghentikan semua motor dengan memberikan sinyal RELEASE pada masing-masing motor.

11. Baris 84-97: Fungsi loop() yang akan dieksekusi secara berulang. Pada bagian ini, program akan memeriksa apakah ada data yang tersedia melalui modul Bluetooth (btSerial). Jika ada, data tersebut akan dibaca dan diproses.

12. Baris 87: Memeriksa apakah ada data yang tersedia melalui btSerial.

13. Baris 88: Membaca data dari btSerial.

14. Baris 89: Memanggil fungsi Berhenti() untuk menghentikan gerakan motor sebelum menjalankan perintah berikutnya.

15. Baris 91-96: Melakukan switch case terhadap instruksi yang diterima dari btSerial. Berdasarkan instruksi tersebut, fungsi yang sesuai akan dipanggil untuk menggerakkan motor dengan arah yang diinginkan.

Dalam hal ini, terdapat beberapa instruksi yang bisa dikirim melalui modul Bluetooth:
- 'F': Maju (menggerakkan semua motor ke depan)
- 'B': Mundur (menggerakkan semua motor ke belakang)
- 'L': Belok kiri
- 'R': Belok kanan

Perintah-perintah ini akan mengatur kecepatan motor sesuai dengan nilai yang telah ditentukan (Aturkecepatan).