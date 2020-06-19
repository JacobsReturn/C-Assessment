#include <iostream>
#include "Table.h"
#include "Players.h"
#include <fstream>

Table::Table()
{
	// initially allocate a single memory block
	max_size = 1;
	scores = new Players[max_size];
	length = 0;
}

Table::~Table()
{
    // The reason I don't have "delete" in here, is because this will probably be pointed at, so I call "remove()" before hand.
}

int Table::NumOfIndex() 
{
    int index = sizeof(Players) * length - 1;
    return index;
}

void Table::LoadFile()
{
    std::fstream loadData;
    loadData.open("Scoreboard.dat", std::ios_base::in | std::ios_base::binary | std::ios_base::ate);

    int COUNT = loadData.tellg() / sizeof(Players);

    loadData.seekg(0, std::ios_base::beg);

    if (loadData.good())
    {
        std::cout << "Loading data now " << COUNT << std::endl;
        for (int i = 0; i <= COUNT && loadData.good() && loadData.peek() != EOF; i++) {
            std::cout << "DATA " << i << " LOADED" << std::endl;
            Players buffer;

            loadData.read((char*)&buffer, sizeof(Players));

            AddTo(buffer);

            //delete buffer;
        }
    }

    loadData.close();
}

Players Table::Get(int pos) 
{
    return scores[pos];
}

void Table::SaveFile()
{
    std::fstream saveData;
    saveData.open("Scoreboard.dat", std::ios_base::out | std::ios_base::binary);
    
    if (saveData.good()) 
    {
        int sizeoffile = NumOfIndex();

        for (int i = 0; i < length; i++) 
        {
            std::cout << "Saving: " << scores[i].name << " (" << strlen(scores[i].name) << ")" << std::endl;

            if (strlen(scores[i].name) > 0)
            {
                saveData.write((char*)&scores[i], sizeoffile);

                return;
            }
        }
    }

    saveData.close();
}

void Table::Remove()
{
	delete[] scores;
}

bool Table::IsFull() {
	return length == max_size;
}

void Table::Resize(int s)
{
}

void Table::Remove(int pos)
{
    max_size--;
    Players* temp_scores = new Players[max_size];

    for (int i = 0; i < length; i++) {
        if (i < pos)
        {
            temp_scores[i] = scores[i];
        }
        else if (i > pos)
        {
            temp_scores[i - 1] = scores[i];
        }
    }

    delete[] scores;

    scores = temp_scores;

    // Adding a new item
    std::cout << "Removed player at: " << pos << "/" << length << std::endl;
    length--;

    Sort(true);
}

void Table::AddTo(Players player)
{
    // Checking for possible adding errors to fix.
    for (int i = 0; i < length; i++)
    {
        if (strcmp(scores[i].name, player.name) == 0 && scores[i].score != player.score)
        {
            scores[i].score = player.score;

            return;
        }
        else if (strlen(player.name) < 1) return;
        else if (strcmp(scores[i].name, player.name) == 0) return;
    }

    // Checking if its full, if so, resize it.
    if (IsFull()) {
        max_size = 2 * max_size;
        Players* temp_scores = new Players[2 * max_size];

        for (int i = 0; i < length; i++) {
            temp_scores[i] = scores[i];
        }

        delete[] scores;

        scores = temp_scores;
    }

    // Adding a new item.
    scores[length] = player;
    length++;

    Sort(true);
}

void swap(Players* xp, Players* yp)
{
    Players temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Table::Sort(bool ascending)
{
    int i, j;
    for (i = 0; i < length - 1; i++)
        for (j = 0; j < length - i - 1; j++)
            if (ascending && strncmp(scores[j].name, scores[j + 1].name, 10) == 1 || !ascending && strncmp(scores[j].name, scores[j + 1].name, 10) == 0)
                swap(&scores[j], &scores[j + 1]);
}

void Table::DisplayScores()
{
    DisplayScores(scores, length);
}

void Table::DisplayScores(Players* scores, int len)
{
    std::cout << "Displaying Scoreboard ("  << len << "):" << std::endl << "I. Name: Score" << std::endl;

    for (int i = 0; i < len; i++) {
        std::cout << i + 1 << ".  " << scores[i].name << ": " << scores[i].score << std::endl;
    }
}

int Table::BinarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;

        std::cout << m << ' ' << l << ' ' << r << std::endl;
    }

    return -1;
}