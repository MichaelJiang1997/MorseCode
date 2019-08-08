/*
Fast Morse Code Encoder && Decoder
Michael Jiang <sencom1997@outlook.com>
2019-8-7 15:31(七夕版)
*/
#include "morsecode.h"

char* ctable[] = {
    "._",   //A
    "_...", //B
    "_._.", //C
    "_..",  //D
    ".",    //E
    ".._.", //F
    "__.",  //G
    "....", //H
    "..",   //I
    ".___", //J
    "_._",  //K
    "._..", //L
    "__",   //M
    "_.",   //N
    "___",  //O
    ".__.", //P
    "__._", //Q
    "._.",  //R
    "...",  //S
    "_",    //T
    ".._",  //U
    "..._", //V
    ".__",  //W
    "_.._", //X
    "_.__", //Y
    "__.."  //Z

};
char* ntable[] = {
    "_____",//0
    ".____",//1
    "..___",//2
    "...__",//3
    "...._",//4
    ".....",//5
    "_....",//6
    "__...",//7
    "___..",//8
    "____." //9
};

void putNumNode(Node* root,int row,int col)
{
    if(ntable[row][col] == '_' && root->left == NULL){
        Node* temp = (Node*)malloc(sizeof(Node));
        root->left = temp;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = '#';//invalid node value stored '#'
        putNumNode(temp,row, ++col);
    }else if(ntable[row][col] == '_' && root->left != NULL){
        putNumNode(root->left,row, ++col);
    }else if(ntable[row][col] == '.' && root->right == NULL){
        Node* temp = (Node*)malloc(sizeof(Node));
        root->right = temp;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = '#';
        putNumNode(temp,row, ++col);
    }else if(ntable[row][col] == '.' && root->right != NULL){
        putNumNode(root->right,row, ++col);
    }else if(ntable[row][col] == '\0'){
        root->data = '0' + row;
    }
}

void putCharNode(Node* root,int row,int col)
{
    if(ctable[row][col] == '_' && root->left == NULL){
        Node* temp = (Node*)malloc(sizeof(Node));
        root->left = temp;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = '#';//invalid node value stored '#'
        putCharNode(temp,row, ++col);
    }else if(ctable[row][col] == '_' && root->left != NULL){
        putCharNode(root->left,row, ++col);
    }else if(ctable[row][col] == '.' && root->right == NULL){
        Node* temp = (Node*)malloc(sizeof(Node));
        root->right = temp;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = '#';//invalid node value stored '#'
        putCharNode(temp,row, ++col);
    }else if(ctable[row][col] == '.' && root->right != NULL){
        putCharNode(root->right,row, ++col);
    }else if(ctable[row][col] == '\0'){
        root->data = 'A' + row;
    }
}

void makeMorseTree(Node* root)
{
    //put char node
    for(int i = 0; i < 26; i++){
        putCharNode(root,i,0);
    }

    //put num node
    for(int i = 0; i < 10; i++){
        putNumNode(root,i,0);
    }
}

void preOrder(Node* root)
{
    printf("%c ",root->data);
    if(root->left != NULL)
        preOrder(root->left);
    if(root->right != NULL)
        preOrder(root->right);
}

char findCode(Node* root, char* temp,int index)
{
    if(root == NULL)
        return 35;//invalid code!
    else if(temp[index]=='/')
        return ' ';
    else if(temp[index] == '_')
        findCode(root->left,temp,++index);
    else if(temp[index] == '.')
        findCode(root->right,temp,++index);
    else if(temp[index] == '\0'){
        if(root->data == '#')
            return 35;//invalid code!
        else
            return root->data;
    }
}

const char* decodeMorseCode(Node* root,const char* src)
{
    char* dst = (char*)malloc(sizeof(char)*4096);
    char temp[6] = {'\0'};
    size_t index = 0;
    size_t offset = 0;
    for(size_t i = 0; i < strlen(src); i++){
        while(src[i] != ' ' && src[i] != '\0'){
            temp[offset++] = src[i++];
        }
        temp[offset] = '\0';
        dst[index++] = findCode(root, temp,0);
        offset = 0;
    }
    dst[index] = '\0';
    return dst;
}

const char* encodeMorseCode(const char* src)
{
    char* dst = (char*)malloc(sizeof(char)*4096);
    size_t index = 0;
    for(size_t i = 0; i < strlen(src); i++){
        if(src[i] >= '0' && src[i] <= '9'){
            for(size_t j = 0; j < strlen(ntable[src[i] - '0']); j++){
                dst[index++] = ntable[src[i] - '0'][j];
            }
        }
        else if(src[i] >= 'A' && src[i] <= 'Z'){
            for(size_t j = 0; j < strlen(ctable[src[i] - 'A']); j++){
                dst[index++] = ctable[src[i] - 'A'][j];
            }
        }
        else if(src[i] == ' '){
            dst[index++] = '/';
        }
        dst[index++] = ' ';
    }
    dst[index] = '\0';
    return dst;
}
