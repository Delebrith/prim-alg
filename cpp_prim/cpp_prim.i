%module cpp_prim

//To allow usage of STL vector
%include <std_vector.i>
//To allow usage of dllimport
%include <windows.i>

//Instatiate vector<int> type and vector<vector<int>> type
namespace std {
	%template(intvector) vector<int>;
	%template(intvectorvector) vector<vector<int>>;
}

//Include c++ file
%{
#define SWIG_FILE_WITH_INIT
#include "prim.h"
%}

//Generate wrapper for included symbols
%include "prim.h"