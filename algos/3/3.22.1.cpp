// 3.22. Ösztöndíj
// 3.22.1. Írjon programot, amely kiszámítja a hallgatók ösztöndíját a 
// tanulmányi átlaguk alapján! Fájl tartalmazza a hallgatók adatait: neptun 
// kódjukat, és a tárgyaik kreditértékét, illetve a szerzett érdemjegyeket. 
// A program írja ki a képernyőre minden hallgató esetében a neptun kódot, a 
// felvett tárgyak számát, a szerzett érdemjegyek kredittel súlyozott 
// átlagát, a felvett és a teljesített kreditek összegét, és a hallgató 
// számára megítélt ösztöndíjat! Egy tárgy teljesített, ha a hallgató 
// átment az adott tárgyból. Az átlagba a felvett tárgyak és nem a 
// teljesítettek tartoznak. Az ösztöndíjak összege: · 0 <= átlag < 2 → 0 
// HUF · 2 <= átlag < 3 → 15 000 HUF · 3 <= átlag < 4 → 20 000 HUF · 4 <= 
// átlag < 4.5 → 25 000 HUF · 4.5 <= átlag <= 5 → 30 000 HUF Az input fájl 
// formátuma: Első sor: A hallgatók száma. A hallgatók adatait tartalmazó 
// sor: Sztring number1 Az egyes tárgyakhoz tartozó sor: number2 number3 Példa 
// bemenet: 2 TGDS32 3 4 2 3 5 3 4 FBG4SW 3 4 5 2 3 4 1 A TGDS32 és FBG4SW neptun 
// kódú hallgató adatait látjuk. TGDS32 3 tárgyat vett fel, az első tárgya 
// 4 kredit értékű, az érdemjegye belőle 2. Kimenet: Neptun: TGDS32 3 
// subjects Neptun: FBG4SW 3 subjects TGDS32: Credits: 10/10 Average: 3.5 Bursary: 
// 20000 HUF FBG4SW: Credits: 10/6 Average: 3 Bursary: 20000 HUF 
// 3.22.1.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

const std::string INPUT_FILE = "students.txt";

// Ösztöndíj szintek
const double MIN_AVERAGE = 2.0;
const double MIDDLE_AVERAGE = 3.0;
const double GOOD_AVERAGE = 4.0;
const double EXCELLENT_AVERAGE = 4.5;

const int MIN_BURSARY = 15000;
const int MIDDLE_BURSARY = 20000;
const int GOOD_BURSARY = 25000;
const int EXCELLENT_BURSARY = 30000;

// Tárgy
struct Subject {
    int credit;
    int mark;
};

// Hallgató
struct Student {
    std::string neptun;
    std::vector<Subject> subjects;
};

// Hallgató beolvasása fájlból
void readStudent(std::ifstream& in, Student& student) {
    int subjCount;
    in >> student.neptun >> subjCount;
    std::cout << "Neptun: " << student.neptun << " " << subjCount << " subjects" << std::endl;

    for (int i = 0; i < subjCount; ++i) {
        Subject s;
        in >> s.credit >> s.mark;
        student.subjects.push_back(s);
    }
}

// Ösztöndíj számítás
void calculateAndDisplay(const std::vector<Student>& students) {
    for (const auto& student : students) {
        int sumCredits = 0;
        int passedCredits = 0;
        int weightedSum = 0;

        for (const auto& subj : student.subjects) {
            weightedSum += subj.credit * subj.mark;
            sumCredits += subj.credit;
            if (subj.mark >= 2)
                passedCredits += subj.credit;
        }

        double average = static_cast<double>(weightedSum) / sumCredits;

        int bursary = 0;
        if (average >= 2.0 && average < 3.0)
            bursary = MIN_BURSARY;
        else if (average < 4.0)
            bursary = MIDDLE_BURSARY;
        else if (average < 4.5)
            bursary = GOOD_BURSARY;
        else if (average <= 5.0)
            bursary = EXCELLENT_BURSARY;

        std::cout << student.neptun << ":\n"
                  << "\tCredits: " << sumCredits << "/" << passedCredits << "\n"
                  << "\tAverage: " << std::fixed << std::setprecision(2) << average << "\n"
                  << "\tBursary: " << bursary << " HUF\n";
    }
}

int main() {
    std::ifstream infile(INPUT_FILE);
    if (!infile) {
        std::cerr << "Error opening file: " << INPUT_FILE << std::endl;
        return 1;
    }

    int studentCount;
    infile >> studentCount;

    std::vector<Student> students(studentCount);
    for (int i = 0; i < studentCount; ++i) {
        readStudent(infile, students[i]);
    }

    calculateAndDisplay(students);

    return 0;
}

