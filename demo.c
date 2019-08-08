/*
this file used for the morse code encode test.
*/
#include "morsecode.h"

int main()
{
    //init the root node
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = '?';//the root data part stored value '?'
    root->left = NULL;
    root->right = NULL;

    //make tree
    makeMorseTree(root);

    //encode and decode
    const char* morse = encodeMorseCode("BH6AOL");
    const char* plain = decodeMorseCode(root,"_._. __._ / _._. __._");

    //print the result
    printf("BH6AOL --> %s\n", morse);
    printf("_._. __._ / _._. __._ --> %s\n", plain);

    return 0;
}