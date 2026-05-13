# Electricity Billing System (OOP)

A comprehensive utility management system developed in C++ that leverages Object-Oriented Programming (OOP) principles to handle customer data, bill calculations based on usage slabs, and payment processing.

## 🔑 OOP Concepts Implemented
- **Inheritance:** Uses multiple and hierarchical inheritance (e.g., `Payment` class inheriting from both `Customer` and `BillCheck`).
- **Encapsulation:** Protected and private data members ensure secure data handling within classes.
- **Polymorphism:** Implementation of `virtual` functions for calculation logic.
- **Abstraction:** Modular class design to separate customer management from billing logic.

## 🚀 Key Features
- **Secure Login:** Administrative access control for system operations.
- **Customer Management:** Full CRUD (Create, Read, Update, Delete) functionality for customer profiles.
- **Dynamic Billing:** Automated calculation based on consumption slabs (0-100, 101-200, etc.).
- **Payment Processing:** Supports both Cash and Online payment simulations with 14-digit account validation.
- **File Handling:** Persistent storage for payment history in `bill_history.txt`.
- **ASCII UI:** Clean console-based interface with clear screen functionality.

## 🛠️ Technical Stack
- **Language:** C++
- **Libraries:** `<iostream>`, `<fstream>`, `<iomanip>`, `<string>`
- **Storage:** Text-based flat-file database

## 📖 How to Run
1. Compile the `Electricity Billing System.cpp` file using any standard C++ compiler (GCC/MinGW).
2. Use the default credentials:
   - **Username:** `customer`
   - **Password:** `rnh245`
