// -----------------------------------------------------------------------
// file: KBTree.cpp
// Author: Jake A. Cole
// Last modified: 5/7/2013
// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
// KBTree is a binary tree that stores questions
// and beverages pertaining to that question in a knowledge base
// -----------------------------------------------------------------------

#include "KBTree.hpp"

using namespace std;

// -----------------------------------------------------------------------
// Insert inserts questions as well as answers pertaining
// to the questions to the knowledge base tree

void KBTree::insert(const string& q, const string& yes, const string& no) {
    if (root != 0) {
        temp = current->el;
        current->left = new KBNode(yes);
        current->right = new KBNode(temp);
        current->el = q;
    }

    if (root == 0) {
        root = new KBNode(q);
        root->left = new KBNode(yes);
        root->right = new KBNode(no);
    }
}

// -----------------------------------------------------------------------
// Fill checks if there is an input file and fills in the tree with
// the input file if available, or asks the user to start the tree

void KBTree::Fill() {
    ifstream infile("KB.txt");

    if(!infile.is_open()) {                                                     //allows user to create a tree
        cout << "Please enter a yes or no question about a beverage." << endl;
        getline (cin, question);
        cout << endl;

        cout << "A beverage that the answer yes applies to." << endl;
        getline (cin, yes);
        cout << endl;

        cout << "A beverage that the answer no applies to." << endl;
        getline (cin, no);
        cout << endl;

        if (question.find('?') == -1) question.append("?");

        insert(question, yes, no);
    }

    else {
        if(infile.get() == '0') {            //adds in root and calls infile
            getline(infile, temp);
            root = new KBNode(temp);
            input(infile, root);
            infile.close();
        }
        else {
            cout << "Input file KB.txt is corrupted." << endl;
            infile.close();
        }
    }
}

// -----------------------------------------------------------------------
// Input inserts nodes into the knowledge base tree from the file KB.txt

void KBTree::input(ifstream& ifstrm, KBNode *kb) {
    string temp;

    if(ifstrm.peek() == '2') {                                              //returns if it is a right child
        if(ifstrm.peek() == '1' || ifstrm.peek() == '2' ) ifstrm.get();
        return;
    }

    if(ifstrm.peek() == '1') {                                              //adds in nodes if it is a left child
        if(ifstrm.peek() == '1' || ifstrm.peek() == '2' ) ifstrm.get();
        getline(ifstrm, temp);
        kb->left = new KBNode(temp);
        input(ifstrm, kb->left);

        if(ifstrm.peek() == '1' || ifstrm.peek() == '2' ) ifstrm.get();
        getline(ifstrm, temp);
        kb->right = new KBNode(temp);
        input(ifstrm, kb->right);
    }
}

// -----------------------------------------------------------------------
// Query allows the user to interact with the knowledge base

void KBTree::Query() {
    int q = 0;

    Fill();

    current = root;

    cout << "Type quit to quit this program and print the tree to the screen and output file." << endl << endl;

    while (q == 0)                                                  //while loop allows the user to quit if they choose to
        while('?') {

            //-------------------------------------------------------------------------
            // If the node is a leaf

            if(current->left == 0 && current->right == 0) {
                    cout << "Is your beverage " << current->el << endl;
                    getline (cin, choice);
                    cout << endl;

                if(choice == "yes" || choice == "YES" || choice == "Yes") {
                    cout << "I Guessed it right!" << endl;
                    current = root;
                    break;
                }

                else if(choice == "no" || choice == "NO" || choice == "No") {
                    cout << "I give up, what is your beverage?" << endl;
                    getline (cin, newbev);
                    cout << endl;

                    cout << "Enter a question about that beverage which applies to " << newbev << " and not to " << current->el << endl;
                    getline (cin, question);
                    cout << endl;

                    if (question.find('?') == -1) question.append("?");

                    insert(question, newbev, current->el);
                    current = root;
                    break;
                }

                else if( choice == "quit" || choice == "QUIT" || choice == "Quit") {
                    cout << "See you next time." << endl << endl;
                    print();
                    q++;
                    break;
                }

                else cout << "Please enter valid input." << endl;
            }

            //-------------------------------------------------------------------------
            // If the node is a parent

            else if(current->left > 0 && current->right > 0){
                cout << current->el << endl;
                getline (cin, choice);
                cout << endl;

                if(choice == "yes" || choice == "YES" || choice == "Yes") {
                    current = current->left;
                }

                else if(choice == "no" || choice == "NO" || choice == "No") {
                    current = current->right;
                }

                else if( choice == "quit" || choice == "QUIT" || choice == "Quit") {
                    cout << "See you next time." << endl << endl;;
                    print();
                    q++;
                    break;
                }

                else cout << "Please enter valid input." << endl;
            }

        }
}

// -----------------------------------------------------------------------
// print outputs the tree in pre-order notation to
// the terminal as well as an output file

void KBTree::print(ofstream& ofstrm, KBNode *kb, int i) {
    if (kb != 0) {
        cout << kb->el << endl; //outputs to screen

        ofstrm << i << kb->el << endl; //outputs to file
        print(ofstrm, kb->left, 1);
        print(ofstrm, kb->right, 2);
    }
}









