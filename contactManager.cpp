#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <algorithm>

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
  cout << "Enter Phone Number: ";
  getline(cin, phone);
  cout << "Enter Address: ";
  getline(cin, address);
  cout << "Enter Email: ";
  getline(cin, email);

  if(file.is_open()){
    cout << "==========================================================" << endl;
    cout << "Writting info to file..." << endl;
    sleep(2);
    cout << "Successfully written to file!" << endl;
    cout << "==========================================================" << endl;
    file << name << "," << phone << "," << address << "," << email << endl;
  }else {
   cout << "Could not write to file: " << endl;
  }

  sleep(2);
}


void list(fstream& file){

  cout << "                   Contact List" << endl;
  cout << "==========================================================" << endl;

  if(file.is_open()){
    string line;
    int lineNumber = 1;

    while ( getline (file,line) )
    {
      cout << lineNumber << ") " << line << '\n';
      lineNumber++;
    }
  } else {
    cout << "File is not open" << endl;
  }
  cout << "==========================================================" << endl;

}

void edit(fstream& file){

  cout << "                   Edit Contact" << endl;
  cout << "==========================================================" << endl;
  cout << "           Select Contact Entry to Edit\n" << endl;
  list(file);

  //put file info into vector
  vector<string> info;
  if(file.is_open()){

    string line;
    int index = 0;

    while ( getline (file,line) )
    {
      info.push_back(line);
      index++;
    }
  } else {
    cout << "File is not open" << endl;
  }

  //determine which info to modify
  int input;
  cout << "\n > ";
  cin >> input;

  string name, phone, address, email;
  cout << "\nEnter Name: ";
  cin >> name;
  cout << "Enter Phone Number:";
  cin >> phone;
  cout << "Enter Address:";
  cin >> address;
  cout << "Enter Email:";
  cin >> email;

  //save info to single string and add to vector
   string allInfo = name + "," + phone + "," + address + "," + email;
   info.at(input) = allInfo;

  // //create new file
  //TODO fix out of range exception
  fstream temp;
  temp.open("temp.txt");
  if(temp.is_open()){
    for(unsigned int i = 0; i<info.size();i++){
      temp << info[i] << endl;
    }
  }



}

int main(){
  fstream file;


  string answer = "";
  cout << "**** Welcome to the Contact Managment System ****" << endl;
while(answer != "5"){

  cout << endl;
  cout << "                     MAIN MENU                 " << endl;
  cout << "           =============================       " << endl;
  cout << "            [1] Add a new Contact" << endl;
  cout << "            [2] List all Contacts" << endl;
  cout << "            [3] Edit a Contact" << endl;
  cout << "            [4] Delete a Contact" << endl;
  cout << "            [5] Exit" << endl;
  cout << "           =============================" << endl;

  cout << "\n > ";
  getline(cin, answer);

  if(answer == "1"){
        file.open("contacts.txt", fstream::app);
        add(file);
        file.close();
    }
  if (answer == "2") {
        file.open("contacts.txt");
        list(file);
        file.close();
    }
  if(answer == "3"){
    file.open("contacts.txt");
    edit(file);
    file.close();
    }
  if(answer == "4") {
      //delete()
    }
  if (answer == "5") {
      cout << "Thank you for using the Contact Managment System!" << endl;
    }
    // } else {
    //   cout << "Enter valid menu option" << endl;
    // }
}



file.close();


  return 0;
}
