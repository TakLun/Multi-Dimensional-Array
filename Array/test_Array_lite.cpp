#include "Array.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  // 1D Arrays

  cout << "==========================================" << endl;
  cout << "============1 Dimensional Array===========" << endl;
  cout << "==========================================" << endl;
  {
    cs540::Array<int, 4> int_a;
    cs540::Array<char, 10> char_a;
    cs540::Array<int, 4> int_a2;

    // Initializations
    for(int i = 0; i < 4; ++i){
      int_a[i] = i;
    }
    for(int i = 0; i < 4; ++i){
      int_a2[i] = i*4;
    }
    for(int j = 65; j < 75; ++j){
      char_a[j-65] = j;
    }

    // ===============================================
    cout << "Print array contents" << endl;
    cout << "int[4]:   ";
    for(int i = 0; i < 4; ++i){
      cout << int_a[i] << " ";
    }
    cout << endl;
    cout << "char[10]: ";
    for(int j = 0; j < 10; ++j){
      cout << char_a[j] << " ";
    }
    cout << endl;


    cout << endl;
    cout << "Assignment int_a to int_a2" << endl;
    cout << "Original:   ";
    for(int i = 0; i < 4; ++i){
      cout << int_a[i] << " ";
    }
    cout << endl;
    cout << "Assignment: ";
    int_a = int_a2;
    for(int j = 0; j < 4; ++j){
      cout << int_a[j] << " ";
    } 
    cout << endl;


    cout << endl;
    cout << "copy constructor" << endl;
    cout << "Array to copy:\t\t";
    for(int j = 0; j < 4; ++j){
      cout << int_a2[j] << " ";
    }
    cout << endl;
    cout << "After copy constructor: ";
    cs540::Array<int, 4> int_to_int_a(int_a2);
    for(int j = 0; j < 4; ++j){
      cout << int_to_int_a[j] << " ";
    }
    cout << endl;


    cout << endl;
    cout << "copy template constructor" << endl;
    cout << "-\t-\t-\t-Array to copy:  ";
    for(int j = 0; j < 10; ++j){
      cout << char_a[j] << "  ";
    }
    cout << endl;
    cout << "After copy constructor Using Iterators: ";
    cs540::Array<int, 10> char_to_int_a(char_a);
    for(auto j = char_to_int_a.fmbegin(); j != char_to_int_a.fmend(); ++j){
      cout << *j << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  // 2D Arrays
  cout << "==========================================" << endl;
  cout << "============2 Dimensional Array===========" << endl;
  cout << "==========================================" << endl;
  {
    cout << "5x9 dimensional array" << endl;
    cs540::Array<int, 5, 9> int_arr;
    for(int i = 0; i < 5; ++i){
      for(int j = 0; j < 9; ++j){
	int_arr[i][j] = j+4;
      }  
    }

    for(int i = 0; i < 5; ++i){
      for(int j = 0; j < 9; ++j){
	cout << int_arr[i][j] << " ";
      }
      cout << endl;
    }

    printf("\n\n");

    {
      cout << "Copy Ctor 2x3 dimensional array" << endl;
      cs540::Array<int, 2, 3> int_arr2;
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  int_arr2[i][j] = j+4;
	}  
      }
      
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  cout << int_arr2[i][j] << " ";
	}
	cout << endl;
      }
      cout << "After Copy Ctor" << endl;
      cs540::Array<int, 2, 3> int_arr3(int_arr2);
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  cout << int_arr3[i][j] << " ";
	}
	cout << endl;
      }
      
      printf("\n\n");
      
      cout << "Copy Ctor 2x3 char to int" << endl;
      cs540::Array<char, 3, 6> char_arr;
      for(int i = 65; i < 65+3; ++i){
	for(int j = 65; j < 65+6; ++j){
	  char_arr[i-65][j-65] = j;
	}  
      }
      
      for(int i = 0; i < 3; ++i){
	for(int j = 0; j < 6; ++j){
	  cout << char_arr[i][j] << " ";
	}
	cout << endl;
      }
      cout << "After Copy Ctor" << endl;
      cs540::Array<int, 3, 6> c_to_int_arr(char_arr);
      for(int i = 0; i < 3; ++i){
	for(int j = 0; j < 6; ++j){
	  cout << c_to_int_arr[i][j] << " ";
	}
	cout << endl;
      }
    }
    printf("\n\n");

    {
      cout << "Copy Assignment 2x3 dimensional array" << endl;
      cs540::Array<int, 2, 3> int_arr2;
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  int_arr2[i][j] = j+4;
	}  
      }
      
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  cout << int_arr2[i][j] << " ";
	}
	cout << endl;
      }
      cout << "After Copy Assignment" << endl;
      cs540::Array<int, 2, 3> int_arr3;
      int_arr3 = int_arr2;
      for(int i = 0; i < 2; ++i){
	for(int j = 0; j < 3; ++j){
	  cout << int_arr3[i][j] << " ";
	}
	cout << endl;
      }
      
      printf("\n\n");
      
      cout << "Copy Assignment 2x3 char to int" << endl;
      cs540::Array<char, 3, 6> char_arr;
      for(int i = 65; i < 65+3; ++i){
	for(int j = 65; j < 65+6; ++j){
	  char_arr[i-65][j-65] = j;
	}  
      }
      
      for(int i = 0; i < 3; ++i){
	for(int j = 0; j < 6; ++j){
	  cout << char_arr[i][j] << " ";
	}
	cout << endl;
      }
      cout << "After Copy Assignment" << endl;
      cs540::Array<int, 3, 6> c_to_int_arr;
      c_to_int_arr = char_arr;
      for(int i = 0; i < 3; ++i){
	for(int j = 0; j < 6; ++j){
	  cout << c_to_int_arr[i][j] << " ";
	}
	cout << endl;
      }
    }
  }

  printf("\n\n");


  // 3D Arrays
  cout << "==========================================" << endl;
  cout << "============3 Dimensional Array===========" << endl;
  cout << "==========================================" << endl;
  {
    cs540::Array<int, 3, 5, 9> int_arr;
    //[][][]init
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 5; ++j){
	for(int k = 0; k < 9; ++k){
	  int_arr[i][j][k] = 100;
	}
      }
    }

    cs540::Array<int, 3, 5> int_arr_m;
    for(int j = 0; j < 3; ++j){
      for(int k = 0; k < 5; ++k){
	int_arr_m[j][k] = j*j+k*k;
      }
    }

    cout << "Before [][][] Assignment" << endl;
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 5; ++j){
	for(int k = 0; k < 9; ++k){
	  cout << int_arr[i][j][k] << " ";
	}cout << endl;
      }cout << endl;
    }

    cout << "[2][4][5] = 8888" << endl;
    int_arr[2][4][5] = 8888;

    cout << "[1][3][2] = " << int_arr_m[2][3] << endl;
    int_arr[1][3][2] = int_arr_m[2][3];

    cout << "After [][][] Assignment" << endl;
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 5; ++j){
	for(int k = 0; k < 9; ++k){
	  cout << int_arr[i][j][k] << " ";
	}cout << endl;
      }cout << endl;
    }

    printf("\n");
    
    cout << "Check for Zeros" << endl;
    //cs540::Array<int, 0, 5, 9> za1;
    //cs540::Array<int, 3, 0, 9> za2;
    //cs540::Array<int, 3, 5, 0> za3;
    cout << "Done Checking" << endl;
  }


  // Iterate Arrays
  cout << "==========================================" << endl;
  cout << "============Iterate thru Arrays===========" << endl;
  cout << "==========================================" << endl;
  {
    cs540::Array<int, 2, 4> arr;
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 4; ++j){
	arr[i][j] = (j+1)*7;
      } 
    }

    cout << "Sequence: " << endl;
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 4; ++j){
	cout << arr[i][j] << " ";
      } 
    }
    printf("\n");

    cout << "- fmbegin -" << endl;
    auto fst = arr.fmbegin();
    printf("begin: %d\n", *fst);
    //for(auto it = arr.fmbegin(); it != arr.fmend(); ++it){

    //}cout << endl;

  }  

  return 0;
}
