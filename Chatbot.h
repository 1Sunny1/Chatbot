#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <vector>
#include <iostream>

class Chatbot {
private:
	std::vector<std::string> listOfKeyWords;
	std::vector<std::string> chatbotNameList;
	std::string chatbotName;

	void loadDataFromFiles(std::vector<std::string> & v, const std::string & filename);
	void pickNameForChatbot();
	void startDialogue();
	std::string getUserInput();
	std::string answerToTheUser(std::string &);
	std::string findKeyword(std::string &);

public:
	Chatbot();
	~Chatbot() = default;
};

#endif