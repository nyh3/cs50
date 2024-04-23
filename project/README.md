# SemesterSync - Organize Your Academic Life

#### Video Demo: [Watch Demo](https://youtu.be/R5scoGwv0VQ?si=gmIrnirWnkFyCUwC)

## Description

SemesterSync is a comprehensive web application designed to streamline and enhance the organization of academic information for students. It provides a suite of features to effectively manage modules, schedules, and todos.

## Features

- **User Authentication:** Robust user authentication powered by Firebase Authentication.
- **Dashboard Overview:** A centralized dashboard offering a quick and insightful overview of enrolled modules.
- **Module Management:** Seamlessly add, edit, and manage academic modules with detailed information such as quiz dates, midterm dates, finals dates, and additional context.
- **Todo List Management: ** Seamlessly add, remove and check your todo list to help you keep track of what you must do.

### Module Management

#### Add a New Module:

1. Click on the "Add Module" button on the dashboard.
2. Fill in essential module details, including module code and optional information like quiz dates, midterm dates, finals dates, etc.
3. Click the "Add Module" button to save the new module to your dashboard.
4. The newly added module will be displayed on your dashboard for quick access.

#### Edit a Module:

1. Navigate to the module you wish to modify on the dashboard.
2. Click on the "Edit" button associated with the selected module.
3. Update module details, such as module code, quiz dates, and additional information.
4. Click "Update Module" to save your changes.
5. Your module details will be instantly updated, ensuring accurate and up-to-date academic information.

## Todo List

SemesterSync's Todo List is a powerful task management tool that allows users to efficiently organize their tasks, providing flexibility and customization for an optimized user experience.

### Features

- **Add a New Todo:**
  - Enter the details of your new task, including the task name, due date, and priority.
  - Click the "Add Todo" button to save the task to your Todo List.

- **Complete or Delete a Todo:**
  - Toggle the checkbox next to each task to mark it as complete.
  - Click the "Delete" button associated with a task to remove it from your Todo List.

- **Priority Levels:**
  - Each todo item can be assigned a priority level, helping you categorize and prioritize tasks based on their urgency or importance.
  - Priority levels include "Low," "Medium," and "High."

- **Filter by Priority:**
  - Use the priority filter to view tasks based on their priority level.
  - Easily focus on specific priority levels, allowing for better task management.

- **Sort by Priority or Due Date:**
  - Sort your Todo List based on priority or due date, providing flexibility in organizing tasks according to your preferences.
  - This sorting feature ensures that you can address high-priority tasks promptly while staying on top of impending deadlines.

### Usage

1. Access the Todo List page (`/todos`) from the dashboard.
2. **Add a New Todo:**
   - Enter the task details, including the task name, due date, and priority level.
   - Click "Add Todo" to save the new task.

3. **Complete or Delete a Todo:**
   - Toggle the checkbox to mark a task as complete.
   - Click "Delete" to remove a task from your Todo List.

4. **Filter by Priority:**
   - Utilize the priority filter options to view tasks based on their priority level.
   - Filter by "Low," "Medium," "High," or view all tasks collectively.

5. **Sort by Priority or Due Date:**
   - Choose to sort tasks based on priority or due date.
   - Sorting options include "Priority" and "Due Date."

SemesterSync's Todo List empowers you to manage your tasks effectively, providing a dynamic and user-friendly interface for streamlined task organization.


## Usage

### Login

1. Access the login page by navigating to `/login`.
2. Enter your email address and password.
3. Click the "Login" button to authenticate.
4. For first-time users, navigate to the register account page from the login page.

### Register

1. Access the registration page by navigating to `/register`.
2. Enter your email address and password.
3. A new account will be created, and you can proceed to the login page.

### Dashboard

1. After login, you will be redirected to the dashboard (`/dashboard`).
2. Get a comprehensive overview of enrolled modules.
3. Access the logout and todo buttons at the top below the header bar.

## Built With

- **React:** A powerful JavaScript library for building user interfaces.
- **Firebase:** Backend services for secure user authentication and database storage.
- **React Router:** Declarative routing for React applications.
