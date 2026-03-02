# include <iostream>
# include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_formatted10(string s) {
	for (long unsigned int j = 0 ; j < 10; j++) {
      if (s.size() > j) {
      	if (j == 9 && s.size()  > 9) {
        	cout << ".";
        } else {
        	cout << s[j];
        }
      } else {
        cout << " ";
      }
	}
}

class Contact {
	private:
    	string name;
        string lastName;
        string nickname;
	public:
    Contact () {
    	this->name = "";
    	this->lastName = "";
        this->nickname = "";
    }
    Contact (string name, string lastName, string nickname) {
    	this->name = name;
    	this->lastName = lastName;
        this->nickname = nickname;
    }
    string getName(void) {
    	return name;
    }
    string getLastName(void) {
    	return lastName;
    }
    string getNickname(void) {
    	return lastName;
    }
    void setName (string name) {
    	this->name = name;
    }
    void setLastName (string lastName) {
    	this->lastName = lastName;
    }
    void setNickname (string nickname) {
    	this->nickname = nickname;
    }
};

class PhoneBook {
  private:
    Contact contacts[8];
    int contactSize;
  public:
    PhoneBook() {
        contactSize = 0;
    }
  	Contact *getContacts(void) {
     	return contacts;
    }
    void addContact(void) {
        string firstName;
        string lastName;
        string nickname;

        cout << "First Name:  ";
        getline(cin, firstName);
        cout << "Last Name:  ";
        getline(cin, lastName);
        cout << "Nickname:  ";
        getline(cin, nickname);

        contacts[contactSize].setName(firstName);
        contacts[contactSize].setLastName(lastName);
        contacts[contactSize].setNickname(nickname);
    	cout << "new contact " << firstName << " added." << endl;
        if (contactSize < 7)
            contactSize++;
    }
    void printAllContacts(void) {
    	if (contactSize == 0) {
        	cout << "The phonebook is empty. " << endl;
            return;
        }
        cout << "index     |first name|last name |nickname ";
    	for (int i = 0; i < contactSize; i++) {
        	cout << i << "         |";
            print_formatted10(contacts[i].getName());
            cout << "|";
            print_formatted10(contacts[i].getLastName());
            cout << "|";
            print_formatted10(contacts[i].getNickname());
        }
    }
    void search(void) {
    	string input;

        cout << "search index:" << endl;
        getline(cin, input);
        cout << endl;

        if (input.size() != 1 || input[0] - '0' < 0 || input[0] - '0' >= 8) {
        	cout << "bad use!" << endl;
            return;
		}

        int index = input[0] - '0';
        
        if (index <= contactSize) {
            Contact *contact = &contacts[index];
        	cout << "First Name: " << contact->getName() << endl;
        	cout << "Last Name: " << contact->getLastName() << endl;
        	cout << "Nickname: " << contact->getNickname() << endl << endl;
		} else {
            cout << "no such contact :(" << endl;
        }
    }
};

int main() {
	PhoneBook phonebook = PhoneBook();

    cout << "Comands : " << endl << "	ADD: save a new contact" << endl << "	SEARCH: display a specific contact" << endl << "	EXIT" << endl;

    cout << "The phonebook is empty. " << endl;

    string input;
    while (input != "EXIT") {
    	cout << "> ";
    	getline(cin, input);

        if (input == "ADD") {
            phonebook.addContact();
        } else if (input == "SEARCH") {
            phonebook.search();
        }
    }
	
    cout << endl;
	
  return 0;
}
