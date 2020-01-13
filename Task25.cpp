#include <iostream>

int strcmp(const char* string1, const char* string2) {
	size_t i = 0;
	while ((string1[i] != '\0') && (string2[i] != '\0')) {
		if (string1[i] != string2[i])
			return string1[i] - string2[i];
		i++;
	}

	return 0;
}

int main()
{
	const int SIZE = 10;
	bool t=false;

	struct Student
	{
		char name[101];
		short group;
		short sec[5];
	};

	Student stud[SIZE]
	{
		{ "HZubenko M. P.", 2 , {2,5,5,5,5,}},
	    { "ZMemvedov V. D.", 2 , {2,5,5,5,5,}},
		{ "FTandirov V. I.", 2 , {2,5,2,5,5,}},
		{ "DTanaev V. I.", 2 , {2,5,5,5,5,}},
		{ "BTanaev V. I.", 2 , {2,5,5,3,5,}},
		{ "AAFTanaev V. I.", 7 , {2,5,5,5,5,}},
		{ "GTanaev V. I.", 2 , {2,5,5,4,5,}},
		{ "ETanaev V. I.", 2 , {2,5,5,4,5,}},
		{ "AACTanaev V. I.", 2 , {2,5,5,4,5,}},
		{ "AABTanaev V. I.", 3 , {2,5,5,4,5,}}
	};

	

	
	Student k;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (strcmp(stud[j].name, stud[j+1].name) > 0)
			{
				std::swap(stud[j], stud[j + 1]);
			}
		}
	}
	
	
	for (int i=0 ; i < SIZE; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (stud[i].sec[j] <= 3)
			{
				std::cout << stud[i].name << " " << stud[i].group << "\n";
				t = true;
				break;
			}
		}
	}
	if (t == false) std::cout << "not found";
}