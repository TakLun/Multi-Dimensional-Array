#ifndef __CS540_ARRAY_HPP
#define __CS540_ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <exception>
#include <cassert>

namespace cs540{

  template <typename T, size_t... Dims> class Array;

  // OutOfRange Exception
  class OutOfRangeException: public std::exception{
    virtual const char* what() const throw(){
      return "Index Out Of Range";
    }
  }OutOfRange;

  /* ===================== Single-Array Template ===================== */
  template <typename T, size_t Dim>
  class Array<T, Dim>{
    static_assert(Dim != 0, "None of the dimensions can be zero");

  private:
    unsigned int length;
    T *arr;

  public:
    // Constructors
    Array() : 
      length(Dim),
      arr(new T[Dim])
    { }

    // Copy Constructor
    Array(const Array &cpy_arr) : 
      length(Dim),
      arr(new T[Dim])
    {
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = cpy_arr[idx]; }
    }

    // Template Copy Constructor
    template <typename U>
    Array(const Array<U, Dim> &cpy_arr) : 
      length(Dim),
      arr(new T[Dim])
    {
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = static_cast<T>(cpy_arr[idx]); }
    }
    
    // Destructor
    ~Array(){
      if(arr != nullptr) delete []arr;
    }

    // Assignment Operators
    /** TODO: Check if this == cpy_arr **/
    Array &operator=(const Array &cpy_arr){
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = cpy_arr[idx]; }
      return *this;
    }

    template <typename U>
    Array<T, Dim> &operator=(const Array<U, Dim> &cpy_arr){
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = cpy_arr[idx]; }
      return *this;
    }

    // Accessor Operators
    T &operator[](size_t idx){ 
      try{
	if(arr != nullptr && idx >= length){
	  throw OutOfRange;
	}
      }catch(std::exception e){
	std::cout << "OutOfRange Exception Thrown" << std::endl;
	std::cout << e.what() << std::endl;
	}
      return arr[idx];
    }

    const T &operator[](size_t idx) const{
      try{
	if(arr != nullptr && idx >= length){
	  throw OutOfRange;
	}
      }catch(std::exception e){
	std::cout << "OutOfRange Exception Thrown" << std::endl;
	std::cout << e.what() << std::endl;
      }
      return arr[idx];
    }

    T &operator*(){ return arr; }

    // Iterator Classes
    // FirstDimensionMajorIterator Iterator Class
    class FirstDimensionMajorIterator{
    private:      
      T *ptr;
      unsigned int length, idx;

    public:
      // Iterator Constructors
      FirstDimensionMajorIterator() : ptr(nullptr), length(0), idx(0){}
      FirstDimensionMajorIterator(const FirstDimensionMajorIterator &p) : ptr(p.ptr), length(p.length), idx(p.idx){}
      FirstDimensionMajorIterator(T *p, unsigned int len) : ptr(p), length(len), idx(0){}

      // Operators
      FirstDimensionMajorIterator &operator=(const FirstDimensionMajorIterator &p){ptr = p.ptr;}
      bool operator==(const FirstDimensionMajorIterator &p){ return ptr == p.ptr; }
      bool operator!=(const FirstDimensionMajorIterator &p){ return ptr != p.ptr; }

      FirstDimensionMajorIterator &operator++(){ ++ptr; return *this;}
      FirstDimensionMajorIterator &operator++(int){ 
	FirstDimensionMajorIterator tmp = *this; 
	++ptr; 
	return tmp; 
      }

      T &operator*(){ return *ptr; }

    };

    //LastDimensionMajorIterator Iterator Class
    class LastDimensionMajorIterator{
    private:
      T* ptr;
      unsigned int length, idx;

    public:
      // Iterator Constructors
      LastDimensionMajorIterator() : ptr(nullptr), length(0), idx(0){}
      LastDimensionMajorIterator(const LastDimensionMajorIterator &p) : ptr(p.ptr), length(p.length), idx(p.idx){}
      LastDimensionMajorIterator(T *p, unsigned int len) : ptr(p), length(len), idx(0){}

      // Operators
      LastDimensionMajorIterator &operator=(const LastDimensionMajorIterator &p){ ptr = p.ptr; }
      bool operator==(const LastDimensionMajorIterator &p){ return ptr == p.ptr; }
      bool operator!=(const LastDimensionMajorIterator &p){ return ptr != p.ptr; }

      LastDimensionMajorIterator &operator++(){ ++ ptr; return *this; }
      LastDimensionMajorIterator &operator++(int){
	LastDimensionMajorIterator tmp = *this;
	++ptr;
	return tmp;
      }

      T &operator*(){ return *ptr; };
    };

    // Iterator Functions
    FirstDimensionMajorIterator fmbegin(){ return FirstDimensionMajorIterator(arr, length); }
    FirstDimensionMajorIterator fmend(){ return FirstDimensionMajorIterator(arr + length, length); }
      
    LastDimensionMajorIterator lmbegin(){ return LastDimensionMajorIterator(arr, length); }
    LastDimensionMajorIterator lmend(){ return LastDimenstionMajorITerator(arr + length, length); }
 };




  /* ===================== Multi-Array Template ===================== */
  template <typename T, size_t FstDim, size_t... LstDims>
  class Array<T, FstDim, LstDims...>{
    static_assert(FstDim != 0, "None of the dimensions can be zero");

  private:
    typedef Array<T, LstDims...> multi_arr;
    unsigned int length;
    multi_arr **arr;
    
  public:
    // Constructors
    Array() : 
      length(FstDim),
      arr(new multi_arr*[length])
    {
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = new multi_arr(); }
    }

    // Copy Constructor
    Array(const Array &cpy_arr) : 
      length(FstDim),
      arr(new multi_arr*[length])
    { 
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = new multi_arr(cpy_arr[idx]); }
    }

    // Template Copy Constructor
    template <typename U>
    Array(const Array<U, FstDim, LstDims...> &cpy_arr) :
      length(FstDim),
      arr(new multi_arr*[length])
    {
      for(unsigned int idx = 0; idx < length; ++idx){ arr[idx] = new multi_arr(static_cast<multi_arr>(cpy_arr[idx])); }
    }
    
    ~Array(){
      if(arr != nullptr){
	for(unsigned int idx = 0; idx < length; ++idx){
	  delete arr[idx];
	}
	delete []arr;
      }
    }

    // Assignment Operators
    /** TODO: Check if this == cpy_arr **/
    Array &operator=(const Array &cpy_arr){
      for(unsigned int idx = 0; idx < length; ++idx){ *arr[idx] = cpy_arr[idx]; }
      return *this;
    }

    template <typename U>
    Array<T, FstDim, LstDims...> &operator=(const Array<U, FstDim, LstDims ...> &cpy_arr){
      for(unsigned int idx = 0; idx < length; ++idx){ *arr[idx] = static_cast<multi_arr>(cpy_arr[idx]); }
      return *this;      
    }

    // Accessor Operators
    multi_arr &operator[](size_t idx){
      try{
	if(arr != nullptr && idx >= length){
	  throw OutOfRange;
	}
      }catch(std::exception e){
	std::cout << "OutOfRange Exception Thrown" << std::endl;
	std::cout << e.what() << std::endl;
      }
      return *arr[idx];
    }

    const multi_arr &operator[](size_t idx) const{
      try{
	if(arr != nullptr && idx >= length){
	  throw OutOfRange;
	}
      }catch(std::exception e){
	std::cout << "OutOfRange Exception Thrown" << std::endl;
	std::cout << e.what() << std::endl;
      }
      return *arr[idx];
    }
    
    // Iterator Classes
    // FirstDimensionMajorIterator Iterator Class
    class FirstDimensionMajorIterator{
    public:
      typename Array<T, FstDim, LstDims...> curr_arr;
      curr_arr *arr;
      multi_arr *nxt;
      unsigned int  idx;
      typename Array<T, LstDims...>::FirstDimensionMajorIterator nxtItr;
      
      
    public:
      // Iterator Constructors
      FirstDimensionMajorIterator() : ptr(nullptr),  idx(0){}
      FirstDimensionMajorIterator(const FirstDimensionMajorIterator &p) : ptr(p.ptr), idx(0){ }
      FirstDimensionMajorIterator(multi_arr *p, unsigned int i) : ptr(p), idx(i){}

      // Operators
      FirstDimensionMajorIterator &operator=(const FirstDimensionMajorIterator &p){ptr = p.ptr;  idx = p.idx;}
      bool operator==(const FirstDimensionMajorIterator &p){ return ptr == p.ptr; }
      bool operator!=(const FirstDimensionMajorIterator &p){ return ptr != p.ptr; }

      FirstDimensionMajorIterator &operator++(){
	
	return *this;
      }

      FirstDimensionMajorIterator &operator++(int){ 
	FirstDimensionMajorIterator tmp = *this;

	return tmp;
      }

      T &operator*(){ return (*ptr)[idx]; }

    };
      
    //LastDimensionMajorIterator Iterator Class
    class LastDimensionMajorIterator{
    private:
      multi_arr *ptr;
      unsigned int idx;

    public:
      // Iterator Constructors
      LastDimensionMajorIterator() : ptr(nullptr), idx(0){}
      LastDimensionMajorIterator(const LastDimensionMajorIterator &p) : ptr(p.ptr), idx(0){}
      LastDimensionMajorIterator(multi_arr *p, unsigned int len) : ptr(p), idx(0){}

      // Operators
      LastDimensionMajorIterator &operator=(const LastDimensionMajorIterator &p){ ptr = p.ptr; }
      bool operator==(const LastDimensionMajorIterator &p){ return ptr == p.ptr; }
      bool operator!=(const LastDimensionMajorIterator &p){ return ptr != p.ptr; }

      LastDimensionMajorIterator &operator++(){ 
	(*ptr).fmbegin()++;
	return *this;
      }

      LastDimensionMajorIterator &operator++(int){
	
	return *this;
      }

      multi_arr &operator*(){ return *ptr; };
    };
      
    // Iterator Functions
    FirstDimensionMajorIterator fmbegin(){ return FirstDimensionMajorIterator(arr, 0); }
    FirstDimensionMajorIterator fmend(){ return FirstDimensionMajorIterator(arr, length); }
      
    LastDimensionMajorIterator lmbegin(){ return LastDimensionMajorIterator(arr, 0); }
    LastDimensionMajorIterator lmend(){ return LastDimenstionMajorITerator(arr, length); }

  };
}

#endif
