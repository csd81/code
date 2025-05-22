// Program 18_6
// 20 Questions Game
#include <iostream>
#include <string>
using namespace std;

class node {
	bool is_answer; //True if an "answer" node, False if a "question" node       
	string text; //The answer for an answer node, the question otherwise
	node* false_answer;
	node* true_answer;

public:
	node() {
		is_answer = true;
		text = "rock";
		false_answer = NULL;
		true_answer = NULL;
	}

	node(string s) {
		is_answer = true;
		text = s;
		false_answer = NULL;
		true_answer = NULL;
	}

	~node() {
		if (!is_answer) {
			delete false_answer;
			delete true_answer;   
			cout << "Deleting question: " << text << endl;

		}
	}
	                                                             
	bool ask_question() {
		if (is_answer) {
			//This is an answer node. 
			//Guess the answer, and if it's wrong, generate new nodes
			cout << "OK, I'm ready to guess: is it " << text << "? (Answer Yes or No): ";
			string answer;
			cin >> answer;
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
				getline(cin, question);
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
}

// This program is a simple implementation of a 20 Questions game using a binary tree structure.
// The program allows the user to play a guessing game where the computer tries to guess an object the user is thinking of by asking yes/no questions.
// The user can teach the program new objects and questions by providing feedback.
// The program uses a binary tree to represent the questions and answers, where each node can be either a question or an answer.
// The program is designed to be interactive, allowing the user to play multiple rounds of the game.
// The program uses dynamic memory allocation to create new nodes in the binary tree when the user teaches the program new objects and questions.
// the program also includes a destructor to free the memory allocated for the nodes when the program ends.
// this way memory leaks are avoided.

// binary tree is a data structure that consists of nodes, where each node has at most two children.
// it is implemented using a class called "node".
// the class has a constructor to initialize the node, a destructor to free memory, and a method to ask questions and process answers.
// the program uses a recursive approach to traverse the binary tree and ask questions.

// recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.
// in this program, the ask_question() method is called recursively to traverse the binary tree and ask questions until an answer node is reached.

// the ask_question() method is responsible for asking questions and processing user input.
// it checks if the current node is an answer or a question, and based on the user's response, it either returns true or false.
// if the user answers "yes", it continues to the true_answer node, and if the user answers "no", it goes to the false_answer node.

// an answer node represents a specific object that the program can guess.
// a question node represents a question that helps distinguish between two objects.
// the program uses a string variable called "text" to store the question or answer for each node.