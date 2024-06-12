#include <iostream>
#include <vector>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent) {
                cout << "Parent : (tidak punya parent)" << endl;
            } else {
                cout << "Parent : " << node->parent->data << endl;
            }
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) {
                cout << "Sibling : " << node->parent->left->data << endl;
            } else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) {
                cout << "Sibling : " << node->parent->right->data << endl;
            } else {
                cout << "Sibling : (tidak punya sibling)" << endl;
            }
            if (!node->left) {
                cout << "Child Kiri : (tidak punya child kiri)" << endl;
            } else {
                cout << "Child Kiri : " << node->left->data << endl;
            }
            if (!node->right) {
                cout << "Child Kanan : (tidak punya child kanan)" << endl;
            } else {
                cout << "Child Kanan : " << node->right->data << endl;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            return max(heightKiri, heightKanan) + 1;
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

// Tampilkan Child
void displayChild(Pohon *node) {
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    } else {
        if (node->left) {
            cout << "Child Kiri : " << node->left->data << endl;
        } else {
            cout << "Child Kiri : (tidak punya child kiri)" << endl;
        }
        if (node->right) {
            cout << "Child Kanan : " << node->right->data << endl;
        } else {
            cout << "Child Kanan : (tidak punya child kanan)" << endl;
        }
    }
}

// Tampilkan Descendants
void displayDescendants(Pohon *node) {
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    } else {
        cout << "Descendants of " << node->data << ": ";
        preOrder(node);
        cout << endl;
    }
}

// Menu
void menu() {
    int choice;
    char data;
    Pohon *node = NULL;
    do {
        cout << "\n=== Menu Binary Tree ===" << endl;
        cout << "1. Buat Node Baru (Root)" << endl;
        cout << "2. Tambah Kiri" << endl;
        cout << "3. Tambah Kanan" << endl;
        cout << "4. Ubah Data Node" << endl;
        cout << "5. Lihat Data Node" << endl;
        cout << "6. Cari Data Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Hapus SubTree" << endl;
        cout << "11. Hapus Tree" << endl;
        cout << "12. Karakteristik Tree" << endl;
        cout << "13. Tampilkan Child Node" << endl;
        cout << "14. Tampilkan Descendants" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node baru: ";
                    cin >> data;
                    cout << "Masukkan data parent: ";
                    char parentData;
                    cin >> parentData;
                    node = root;
                    while (node && node->data != parentData) {
                        if (parentData < node->data) node = node->left;
                        else node = node->right;
                    }
                    insertLeft(data, node);
                }
                break;
            case 3:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node baru: ";
                    cin >> data;
                    cout << "Masukkan data parent: ";
                    char parentData;
                    cin >> parentData;
                    node = root;
                    while (node && node->data != parentData) {
                        if (parentData < node->data) node = node->left;
                        else node = node->right;
                    }
                    insertRight(data, node);
                }
                break;
            case 4:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin diubah: ";
                    char oldData;
                    cin >> oldData;
                    node = root;
                    while (node && node->data != oldData) {
                        if (oldData < node->data) node = node->left;
                        else node = node->right;
                    }
                    if (node) {
                        cout << "Masukkan data baru: ";
                        cin >> data;
                        update(data, node);
                    } else {
                        cout << "\nNode tidak ditemukan!" << endl;
                    }
                }
                break;
            case 5:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin dilihat: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        if (data < node->data) node = node->left;
                        else node = node->right;
                    }
                    retrieve(node);
                }
                break;
            case 6:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin dicari: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        if (data < node->data) node = node->left;
                        else node = node->right;
                    }
                    find(node);
                }
                break;
            case 7:
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                cout << endl;
                break;
            case 8:
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                cout << endl;
                break;
            case 9:
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                cout << endl;
                break;
            case 10:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin dihapus subtree-nya: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        if (data < node->data) node = node->left;
                        else node = node->right;
                    }
                    if (node) {
                        deleteSub(node);
                    } else {
                        cout << "\nNode tidak ditemukan!" << endl;
                    }
                }
                break;
            case 11:
                clear();
                break;
            case 12:
                characteristic();
                break;
            case 13:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin dilihat child-nya: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        if (data < node->data) node = node->left;
                        else node = node->right;
                    }
                    displayChild(node);
                }
                break;
            case 14:
                if (isEmpty()) {
                    cout << "\nBuat tree terlebih dahulu!" << endl;
                } else {
                    cout << "Masukkan data node yang ingin dilihat descendants-nya: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        if (data < node->data) node = node->left;
                        else node = node->right;
                    }
                    displayDescendants(node);
                }
                break;
            case 0:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 0);
}

int main() {
    init();
    menu();
    return 0;
}
