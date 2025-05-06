// Program 18_5
// 20 Questions Game
#include <iostream>
#include <string>
using namespace std;

class node {
	bool is_answer; 		//True if an "answer" node, False if a "question" node

	string text;		 	//The answer for an answer node, the question otherwise
	
	node* false_answer; // we declared this as a pointer to a node object
	node* true_answer;

public:
	node() { 					 // Default constructor
		is_answer = true;		//This is an answer node
		text = "rock";			//Default answer is "rock"
		false_answer = NULL; 	 // false_answer is a pointer to a node object
		true_answer = NULL;  	// true_answer is a pointer to a node object
	}

	node(string s) {								// Constructor with a string argument, which is the answer
		is_answer = true;  // This is an answer node 
		text = s;
		false_answer = NULL;
		true_answer = NULL;
	}

	bool ask_question() {  					// This function asks the question and gets the answer
		if (is_answer) {
			//This is an answer node. 
			//Guess the answer, and if it's wrong, generate new nodes
			cout << "OK, I'm ready to guess: is it " << text << "? (Answer Yes or No): ";
			string answer;
			cin >> answer; // Get the answer
			if ((answer == "Yes") || (answer == "yes") || (answer == "y") || 
				(answer == "Y")) {
				return true;
			}
			else {
				cout << "What were you thinking of? ";
				cin >> answer;
				cout << "Help me learn.  What is a question that would help me distinguish "
					<< text << " from " << answer << "? " << endl;
				cout << " (The answer to the question should be Yes for " << answer 
					<< " and No for " << text << ".)" << endl;
				string question;
				getline(cin, question); 
				getline(cin, question); // Clear the input buffer
				true_answer = new node(answer);
				false_answer = new node(text);
				text = question;
				is_answer = false;
				return false;
			}
		}
		else {
			//This is a question node.  Ask the question, get the answer, and go to a child
			cout << text;
			cout << " (Answer Yes or No): ";
			string answer;
			cin >> answer;
			if ((answer == "Yes") || (answer == "yes") || (answer == "y") ||
				(answer == "Y")) {
				return true_answer->ask_question();
			}
			else {
				return false_answer->ask_question();
			}
		}
	}
};

int main()
{
	node firstnode;

	cout << "Would you like to play 20 questions? ";
	string answer;
	cin >> answer;
	while ((answer == "Yes") || (answer == "yes") || (answer == "y") || 
		(answer == "Y")) {
		if (firstnode.ask_question()) {
			cout << endl << "I won!!!" << endl;
		}
		else {
			cout << endl << "OK, I guess I lost..." << endl;
		}
		cout << "Would you like to play again? ";
		cin >> answer;
	}                   
	// the delete operator is not used in this program, which means that the memory allocated for the nodes will not be freed when the program ends.
	cout << "Thanks for playing!" << endl;
	
	
	return 0;
	
}

// This program is a simple implementation of a 20 questions game.
// The user thinks of an object, and the program tries to guess it by asking questions.
// If the program guesses wrong, it asks the user to provide a new question and answer.
// The program uses a binary tree structure to store the questions and answers.
// The user can play the game multiple times, and the program learns from each game.
// The program uses a class called "node" to represent each node in the binary tree.
// The class has methods to ask questions and store new questions and answers.
// The program uses dynamic memory allocation to create new nodes as needed.

// a binary tree is a tree data structure in which each node has at most two children.
// The two children are referred to as the left child and the right child.
// In this program, the left child represents the "No" answer and the right child represents the "Yes" answer.
// The program uses a recursive approach to traverse the tree and ask questions.
// The program starts with a default answer of "rock" and builds the tree as the user plays the game.

// the program learns from the user's input and updates the tree structure accordingly.
// learnig is done by asking the user to provide a new question and answer when the program guesses wrong.
// The new question is added to the tree, and the new answer is stored in a new node.

// dynamic memory allocation is used to create new nodes as needed.
// The program uses the "new" operator to allocate memory for new nodes and the "delete" operator to free memory when it is no longer needed.

// the delete operator is not used in this program, which means that the memory allocated for the nodes will not be freed when the program ends.
// This can lead to memory leaks if the program is run multiple times.


// the progam stores the questions and answers in a binary tree structure.
// The tree is built dynamically as the user plays the game.
// The program uses a recursive approach to traverse the tree and ask questions.
