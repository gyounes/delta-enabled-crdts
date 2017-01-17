//-------------------------------------------------------------------
//
// File:      id-gen.h
//
// @author    Georges Younes <georges.r.younes@gmail.com>
//
// @copyright 2016-2017 Georges Younes
//
// This file is provided to you under the Apache License,
// Version 2.0 (the "License"); you may not use this file
// except in compliance with the License.  You may obtain
// a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License. 
//
//
//-------------------------------------------------------------------

#ifndef IDGEN_H_
#define IDGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define N127 0x7f
#define N128 0x80
#define Compression 1

typedef struct _ByteArray{
  size_t len; /**< Number of bytes in the `data` field. */
  uint8_t* data; /**< Pointer to an allocated array of data bytes. */
} ByteArray;

void coutByteArray(ByteArray ba);

void printByteArray(ByteArray ba);

ByteArray decompress(ByteArray compba);

int isTopVal(ByteArray ba);

int getNumberOfSevenBits(int num);

ByteArray compress(ByteArray ba);

int is_full(ByteArray ba, int start);

ByteArray incrementByteArray(ByteArray ba);

ByteArray ByteArray_GenerateBetween(ByteArray ba1, ByteArray ba2, int withCompression);

int compare(ByteArray a, ByteArray b);

int lessThan(ByteArray a, ByteArray b);

int greaterThan(ByteArray a, ByteArray b);

int equalsTo(ByteArray a, ByteArray b);

struct node {
    ByteArray ba;
    struct node *next;
};
typedef struct node node;

/* linked list functions */
int Delete(node *, ByteArray);
void Traverse(node *);
node * createList();

node * InsertAfter(node *pos);

void pushFront(node *head);

void pushBack(node *head);

int Delete(node *head, ByteArray ba);
 
void Traverse(node * head);

void printSeqSize(node * head);

void testDecompress();

void testPushFront();

void testPushBack();

void testInsertAfter();

void testGenerateBetween();

void testCompress();

ByteArray getByteArrayAt(node* head, int pos);

node * insertAfterPos(node* head, int pos);

void randomInsertTest(int max);

#endif // IDGEN_H_