#include <iostream>
#include <fstream>
 #include <unistd.h>
using namespace std;

void add(fstream& file){
  cout << "                   Contact Format" << endl;
  cout << "==========================================================" << endl;
  cout << endl;
  cout << "Name \t :" << endl;
  cout << "Phone \t :" << endl;
  cout << "Address\t :" << endl;
  cout << "Email \t :" << endl;

  string name, phone, address, email;
  cout << "\nEnter name: ";
  getline(cin, name);
  cout << "Enter Phone Number:";
  getline(cin, phone);
  cout << "Enter Address:";
  getline(cin, address);
  cout << "Enter Email:";
  getline(cin, email);

  if(file.is_open()){
    cout << "==========================================================" << endl;
    cout << "Writting info to file..." << endl;
    sleep(2);
    cout << "Successfully written to file!" << endl;
    cout << "==========================================================" << endl;
    file << name << "," << phone << "," << address << "," << email << endl;
  }else {
   cout << "Could write to file: " << endl;
  }

  sleep(2);
}


void list(fstream& file){
  if(file.is_open()){

    string line;

    while(!file.eof()){ //end of file
    getline(file, line);
    cout << line << endl;
  }
}
}

int main(){
  fstream file;
  file.open("contacts.txt", ios::out);

  string answer = "";
  cout << "**** Welcome to the Contact Managment System ****" << endl;
while(answer != "5"){

  cout << endl;
  cout << "                     MAIN MENU                 " << endl;
  cout << "            ===========================        " << endl;
  cout << "            [1] Add a new Contact" << endl;
  cout << "            [2] List all Contacts" << endl;
  cout << "            [3] Edit a Contact" << endl;
  cout << "            [4] Delete a Contact" << endl;
  cout << "            [5] Exit" << endl;
  cout << "            ===========================" << endl;

  getline(cin, answer);

  if(answer == "1"){
        add(file);
    } else if (answer == "2") {
        list(file);
    } else if(answer == "3"){
      //edit()
    } else if(answer == "4") {
      //delete()
    } else if (answer == "5") {
      cout << "Thank you foe using the Contact Managment System!" << endl;
    } else {
      cout << "Enter valid menu option" << endl;
    }
}



file.close();


  return 0;
}
