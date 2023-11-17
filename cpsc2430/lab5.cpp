//Jared Callero
//lab5.cpp
//11/12/2021
#include <iostream>
using namespace std;

//size = 10, 8 collisions
//size = 12, 7 collisions
//size = 13, 3 collisions

//Answer to question 6: With the current data set we have, we can see a downward
//trend in the number of collisions the table has when the size of said table increases
//this is because not only is there more room for the contents of the table, but the hash is
//able to make more unique keys for said table to use.



class Course{
  private:
    string title;
    int courseNo;

  public:

    Course(){

      title = "";
      courseNo = 0;

    }

    Course(string newTitle, int newNumber){

      title = newTitle;
      courseNo = newNumber;

    }

    int getCourseNo(){

      return courseNo;

    }

    string getTitle(){

      return title;

    }
};

int hashFunc(int key);
bool addCourse(Course newCourse, Course*& schedule);

//Global tableSize variable to help with experimenting on size
int tableSize = 7;

int main()
{
  string titleArr [] = {"Introduction to Computer Science", 
 "Data-Driven Problem Solving & Programming", "Programming and Data Types", 
 "Programming and Problem Solving I ", "Programming and Problem Solving II",
 "Data Structures", "Computer Organization", "Foundations of Computer Science",
 "Object-Oriented Development", "Fundamentals of Databases", 
 "Languages and Computation", "Computing Systems", 
 "Design and Analysis of Algorithms", "Software as a Service", 
 "Mobile Software Development"};
  int keyArr [] = {1000,1220,1230,1420,1430,2430,2500,2600,3200,3300,
                    3400,3500,4100,4240,4250};

  Course* schedule = new Course[tableSize];
  int collisionCount = 0;

  for(int i = 0; i < 15; i++){

    Course newCourse = Course(titleArr[i],keyArr[i]);

    if(!addCourse(newCourse,schedule)){

      cout << "Collision at index " << hashFunc(keyArr[i]) << " for key " << keyArr[i] << endl;
      collisionCount++;

    }
  }
    cout << endl << "There were "<< collisionCount << " collisions" << endl << endl;

    for(int i = 0; i < tableSize; i++){

      cout << "schedule [" << i << "]" << endl;
      cout << "Course: CPSC" << schedule[i].getCourseNo() << endl;
      cout << "Title :" << schedule[i].getTitle() << endl << endl;

    }
  
  return 0;
}

int hashFunc(int key){
  //creates a hash based off of the number provided

  int firstTwo = key/100;
  int lastTwo = key % 100;

  return (firstTwo + lastTwo) % tableSize;

}

bool addCourse(Course newCourse, Course*& schedule){
  //adds a course to the provided schedule, returns true if inserted correctly
  //otherwise returns false

  int newHash = hashFunc(newCourse.getCourseNo());

  if(schedule[newHash].getTitle() != ""){

    return false;

  }else{

    schedule[newHash] = newCourse;
    return true;
  

  }

}