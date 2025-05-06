#include <iostream>
#include <string>

namespace university {

struct subject { // Structure to hold subject information
    std::string code;
    unsigned gradeCount;
    unsigned* grades;
};

void printSubject(const subject& s) { // Function to print subject information
    std::cout << s.code << " (" << s.gradeCount << " grades): ";  // Print subject code and number of grades
    for (unsigned i = 0; i < s.gradeCount; ++i) // Loop through grades
        std::cout << s.grades[i] 
                    << (i + 1 < s.gradeCount ? ' ' : '\n'); // Print grades with space or newline
}

double average(const subject& s) { // Function to calculate average of grades
    if (s.gradeCount == 0) return 0.0;
    double sum = 0.0;
    for (unsigned i = 0; i < s.gradeCount; ++i)
        sum += s.grades[i];
    return sum / s.gradeCount;
}

void showHighestAverage(const subject* subjects, unsigned size) { // Function to find and print the subject with the highest average
    if (size == 0) return;
    unsigned idx = 0;
    double maxAvg = average(subjects[0]);
    for (unsigned i = 1; i < size; ++i) {
        double avg = average(subjects[i]);
        if (avg > maxAvg) {
            maxAvg = avg;
            idx = i;
        }
    }
    std::cout << "Highest average is " << maxAvg << " for subject:\n";
    printSubject(subjects[idx]);
}

void resize(subject& s, unsigned newSize) { // Function to resize the grades array
    unsigned* newGrades = new unsigned[newSize];
    unsigned minCount = s.gradeCount < newSize ? s.gradeCount : newSize;
    // Copy existing grades
    for (unsigned i = 0; i < minCount; ++i)
        newGrades[i] = s.grades[i];
    // Fill new slots with 5
    for (unsigned i = minCount; i < newSize; ++i)
        newGrades[i] = 5;
    delete[] s.grades;
    s.grades = newGrades;
    s.gradeCount = newSize;
}

void resize(subject& s, unsigned newSize, unsigned a, unsigned b) {  // Overloaded function to resize with alternating values
    unsigned* newGrades = new unsigned[newSize];
    unsigned minCount = s.gradeCount < newSize ? s.gradeCount : newSize;
    for (unsigned i = 0; i < minCount; ++i)
        newGrades[i] = s.grades[i];
    // Fill new slots alternately with a and b
    for (unsigned i = minCount; i < newSize; ++i)
        newGrades[i] = ((i - minCount) % 2 == 0) ? a : b;
    delete[] s.grades;
    s.grades = newGrades;
    s.gradeCount = newSize;
}

void freeMemory(subject& s) { // Function to free memory allocated for grades
    delete[] s.grades;
    s.grades = nullptr;
    s.gradeCount = 0;
}

} // namespace university

using namespace university; 

int main() { // Main function
    constexpr unsigned SUBJECT_COUNT = 3;
    subject subjects[SUBJECT_COUNT];

    // Read subjects
    for (unsigned i = 0; i < SUBJECT_COUNT; ++i) {
        std::cout << "Subject code: ";
        std::cin >> subjects[i].code;
        std::cout << "Number of grades: ";
        std::cin >> subjects[i].gradeCount;
        subjects[i].grades = new unsigned[subjects[i].gradeCount];
        std::cout << "Enter grades: ";
        for (unsigned j = 0; j < subjects[i].gradeCount; ++j)
            std::cin >> subjects[i].grades[j];
    }

    // Print subjects
    std::cout << "\nInitial subjects:\n";
    for (unsigned i = 0; i < SUBJECT_COUNT; ++i)
        printSubject(subjects[i]);

    // Show highest average
    std::cout << '\n';
    showHighestAverage(subjects, SUBJECT_COUNT);

    // Resize subjects
    for (unsigned i = 0; i < SUBJECT_COUNT; ++i) {
        unsigned newSize;
        std::cout << "\nNew size for " << subjects[i].code << ": ";
        std::cin >> newSize;
        resize(subjects[i], newSize);
    }

    // Print subjects after resizing
    std::cout << "\nSubjects after resizing:\n";
    for (unsigned i = 0; i < SUBJECT_COUNT; ++i)
        printSubject(subjects[i]);

    // Clean up
    for (unsigned i = 0; i < SUBJECT_COUNT; ++i)
        freeMemory(subjects[i]);

    return 0;
}
 
