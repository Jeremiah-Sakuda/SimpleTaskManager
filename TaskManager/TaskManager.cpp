#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task {
    string description;
    string dueDate;
    bool isComplete;

    Task(string desc, string date) : description(desc), dueDate(date), isComplete(false) {}
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void markTaskComplete(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    loadTasks(tasks);  // Load tasks from file

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline after the choice

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            markTaskComplete(tasks);
            break;
        case 5:
            saveTasks(tasks);
            cout << "Tasks saved successfully!" << endl;
            break;
        case 0:
            saveTasks(tasks);  // Save before exiting
            cout << "Exiting and saving tasks..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\n===== Task Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Mark Task Complete" << endl;
    cout << "5. Save Tasks" << endl;
    cout << "0. Exit" << endl;
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    string description, dueDate;

    cout << "Enter task description: ";
    getline(cin, description);
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, dueDate);

    tasks.emplace_back(description, dueDate);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }

    cout << "\n===== Task List =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
            << " | Due: " << tasks[i].dueDate
            << " | Status: " << (tasks[i].isComplete ? "Complete" : "Incomplete") << endl;
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;
    cin.ignore();  // Ignore newline

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!" << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

// Function to mark a task as complete
void markTaskComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as complete." << endl;
        return;
    }

    int index;
    cout << "Enter the task number to mark as complete: ";
    cin >> index;
    cin.ignore();  // Ignore newline

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].isComplete = true;
        cout << "Task marked as complete!" << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

// Function to save tasks to a file
void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    for (const auto& task : tasks) {
        file << task.description << "|" << task.dueDate << "|" << task.isComplete << endl;
    }

    file.close();
}

// Function to load tasks from a file
void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.rfind('|');

        string description = line.substr(0, pos1);
        string dueDate = line.substr(pos1 + 1, pos2 - pos1 - 1);
        bool isComplete = (line.substr(pos2 + 1) == "1");

        tasks.emplace_back(description, dueDate);
        tasks.back().isComplete = isComplete;
    }

    file.close();
}
