#include "Strings.h"
#include <assert.h>
#include <cctype>
#include <string.h>



String::String(){

}

String::String(const char* str){
	assert(str != NULL); 
	int length = strlen(str);
	string = new char[length + 1];
	strcpy_s(string, length + 1, str);
}

String::String(char* str){
	assert(str != NULL);
	int length = strlen(str);
	string = new char[length + 1];
	strcpy_s(string, length + 1, str);
}

String::String(const String& str){
	int length = strlen(str.string);
	string = new char[length + 1];
	strcpy_s(string, length + 1, str.string);
}

unsigned int String::length(){
	return strlen(string);
}

bool String::isempty(){
	return (string[0] == NULL); 
}

void String::empty(){
	string[0] = '\0';
}

String::~String(){
	delete[] string; 
}

bool String::operator==(const String& str2) const{
	return (strcmp(string, str2.string) == 0);
}

bool String::operator==(const char* str2) const{
	return (strcmp(string, str2) == 0);
}

bool String::operator!=(const char* str2) const{
	return (strcmp(string, str2) != 0);
}

 String& String::operator=(char* str2){
	
	int length_str2 = strlen(str2);
	max_value = strlen(string) + 1; 
	
	if (max_value < length_str2){
		delete[] string;
		string = new char[length_str2 + 1];	
	}
	strcpy_s(string, length_str2 + 1, str2); 

	return *this;
}

 String& String::operator=(String*& str2){

	 int length_str2 = strlen(str2->string);
	 max_value = strlen(string) + 1;

	 if (max_value < length_str2){
		 delete[] string;
		 string = new char[length_str2 + 1];
	 }

	 strcpy_s(string, length_str2 + 1, str2->string);

	 return *this;
 }






 

const char* String::c_str(){
	return string; 
}
