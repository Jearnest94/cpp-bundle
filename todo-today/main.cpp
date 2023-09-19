#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

// [CURRENTLY UNUSED] Function to print string to console
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
    cout << "3 Remove item" << endl;
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

void change_item_status() {
    cout << "Current list of items:" << endl;
    print_list();

    cout << "Enter the number of the item you want to change: ";
    int item_number;
    cin >> item_number;

    if (item_number < 1 || item_number > my_items.size()) {
        cout << "Invalid item number." << endl;
        return;
    }

    cout << "Change status to (1: todo, 2: ongoing, 3: done): ";
    int new_status_value;
    cin >> new_status_value;

    my_items[item_number - 1].status = static_cast<status>(new_status_value - 1);
    cout << "Status of item updated." << endl;
}

void remove_item() {
    cout << "Current list of items:" << endl;
    print_list();

    cout << "Enter the number of the item you want to remove: ";
    int item_number;
    cin >> item_number;

    if (item_number < 1 || item_number > my_items.size()) {
        cout << "Invalid item number." << endl;
        return;
    }

    my_items.erase(my_items.begin() + item_number - 1);

    cout << "Item removed from the list." << endl;
}

void save_list_to_file() {
    ofstream outfile("todolist.txt");

    if (outfile.is_open()) {
        for (const auto& task : my_items) {
            outfile << task.name << "," << static_cast<int>(task.status) << endl;
        }
        outfile.close();
        cout << "List saved to 'todolist.txt'." << endl;
    } else {
        cout << "Unable to save the list." << endl;
    }
}

void load_list_from_file() {
    ifstream infile("todolist.txt");
    my_items.clear(); 

    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            size_t comma_pos = line.find(',');
            if (comma_pos != string::npos) {
                string task_name = line.substr(0, comma_pos);
                int task_status = stoi(line.substr(comma_pos + 1));
                my_items.push_back({task_name, static_cast<status>(task_status)});
            }
        }
        infile.close();
        cout << "List loaded from 'todolist.txt'." << endl;
    } else {
        cout << "Unable to load the list. Starting with an empty list." << endl;
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
        change_item_status();
        system("pause");
        break;
    } 
    case 3: {
        remove_item();
        system("pause");
        break;
    } 
    case 4: {
        print_list();
        system("pause");
        break;
    } 
    case 5:{
        save_list_to_file();
        exit(0);
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
    load_list_from_file();
    print_menu();

    while (true)
    {
        auto input = console_input();
        menu_selection(input);
        print_menu();
    }

    return 0;
}