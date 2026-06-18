
 🏨 RoomNest – Hostel Accommodation Management System

   RoomNest is a console-based hostel management system built with C++ and file handling, designed to streamline room allocation and reservation tracking for hostels with     features like:
  
   ✅ Role-Based Authentication – Separate login portals for Admin and Student with credential validation from a persistent user database.
   
   🛏️ Smart Bed Reservation – Students can reserve available beds with real-time availability tracking and automatic inventory updates.
   
   🔒 Duplicate Booking Prevention – System checks reservation history to ensure each student can only reserve one bed, preventing overbooking.
   
   👨‍💼 Admin Dashboard – View hostel data including name, rent, and live bed availability at a glance.
   
   💾 Persistent File Storage – All hostel data, user credentials, and reservations are stored in text files ensuring data persists across sessions.
   
   🔄 Real-Time Inventory Sync – Bed count updates instantly in the hostel data file after every successful reservation.
   
🛠️ Tech Stack

   Language: C++ (OOP)
   
   Data Storage: File Handling (fstream – ifstream/ofstream)
  
   Concepts Used:
  
   - Object-Oriented Programming (Classes, Encapsulation, Constructors)
     
   - File I/O for persistent data management
     
   - Authentication & Authorization logic
     
   - Modular function design with separation of concerns
    

📈 Potential Use Cases

   🏫 Small hostels or PGs managing room allocation manually 
   
   🎓 University accommodation offices tracking bed availability
   
   🧑‍💻 C++ learners looking for a mini-project with file handling and OOP
   
   📋 Any small-scale inventory reservation system
   
 
🚀 How to Run

   g++ modification.cpp -o RoomNest
 
   ./RoomNest
