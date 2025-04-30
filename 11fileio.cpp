#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

class Student {
private:
    string name, div, address;
    int roll;
public:
    void getdata();
    void displayAll();
    void insert_record();
    void delete_record();
    void search_record();
};

void Student::getdata() {
    cout << "\nEnter Roll No, Division, Name and Address of Student: ";
    cin >> roll >> div >> name >> address;
}

void Student::insert_record() {
    fstream out;
    Student s1;
    out.open("StudRecord.txt", ios::app | ios::binary);
    
    s1.getdata();
    out.write((char *)&s1, sizeof(s1));
    
    out.close();
}

void Student::displayAll() {
    fstream out;
    Student s2;
    out.open("StudRecord.txt", ios::in | ios::binary);
    
    cout << "\nThe Contents of file are.......\n\n";
    cout << "\nROLL" << setw(15) << "Division" << setw(15) << "NAME" << setw(15) << "ADDRESS\n";
    
    while (out.read((char *)&s2, sizeof(s2))) {
        cout << "\n" << s2.roll << setw(15) << s2.div << setw(15) << s2.name << setw(15) << s2.address;
    }
    cout << "\n";
    out.close();
}

void Student::delete_record() {
    fstream out, temp;
    Student s2;
    int item;
    out.open("StudRecord.txt", ios::in | ios::binary);
    temp.open("temp.txt", ios::out | ios::binary);
    
    cout << "\nEnter Roll_No: ";
    cin >> item;
    
    while (out.read((char *)&s2, sizeof(s2))) {
        if (s2.roll != item) {
            temp.write((char *)&s2, sizeof(s2));
        }
    }
    
    out.close();
    temp.close();
    
    remove("StudRecord.txt");
    rename("temp.txt", "StudRecord.txt");
}

void Student::search_record() {
    int item;
    Student s2;
    fstream out;
    out.open("StudRecord.txt", ios::in | ios::binary);
    
    cout << "\nEnter Roll_No: ";
    cin >> item;
    
    while (out.read((char *)&s2, sizeof(s2))) {
        if (s2.roll == item) {
            cout << "\nRecord is Present in the File....\n";
            cout << "\n" << s2.roll << "\t" << s2.div << "\t" << s2.name << "\t" << s2.address;
            break;
        }
    }
    out.close();
}

int main() {
    Student t1;
    int ch = 0;
    fstream out;
    out.open("StudRecord.txt", ios::out);
    out.close();
    
    while (ch != 5) {
        cout << "\n*******  SEQUENTIAL ACCESS FILE PROGRAM USING C++ ********** \n\n";
        cout << "\n1.INSERT RECORD\n2.DISPLAY All Records \n3.SEARCH\n4.Delete\n5.EXIT.";
        cout << "\nEnter UR Choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                t1.insert_record();
                cout << "\n\nRecord is Inserted..\n\n";
                break;
            case 2:
                t1.displayAll();
                break;
            case 3:
                t1.search_record();
                break;
            case 4:
                t1.delete_record();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
/*
  Theory Explanation:

  1. What the Program Does:
     This C++ program provides a basic implementation of **sequential file handling** to manage student records.
     - It allows insertion, display, searching, and deletion of student data.
     - All records are stored in a binary file (`StudRecord.txt`) using `fstream`.

  2. What Data Structures Are Used and Why:
     - **Class `Student`**: Encapsulates student information such as roll number, division, name, and address.
     - **Binary File**: Used to store and retrieve structured data in an efficient, persistent format.
       - The binary format allows storing class objects directly and reading/writing them quickly.

  3. Key Functionalities:
     - **insert_record()**:
         - Prompts the user to input student data and appends it to the file.
         - Uses `ios::app | ios::binary` to ensure new data doesn't overwrite existing records.
     - **displayAll()**:
         - Reads the entire file sequentially and displays all student records.
     - **search_record()**:
         - Searches the file for a specific roll number and displays the corresponding student details if found.
     - **delete_record()**:
         - Creates a temporary file and copies all records except the one to be deleted.
         - Replaces the original file with the new one, effectively deleting the specified record.

  4. Real-Life Applications:
     - **Student Record Management Systems**: Maintaining and retrieving student details in schools or universities.
     - **Employee/Client Data**: For small-scale recordkeeping without needing databases.
     - **Persistent Storage**: For applications where structured data needs to survive after program termination.

  5. File Handling Notes:
     - Binary file I/O is used to efficiently store object data.
     - `fstream` objects are used in various modes: `ios::in`, `ios::out`, `ios::app`, and `ios::binary`.
     - Temporary files are used during deletion to maintain file integrity.

  Additional Notes:
     - The file is opened in write mode (`ios::out`) at the beginning of `main()` to clear any previous data.
     - Input validation is minimal; in a production system, input sanitation and error handling should be improved.
     - The program uses basic text-based menus for interaction.
*/
