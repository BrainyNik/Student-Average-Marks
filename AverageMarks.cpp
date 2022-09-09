#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
// to use the setw method
#include<iomanip>

using namespace std;
double GetAverage(string marks)
{
    // Marks has string like 70,80,90
    istringstream iss2(marks);
    string marks_of_each_sub;
    int sum = 0;

    while (!iss2.eof())
    {
        getline(iss2, marks_of_each_sub, ',');
        sum = sum + stoi(marks_of_each_sub);
    }
    double average = (double)sum / 3;

    return average;
}
char getGrade(double average)
{
    if (average >= 90.00)
    {
        return 'A';
    }
    else if (average >= 80.00 && average <= 90.00)
    {
        return 'B';
    }
    else if (average >= 70.00 && average <= 80.00)
    {
        return 'C';
    }
    else if (average >= 60.00 && average <= 70.00)
    {
        return 'D';
    }
    else if (average >= 50.00 && average <= 60.00)
    {
        return 'F';
    }
    else
    {
        return 'E';
    }
}
int main()
{
    ofstream fout;
    ifstream fin;
    fin.open("txts/data1.txt");
    if (fin.fail())
    {
        cout << "Error while opening the file." << endl;
        exit(1);
    }
    fout.open("txts/result.txt");
    if (fout.fail())
    {
        cout<<"Error while opening the output file.."<<endl;
        exit(1);
    }
    
    // to read the entire file line by line :
    string line;

    // to generate heading and lines--- to write them into file

    fout << setw(15) <<left<< "Name"
         << " " << setw(7) <<left<< "Average"
         << " " << setw(5) <<left<< "Grade"
         <<endl;

    fout << string(30, '-')<<endl;

    while (!fin.eof())
    {
        getline(fin, line);

        // Seperating names portion and marks portion of each line by line and
        //  storing the name in Variable : name

        istringstream iss1(line);
        string name;
        getline(iss1, name, ':');

        // Getting marks and store it
        string marks;
        getline(iss1, marks, ':');

        // Getting average of all marks
        double average = GetAverage(marks);

        // Getting grade for calculated average
        char grade = getGrade(average);

        fout<<setw(15)<<left<<name
        <<setw(7)<<right<<setprecision(2)<<fixed<<average<<setw(5)<<right<<grade<<endl;
    }
    cout << endl;
    fin.close();
    fout.close();
}