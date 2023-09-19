#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum class status
{
    todo,
    ongoing,
    done
};

struct item
{
    // Detta är en constructor
    item(string name, status status) : name(name), status(status) {
    }

    // Det är en destructor
    ~item() {
    }

    string name;
    status status;
};

// Global vector to store task items
vector<item> my_items;

// Function to convert status enum to a string for printing
string enum_to_string(status status)
{
    switch (status)
    {
    case status::todo:
        return "todo";
    case status::ongoing:
        return "ongoing";
    case status::done:
        return "done";
    }
    cout << "error in enum_to_string" << endl;
    return "";
};

void console_print(string input) {
    cout << "Console: " << input << endl;
}

string console_input() {
    cout << "> ";
    string console_input;
    cin >> console_input;
    return console_input;
}

void print_menu() {
    cout << "~ Menu ~" << endl;
    cout << "1 Create item" << endl;
    cout << "2 Change item" << endl;
    cout << "3 Delete item" << endl;
    cout << "4 List items" << endl;
    cout << "5 Exit" << endl;
}

void print_list() {
    int i = 1;
    for (auto item : my_items) {
        cout << i << ". " << item.name << ", " << enum_to_string(item.status) << endl;
        i++;
    }
}

void menu_selection(string selection_string) {

    int selection = stoi(selection_string);
    switch (selection) {
    case 1: {
        cout << "Item name: ";
        string item_name;
        cin >> item_name;
        item new_item{ item_name, status::todo };
        my_items.push_back(new_item);
        cout << "Added new item to list: " << new_item.name << endl;
        system("pause");
        break;
    }

    case 2: {
        // Change item
        system("pause");
        break;
    }


    case 3: {
        // Delete item
        system("pause");
        break;
    }


    case 4: {
        print_list();
        system("pause");
        break;
    }

    case 5:{
        abort();
    }

    default: {
        cout << "Invalid selection" << endl;
        system("pause");
        break;
    }
    }
}

int main()
{
    cout << "Welcome to the todo-program!" << endl;
    print_menu();

    while (true)
    {
        auto input = console_input();
        menu_selection(input);
        print_menu();
    }

    return 0;
}