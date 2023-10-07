#include  "TextFileQueue.h"

TextFileQueue::TextFileQueue(const TextFileQueue& SOURCE) {

	if (SOURCE.isEmpty()) {
		cout << "NOTE: Source TextFileQueue object is empty. An empty object will be created.\n";
		cout << "\n";
	}
	else {

		queueNode* sourceNode = SOURCE.front;

		front = new queueNode;
		rear = front;

		while (sourceNode != nullptr) {

			if (characters == 0) {
				front->letter = sourceNode->letter;
				front->next = nullptr;
			}
			else {
				rear->next = new queueNode;
				rear = rear->next;
				rear->letter = sourceNode->letter;
				rear->next = nullptr;
			}

		}

		characters = SOURCE.characters;

	}

}

TextFileQueue::~TextFileQueue() {

	queueNode* temp = nullptr;

	while (front != nullptr) {
		temp = front->next;
		delete front;
		front = temp;
		characters--;
	}

}

void TextFileQueue::enqueue(const char LETTER) {

	queueNode* newNode = new queueNode;
	newNode->letter = LETTER;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	}
	else {

		rear->next = newNode;
		rear = newNode;

	}

	characters++;

}

void TextFileQueue::dequeue(char& letter) {

	queueNode* temp = nullptr;

	if (isEmpty()) {
		cout << "ERROR: Queue is empty. Dequeue function has failed.\n";
	}
	else {

		letter = front->letter;
		temp = front->next;
		delete front;
		front = temp;
		characters--;

	}

}

void TextFileQueue::print(const string LABEL) {

	string line = "";

	cout << LABEL << "\n";
	for (int i = 0; i < LABEL.length(); i++) {
		line += "-";
	}

	cout << line << "\n";

	queueNode* currentNode = front;

	while (currentNode != nullptr) {
		cout << currentNode->letter;
		currentNode = currentNode->next;
	}

	cout << "\n";

}

bool TextFileQueue::isEmpty() const {

	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}

}