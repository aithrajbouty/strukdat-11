#include <iostream>
#include <stdlib.h>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void CreateTree(Tree& Root){
    Root = NULL;
}

void CreateSimpul(pointer& pBaru){
    pBaru = new Simpul;
    cout << "Masukkan satu huruf : "; cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST(Tree& Root, pointer pBaru){
    if(Root==NULL){
        Root = pBaru;
    }
    else if(pBaru->info < Root->info){
        insertBST(Root->left,pBaru);
    }
    else if(pBaru->info > Root->info){
        insertBST(Root->right,pBaru);
    }
    else{
        cout << "Sudah ada";
    }
}

void preOrder(Tree Root){
    if(Root!=NULL){
        cout << Root->info << endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder(Tree Root){
    if(Root!=NULL){
        inOrder(Root->left);
        cout << Root->info << endl;
        inOrder(Root->right);
    }
}

void postOrder(Tree Root){
    if(Root!=NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout << Root->info << endl;
    }
}

int kedalaman(Tree Root){
    int kiri,kanan;
    if(Root==NULL){
        return 0;
    }
    else{
        kiri = kedalaman(Root->left);
        kanan = kedalaman(Root->right);
        if(kiri>kanan){
            return(kiri+1);
        }
        else{
            return(kanan+1);
        }
    }
}

void level(Tree Root, int l){
    if(Root==NULL){
        return;
    }
    if(l==1){
        cout << Root->info << " ";
    }
    else if(l>1){
        level(Root->left,l-1);
        level(Root->right,l-1);
    }
}

void urutanLevel(Tree Root){
    int dalam=kedalaman(Root);
    for(int i=1;i<dalam;i++){
        cout << i << " ";
        level(Root,i);
        cout << endl;
    }
}

void anak(Tree Root, pointer pBaru){
    pBaru = Root;
    if(pBaru!=NULL){
        cout << "Ayah   : " << pBaru->info << endl;
        cout << "Anak   : " << endl;
        if(pBaru->left==NULL){
            cout << "- Kiri : -" << endl;
        }
        else{
            cout << "- Kiri : " << pBaru->left->info << endl;
        }
        if(pBaru->right==NULL){
            cout << "- Kanan: -" << endl;
        }
        else{
            cout << "- Kanan: " << pBaru->right->info << endl;
        }

        cout << endl;
        anak(Root->left,pBaru);
        anak(Root->right,pBaru);
    }
}

int main()
{
    Tree r;
    pointer p;
    int n,menu;

    CreateTree(r);

    cout << "Masukkan jumlah: "; cin >> n;
    for(int i=0;i<n;i++){
        CreateSimpul(p);
        insertBST(r,p);
    }

    do{
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Masukkan" << endl;
        cout << "2. Pre Order" << endl;
        cout << "3. In Order" << endl;
        cout << "4. Post Order" << endl;
        cout << "5. Kedalaman" << endl;
        cout << "6. Level" << endl;
        cout << "7. Anak" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih salah satu menu : "; cin >> menu;
        cout << endl;

        switch(menu){
        case 1:
            CreateSimpul(p);
            insertBST(r,p);
        break;

        case 2:
            cout << "Pre Order" << endl;
            preOrder(r);
        break;

        case 3:
            cout << "In Order" << endl;
            inOrder(r);
        break;

        case 4:
            cout << "Post Order" << endl;
            postOrder(r);
        break;

        case 5:
            cout << "Kedalaman pohon = " << kedalaman(r) << endl;
        break;

        case 6:
            cout << "Level pohon : " << endl;
            urutanLevel(r);
        break;

        case 7:
            anak(r,p);

        default :
            exit(0);
        }
        cout << endl;
        system("pause");
    }while(menu!=8);
}
