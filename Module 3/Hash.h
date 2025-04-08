#ifndef  HASH_H
#define HASH_H

class HashT
{
    public:
        HashT (int tableSize);
        ~HashT ();
        int search(int key);
        void isItemEqual(int key, int value);
        int retrieve(int key);
        int remove(int key);
        void insert(int key, int value);
        void print();

    private:
        struct HashNode
        {
            int key;
            int value;
            HashNode *next;
        };
        HashNode **table;
        int tableSize;
};

#endif // HASH_H