/*
*@file: main.cpp
*@author: Hunter Crisp
*@date: 7 October 2018
*/


#include "DoubleHash.h"
#include "QuadraticProbing.h"
#include "HashTable.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;

void CompareTables()
{
  //Initialize all variables
  int m = 100003;
  int inputSize = 0;
  int m_search = floor(m / 100);

  double chainBuild = 0.0;
  double chainFound = 0.0;
  double averageChainBuild = 0.0;
  double averageChainFound = 0.0;
  double averageChainNotFound = 0.0;
  double chainNotFound = 0.0;

  double dblBuild = 0.0;
  double dblFound = 0.0;
  double dblNotFound = 0.0;
  double averageDblBuild = 0.0;
  double averageDblFound = 0.0;
  double averageDblNotFound = 0.0;

  double quadBuild = 0.0;
  double quadFound = 0.0;
  double quadNotFound = 0.0;
  double averageQuadBuild = 0.0;
  double averageQuadFound = 0.0;
  double averageQuadNotFound = 0.0;

  clock_t t;

  for(double i = 0.1; i < 0.6; i = i + 0.1)
  {
    //Initialize timing variables
    inputSize = floor(i*m);
    averageChainBuild = 0.0;
    averageChainFound = 0.0;
    averageChainNotFound = 0.0;
    averageDblBuild = 0.0;
    averageDblFound = 0.0;
    averageDblNotFound = 0.0;
    averageQuadFound = 0.0;
    averageQuadNotFound = 0.0;
    averageQuadBuild = 0.0;

    for(int j = 0; j < 5; j++)
    {
      chainBuild = 0.0;
      chainFound = 0.0;
      chainNotFound = 0.0;
      dblBuild = 0.0;
      dblFound = 0.0;
      dblNotFound = 0.0;
      quadBuild = 0.0;
      quadFound = 0.0;
      quadNotFound = 0.0;

      //New random seed
      srand(time(NULL));

      //Initialize tables
      HashTable chainTable;
      DoubleHash dblHash;
      QuadraticProbing quadProbe;
      

      //Input array of random values
      int temp[inputSize];
      for(int p = 0; p < inputSize; p++)
      {
        temp[p] = rand() % (5*m) + 1;
      }

      //Search array of random values
      int temp2[m_search];
      for(int q = 0; q < m_search; q++)
      {
        temp2[q] = rand() % (5*m) + 1;
      }

      //Build Chain Hash Table and time it
      t = clock();
      for(int r = 0; r < inputSize; r++)
      {
        chainTable.insert(temp[r]);
      }
      t = clock() - t;
      chainBuild = ((float)t)/CLOCKS_PER_SEC;
      
      //Search for values in Chain Hash Table and time it
      for(int a = 0; a < m_search; a++)
      {
        t = clock();
        if(chainTable.find(temp2[a]))
        {
          chainFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
        else
        {
          chainNotFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
      }

      //Empty the table
      chainTable.~HashTable();

      //Build Double Hash table and time it
      t = clock();
      for(int a = 0; a < inputSize; a++)
      {
        dblHash.insert(temp[a]);
      }
      t = clock() - t;
      dblBuild = ((float)t)/CLOCKS_PER_SEC;

      //Search for values in Double Hash table and time it
      for(int a = 0; a < m_search; a++)
      {
        t = clock();
        if(dblHash.find(temp2[a]) > 0)
        {
          dblFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
        else
        {
          dblNotFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
      }

      //Build the Quadratic Probing Hash Table and time it
      t = clock();
      for(int a = 0; a < inputSize; a++)
      {
        quadProbe.insert(temp[a]);
      }
      t = clock() - t;
      quadBuild = ((float)t)/CLOCKS_PER_SEC;

      //Search for values in the Quadratic Probing Hash Table and time it
      for(int a = 0; a < m_search; a++)
      {
        t = clock();
        if(quadProbe.find(temp2[a]) > 0)
        {
          quadFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
        else
        {
          quadNotFound += ((float)(clock() - t))/CLOCKS_PER_SEC;
        }
      }

      //Add current values to sum
      averageChainBuild += chainBuild;
      averageChainFound += chainFound;
      averageChainNotFound += chainNotFound;
      averageDblBuild += dblBuild;
      averageDblFound += dblFound;
      averageDblNotFound += dblNotFound;
      averageQuadBuild += quadBuild;
      averageQuadFound += quadFound;
      averageQuadNotFound += quadNotFound;
    }
    
    cout << "Average Open Hash Table Build Time for " << inputSize << " is: " << averageChainBuild / 5.0 << endl;
    cout << "Average Open Hash Table Find Time is: " << averageChainFound / 5.0 << endl;
    cout << "Average Open Hash Table Not Found Time is: " << averageChainNotFound / 5.0 << "\n\n";

    cout << "Average Quadratic Probing Build Time for " << inputSize << " is: " << averageQuadBuild/ 5.0 << endl;
    cout << "Average Quadratic Probing Find Time is: " << averageQuadFound / 5.0 << endl;
    cout << "Average Quadratic Probing Not Found Time is: " << averageQuadNotFound / 5.0 << "\n\n";

    cout << "Average Double Hashing Build Time for " << inputSize << " is: " << averageDblBuild / 5.0 << endl;
    cout << "Average Double Hashing Find Time is: " << averageDblFound / 5.0 << endl;
    cout << "Average Double Hashing Not Found Time is: " << averageDblNotFound / 5.0 << "\n\n";
  }
}

int main(int argc, char* argv[])
{

  int choice = 0;
  while(choice != 3)
  {

    cout << "\nPlease choose a command: " << endl
    << "1: Test HashTables" << endl
    << "2: Performance Comparison" << endl
    << "3: Exit" << endl
    << endl << "< ";
    cin >> choice;


    switch(choice)
    {
      case 1:
      {
        /*DoubleHash dblHash;
        QuadraticProbing quadProbe;
        HashTable chainTable(11);
        int temp;

        ifstream dataFile;
        dataFile.open("data.txt");
        while(dataFile >> temp)
        {
          dblHash.insert(temp);
          quadProbe.insert(temp);
          chainTable.insert(temp);
        }

        dataFile.close();

        chainTable.print();
        dblHash.print();
        quadProbe.print();*/

        break;
      }

      case 2:
      {
        CompareTables();
        break;
      }
      case 3:
      {
        return 0;
      }
      default:
      {
        break;
      }
    }
  }


return 0;
}
