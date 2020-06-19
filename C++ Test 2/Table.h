#pragma once
#include "Players.h"

class Table
{
	private:

	public:
		Players* scores;

		int length;
		int max_size;

		Table();
		~Table();

		int NumOfIndex();
		void LoadFile();
		void SaveFile();
		bool IsFull();
		void Remove();
		void Resize(int s);
		void AddTo(Players player);
		void Remove(int pos);
		void DisplayScores();
		void DisplayScores(Players* scores, int len);
		void Sort(bool ascending);
		int BinarySearch(int arr[], int l, int r, int x);

		Players Get(int pos);
};