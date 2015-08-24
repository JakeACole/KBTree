// -----------------------------------------------------------------------
// file: KBTree.hpp
// Author: Jake A. Cole
// Last modified: 5/7/2013
// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
// Header file for KBTree
// -----------------------------------------------------------------------

#include "tools.hpp"

using namespace std;

class KBNode {
public:
    KBNode() {
        left = right = 0;
    }

    KBNode(const string& e, KBNode *l = 0, KBNode *r = 0) {
        el = e;
        left = l;
        right = r;
    }

    string el;
    KBNode *left, *right;
};

class KBTree {
protected:
    KBNode* root;
    KBNode *current;

    string question, yes, no, choice, newbev, temp;

    void print() {
        ofstream outfile ("KB.txt");
        print(outfile, root, 0);
        outfile.close();
    }

public:
    KBTree () {     // Constructor: Sets the root to null
        root = 0;
    }

    ~KBTree() {}

    void Fill();
    void Query();

    void insert(const string& q, const string& yes, const string& no);
    void print(ofstream& ofstrm, KBNode *kb, int i);
    void input(ifstream& ifstrm, KBNode *kb);

};




