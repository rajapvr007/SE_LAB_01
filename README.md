# SE_LAB_01

# 🎓 Student Result Processing System (Modular C Application)

## 📌 Problem Statement

Design and implement a **modular Student Result Processing System** in **C language** that reads student details from a file, validates the data, computes results, and generates a comprehensive class report by following **software engineering principles**.

---

## 🎯 Objectives

- Apply **modular programming** with low coupling and high cohesion
- Read and validate student data from a file
- Compute total marks, percentage, grade, and CGPA
- Generate individual student result sheets
- Analyze and report class performance statistics

---

## 📂 Project Structure

~~~
StudentResultSystem/
│
├── include/
│   ├── student.h
│   ├── validation.h
│   ├── grading.h
│   ├── fileio.h
│   └── statistics.h
│
├── src/
│   ├── student.c
│   ├── validation.c
│   ├── grading.c
│   ├── fileio.c
│   ├── statistics.c
│   └── main.c
│
├── input.txt
├── output.txt
└── README.md
~~~

---
## 🧩 Features & Requirements

### 1️⃣ Input & Validation

- Accept details for **N students** (input taken from a file)
- For each student:
  - **Student ID**
    - Must be **unique**
    - Must be **alphanumeric**
    - No special characters allowed
  - **Student Name**
    - Only alphabets allowed
  - **Marks in 5 Subjects**
    - Minor Exam: **40 Marks**
    - Major Exam: **60 Marks**
    - Valid range: **0 – 100**

#### ❌ Invalid Data Handling

- Invalid Student IDs (special characters, duplicates) are rejected
- Names containing digits or symbols are rejected
- Marks outside valid range are rejected or ignored with warning

---

### 2️⃣ Computation

- Calculate:
  - **Total Marks**
  - **Percentage**
  - **CGPA**
- **Minimum passing marks:** 50% in each subject

#### 🎓 Grade Assignment

| Percentage Range | Grade |
| ---------------- | ----- |
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

- Generates a **formatted result sheet** for each student
- Displays:
  - Student ID and Name
  - Subject-wise marks and grades
  - Total marks, percentage, and CGPA

#### 📊 Class Statistics

- Average percentage of the class
- Highest and lowest percentage
- Grade distribution (O, A+, A, B+, B, C, F)

---

### 4️⃣ Modular Design

The application is divided into the following modules:

| Module     | Description                                 |
| ---------- | ------------------------------------------- |
| Validation | Input validation for ID, name, and marks    |
| Grading    | Grade assignment and grade-point conversion |
| Student    | CGPA calculation                            |
| File I/O   | Reading input and writing output files      |
| Statistics | Class statistics and grade distribution     |

Each module:

- Is separately compilable
- Has high cohesion and low coupling
- Can be reused in other applications

---

## 🛠️ Compilation & Execution

### Compile
```bash
gcc src/\*.c -Iinclude -o result
./result

```
---

## 🧪 Test Plan

A detailed test plan has been prepared.
The test plan covers validation, computation, grading, and statistics modules.

🔗 Full Test Plan (Google Sheets):
[Click here to view the Test Plan](https://docs.google.com/spreadsheets/d/1kKZ_ZBqErOd8GxvnwvV5KduzpX6l5KA0HgyudPgEbDg/edit?usp=sharing)
