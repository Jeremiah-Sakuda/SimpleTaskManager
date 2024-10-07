# Task Manager

This is a simple task manager program written in C++ that allows you to manage a list of tasks. You can add tasks, view them, delete tasks, mark tasks as complete, and save/load tasks to/from a file.

## Features

- **Add a Task**: Add a task with a description and a due date.
- **View Tasks**: Display the list of all tasks along with their status (complete or incomplete).
- **Delete a Task**: Remove a specific task from the list.
- **Mark Task as Complete**: Update the status of a task to mark it as complete.
- **Save Tasks**: Save all tasks to a file (`tasks.txt`) for future use.
- **Load Tasks**: Automatically load tasks from the `tasks.txt` file when the program starts.

## Prerequisites

- A C++ compiler (e.g., g++)

## How to Compile and Run

1. **Compile the Program**:
    ```bash
    g++ -o task_manager task_manager.cpp

2. **Run the Program**:
    ```bash
    ./task_manager

## Menu Options

1. **Add Task**: Allows you to add a new task by providing a description and a due date (in `YYYY-MM-DD` format).
2. **View Tasks**: Displays the list of all tasks with their due dates and completion status.
3. **Delete Task**: Prompts you to enter the task number you want to delete from the list.
4. **Mark Task Complete**: Marks a selected task as complete.
5. **Save Tasks**: Saves the current list of tasks to the `tasks.txt` file.
0. **Exit**: Exits the program and saves the tasks automatically.

## File Structure

The tasks are stored in a plain text file (`tasks.txt`) in the following format:

task description|due date|completion status


- The description is a string of the task's description.
- The due date is in the `YYYY-MM-DD` format.
- The completion status is represented as `0` for incomplete and `1` for complete.

## Example Usage

When you run the program, you'll be presented with the following menu:

===== Task Manager =====

0. Add Task
1. View Tasks
2. Delete Task
3. Mark Task Complete
4. Save Tasks
5. Exit
Enter your choice:


You can interact with the menu by typing the corresponding number for each option.

## License

This project is licensed under the MIT License. 
