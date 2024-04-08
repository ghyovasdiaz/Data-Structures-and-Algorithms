#include <iostream> 
using namespace std;

class Node { // Mendefinisikan kelas Node
public:
    char id; // Menyimpan karakter
    Node* next; // Pointer ke node berikutnya
    
    Node() { // Konstruktor kelas Node
        next = NULL; // Menginisialisasi pointer next dengan NULL
    }
};

class LinkedList { // Mendefinisikan kelas LinkedList
public:
    Node* head; // Pointer ke node pertama dalam linked list
    Node* tail; // Pointer ke node terakhir dalam linked list
    
    LinkedList() { // Konstruktor kelas LinkedList
		head = tail = NULL; // Menginisialisasi head dan tail dengan NULL, menandakan linked list kosong
	}

    void insertToHead(char data){
    	Node *node = new Node();
    	node->id = data;
    	
    	if(head == NULL){
    		head = node;
    		tail = node;
		}else{
			Node *tmp = head;
			head = node;
			head->next = tmp;
		}
	}
	
	void insertToTail(char data){
		Node *node = new Node();
		node->id = data;
		
		if(head == NULL){
			head = node;
			tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
	}
	
	void printAll(){
		Node *tmp = head;
		
		while (tmp != NULL){
			cout << tmp->id << "->";
			tmp = tmp->next;
		}
	}
	
	void insertDataAfter(char data, char after){
		if (head == NULL){
			cout << "Error: empty data";
			
		}else if(tail->id == after){
			insertToTail(data);
			
		}else{
			Node *tmp = head;
			
			while(tmp != NULL && tmp->id != after){
				tmp = tmp->next;
			}
			
			if(tmp == NULL){
				cout << "After data not found" << endl;
			}else{
				Node*newNode = new Node();
				newNode->id = data;
				
				newNode->next = tmp->next;
				tmp->next = newNode;
			}
		}
	}
	
	
	void DeleteHead(){
		Node *tmp = head;
		
		if(head == NULL){
			cout << "Data kosong!!" << endl;
		
		}else if(head == tail){
			delete tmp;
			head = tail = NULL;
		
		}else{
			head = head->next;
			delete tmp;
			
		}
		cout << "Deleted head" << endl;
	}
	
	void DeleteTail(){
		if(head == NULL){//data kosong
			cout << "Data kosong!!" << endl;
			
		}else if(head == tail){//1 node
			Node *tmp = head;
			delete tmp;
			head = tail = NULL;
			
		}else{//lebih dari 1 ndoe
			Node* current = head;
			Node* prev = NULL;
			Node *tmp = tail;
			
			while(current != NULL && current != tail){//mencari data sebelum tail
			prev = current;
			current = current->next;
			}
			prev->next = NULL;
			tail = prev;//menjadikan prev = tail
			delete tmp;
			cout << "Deleted tail " << endl;
		}
	}
	
	void DeleteData(char data){
    	if(head == NULL){//list kosong
        	cout << "Data kosong " << endl;
        	return;
		}

		Node* current = head;
		Node* prev = NULL;
		Node* prevhead = head;
    
    	if(head->id == data){// head adalah node yg dihapus
        	Node *tmp = head; // Simpan node head yang akan dihapus
        	head = head->next; // Pindahkan head ke node berikutnya
        	
        	if(head == NULL){ // setlah hapus list kosong
            	head = tail = NULL; 
        	}
        delete tmp; // Hapus node
        cout << "Deleted prev Head" << endl;
        return;
		}

    
    	while(current != NULL && current->id != data){//mencari node target
			prev = current;
			current = current->next;
		}
    
    	if(current == NULL){//target tidak ada di list
        	cout << "Data yang mau dihapus tidak ditemukan" << endl;
        	return;
    	}

    	if(prev != NULL){//target bukan head/tail
        	prev->next = current->next; // prev agar menunjuk node setelah target
   		}

    
    	if(current == tail){//terget = tail
        	tail = prev; // ganti tail ke node sebelum target
    	}

    	delete current; // Hapus target
    	cout << "Data deleted : " << data << endl;
	}

};


int main(int argc, char** argv) { 
    LinkedList *list1 = new LinkedList();
    
    list1->insertToHead('A');
    list1->insertToTail('B');
    list1->insertDataAfter('C', 'B');
    list1->insertDataAfter('D', 'C');
    
    //list1->DeleteHead();
    //list1->DeleteTail();
    //list1->DeleteData('D');
    cout << "Head : " << list1->head->id <<endl;
    cout << "Tail : " << list1->tail->id <<endl;
    cout << "\n----------------------\n";
    list1->printAll();
    
    return 0; 
}