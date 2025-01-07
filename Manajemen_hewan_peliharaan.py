# Abstract Class untuk Hewan Peliharaan
from abc import ABC, abstractmethod

# Bagian: Abstract Class (Abstraction)
class HewanPeliharaan(ABC):
    def __init__(self, nama, umur, jenis, status_kesehatan, kelamin):
        # Bagian: Encapsulation (atribut privat)
        self.__nama = nama
        self.__umur = umur
        self.__jenis = jenis
        self.__status_kesehatan = status_kesehatan
        self.__kelamin = kelamin

    # Bagian: Abstract Method (Polymorphism)
    # Method ini harus diimplementasikan di subclass
    @abstractmethod
    def suara(self):
        pass

    # Bagian: Method untuk menampilkan informasi hewan
    def info(self):
        return (f"Nama: {self.__nama}\n"
                f"Jenis: {self.__jenis}\n"
                f"Kelamin: {self.__kelamin}\n"
                f"Umur: {self.__umur} tahun\n"
                f"Kesehatan: {self.__status_kesehatan}")

    # Bagian: Method untuk memperbarui status kesehatan
    def update_status_kesehatan(self, status_baru):
        self.__status_kesehatan = status_baru

# Subclass untuk Anjing (Inheritance)
class Anjing(HewanPeliharaan):
    def __init__(self, nama, umur, status_kesehatan, kelamin, ras):
        # Bagian: Memanggil konstruktor superclass
        super().__init__(nama, umur, "Anjing", status_kesehatan, kelamin)
        self.__ras = ras  # Bagian: Atribut khusus untuk Anjing

    # Implementasi Abstract Method (Polymorphism)
    def suara(self):
        return "Guk guk!"

    # Bagian: Override method info untuk menambahkan informasi ras
    def info(self):
        return f"{super().info()}\nRas: {self.__ras}\nSuara: {self.suara()}"

    # Bagian: Overloading untuk menambahkan fungsi deskripsi lengkap
    def deskripsi(self, detail_tambahan=None):
        if detail_tambahan:
            return f"{self.info()}\nDetail: {detail_tambahan}"
        return self.info()

# Subclass untuk Kucing (Inheritance)
class Kucing(HewanPeliharaan):
    def __init__(self, nama, umur, status_kesehatan, kelamin, warna_bulu):
        # Bagian: Memanggil konstruktor superclass
        super().__init__(nama, umur, "Kucing", status_kesehatan, kelamin)
        self.__warna_bulu = warna_bulu  # Bagian: Atribut khusus untuk Kucing

    # Implementasi Abstract Method (Polymorphism)
    def suara(self):
        return "Meong!"

    # Bagian: Override method info untuk menambahkan informasi warna bulu
    def info(self):
        return f"{super().info()}\nWarna Bulu: {self.__warna_bulu}\nSuara: {self.suara()}"

    # Bagian: Overloading untuk menambahkan fungsi deskripsi lengkap
    def deskripsi(self, detail_tambahan=None):
        if detail_tambahan:
            return f"{self.info()}\nDetail: {detail_tambahan}"
        return self.info()

# Bagian Program Utama
if __name__ == "__main__":
    # Membuat objek Anjing dan Kucing
    anjing1 = Anjing("Buddy", 3, "Sehat", "Jantan", "Golden Retriever")
    kucing1 = Kucing("Whiskers", 2, "Sedikit Sakit", "Betina", "Hitam")

    # Menampilkan informasi hewan peliharaan
    print("=" * 30)
    print("Informasi Hewan Peliharaan")
    print("=" * 30)
    print(anjing1.info())  # Polymorphism: info() dipanggil dari subclass Anjing
    print("-" * 30)
    print(kucing1.info())  # Polymorphism: info() dipanggil dari subclass Kucing
    print("=" * 30)

    # Memperbarui status kesehatan Anjing
    anjing1.update_status_kesehatan("Tidak Sehat")
    print("\nSetelah Update Status Kesehatan:")
    print("=" * 30)
    print(anjing1.info())
    print("=" * 30)

    # Menampilkan deskripsi dengan overloading
    print("\nDeskripsi Anjing dengan Detail:")
    print(anjing1.deskripsi("Anjing yang sangat ramah dan suka bermain."))
    print("\nDeskripsi Kucing tanpa Detail:")
    print(kucing1.deskripsi())
