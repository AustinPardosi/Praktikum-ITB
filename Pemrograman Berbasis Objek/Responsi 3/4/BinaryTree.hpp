#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree() {
            this->numChildren = 0;
        }

        // Copy constructor
        BinaryTree(const BinaryTree<T>& other) {
            this->numChildren = other.numChildren;
            this->value = other.value;
            this->children = other.children;
        }

        // Destruktor
        ~BinaryTree() {}

        // Setter untuk value
        void setValue(const T & value) {
            this->value = value;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T val) {
            if (numChildren == 2) {
                throw "Tidak bisa memiliki lebih dari dua children\n";
            }
            BinaryTree<T> newChild;
            newChild.setValue(val);
            children.push_back(newChild);
            numChildren++;
            return children[numChildren-1];
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& x, BinaryTree<T> t) {
            int i;
            x << t.value;
            for (i=0; i < 2; i++) {
                x << "(";
                if (i < t.children.size()) {
                    x << t.children[i];
                }
                x << ")";
            }
            return x;
        }
};

#endif