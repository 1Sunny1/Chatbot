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
	while (userInput != "exit" && userInput != "Exit") {
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
	std::cout << "[type \"exit\" if you want to exit.]\nHello, i am " << chatbotName << ". How can i help you? :)\n";
}

std::string Chatbot::getUserInput() {
	std::string tempString;
	getline(std::cin, tempString);
	return tempString;
}

template <typename Container>
bool in_quote(const Container& cont, const std::string& s)
{
	return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

std::string Chatbot::findKeyword(std::string & userIn) {
	for (auto & keyword : listOfKeyWords)
		if (std::includes(userIn.begin(), userIn.end(),
			keyword.begin(), keyword.end())) //
			return keyword;
}

std::string Chatbot::answerToTheUser(std::string & userInput) {
	if (findKeyword(userInput) == listOfKeyWords[0])
		return "Kinda hot today.";
	else if (findKeyword(userInput) == listOfKeyWords[1])
		return "I am busy talking :)";
	else if (findKeyword(userInput) == listOfKeyWords[2])
		return "Why java programmers wear glasses? Because they can't C#!";
	else if (findKeyword(userInput) == listOfKeyWords[3])
		return "It is not so healthy snack. You should better eat some green!";
	else if (findKeyword(userInput) == listOfKeyWords[4])
		return "It's important, You should drink at least two liters per day.";
	else
		return "sorry i don't understand.";

	/*XD*/


}