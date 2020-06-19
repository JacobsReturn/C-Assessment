#include <iostream>
#include <string.h>
#include "Search.h"
#include "Players.h"

Search::Search()
{
	name = "Search for a users score";
}

Search::Search(int cmd)
{
	name = "Search for a users score";

	command = cmd;
}

Search::~Search()
{
}

void Search::Run(Table* scoreboard)
{
	std::cout << "// Searching a score //" << std::endl;

	std::cout << "Input a score to look for: ";

	//std::string strtmp;
	int strtmp;
	std::cin >> strtmp;

	if (!std::cin)
	{
		std::cout << "Failed inputting a name! (You have to restart the command now)" << std::endl;

		return;
	}

	//Players* testPlayer = new Players();

	//strcpy_s(testPlayer->name, strtmp.c_str());

	//int tempCount = 0;

	//int len = strtmp.length();

	// A temp handler.
	//Table* tempPlayers = new Table();

	// Adding to the array.

	// BINARY
	int* results = new int[scoreboard->length - 1];

	for (int i = 0; i < scoreboard->length; i++)
	{
		results[i] = scoreboard->scores[i].score;

		//std::cout << results[i] << std::endl;
	}

	int result = scoreboard->BinarySearch(results, 1, scoreboard->length, strtmp);

	if (result != -1)
	{
		Players ply = scoreboard->scores[result];

		std::cout << result << " " << strtmp << " " << scoreboard->length << std::endl;
		std::cout << "Displaying binary search result: " << std::endl << "- Name: " << ply.name << std::endl << "- Score: " << ply.score << std::endl;

		delete[] results;
	}
	else std::cout << "No results appeared." << std::endl;

	//

	// LINEAR
	//for (int i = 0; i < scoreboard->length; i++)
	//{
	//	bool working = false;
	//	//for (int ii = 0; ii <= sizeof(scoreboard->scores[i].name) / sizeof(char) && ii <= len; ii++)
	//	//{
	//	//	std::cout << (scoreboard->scores[i].name[ii] == testPlayer->name[ii]) << " " << scoreboard->scores[i].name[ii] << std::endl;

	//	//	/*if (scoreboard->scores[i].name[ii] == testPlayer->name[ii])
	//	//	{
	//	//		working = true;
	//	//	}*/
	//	//}

	//	if (strstr(scoreboard->scores[i].name, testPlayer->name) != NULL)
	//	{
	//		working = true;
	//	}

	//	if (working)
	//	{
	//		tempPlayers->AddTo(scoreboard->scores[i]);
	//		tempCount++;
	//	}
	//}

	//tempPlayers->Sort(true);

	//scoreboard->DisplayScores(tempPlayers->scores, tempCount);

	//delete testPlayer;
	//delete tempPlayers;
}
