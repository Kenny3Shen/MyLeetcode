/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <iostream>
// @lc code=start
class MyLinkedList
{

public:
    //define List
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr){};
    };

private:
    int _size;
    LinkedNode *_dummyHead;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index > (_size - 1) || index < 0) //invalid index
            return -1;

        LinkedNode *cur = _dummyHead->next;
        while (index--)
            cur = cur->next;

        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (cur->next) //find last node
            cur = cur->next;

        cur->next = newNode;
        _size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > _size) //invalid index
            return;
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (index--)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0)
            return;

        LinkedNode *cur = _dummyHead;
        while (index--)
            cur = cur->next;
        LinkedNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }

    void printList()
    {
        LinkedNode *cur = _dummyHead;
        while (cur->next)
        {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
