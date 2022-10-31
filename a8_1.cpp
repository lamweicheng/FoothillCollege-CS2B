#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAMESIZE = 24;

struct Highscore {

    char name[MAX_NAMESIZE];
    int score;
};

void getVectorSize(int& size);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
void displayData(const vector<Highscore>& scores);
vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& highScores,
    vector<Highscore>::iterator it);


int main(){

    int size;
    getVectorSize(size);
    vector<Highscore> highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);

    return 0;
}






void getVectorSize(int& size) {

    cout << "How many scores will you enter?: ";    
    cin >> size;
    cin.ignore();
}







void readData(vector<Highscore>& scores){

    int count = 0;
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++){

        cout << "Enter the name for score #" << (count + 1) << ": ";
        cin.getline(i->name, MAX_NAMESIZE, '\n');

        cout << "Enter the score for score #" << (count + 1) << ": ";
        cin >> i->score;
        cin.ignore();

        count++;
    }
    cout << endl;
}

 




void sortData(vector<Highscore>& scores) {

    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
     
        swap(indexOfLargest(scores, i)->name, i->name);
        swap(indexOfLargest(scores, i)->score, i->score);
    }
}






void displayData(const vector<Highscore>& scores){

    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator i = scores.begin(); i != scores.end(); i++){
        
        cout << i->name << ": " << i->score << endl;
    }
}






vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores,
    vector<Highscore>::iterator it) {

    vector<Highscore>::iterator largest = it;

    for (vector<Highscore>::iterator i = it; i != scores.end(); i++){

        if (i->score > largest->score){

            largest = i;
        }
    }
    return largest;
}


/*------------------------------Paste of Run #1----------------------------------------------
How many scores will you enter?: 2
Enter the name for score #1: Isabelle Hong
Enter the score for score #1: 10000000
Enter the name for score #2: Hong
Enter the score for score #2: 12344

Top Scorers:
Isabelle Hong: 10000000
Hong: 12344

(process 2356) exited with code 0.
Press any key to close this window . . .


--------------------------------------------------------------------------------*/

/*------------------------------Paste of Run #2----------------------------------------------
How many scores will you enter?: 4
Enter the name for score #1: Isabelle
Enter the score for score #1: 101
Enter the name for score #2: Laws
Enter the score for score #2: 0
Enter the name for score #3: Negativer
Enter the score for score #3: -10993
Enter the name for score #4: positiver
Enter the score for score #4: 1000000

Top Scorers:
positiver: 1000000
Isabelle: 101
Laws: 0
Negativer: -10993

(process 11276) exited with code 0.
Press any key to close this window . . .


--------------------------------------------------------------------------------*/