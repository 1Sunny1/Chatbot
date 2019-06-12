#include "Chatbot.h"
#include <fstream>
#include <random>
#include <cstdio>
#include <algorithm>
#include <functional>

std::mt19937 gen{ std::random_device{}() };
template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

Chatbot::Chatbot() {
	loadDataFromFiles(listOfKeyWords, "Keywords.txt");
	loadDataFromFiles(chatbotNameList, "ChatbotNames.txt");
	pickNameForChatbot();
	startDialogue();
	std::string userInput = getUserInput();
	while (userInput != "exit") {
		std::cout << answerToTheUser(userInput) << '\n';
		userInput = getUserInput();
	}
}

void Chatbot::loadDataFromFiles(std::vector<std::string> & container, const std::string & filename) {
	std::fstream _file(filename);
	if (!_file)
		std::cout << "Couldn't open " << filename << "!\n";

	std::string lineToReadFromFile;
	while (getline(_file, lineToReadFromFile))
		container.push_back(lineToReadFromFile);
}

void Chatbot::pickNameForChatbot() {
	if (chatbotNameList.empty()) {
		std::cout << "Cannot pick bot name - containers are empty!\n";
		std::getchar();
		exit(1);
	} else {
		int randomNumber = random<int>(0, chatbotNameList.size() - 1);
		chatbotName = chatbotNameList[randomNumber];
	}
}

void Chatbot::startDialogue() {
	std::cout << "Hello, i am " << chatbotName << ". How can i help you? :)\n";
}

std::string Chatbot::getUserInput() {
	std::string tempString;
	getline(std::cin, tempString);
	return tempString;
}

std::string Chatbot::answerToTheUser(std::string & userIn) {
	if ( std::search(userIn.begin(), userIn.end(),
		std::boyer_moore_searcher(x.begin(), x.end()))) 
		return "Kinda hot today.";
	else if (userIn.find("joke") && userIn.find("Joke"))
		return "java.";
	else
		return "sorry i don't understand.";

	/* */


}