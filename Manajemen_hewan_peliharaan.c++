#include <iostream>
#include <string>
using namespace std;

// Abstract Class untuk Hewan Peliharaan
class HewanPeliharaan {
protected:
    string nama;              // Nama hewan peliharaan
    int umur;                 // Umur hewan peliharaan
    string jenis;             // Jenis hewan (misalnya: Anjing, Kucing)
    string statusKesehatan;  // Status kesehatan hewan (misalnya: Sehat, Sakit)
    string kelamin;           // Kelamin hewan (Jantan atau Betina)

public:
    // Konstruktor untuk menginisialisasi atribut-atribut hewan peliharaan
    HewanPeliharaan(string nama, int umur, string jenis, string statusKesehatan, string kelamin)
        : nama(nama), umur(umur), jenis(jenis), statusKesehatan(statusKesehatan), kelamin(kelamin) {}

    // Virtual Destructor untuk memastikan pemanggilan destructor subclass jika ada
    virtual ~HewanPeliharaan() {}

    // Abstract Method untuk suara
    // Fungsi ini harus diimplementasikan di subclass
    virtual string suara() = 0;

    // Method untuk menampilkan informasi hewan peliharaan
    virtual string info() {
        return "Nama: " + nama + "\nJenis: " + jenis + "\nKelamin: " + kelamin +
               "\nUmur: " + to_string(umur) + " tahun\nKesehatan: " + statusKesehatan;
    }

    // Method untuk memperbarui status kesehatan hewan
    void updateStatusKesehatan(string statusBaru) {
        statusKesehatan = statusBaru;  // Update status kesehatan dengan yang baru
    }
};

// Subclass untuk Anjing
class Anjing : public HewanPeliharaan {
private:
    string ras;  // Atribut tambahan khusus untuk Anjing

public:
    // Konstruktor untuk kelas Anjing
    // Memanggil konstruktor kelas dasar (HewanPeliharaan) dan menambahkan atribut ras
    Anjing(string nama, int umur, string statusKesehatan, string kelamin, string ras)
        : HewanPeliharaan(nama, umur, "Anjing", statusKesehatan, kelamin), ras(ras) {}

    // Implementasi fungsi suara() untuk Anjing
    string suara() override {
        return "Guk guk!";  // Suara khas Anjing
    }

    // Override info untuk menambahkan informasi tentang ras Anjing
    string info() override {
        return HewanPeliharaan::info() + "\nRas: " + ras + "\nSuara: " + suara();
    }

    // Fungsi deskripsi yang mengembalikan informasi lengkap
    // Overloading: Menambahkan detail tambahan jika diberikan
    string deskripsi(string detailTambahan = "") {
        if (!detailTambahan.empty()) {
            return info() + "\nDetail: " + detailTambahan;
        }
        return info();  // Jika tidak ada detail tambahan, hanya menampilkan info dasar
    }
};

// Subclass untuk Kucing
class Kucing : public HewanPeliharaan {
private:
    string warnaBulu;  // Atribut tambahan khusus untuk Kucing

public:
    // Konstruktor untuk kelas Kucing
    // Memanggil konstruktor kelas dasar (HewanPeliharaan) dan menambahkan atribut warnaBulu
    Kucing(string nama, int umur, string statusKesehatan, string kelamin, string warnaBulu)
        : HewanPeliharaan(nama, umur, "Kucing", statusKesehatan, kelamin), warnaBulu(warnaBulu) {}

    // Implementasi fungsi suara() untuk Kucing
    string suara() override {
        return "Meong!";  // Suara khas Kucing
    }

    // Override info untuk menambahkan informasi tentang warna bulu Kucing
    string info() override {
        return HewanPeliharaan::info() + "\nWarna Bulu: " + warnaBulu + "\nSuara: " + suara();
    }

    // Fungsi deskripsi yang mengembalikan informasi lengkap
    // Overloading: Menambahkan detail tambahan jika diberikan
    string deskripsi(string detailTambahan = "") {
        if (!detailTambahan.empty()) {
            return info() + "\nDetail: " + detailTambahan;
        }
        return info();  // Jika tidak ada detail tambahan, hanya menampilkan info dasar
    }
};

// Bagian Program Utama
int main() {
    // Membuat objek Anjing dan Kucing
    Anjing anjing1("Buddy", 3, "Sehat", "Jantan", "Golden Retriever");
    Kucing kucing1("Whiskers", 2, "Sedikit Sakit", "Betina", "Hitam");

    // Menampilkan informasi hewan peliharaan
    cout << "==============================\n";
    cout << "Informasi Hewan Peliharaan\n";
    cout << "==============================\n";
    cout << anjing1.info() << endl;  // Menampilkan informasi Anjing
    cout << "------------------------------\n";
    cout << kucing1.info() << endl;  // Menampilkan informasi Kucing
    cout << "==============================\n";

    // Memperbarui status kesehatan Anjing
    anjing1.updateStatusKesehatan("Tidak Sehat");
    cout << "\nSetelah Update Status Kesehatan:\n";
    cout << "==============================\n";
    cout << anjing1.info() << endl;  // Menampilkan informasi Anjing setelah update status kesehatan
    cout << "==============================\n";

    // Menampilkan deskripsi dengan overloading
    cout << "\nDeskripsi Anjing dengan Detail:\n";
    cout << anjing1.deskripsi("Anjing yang sangat ramah dan suka bermain.") << endl;
    cout << "\nDeskripsi Kucing tanpa Detail:\n";
    cout << kucing1.deskripsi() << endl;

    return 0;  // Mengakhiri program
}
