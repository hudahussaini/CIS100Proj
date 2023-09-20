#include <iostream>
using namespace std;

class PersonInfo {
public:
    void   SetNumKids(int personsKidsToSet);
    void   IncNumKids();
    int    GetNumKids() const;
private:
    int    numKids;
};

void PersonInfo::SetNumKids(int personsKidsToSet) {
    numKids = personsKidsToSet;
}

void PersonInfo::IncNumKids() {
    numKids = numKids + 1;
}

int PersonInfo::GetNumKids() const {
    return numKids;
}

int main() {
    PersonInfo person1;
    int personsKids;

    cin >> personsKids;

    person1.SetNumKids(personsKids);

    /* Your solution goes here  */

    cout << "Kids: " << personsKids << endl;
    cout << "New baby, Kids now: " << print() << endl;




    return 0;
}