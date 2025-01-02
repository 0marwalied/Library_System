#include <iostream>
#include <algorithm>

using namespace std;

const int mxNum = 100;

struct book {
	int id, quantity, borrowed;
	string name;
	string userNames[mxNum];
	book() {id = 0, quantity = 0, borrowed = 0, name = "";}
	void print() {
		cout << "id = " << id << " name = " << name << " total_quantity "
		     << quantity << " total_borrowed " << borrowed << '\n';
	}
};

struct user {
	int id, borrowed;
	string name;
	int bookIds[mxNum];
	user() {id = 0, borrowed = 0, name = "";}
	void print() {
		cout << "user " << name << " id " << id << " borrowed books ids: ";
		for (int book = 0; book < borrowed; book++) {
			cout << bookIds[book] << " ";
		}
		cout << '\n';
	}
};

bool checkPrefix(const string &prefix, const string &needed) {
	if (prefix.size() > needed.size())
		return false;
	for (int it = 0; it < prefix.size(); it++) {
		if (prefix[it] != needed[it])
			return false;
	}
	return true;
}

bool byId(const book &first, const book &second) {
	return first.id <= second.id;
}

bool byName(const book &first, const book &second) {
	return first.name <= second.name;
}


struct Library {
	int curBook, curUser;
	book books[mxNum];
	user users[mxNum];
	library() {curBook = 0, curUser = 0;}

	void menu() {
		cout << "Library Menu:\n";
		cout << "1) add_book\n";
		cout << "2) search_books_by_prefix\n";
		cout << "3) print_who_borrowed_book_by_name\n";
		cout << "4) print_library_by_id\n";
		cout << "5) print_library_by_name\n";
		cout << "6) add_user\n";
		cout << "7) user_borrow_book\n";
		cout << "8) user_return_book\n";
		cout << "9) print_users\n";
		cout << "10) Exit\n";
	}

	void add_book() {
		book temp;
		cout << "Enter book info: id & name & total quantity: ";
		cin >> temp.id >> temp.name >> temp.quantity;
		books[curBook++] = temp;
		cout << '\n';
	}

	void search_books_by_prefix() {
		cout << "Enter book name prefix: ";
		string prefix; cin >> prefix;
		cout << '\n';
		bool found = false;
		for (int Book = 0; Book < curBook; Book++) {
			if (checkPrefix(prefix, books[Book].name)) {
				cout << books[Book].name << '\n';
				found = true;
			}
		}
		if (!found)
			cout << "No book with such prefix\n";
		cout << '\n';
	}

	void print_who_borrowed_book_by_name() {
		cout << "Enter book name: ";
		string bookName; cin >> bookName;
		bool found = false;
		for (int Book = 0; Book < curBook; Book++) {
			if (books[Book].name == bookName) {
				found = true;
				for (int user = 0; user < books[Book].borrowed; user++) {
					cout << books[Book].userNames[user] << '\n';
				}
			}
		}
		if (!found)
			cout << "Invalied book\n";
		cout << '\n';
	}

	void print_library_by_id() {
		book temp[mxNum] = books;
		sort(temp, temp + curBook, byId);
		for (int Book = 0; Book < curBook; Book++) {
			temp[Book].print();
		}
		cout << '\n';
	}

	void print_library_by_name() {
		book temp[mxNum] = books;
		sort(temp, temp + curBook, byName);
		for (int Book = 0; Book < curBook; Book++) {
			temp[Book].print();
		}
		cout << '\n';
	}

	void add_user() {
		user temp;
		cout << "Enter book info: name & national id: ";
		cin >> temp.name >> temp.id;
		users[curUser++] = temp;
		cout << '\n';
	}

	void user_borrow_book() {
		cout << "Enter user name and book name: ";
		string userName, bookName;
		cin >> userName >> bookName;
		int bookId = -1;
		for (int Book = 0; Book < curBook; Book++) {
			if (books[Book].name == bookName) {
				bookId = books[Book].id;
				books[Book].userNames[books[Book].borrowed++] = userName;
			}
		}
		for (int User = 0; User < curUser; User++) {
			if (users[User].name == userName) {
				users[User].bookIds[users[User].borrowed++] = bookId;
			}
		}
		cout << '\n';
	}

	void user_return_book() {
		cout << "Enter user name and book name: ";
		string userName, bookName;
		cin >> userName >> bookName;
		bool bookFounded = false;
		bool userFounded = false;
		int bookId = -1;
		for (int Book = 0; Book < curBook; Book++) {
			if (books[Book].name == bookName) {
				bookFounded = true;
				userFounded = false;
				bookId = books[Book].id;

				for (int user = 0; user < books[Book].borrowed; user++) {
					if (books[Book].userNames[user] == userName)
						userFounded = true;
					if (userFounded)
						books[Book].userNames[user] = books[Book].userNames[user + 1];
				}

				if (userFounded)
					books[Book].borrowed--;
			}
		}

		for (int user = 0; user < curUser; user++) {
			if (users[user].name == userName) {
				userFounded = true;
				bookFounded = false;

				for (int book = 0; book < users[user].borrowed; book++) {
					if (users[user].bookIds[book] == bookId)
						bookFounded = true;
					if (bookFounded)
						users[user].bookIds[book] = users[user].bookIds[book + 1];
				}

				if (bookFounded)
					users[user].borrowed--;
			}
		}

		cout << '\n';
	}

	void print_users() {
		for (int user = 0; user < curUser; user++) {
			users[user].print();
		}
		cout << '\n';
	}

	void callFunction() {
		cout << "Enter your menu choice [1 - 10]: ";
		int choice; cin >> choice;
		if (choice == 1) add_book();
		if (choice == 2) search_books_by_prefix();
		if (choice == 3) print_who_borrowed_book_by_name();
		if (choice == 4)print_library_by_id();
		if (choice == 5)print_library_by_name();
		if (choice == 6)add_user();
		if (choice == 7)user_borrow_book();
		if (choice == 8)user_return_book();
		if (choice == 9)print_users();
		if (choice)system("exit");
	}
};

int main() {

	Library library;
	library.menu();
	while(true){
		library.callFunction();
	}


}
