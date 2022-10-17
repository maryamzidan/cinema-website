#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <istream>
#include <ctime>
#include<time.h>

using namespace std;

struct tm time1()
{
	time_t now;
	struct tm today;
	now = time(0);
	today = *localtime(&now);
	return today;
}
struct Time {
	int hours;
	int min;
};
struct Theatre {
	int ID_theatre;
	int capacity;
	int resevered_seats;
};
struct Screening_info {
	Theatre theater;
	Time time;
};
struct Films {
	string title;
	string actors[3];
	string director;
	string rate;
	Time duration;
	Screening_info screens[4];
};

Films arr_of_films[5];

int main() {

	ifstream output;
	output.open("Films.txt");
	string tmp;
	getline(output, tmp, '\n');                    //⁄‘«‰ «Ê· ”ÿ— › «·›«Ì· ›«÷Ï
	for (int i = 0; output.eof() == false; i++)
	{
		getline(output, arr_of_films[i].title, '|');
		for (int j = 0; j < 3; j++) {
			getline(output, arr_of_films[i].actors[j], '&');
		}
		getline(output, arr_of_films[i].director, '#');
		getline(output, arr_of_films[i].rate, '/');
		string str;                   //„‘ »ÌŒ“‰ »Ì«‰«  €Ì— › «” —Ì‰Ã (getline)
		getline(output, str, '@');
		arr_of_films[i].duration.hours = stoi(str);         // stoi --> string to int 
		getline(output, str, '*');
		arr_of_films[i].duration.min = stoi(str);

		
		
		for (int z = 0; z < 4; z++)       //loop for screens
		{
			getline(output, tmp, '+');
			arr_of_films[i].screens[z].theater.ID_theatre = stoi(tmp);
			getline(output, tmp, '-');
			arr_of_films[i].screens[z].theater.capacity = stoi(tmp);
			getline(output, tmp, '=');
			arr_of_films[i].screens[z].theater.resevered_seats = stoi(tmp);
			getline(output, tmp, ':');
			arr_of_films[i].screens[z].time.hours = stoi(tmp);
			getline(output, tmp, '$');
			arr_of_films[i].screens[z].time.min = stoi(tmp);
		}
		getline(output, tmp, '\n');

	}
	output.close();


	//////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 4; ++i) {
		cout << i + 1 << " - " << arr_of_films[i].title << endl;


	}
	bool check = 0;

	int num;
	while (true)
	{
		if (check == 0)
		{
			cout << "Write the number of the film you need:" << endl;
			cin >> num;
			cout << "title: " << arr_of_films[num - 1].title << endl;          // index start from 0
			cout << "actros: ";
			for (int i = 0; i < 3; ++i) {

				cout << arr_of_films[num - 1].actors[i] << ' ';
			}
			cout << endl;
			cout << "director: " << arr_of_films[num - 1].director << endl;
			cout << "rate: " << arr_of_films[num - 1].rate << endl;
			cout << "duration: " << arr_of_films[num - 1].duration.hours << " h " << arr_of_films[num - 1].duration.min << " min " << endl;
			cout << "----------------------------------------------" << endl;
			for (int i = 0; i < 4; i++) //„Ê«⁄Ìœ «·„ «ÕÂ ·ﬂ· ›Ì·„ («·«Œ Ì«—« 
			{
				cout << "choice : " << i + 1 << endl;                   //i start from 0 
				cout << "ID of theatre : " << arr_of_films[num - 1].screens[i].theater.ID_theatre << endl;
				cout << "Capacity of theatre :" << arr_of_films[num - 1].screens[i].theater.capacity << endl;
				cout << " Resevered seats :   " << arr_of_films[num - 1].screens[i].theater.resevered_seats << endl;
				cout << "Time of film : " << arr_of_films[num - 1].screens[i].time.hours << " h " << arr_of_films[num - 1].screens[i].time.min << " min " << endl;
				cout << "***********************************" << endl;

			}
		}
		
		if (num > 0 && num < 5) {                 // «·—ﬁ„ «··Ï ÂÌœŒ·Â «·ÌÊ“—
			check = 1;
			
			cout << "please ,Enter the time you want" << endl;
			int m ;
			cin >> m;
			
		int e = m;           // m :«·„⁄«œ «··Ï «·ÌÊ“— ÂÌœŒ·Â 
		                     //e: —ﬁ„ «·«”ﬂ—Ì‰
		int curTime;              // Êﬁ  «··«»
		if (e > 0 && e < 5) {
				int Time;
				Time = (arr_of_films[num - 1].screens[e - 1].time.hours) * 60;         //  ÕÊÌ· Êﬁ  «·›Ì·„ ·œﬁ«Ìﬁ
				Time += (arr_of_films[num - 1].screens[e - 1].time.min);
				tm today = time1();
				curTime = (today.tm_hour) * 60 + (today.tm_min);
				if (curTime <= (Time + 15)) 
				{
					cout << "How many tickets you want.Sir?" << endl;
					int numTic;
					cin >> numTic;
					int remain = arr_of_films[num - 1].screens[e - 1].theater.capacity - arr_of_films[num - 1].screens[e - 1].theater.resevered_seats;
					if (numTic <= remain) {
						cout << "Your reservation is completed "<<endl;
						break;
				  }

					else {
						cout << "Sorry,All places are reserved "<<endl;
						cout << "Do you want to reserve another time? (Y , N) " << endl;
						char choice1;
						cin >> choice1;
						if (choice1 == 'Y') {
							if (e > 3) {
								cout << " this the last party today" << endl;
								break;
							}
							else {
							       
								cout << " The time you have choosen is not avaliable , These are the suggestions" << endl;

								for (int i = e; i < 4; i++)        // for loop for the suggestion theatre
								{
									cout << "choice : " << i + 1 << endl;
									cout << "ID of theatre : " << arr_of_films[num - 1].screens[i].theater.ID_theatre << endl;
									cout << "Capacity of theatre :" << arr_of_films[num - 1].screens[i].theater.capacity << endl;
									cout << " Resevered seats :   " << arr_of_films[num - 1].screens[i].theater.resevered_seats << endl;
									cout << "Time of film : " << arr_of_films[num - 1].screens[i].time.hours << " h " << arr_of_films[num - 1].screens[i].time.min << " min " << endl;
									cout << "***********************************" << endl;
							
								}
								continue;
							}
						}
						else {
							cout << "Exit" << endl;
							break;
						}
					}
				}
				else {
					if (e > 3) {
						cout << " this the last party today" << endl;
						break;
					}

					else {
						//cout << " suggestion Time " << endl;               //suggestion time

						cout << "The time you have choosen is not avaliable , These are the suggestions" << endl;
						cout << "-----------------------------------" << endl;
						for (int i = e; i < 4; i++)
						{

							int Time;
							Time = (arr_of_films[num - 1].screens[i].time.hours) * 60;
							Time += (arr_of_films[num - 1].screens[i].time.min);
							if (curTime <= (Time + 15)) {
								cout << "choice : " << i + 1 << endl;
								cout << "ID of theatre : " << arr_of_films[num - 1].screens[i].theater.ID_theatre << endl;
								cout << "Capacity of theatre :" << arr_of_films[num - 1].screens[i].theater.capacity << endl;
								cout << " Resevered seats :   " << arr_of_films[num - 1].screens[i].theater.resevered_seats << endl;
								cout << "Time of film : " << arr_of_films[num - 1].screens[i].time.hours << " h " << arr_of_films[num - 1].screens[i].time.min << " min " << endl;
								cout << "***********************************" << endl;
							}
						
						}
						continue;


					}
					
				}

				//tm* ltm = localtime(&today);
				////int curTime = (today.tm_hour) * 60 + (today.tm_min);
				//cout << Time << " " << ltm->tm_hour << endl;
			}
			cout << "-----------------------------------------------" << endl;
			

		}
		else {
			cout << "Sorry, choose the correct number from the displayed list" << endl;
		}
	}
	cout<<"Exit,GoodBye"<<endl;



	
	//system("Pause");
}





   