#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ==========================
// ESTRUCTURA STUDENT
// ==========================

struct Student {

    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;

};

// ==========================
// NODO PARA LISTA ENLAZADA
// ==========================

struct Node {

    Student data;
    Node* next;

};

// ==========================
// HASH TABLE
// ==========================

class HashTable {

private:

    static const int SIZE = 10;

    Node* table[SIZE];

    int totalStudents;
    int collisions;

public:

    HashTable() {

        totalStudents = 0;
        collisions = 0;

        for(int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(int id) {
        return id % SIZE;
    }

    void insert(Student student) {

        int index = hashFunction(student.student_id);

        Node* temp = table[index];

        while(temp != NULL) {

            if(temp->data.student_id == student.student_id) {
                cout << "Estudiante duplicado: "
                     << student.student_id << endl;
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node();
        newNode->data = student;
        newNode->next = NULL;

        if(table[index] != NULL) {
            collisions++;
            newNode->next = table[index];
        }

        table[index] = newNode;
        totalStudents++;
    }

    void search(int id) {

        int index = hashFunction(id);
        Node* temp = table[index];

        while(temp != NULL) {

            if(temp->data.student_id == id) {

                cout << "\nESTUDIANTE ENCONTRADO\n";
                cout << "ID: " << temp->data.student_id << endl;
                cout << "Nombre: " << temp->data.full_name << endl;
                cout << "Carrera: " << temp->data.career << endl;
                cout << "Semestre: " << temp->data.semester << endl;
                cout << "GPA: " << temp->data.gpa << endl;
                cout << "Skill Score: " << temp->data.skill_score << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nEstudiante no encontrado\n";
    }

    void remove(int id) {

        int index = hashFunction(id);

        Node* temp = table[index];
        Node* prev = NULL;

        while(temp != NULL && temp->data.student_id != id) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "\nEstudiante no encontrado\n";
            return;
        }

        if(prev == NULL) {
            table[index] = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        totalStudents--;

        cout << "\nEstudiante eliminado correctamente\n";
    }

    void display() {

        cout << "\n===== TABLA HASH =====\n";

        for(int i = 0; i < SIZE; i++) {

            cout << "\nBucket " << i << ": ";

            Node* temp = table[i];

            while(temp != NULL) {

                cout << "[" << temp->data.student_id
                     << " - "
                     << temp->data.full_name
                     << "] -> ";

                temp = temp->next;
            }

            cout << "NULL";
        }

        cout << endl;
    }

    void statistics() {

        float loadFactor = (float) totalStudents / SIZE;

        cout << "\n===== ESTADISTICAS =====\n";
        cout << "Total estudiantes: " << totalStudents << endl;
        cout << "Colisiones: " << collisions << endl;
        cout << "Factor de carga: " << loadFactor << endl;
    }
};



void loadCSV(string filename, HashTable& hashTable) {

    ifstream file(filename);

    if(!file.is_open()) {
        cout << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    string line;

    getline(file, line);

    while(getline(file, line)) {

        stringstream ss(line);
        Student s;
        string temp;

        getline(ss, temp, ',');
        s.student_id = stoi(temp);

        getline(ss, s.full_name, ',');
        getline(ss, s.career, ',');

        getline(ss, temp, ',');
        s.semester = stoi(temp);

        getline(ss, temp, ',');
        s.gpa = stof(temp);

        getline(ss, temp, ',');
        s.skill_score = stoi(temp);

        hashTable.insert(s);
    }

    file.close();
}

// ==========================
// MAIN
// ==========================

int main() {

    cout << "Nombre: TU NOMBRE: Carlos Daniel Castro Caceres\n";
    cout << "Carné: TU CARNE: 9941-24-10004\n";

    HashTable hashTable;

    
    loadCSV("./estudiantes.csv", hashTable);

    cout << "\nESTUDIANTES CARGADOS\n";

    hashTable.display();
    hashTable.statistics();

    hashTable.search(1002);
    hashTable.remove(1003);

    hashTable.display();
    hashTable.statistics();

    return 0;
}