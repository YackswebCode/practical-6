#### `student.h`

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Subject {
public:
    string name;
    int marks;

    Subject(string name, int marks) : name(name), marks(marks) {}
};

class Student {
public:
    string name;
    int rollNumber;
    vector<Subject> subjects;

    Student(string name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    void addSubject(string subjectName, int marks) {
        subjects.push_back(Subject(subjectName, marks));
    }

    int getTotalMarks() {
        int total = 0;
        for (Subject& subject : subjects) {
            total += subject.marks;
        }
        return total;
    }

    double getAverageMarks() {
        if (subjects.empty()) return 0.0;
        return getTotalMarks() / static_cast<double>(subjects.size());
    }
};

#endif // STUDENT_H
