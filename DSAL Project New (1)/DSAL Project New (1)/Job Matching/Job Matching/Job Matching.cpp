#include <iostream>
#include "LinkedList.h"
#include "Jobs.h"
#include "Functions.h"
#include <string>

using namespace std;

int main() {
    linkedList Applicants;
    linkedListJobs Jobs;

    Jobs.insertLast("Mechanical Engineer");
    Jobs.returnNode("Mechanical Engineer")->QualificationsRequired.push_back("bsc in mechanical engineering");
    Jobs.returnNode("Mechanical Engineer")->QualificationsRequired.push_back("msc in mechanical engineering");

    Jobs.insertLast("Mechanical Engineering Advisor");
    Jobs.returnNode("Mechanical Engineering Advisor")->QualificationsRequired.push_back("phd in mechanical engineering");
    Jobs.returnNode("Mechanical Engineering Advisor")->QualificationsRequired.push_back("mpil in mechanical engineering");

    Jobs.insertLast("Electrical Engineer");
    Jobs.returnNode("Electrical Engineer")->QualificationsRequired.push_back("bsc in electrical engineering");
    Jobs.returnNode("Electrical Engineer")->QualificationsRequired.push_back("msc in electrical engineering");

    Jobs.insertLast("Electrical Engineering Lecturer");
    Jobs.returnNode("Electrical Engineering Lecturer")->QualificationsRequired.push_back("phd in electrical engineering");
    Jobs.returnNode("Electrical Engineering Lecturer")->QualificationsRequired.push_back("mpil in electrical engineering");

    Jobs.insertLast("Chemical Engineer");
    Jobs.returnNode("Chemical Engineer")->QualificationsRequired.push_back("bsc in chemical engineering");
    Jobs.returnNode("Chemical Engineer")->QualificationsRequired.push_back("msc in chemical engineering");

    Jobs.insertLast("R&D Chemical Engineer");
    Jobs.returnNode("R&D Chemical Engineer")->QualificationsRequired.push_back("phd in chemical engineering");

    Jobs.insertLast("Material Engineer");
    Jobs.returnNode("Material Engineer")->QualificationsRequired.push_back("bsc in material engineering");
    Jobs.returnNode("Material Engineer")->QualificationsRequired.push_back("msc in material engineering");

    Jobs.insertLast("Software Engineer");
    Jobs.returnNode("Software Engineer")->QualificationsRequired.push_back("bsc in software engineering");
    Jobs.returnNode("Software Engineer")->QualificationsRequired.push_back("msc in software engineering");

    Jobs.insertLast("Software Engineer");
    Jobs.returnNode("Software Engineer")->QualificationsRequired.push_back("bsc in computer science");

    Jobs.insertLast("Computer Engineer");
    Jobs.returnNode("Computer Engineer")->QualificationsRequired.push_back("bsc in computer science");

    Jobs.insertLast("Data Science Engineer");
    Jobs.returnNode("Data Science Engineer")->QualificationsRequired.push_back("phd in software engineering");

    Jobs.insertLast("Civil Engineer");
    Jobs.returnNode("Civil Engineer")->QualificationsRequired.push_back("bsc in civil engineering");

    Jobs.insertLast("Civil Engineering Lecturer");
    Jobs.returnNode("Civil Engineering Lecturer")->QualificationsRequired.push_back("msc in civil engineering");

    Jobs.insertLast("Research Assistant Civil Engineer");
    Jobs.returnNode("Research Assistant Civil Engineer")->QualificationsRequired.push_back("phd in civil engineering");

    Jobs.insertLast("Teacher");
    Jobs.returnNode("Teacher")->QualificationsRequired.push_back("bsc in teaching");
    Jobs.returnNode("Teacher")->QualificationsRequired.push_back("msc in teaching");


    Jobs.insertLast("Nurse");
    Jobs.returnNode("Nurse")->QualificationsRequired.push_back("bsc in nursing");
    Jobs.returnNode("Nurse")->QualificationsRequired.push_back("msc in nursing");

    Jobs.insertLast("Doctor");
    Jobs.returnNode("Doctor")->QualificationsRequired.push_back("mbbs");
    Jobs.returnNode("Doctor")->QualificationsRequired.push_back("md");
    Jobs.returnNode("Doctor")->QualificationsRequired.push_back("phd");

    Jobs.insertLast("Lawyer");
    Jobs.returnNode("Lawyer")->QualificationsRequired.push_back("llb");
    Jobs.returnNode("Lawyer")->QualificationsRequired.push_back("llm");
    Jobs.returnNode("Lawyer")->QualificationsRequired.push_back("phd");

    int selection = mainMenu();
    secondMenu(selection, Applicants, Jobs);
    return 0;
}
