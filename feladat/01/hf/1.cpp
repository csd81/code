
#include <iostream>
#include <string>
namespace university {   
    struct subject         
    {             
    std::string code;
    unsigned int gradeCount;
    unsigned int* grades;         
    };

    void printSubject(const subject& s){
        std::cout << "Subject code: " << s.code << std::endl;
        std::cout << "Number of grades: " << s.gradeCount << std::endl;
        std::cout << "Grades: ";
        for (unsigned int i = 0; i < s.gradeCount; ++i)
        {
            std::cout << s.grades[i] << " ";
        }
        std::cout << std::endl;
    }

    double average(const subject& s){
        double sum = 0;
        for (unsigned int i = 0; i < s.gradeCount; i++){
            sum += s.grades[i];
            return  (double)sum / (double)s.gradeCount;
        }
    }
     
    void showHighestAverage(const subject* subjects, int size) { 
        int highestIndex =0;
        double highestAverage = average(subjects[0]);

        for (int i = 1; i < size; ++i)
        {
            double avg = average(subjects[i]);
            if (avg > highestAverage)
            {
                highestAverage = avg;
                highestIndex = i;
            }
        }
        printSubject(subjects[highestIndex]);
    }
}


 

void resize(subject& s, unsigned int newSize){
    unsigned int* newGrades = new unsigned int[newSize];
    for (unsigned int i = 0; i < newSize; ++i)
    {
        if (i < s.gradeCount) {
            newGrades[i] = s.grades[i];
        }
        else 
        {
            newGrades[i] = 5;
        }
    }
    delete[] s.grades;
    s.grades = newGrades;
    s.gradeCount = newSize;
}

 

void resize(subject& s, unsigned int newSize, unsigned int a, unsigned int b){
    unsigned int* newGrades = new unsigned int[newSize];
    for (unsigned int i = 0; i < newSize; ++i)
    {
        if (i < s.gradeCount)
        {
            newGrades[i] = s.grades[i];
        }
        else
        {
            newGrades[i] = (i % 2 == 0) ? a : b; 
        }
    }
    delete[] s.grades; 
    s.grades = newGrades;
    s.gradeCount = newSize;
}

 

 

void freeMemory(subject& s){
    delete[] s.grades; 
    s.grades = nullptr;  
}


using namespace university;
int main()
{
    subject subjects[3];
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Enter subject code: ";
        std::cin >> subjects[i].code;
        std::cout << "Enter number of grades: ";
        std::cin >> subjects[i].gradeCount;
        subjects[i].grades = new unsigned int[subjects[i].gradeCount];  
        for (unsigned int j = 0; j < subjects[i].gradeCount; ++j)
        {
            std::cout << "Enter grade " << j + 1 << ": ";
            std::cin >> subjects[i].grades[j];
        }
    }
    for (int i = 0; i < 3; ++i)    {    printSubject(subjects[i]);    } 
    std::cout << "The subject with the highest average  is:";
    showHighestAverage(subjects);
}

 