#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Set {
private:
    vector<int> elements;

public:
    void addElement(int element) {
        elements.push_back(element);
    }

    void inputSet(int setSize) {
        cout << "Enter the elements of the set: ";
        for (int i = 0; i < setSize; ++i) {
            int element;
            cin >> element;
            addElement(element);
        }
    }

    void displaySet() const {
        cout << "Set elements: ";
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

    bool isMember(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    vector<vector<int>> powerset() const {
        int n = elements.size();
        int powerSetSize = pow(2, n);
        vector<vector<int>> result;
        for (int i = 0; i < powerSetSize; ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(elements[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }

    bool isSubsetOf(const Set& otherSet) const {
        for (const auto& element : elements) {
            if (!otherSet.isMember(element)) {
                return false;
            }
        }
        return true;
    }

    Set unionWith(const Set& otherSet) const {
        Set unionSet;
        unionSet.elements = elements;
        for (const auto& element : otherSet.elements) {
            if (!isMember(element)) {
                unionSet.addElement(element);
            }
        }
        return unionSet;
    }

    Set intersectionWith(const Set& otherSet) const {
        Set intersectionSet;
        for (const auto& element : elements) {
            if (otherSet.isMember(element)) {
                intersectionSet.addElement(element);
            }
        }
        return intersectionSet;
    }

    Set complementOf(const Set& universalSet) const {
        Set complementSet;
        for (const auto& element : universalSet.elements) {
            if (!isMember(element)) {
                complementSet.addElement(element);
            }
        }
        return complementSet;
    }

    Set differenceWith(const Set& otherSet) const {
        Set differenceSet;
        for (const auto& element : elements) {
            if (!otherSet.isMember(element)) {
                differenceSet.addElement(element);
            }
        }
        return differenceSet;
    }

    Set symmetricDifferenceWith(const Set& otherSet) const {
        Set symmetricDifferenceSet = unionWith(otherSet).differenceWith(intersectionWith(otherSet));
        return symmetricDifferenceSet;
    }

    vector<pair<int, int>> cartesianProductWith(const Set& otherSet) const {
        vector<pair<int, int>> cartesianProductSet;
        for (const auto& elementA : elements) {
            for (const auto& elementB : otherSet.elements) {
                cartesianProductSet.emplace_back(elementA, elementB);
            }
        }
        return cartesianProductSet;
    }
};

int main() {
    int setSize;

    cout << "Enter the size of the sets: ";
    cin >> setSize;

    Set setA, setB;

    cout << "Enter the elements for Set A" << endl;
    setA.inputSet(setSize);

    cout << "Enter the elements for Set B" << endl;
    setB.inputSet(setSize);

    cout << "Set A: ";
    setA.displaySet();

    cout << "Set B: ";
    setB.displaySet();

    while (true) {
        cout << endl;
        cout << "SET Operations Menu:" << endl;
        cout << "1. Check if an element belongs to the set" << endl;
        cout << "2. List all elements of the power set" << endl;
        cout << "3. Check if one set is a subset of the other" << endl;
        cout << "4. Find the union of two sets" << endl;
        cout << "5. Find the intersection of two sets" << endl;
        cout << "6. Find the complement of a set" << endl;
        cout << "7. Find the set difference between two sets" << endl;
        cout << "8. Find the symmetric difference between two sets" << endl;
        cout << "9. Find the Cartesian product of two sets" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice (0-9): ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            int setNumber, element;
            cout << "Enter the set number (1 or 2): ";
            cin >> setNumber;
            cout << "Enter the element to check: ";
            cin >> element;
            if (setNumber == 1) {
                bool result = setA.isMember(element);
                cout << element << (result ? " belongs to Set A" : " does not belong to Set A") << endl;
            } else if (setNumber == 2) {
                bool result = setB.isMember(element);
                cout << element << (result ? " belongs to Set B" : " does not belong to Set B") << endl;
            } else {
                cout << "Invalid set number." << endl;
            }
        } else if (choice == 2) {
            vector<vector<int>> powerSetA = setA.powerset();
            vector<vector<int>> powerSetB = setB.powerset();

            cout << "Power Set of Set A:" << endl;
            for (const auto& subset : powerSetA) {
                cout << "{ ";
                for (const auto& element : subset) {
                    cout << element << " ";
                }
                cout << "}" << endl;
            }

            cout << "Power Set of Set B:" << endl;
            for (const auto& subset : powerSetB) {
                cout << "{ ";
                for (const auto& element : subset) {
                    cout << element << " ";
                }
                cout << "}" << endl;
            }
        } else if (choice == 3) {
            bool isSubset = setA.isSubsetOf(setB);
            cout << (isSubset ? "Set A is a subset of Set B" : "Set A is not a subset of Set B") << endl;
        } else if (choice == 4) {
            Set unionSet = setA.unionWith(setB);
            cout << "Union of Set A and Set B: ";
            unionSet.displaySet();
        } else if (choice == 5) {
            Set intersectionSet = setA.intersectionWith(setB);
            cout << "Intersection of Set A and Set B: ";
            intersectionSet.displaySet();
        } else if (choice == 6) {
            Set universalSet;
            cout << "Enter the elements of the universal set: ";
            universalSet.inputSet(setSize);

            Set complementSetA = setA.complementIn(universalSet);
            Set complementSetB = setB.complementIn(universalSet);

            cout << "Complement of Set A: ";
            complementSetA.displaySet();
            cout << "Complement of Set B: ";
            complementSetB.displaySet();
        } else if (choice == 7) {
            Set differenceSet = setA.differenceWith(setB);
            cout << "Set Difference (Set A - Set B): ";
            differenceSet.displaySet();
        } else if (choice == 8) {
            Set symmetricDifferenceSet = setA.symmetricDifferenceWith(setB);
            cout << "Symmetric Difference of Set A and Set B: ";
            symmetricDifferenceSet.displaySet();
        } else if (choice == 9) {
            vector<pair<int, int>> cartesianProductSet = setA.cartesianProductWith(setB);

            cout << "Cartesian Product of Set A and Set B:" << endl;
            for (const auto& pair : cartesianProductSet) {
                cout << "(" << pair.first << ", " << pair.second << ")" << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
