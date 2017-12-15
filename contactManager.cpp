#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>



void add(std::fstream& file){

  int index=-1;
  //display proper formating for conact
  std::cout << "                   Contact Format" << std::endl;
  std::cout << "==========================================================" << std::endl;
  std::cout << std::endl;
  std::cout << "Name \t :" << std::endl;
  std::cout << "Phone \t :" << std::endl;
  std::cout << "Address\t :" << std::endl;
  std::cout << "Email \t :" << std::endl;

  //retrive contact info

  std::string name, phone, address, email;
  size_t foundAT = email.find("@");
  size_t foundCOM = email.find(".com");

  std::cout << "\nEnter name: ";
  std::cin.ignore();
  getline(std::cin, name);

  //check that number is only digits
  do{
  std::cout << "Enter Phone Number: ";
  std::cin.ignore();
  getline(std::cin, phone);
  index++;
  } while(!isdigit(phone[index]));


  std::cout << "Enter Address: ";
  std::cin.ignore();
  getline(std::cin, address);

  do{
  std::cout << "Enter Email: ";
  std::cin.ignore();
  getline(std::cin, email);
  foundAT = email.find("@");
  foundCOM = email.find(".com");
  } while(foundAT==std::string::npos && foundCOM ==std::string::npos);

  //if file is open then display fun loading message and write to file
  //if its not then return
  if(file.is_open()){
    std::cout << "==========================================================" << std::endl;
    std::cout << "Writting info to file..." << std::endl;
    sleep(1);
    std::cout << "Successfully written to file!" << std::endl;
    std::cout << "==========================================================" << std::endl;
    file << name << "," << phone << "," << address << "," << email << std::endl;
  }else {
   std::cout << "Could not write to file: " << std::endl;
   return;
  }

  sleep(2);

  std::string answer;
  std::cout << '\n' << "Return to Main Menu? (y/n): ";
  std::cin >> answer;
  if(answer != "y"){
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Thank you for using the Contact Managment System!" << std::endl;
    std::cout << "==========================================================" << std::endl;
    file.close();
    exit(0);
 }
  std::cin.ignore();
}

void list(std::fstream& file){

  std::cout << "                   Contact List" << std::endl;
  std::cout << "==========================================================" << std::endl;

  //check if file is open
  //if it is, get each line and display it with its line Number
  //if its not, then return
  if(file.is_open()){
    std::string line;
    int lineNumber = 1;

    while ( getline (file,line) )
    {
      std::cout << lineNumber << ") " << line << '\n';
      lineNumber++;
    }
  } else {
    std::cout << "File is not open" << std::endl;
    return;
  }
  std::cout << "==========================================================" << std::endl;

  sleep(3);

  std::string answer;
  std::cout << '\n' << "Return to Main Menu? (y/n): ";
  std::cin >> answer;
  if(answer != "y"){
    std::cout << "\n==========================================================" << std::endl;
    std::cout << "Thank you for using the Contact Managment System!" << std::endl;
    std::cout << "==========================================================" << std::endl;
    file.close();
    exit(0);
 }
  std::cin.ignore();

}

void edit(std::fstream& file){
  std::cout << "                   Edit Contact" << std::endl;
  std::cout << "==========================================================" << std::endl;
  std::cout << "           Select Contact Entry to Edit\n" << std::endl;


  //create std::vector to hold current contact info
  std::vector<std::string> info;
  int index = 0;
  int phoneIndex = -1;

  if(file.is_open()){
    std::string line;

    //add info from file into std::string std::vector
    //if file is not open return to main menu
    while ( getline (file,line) )
    {
      info.push_back(line);
      index++;
    }
  } else {
    std::cout << "File is not open" << std::endl;
    return;
  }

  //display choices for user
  for(int i = 0; i<info.size();i++){
    std::cout << i+1 << ") " << info[i]<< std::endl;
  }
  std::cout << "==========================================================" << std::endl;

  //determine which info to modify
  int input;
  // make sure input is valid
  do{
  std::cout << "\n > ";
  std::cin >> input;
  } while (input < 1 || input - 1 > info.size());

  std::string name, phone, address, email;
  size_t foundAT = email.find("@");
  size_t foundCOM = email.find(".com");

  std::cout << "\nEnter name: ";
  std::cin.ignore();
  getline(std::cin, name);

  //check that number is only digits
  do{
  std::cout << "Enter Phone Number: ";
  std::cin.ignore();
  getline(std::cin, phone);
  phoneIndex++;
} while(!isdigit(phone[phoneIndex]));

  std::cout << "Enter Address: ";
  std::cin.ignore();
  getline(std::cin, address);


  do{
  std::cout << "Enter Email: ";
  std::cin.ignore();
  getline(std::cin, email);
  foundAT = email.find("@");
  foundCOM = email.find(".com");
  } while(foundAT==std::string::npos && foundCOM ==std::string::npos);

  //save info to single std::string and add to std::vector
   std::string newContact = name + "," + phone + "," + address + "," + email;
   info.at(input-1) = newContact;


   //create new temporary file to hold altered std::vector values
   //add each contact with new edited contact into file
   std::fstream temp;
   temp.open("temp.txt", std::fstream::app);
   if(temp.is_open()){
     for(int i = 0; i<info.size();i++){
           temp << info[i]<< std::endl;
         }
       }

    //remove old contacts.txt and rename temp.txt to contacts
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    std::cout << "==========================================================" << std::endl;
    std::cout << "Writting edit to file.." << std::endl;
    sleep(1);
    std::cout << "Successfully written to file!" << std::endl;
    std::cout << "==========================================================" << std::endl;

    sleep(2);

    std::string answer;
    std::cout << '\n' << "Return to Main Menu? (y/n): ";
    std::cin >> answer;
    if(answer != "y"){
      std::cout << "\n==========================================================" << std::endl;
      std::cout << "Thank you for using the Contact Managment System!" << std::endl;
      std::cout << "==========================================================" << std::endl;
      file.close();
      exit(0);
   }
    std::cin.ignore();
}

