/*
// Morse Code Header
// Last-Modified:2019-8-8 17:09:25
// Copyright (C)2019 Michael Jiang <sencom1997@outlook.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef MORSECODE_H
#define MORSECODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char  data;
    struct Node* left;
    struct Node* right;
}Node;
void putNumNode(Node* root,int row,int col);
void putCharNode(Node* root,int row,int col);
void makeMorseTree(Node* root);//this func call putNumNode() and putCharNode() to make a morse code tree
void preOrder(Node* root);//DLR Morse Tree for test
char findCode(Node* root, char* temp,int index);
const char* decodeMorseCode(Node* root,const char* src);
const char* encodeMorseCode(const char* src);

#endif