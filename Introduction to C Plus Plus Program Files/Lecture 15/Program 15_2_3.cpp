// Program 15_2_3
// Example bottom-up program - string processing (incomplete) - Stage 3
#include <iostream>
#include <string>
using namespace std;

int pos_first(string& string_to_find, string& string_to_search) {
	/* Returns the first position of string_to_find in string_to_search, 
	or -1 if it is not in there */
	//Code Here
}

void replace_string(string& string_to_modify, int start_pos, int end_pos, 
	string& string_to_insert) {
	/* Inserts string_to_insert into string_to_modify, replacing anything 
	in positions start_pos to just BEFORE end_pos */
	//Code Here
}

bool search_and_replace(string& string_to_modify, string& old_string, 
	string& new_string) {
	/* Replaces first occurrence of old_string with new_string and returns 
	true, or returns false if it did not find old_string */
	int start_position = pos_first(old_string, string_to_modify);
	if (start_position == -1) {
		return false;
	}
	int end_position = start_position + old_string.size();
	replace_string(string_to_modify, start_position, end_position, new_string);
	return true;
}

void search_and_replace_all(string& string_to_modify, string& old_string, 
	string& new_string) {
	/* Replaces every occurrence of old_string with new_string and returns 
	true, or returns false if it did not find old_string */
	while (search_and_replace(string_to_modify, old_string, new_string)) {}
}

int main()
{
	//Code Here      
}