void deleteContact(std::fstream& file){
  std::cout << "                   Delete Contact" << std::endl;
  std::cout << "==========================================================" << std::endl;
  std::cout << "           Select Contact Entry to Remove\n" << std::endl;

  //create std::vector to hold current contact info
  std::vector<std::string> info;
  int index = 0;

  if(file.is_open()){
    std::string line;

    //add info from file into std::string std::vector
    //if file is not open return to main menu
    while ( getline (file,line) )
    {
      info.push_back(line);
      index++;
    }
  } else {
    std::cout << "File is not open" << std::endl;
    return;
  }

  //display choices for user
  for(int i = 0; i<info.size();i++){
    std::cout << i+1 << ") " << info[i]<< std::endl;
  }
  std::cout << "==========================================================" << std::endl;
  //determine which info to modify
  int input;

  //determine that input is valid
  do{
  std::cout << "\n > ";
  std::cin >> input;
  } while (input < 1 || input - 1 > info.size());
  std::cin.ignore();

  //erase entry from std::vector
  info.erase(info.begin()+input-1);

  //create new temporary file to hold altered std::vector values
  //add each contact with new edited contact into file
  std::fstream temp;
  temp.open("temp.txt", std::fstream::app);
  if(temp.is_open()){
    for(int i = 0; i<info.size();i++){
          temp << info[i]<< std::endl;
        }
      }

   //remove old contacts.txt and rename temp.txt to contacts
   remove("contacts.txt");
   rename("temp.txt", "contacts.txt");

   std::cout << "==========================================================" << std::endl;
   std::cout << "Deleting entry from file.." << std::endl;
   sleep(1);
   std::cout << "Successfully deleted from file!" << std::endl;
   std::cout << "==========================================================" << std::endl;

   sleep(2);

   std::string answer;
   std::cout << '\n' << "Return to Main Menu? (y/n): ";
   std::cin >> answer;
   if(answer != "y"){
     std::cout << "\n==========================================================" << std::endl;
     std::cout << "Thank you for using the Contact Managment System!" << std::endl;
     std::cout << "==========================================================" << std::endl;
     file.close();
     exit(0);
  }
   std::cin.ignore();

}

int main(){
  std::fstream file;
  std::string answer = "";

  //display welcomeing prompt and main menu
  std::cout << "**** Welcome to the Contact Managment System ****" << std::endl;

//loop contines until a 5 is entered to end the program
while(answer != "5"){

  std::cout << std::endl;
  std::cout << "                     MAIN MENU                 " << std::endl;
  std::cout << "           =============================       " << std::endl;
  std::cout << "            [1] Add a new Contact" << std::endl;
  std::cout << "            [2] List all Contacts" << std::endl;
  std::cout << "            [3] Edit a Contact" << std::endl;
  std::cout << "            [4] Delete a Contact" << std::endl;
  std::cout << "            [5] Exit" << std::endl;
  std::cout << "           =============================" << std::endl;

  std::cout << "\n > ";

  getline(std::cin, answer);

  //choose action based on answer
  if(answer == "1"){
        file.open("contacts.txt", std::fstream::app);
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
      file.open("contacts.txt");
      deleteContact(file);
      file.close();
    }
  if (answer == "5") {
      std::cout << "==========================================================" << std::endl;
      std::cout << "Thank you for using the Contact Managment System!" << std::endl;
      std::cout << "==========================================================" << std::endl;
      file.close();
    }

}


//close file at end just in case
file.close();


  return 0;
}
