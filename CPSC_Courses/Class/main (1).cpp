#include "BST.h"

int main(){

    BST<int> tree;

    tree.insert(4);
    tree.insert(10);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    cout << "The size is: " << tree.getSize() << endl;
    // cout << "=== Print Tree In Order ===" << endl;
    // tree.printTreeInOrder();
    // cout << "=== Print Tree Post Order ====" << endl;
    // tree.printTreePostOrder();
    cout << "=== Testing contains ====" << endl;
    cout << tree.contains(10) << endl;
    cout << tree.contains(5) << endl;
    cout << "=== Testing remove ===" << endl;
    cout << "remove 1" << endl;
    tree.remove(1);
    cout << "-- Result of remove --" << endl;
    cout << "remove 10" << endl;
    tree.remove(10);
    cout << "remove 3" << endl;
    tree.remove(3);
    cout << "remove 6" << endl;
    tree.remove(6);
    cout << "end remove 6" << endl;

    //tree.printTreeInOrder();
    // cout << "remove 4" << endl;
    // tree.remove(4);
    // cout << "end remove 4" << endl;
    // tree.printTreeInOrder();

    return 0;
}