/**Author: Jared Callero
 * Program: hw3.cpp
 *
 */

using namespace std;

#include "hw3.h"
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <iostream>
#include<math.h>

bool treeLevelTraversal(Node *root, deque<int>* treeLevels, int level);

Node * Prog3::createBalancedBst(int *A, int n)
{
    
    int mid = n / 2;

    Node* newNode = new Node;

    if (n < 0){
        
        return nullptr;
    
    }

    Node *leftNode = createBalancedBst(A, mid - 1);
    Node *rightNode = createBalancedBst(A + mid + 1, mid - 1);

    newNode->data_ = A[mid];
    newNode->left_ = leftNode;
    newNode->right_ = rightNode;
    newNode->size_ = n + 1;
    return newNode;
    
}

void Prog3::zigzagLevelTraversal(Node *root)
{
    int height = log2(root->size_);
    deque<int>* treeLevels = new deque<int>(height);
    string result = "", append = "";

    for(int i = 0; i < height; i++){

        treeLevels[i] = deque<int>();

    }

    treeLevelTraversal(root, treeLevels, 0);

    for(int i = 0; i < height; i++){

        int levelsize = treeLevels[i].size();

        for(int j = 0; j < levelsize; j++){

            append = to_string(treeLevels[i][j]) + ", ";
            result.append(append);

        }
    }

    result.erase(result.size()-2, 2);

    cout << result;
}

bool treeLevelTraversal(Node *root, deque<int>* treeLevels, int level){

    if(root == nullptr) return false;
    
    bool isLeft = level % 2;

    if(isLeft)treeLevels[level].push_front(root->data_);
    else treeLevels[level].push_back(root->data_);

    return treeLevelTraversal(root->left_, treeLevels, level+1) || treeLevelTraversal(root->right_, treeLevels, level+1);

}

int Prog3::gap(Node *root, Node *p, Node *q)
{

    set<int> pPath, qPath;
    Node *pTravel = root;
    Node *qTravel = root;
    bool pdone = false, qdone = false, allDone = false;
    int pValue, qValue;

    //cout << "p = " << p->data_ << ", q = " << q->data_ << endl; 

    // edge case, p = q
    if (p->data_ == q->data_){
        //cout << "P and Q are the same, returning edge case" << endl;
        return 0;
    }
    // main loop
    while (!allDone)
    {
        //cout << "pTravel.data =" << pTravel->data_ << ", qTravel.data =" << qTravel->data_ << endl;

        if (!pdone)
        {

            pValue = pTravel->data_;
            if (pTravel->data_ > p->data_)
                pTravel = pTravel->left_;
            else if (pTravel->data_ < p->data_)
                pTravel = pTravel->right_;
            else
                pdone = true;
        }

        if (!qdone)
        {

            qValue = qTravel->data_;
            if (qTravel->data_ > q->data_)
                qTravel = qTravel->left_;
            else if (qTravel->data_ < q->data_)
                qTravel = qTravel->right_;
            else
                qdone = true;
        }

        //cout << "pValue = " << pValue << ", qValue =" << qValue << endl;

        if (pValue != qValue)
        {

            pPath.insert(pValue);
            qPath.insert(qValue);
        }

        if(pdone && qdone) allDone = true;
    }

    // conclusion

    return pPath.size() + qPath.size();
}

long long Prog3::pathSum(Node *root, Node *p, Node *q)
{

    set<long long> gap;
    Node *pTravel = root;
    Node *qTravel = root;
    bool pdone = false, qdone = false, pleft = false, qleft = false, isSplit = false, allDone = false;
    long long pValue, qValue;
    long long result = 0;

    // edge case, p = q
    if (p->data_ == q->data_)
    {

        result = q->data_;
        return result;
    }

    // main loop
    while (!allDone)
    {

        if (!pdone)
        {

            pValue = (long long)pTravel->data_;
            if (pTravel->data_ > p->data_)
                pleft = true;
            else if (pTravel->data_ < p->data_)
                pleft = false;
            else
                pdone = true;
        }

        if (!qdone)
        {

            qValue = (long long)qTravel->data_;
            if (qTravel->data_ > q->data_)
                qleft = true;
            else if (qTravel->data_ < q->data_)
                qleft = false;
            else
                qdone = true;
        }

        if (pleft != qleft)
            isSplit = true;

        if (isSplit)
        {

            gap.insert(pValue);
            gap.insert(qValue);
        }

        if (!pdone)
        {

            if (pleft)
                pTravel = pTravel->left_;
            else
                pTravel = pTravel->right_;
        }

        if (!qdone)
        {

            if (qleft)
                qTravel = qTravel->left_;
            else
                qTravel = qTravel->right_;
        }

        if(pdone && qdone) allDone = true;
    }

    // conclusion

    for (long long number : gap)
    {

        result += number;
    }

    return result;
}

int Prog3::kthLargest(Node *root, int k)
{

    int curr;

    while (root)
    {

        if (root->left_ != nullptr)
            curr = root->left_->size_ + 1;
        else
            curr = 1;


        if (k > curr){
                root = root->left_;
                k = k - curr;
        }
        else if (k < curr)
        {

            root = root->right_;
        }
        else break;
    }
    return root->data_;
}