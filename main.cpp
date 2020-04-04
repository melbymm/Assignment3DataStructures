
#include "stackpractice.h"
#include <fstream>

int main(int argc, char **argv){
  //establish variables
  string name;
  string btext;
  ifstream ifs;
  string inFile = "";
  string in = "";
  string inf = "";
  int leftBracket = 0;
  int rightBracket = 0;
  int leftcurly = 0;
  int leftsquare = 0;
  int leftparen = 0;
  int rightcurly = 0;
  int rightsquare = 0;
  int rightparen = 0;
  int line = 0;
  //GenStack<char> *z;
  if(argc == 1){
    cout << "Invalid, enter a file name as command line argument" << endl;
    exit(1);
  }
  else{
    name = argv[1];
  }
  ifs.open(name);
//open file
    if(!ifs.is_open()){
      cout << "Couldn't Open! " << endl;
}
    while(ifs >> inFile){
//Count for all delimeters

      for(int i = 0; i < inFile.size(); ++i){
        if(inFile.at(i) == '{' || inFile.at(i)== '(' ||inFile.at(i)=='['){
          leftBracket +=1;
          if(inFile.at(i) == '{'){
            leftcurly++;
          }
          else if(inFile.at(i)== '('){
            leftparen++;
          }
          else if(inFile.at(i)=='['){
            leftsquare++;
          }
          //cout << leftBracket << endl;
        }
        if(inFile.at(i) == '}' ||inFile.at(i)== ')' ||inFile.at(i)== ']'){
          rightBracket += 1;
          //cout << rightBracket << endl;
          if(inFile.at(i) == '}'){
            rightcurly++;
          }
          else if(inFile.at(i)== ')'){
            rightparen++;
          }
          else if(inFile.at(i)== ']'){
            rightsquare++;
          }
        }
      }

}
ifs.close();
//make stack
    GenStack<char> *z = new GenStack<char>(leftBracket);
    ifs.open(name);
    while(ifs>>inf){
      ++line;
      for(int i = 0; i < inf.size(); ++i){
        if(inf.at(i) == '{' ||inf.at(i)== '(' ||inf.at(i)== '['){
          //push to stack if left delimeter
          z->GenStack::push(inf.at(i));

        }
        else if (inf.at(i) == '}' ||inf.at(i)== ')' ||inf.at(i)== ']'){
          if(z->isEmpty()){
            //z->peek();
            cout << "Line " << line << " unexpected " << inf.at(i) << endl;
            exit(1);
          }
          else{
          if(inf.at(i) == '}'){
            if(z->peek() != '{'){
              //check for incorrect delimeters
              if(z->peek()=='['){
                cout << "Line: " << line << " expected: ]" << ", got: } " << endl;
                exit(1);
              }
              else if(z->peek()=='('){
                cout << "Line: " << line << " expected: )" << ", got: } " << endl;
                exit(1);
              }
              exit(1);
            }
            else{
              //pop from stack if doesn't cause error
                z->pop();
            }
          }

          else if(inf.at(i) == ')'){
            if(z->peek() != '('){
              //check for incorrect delimeters
              if(z->peek()=='['){
                cout << "Line: " << line << " expected: ]" << ", got: ) " << endl;
                exit(1);
              }
              else if(z->peek()=='{'){
                cout << "Line: " << line << " expected: }" << ", got: ) " << endl;
                exit(1);
              }
              exit(1);
            }
            else{
//pop from stack if doesn't cause error
              if(!z->isEmpty()){
                z->pop();
              }
            }
          }
          else if(inf.at(i) == ']'){
            if(z->peek() != '['){
              //check for incorrect delimeters
              if(z->peek()=='{'){
                cout << "Line: " << line << " expected: }" << ", got: ] " << endl;
                exit(1);
              }
              else if(z->peek()=='('){
                cout << "Line: " << line << " expected: )" << ", got: ] " << endl;
                exit(1);
              }
              exit(1);
            }
            else{
              //pop from stack if doesn't cause error
              if(!z->isEmpty()){
                z->pop();
              }

            }
          }
          }
         }
        }
      }

    if(leftcurly > rightcurly){
      cout << "Reached end of file, missing }" << endl;
      exit(1);
    }
    if(leftparen > rightparen){
      cout << "Reached end of file, missing )" << endl;
      exit(1);
    }
    if(leftsquare > rightsquare){
      cout << "Reached end of file, missing ]" << endl;
      exit(1);
    }

    //letting user know the syntax is good
      cout <<"Syntax is correct " << endl;


//Closing the file
    ifs.close();
  //  delete z;


}
