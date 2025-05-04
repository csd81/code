// Program 18_5
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