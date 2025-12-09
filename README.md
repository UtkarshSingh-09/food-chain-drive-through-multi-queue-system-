# Fast Food Drive-Thru Simulation 🍔🍟

A C-based simulation of a multi-counter drive-thru system. This program uses **Circular Queues** to manage customer orders and implements an intelligent **Load Balancing** algorithm to assign new customers to the counter with the least estimated waiting time.

## 📋 Features

* **Multi-Counter System:** Simulates 3 distinct service counters running in parallel.
* **Smart Queue Assignment:** Customers are not assigned to the shortest line by *headcount*, but by **total preparation time**. The system calculates the wait time of every queue and assigns the new customer to the fastest one.
* **Circular Queue Implementation:** Efficient memory usage using array-based circular queues.
* **Interactive Menu:** Simple CLI interface to add customers, serve orders, and view queue status.
* **Data Tracking:** Tracks Customer ID, Order Name, and Preparation Time.

## 🛠️ Data Structures

### 1. `Customer`
Stores individual order details:
* `id`: Unique sequential ID.
* `orderName`: Description of the food.
* `prepTime`: Time required to fulfill the order (in minutes).

### 2. `CounterQueue`
Represents a checkout counter:
* `queue[MAX]`: Array storing `Customer` objects.
* `front` / `rear`: Pointers for circular queue management.
* `count`: Current number of people in the line.

## 🚀 How to Compile and Run

You need a standard C compiler (like GCC or Clang) to run this program.

### 1. Save the file
Save your C code as `drive_thru.c`.

### 2. Compile
Open your terminal or command prompt and run:
```bash
gcc drive_thru.c -o drive_thru
