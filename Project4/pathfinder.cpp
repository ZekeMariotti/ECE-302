#include <iostream>
#include <vector>
#include "image.h"
#include "deque.hpp"
using std::cout;
using std::endl;

void indexToij(int index, int ij[], Image<Pixel> img);
int ijToIndex(int ij[], Image<Pixel> img);
//void solution(int sn, int s_next[]);


int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  // writeToFile(inputImg, "outout00.png"); <- syntax to write to file
  // string variables to hold names of input and output files
  std::string input_file = argv[1];
  std::string output_file = argv[2];

  //Frontier deque
  Deque<int> frontier;
  Deque<int> explored;

  // read inputfile
  Image<Pixel> inputImg=readFromFile(input_file);

  //startPos holds i and j value for the red pixel/start position
  int startPos[2];
  int s;
  int redCount=0; //used to error check number of red pixels
  
  //Search for red pixel
  for (int i=0; i<=inputImg.width()-1; i++)
  {
    for (int j=0; j<=inputImg.height()-1; j++)
    {
      //error check for pixels that aren't black, white, or red
      if (inputImg(i, j)!=RED && inputImg(i, j)!=WHITE && inputImg(i, j)!=BLACK)
      {
          //Invalid color in image*
          
      }

      //pixel at i, j is red
      if(inputImg(i, j)==RED)
      {
          indexToij(i*inputImg.width()+j, startPos, inputImg); //set i and j values of startPos
          s=ijToIndex(startPos, inputImg); //copy startPos to int s
          frontier.pushFront(i*inputImg.width()+j); //pushes the vector indexing of the image to the frontier
          redCount++;
      }
    }
  }

  //error check multiple red pixels
  if (redCount>1)
  {
    //More than one red pixel*

  }

  //error check no red
  if (redCount==0)
  {
    //Less than one pixel*

  }

  //Check if start is a solution
  if(startPos[0]==0 || startPos[1]==0)
  {
    //start position is a solution*

  }

  // next state variables
  int s_next1[2], s_next2[2], s_next3[2], s_next4[2];
  int sn1, sn2, sn3, sn4; 

  //Main while loop
  while(true)
  {
    //check if frontier is empty
    if (frontier.isEmpty())
    {
      //return failure*
      cout << "empty frontier";
      return EXIT_FAILURE;
    }

    //s = next state from frontier
    s=frontier.front();
    frontier.popFront();

    //add s to explored
    explored.pushBack(s);

    //set next states
    sn1=s-inputImg.width(); //sn1=s-one row
    sn2=s+inputImg.width(); //sn2=s+one row
    sn3=s-1; //sn3=s-one column
    sn3=s+1; //sn4=s+one column
    indexToij(sn1, s_next1, inputImg);
    indexToij(sn2, s_next2, inputImg);
    indexToij(sn3, s_next3, inputImg);
    indexToij(sn4, s_next41, inputImg);

    //go through each next state

    //check that next state isn't in frontier or explored, and that its not a black pixel
    if (!frontier.contains(sn1) && !explored.contains(sn1) && inputImg(s_next1[0], s_next1[1])!=BLACK)
    {
      //if next state is goal state
      if(s_next1[0]==0 || s_next1[1]==0)
      {
        //solution found***
        cout << s_next1[0] << " " << s_next1[1] << endl;

        //return success
        return EXIT_SUCCESS;
      }

      //insert sn into frontier
      frontier.pushBack(sn1);
    }

    //break;
  }



  
}


//converts an index for an image to i and j
void indexToij(int index, int ij[], Image<Pixel> img)
{
  ij[0]=index/img.width();
  ij[1]=index%img.width();
}

//converts an i, j in array form to a vector index as an int
int ijToIndex(int ij[], Image<Pixel> img)
{
  return (ij[0]*img.width()+ij[1]);
}

/*//checks if a pixel location is a solution
bool solution(int sn, int s_next[])
{
  // if next state is goal state
  if (s_next[0] == 0 || s_next[1] == 0)
  {
    // solution found***
    cout << s_next[0] << " " << s_next[1] << endl;

    // return success
    return EXIT_SUCCESS;
  }
}*/
