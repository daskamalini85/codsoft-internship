#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;

    // Input student names and grades
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        double grade;

        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> name;

        std::cout << "Enter the grade of student " << i + 1 << ": ";
        std::cin >> grade;

        students.push_back({name, grade});
    }

    // Calculate average grade
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.grade;
    }
    double average = sum / numStudents;

    // Find highest and lowest grades
    auto maxGrade = std::max_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });

    auto minGrade = std::min_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });

    // Display results
    std::cout << "Average grade: " << average << std::endl;
    std::cout << "Highest grade: " << maxGrade->grade << " ("
              << maxGrade->name << ")" << std::endl;
    std::cout << "Lowest grade: " << minGrade->grade << " ("
              << minGrade->name << ")" << std::endl;

    return 0;
}

