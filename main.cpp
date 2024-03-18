#include <iostream>

using namespace std;

class Queue {
private:
    int frontIndex; // Menunjukkan indeks elemen depan dari queue.
    int rearIndex; // Menunjukkan indeks di mana elemen berikutnya akan dimasukkan.
    int capacity; // Kapasitas maksimum dari queue.
    int size; // Jumlah elemen saat ini dalam queue.
    int *queue; // Pointer ke array dinamis yang menyimpan elemen queue.

public:
    // Constructor untuk inisialisasi queue.
    Queue(int queueCapacity) {
        capacity = queueCapacity; // Set kapasitas.
        queue = new int[capacity]; // Buat array dengan kapasitas yang diberikan.
        frontIndex = 0; // Set indeks depan ke 0.
        rearIndex = -1; // Set indeks belakang ke -1, menunjukkan queue kosong.
        size = 0; // Set ukuran awal ke 0.
    }

    // Fungsi untuk menambahkan elemen ke queue.
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity; // Gunakan aritmatika modulo untuk sirkulasi indeks.
        queue[rearIndex] = value; // Masukkan nilai ke dalam queue.
        size++; // Tambahkan ukuran queue.
    }

    // Fungsi untuk menghapus elemen dari queue.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity; // Gunakan aritmatika modulo untuk sirkulasi indeks.
        size--; // Kurangi ukuran queue.
    }

    // Fungsi untuk mendapatkan elemen depan dari queue.
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1; // Kembalikan nilai default jika queue kosong.
        }
        return queue[frontIndex]; // Kembalikan elemen depan.
    }

    // Fungsi untuk memeriksa apakah queue kosong.
    bool isEmpty() {
        return (size == 0);
    }

    // Fungsi untuk mendapatkan ukuran queue.
    int getSize() {
        return size;
    }
};

int main() {
    Queue queue(3); // Membuat queue dengan kapasitas 3.

    // Menambahkan elemen ke queue.
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(7);

    // Menampilkan elemen depan dan menghapusnya dari queue.
    cout << "Front element: " << queue.front() << endl;
    queue.dequeue();

    cout << "Front element after dequeue: " << queue.front() << endl;
    queue.dequeue();

    cout << "Front element after dequeue: " << queue.front() << endl;
    queue.dequeue();

    // Menambahkan elemen baru ke queue dan menampilkan ukuran queue.
    queue.enqueue(100);
    cout << "Queue size: " << queue.getSize() << endl;

    // Mengosongkan queue dan menampilkan ukuran akhir.
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout << "Queue size after dequeue all: " << queue.getSize() << endl;

    return 0;
}
