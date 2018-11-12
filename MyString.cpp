
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include "MyString.h"

// My own implementation of strlen
int
MyString::slength(const char *s) const
{
  // Add implementation here
	int len = 0;
	while(*(s + len) != '\0'){
		len++;
	}

	return len;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
  // Add implementation here
  // Allocate memory for _s.
	_s = new char[slength(s)];
// Copy s into _s
	for(int i = 0; i < slength(s); i++){
		_s[i] = *(s + i);
	}

	_s[slength(s)] = '\0';
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  _s = new char[1];
  *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
  if (this != &other) // protect against invalid self-assignment
  {
    // deallocate old memory
    delete [] _s;

    // Initialize _s with the "other" object.
    initialize(other._s);

    // by convention, always return *this
    return *this;
  }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
  // Add implementation here

  // Make sure that i is not beyond the end of string
	if(i > length()) return MyString();
// Allocate memory for substring
	char sub[n];
 // Copy characters of substring
	int j = 0;
	for(j; (j < n) && (j + i < length()); j++){\
		sub[j] = *(_s + j + i);
	}
	sub[j]= '\0';
	return MyString(sub);
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{
  // Add implementation here
	if( i > length()) return;

	if(i + n > length()){
		_s[i] = '\0';
		return;
	} else {
		int j = i + n;
		for(j; j < length(); j++){
			_s[j - n] = _s[j];
		}
		_s[j - n] = '\0';
		return;
	}
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
	if(length() != s.length()) return false;

	for(int i = 0; i < length(); i++){
		if(_s[i] != s._s[i]) return false;
	}
   return true;
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
	if(length() != s.length()) return true;
	for(int i = 0; i < length(); i++){
		if(_s[i] != s._s[i]) return true;
	}
 return false;

}

//return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
  int i = 0;

  while((_s[i] != '\0' && s._s[i] != '\0') && (_s[i] == s._s[i])){
	i++;
  }
  return ((_s[i] - s._s[i]) <= 0);
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
  // Add implementation here
  int i = 0;

  while((_s[i] != '\0' && s._s[i] != '\0') && (_s[i] == s._s[i])){
	i++;
  }

  return ((_s[i] - s._s[i]) > 0);
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
  // Add implementation here
  if(i > length()) return '\0';

  char out = *(_s + i);

  return out;
}

// Return C representation of string
const char *
MyString::cStr()
{
  // Add implementation here
  return _s;
}

// Get string length of this string.
int
MyString::length() const
{
  // Add implementation here
  return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  // Add implementation here
  delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  // Add implementation here

  // Allocate memory for the concatenated string

  // Add s1

  // Add s2

  MyString s;
  int totalLen = s1.length() + s2.length() + 1;
  s._s = new char[totalLen];

  char * str1 = s1._s;
  char * str2 = s2._s;

  for(int i = 0; i < totalLen; i++){
	if(i < s1.length()){
		s._s[i] = str1[i];
        } else {
		s._s[i] = str2[i - s1.length()];
    	}
  }

 return s;
}

