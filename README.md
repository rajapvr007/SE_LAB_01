# SE_LAB_01
# 🎓 Student Result Processing System (C Language)

## 📌 Problem Statement
Design and implement a **Student Result Processing System** in **C** that reads student details from a file, validates the data, computes results, and displays a comprehensive report.

---

## 🎯 Objectives
- Read and validate student data from a file
- Compute total marks, percentage, grade, and CGPA
- Generate a tabular result report
- Analyze class performance statistics

---

## 🧩 Features & Requirements

### 1️⃣ Input & Validation
- Accept details for **N students** (input taken from a file)
- For each student, the following details are required:
  - **Student ID**
    - Must be **unique**
    - Must be **alphanumeric**
    - No special characters allowed
  - **Student Name**
    - Only alphabets allowed
    - No digits or special characters
  - **Marks in 5 Subjects**
    - Minor Exam: **40 Marks**
    - Major Exam: **60 Marks**
    - Valid range: **0 – 100**

#### ❌ Invalid Data Handling
- Reject duplicate or invalid Student IDs
- Reject names containing digits or symbols
- Reject marks outside the valid range

---

### 2️⃣ Computation
- Calculate:
  - **Total Marks**
  - **Percentage**
- **Minimum passing marks:** 50% in each subject

#### 🎓 Grade Assignment
| Percentage Range | Grade |
|------------------|-------|
| ≥ 90             | O     |
| 85 – 90          | A+    |
| 75 – 85          | A     |
| 65 – 75          | B+    |
| 60 – 65          | B     |
| 55 – 60          | C     |
| 50 – 55          | D     |
| < 50             | F     |

---

### 3️⃣ Output & Reporting
- Display a **tabular report** containing:
  - Student ID
  - Name
  - Marks (All Subjects)
  - Total Marks
  - Percentage
  - Grade
  - CGPA

#### 📊 Class Statistics
- Class average percentage
- Highest percentage
- Lowest percentage
- Number of students in each grade category

---

### 4️⃣ Additional Requirements
- Use **modular programming**
  - Separate functions for:
    - Input
    - Validation
    - Computation
    - Output
- Use **structures** to represent student details
- Use **files** for storing and reading student data
- Proper **error handling**
  - Re-prompt or reject invalid data

---

## 🛠️ Technologies Used
- Programming Language: **C**
- Concepts:
  - Structures
  - File Handling
  - Functions
  - Arrays
  - Conditional Logic

---

## 📁 Project Structure
