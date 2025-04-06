#include <iostream>
using namespace std;

struct node{
    string role, namaPemain;
    node *next, *bot;
} *head, *tail, *C;

node *helpRole, *ganti;
string namaST,namaMD,namaDF,namaGK,delNama,namaPlay,swapNama;
string penampungHapus[11];
string penampungGanti[3];

int tmpung = 0;
int tmpungC = 0;

int countST = 2;
int countMD = 4;
int countDF = 4;
int countGK = 1;
int countDel = 3;
int countSwap = 3;

// jumlah pemain tiap posisi
int jumlahST = 0;
int jumlahMD = 0;
int jumlahDF = 0;
int jumlahGK = 0;

bool cekNm(string nama){
    int bntu = 0;
    node *posisi;
    posisi = head;
    while( posisi!=nullptr ){
        node *name = posisi;
        while( name!=nullptr ){
            if( name->namaPemain==nama ){
                bntu = 1;
                break;
            }
            name = name->bot;
        }
        posisi = posisi->next;
    }
    if( bntu==1 ){
        return true;
    } else{
        return false;
    }
}

bool cekCadangan(string nama){
    node *cek;
    int bantu = 0;
    cek = C;
    while( cek!=nullptr ){
        if( cek->namaPemain==nama ){
            bantu = 1;
            break;
        }
        cek = cek->bot;
    }
    if( bantu=1 ){
        return true;
    } else{
        return false;
    }
}

void addRole(node *newNode, string role){
    newNode = new node;
    newNode->role = role;
    newNode->next = nullptr;
    newNode->bot = nullptr;

    if (head == nullptr){
        head = newNode;
        tail = head;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}

// void addPemain(node *newBot, string role, string nama)
// {
//     helpRole = head;
//     while (helpRole != NULL)
//     {   
//         // Cek role
//         if (helpRole->role == role)
//         {
//             newBot = new node;
//             newBot->namaPemain = nama;
//             newBot->bot = NULL;
//             newBot->next = NULL;
//             // cout << "pemain masuk sini" << endl;
//             if (helpRole->bot == NULL)
//             {
//                 helpRole->bot = newBot;
//                 // cout << "Pemain sudah ditambahkan" << endl;
//             }
//             else
//             {
//                 node *helpBot = helpRole;
//                 while (helpBot->bot != NULL)
//                 {
//                     helpBot = helpBot->bot;
//                 }
//                 helpBot->bot = newBot;
//                 // cout << "pemain sudah ditambahkan" << endl;
//             }
//         }
//         helpRole = helpRole->next;
//     }
// }

// void delPemain(node *del, string posisi, string nama){
//     del = head;
//     node *bef;
//     while (del != NULL){
//         if (del->role == posisi){
//             node *temp = del;
//             while (temp != NULL){
//                 if (temp->bot->namaPemain == nama){
//                     bef = temp;
//                     del = bef->bot;
//                     break;
//                 }
//                 temp = temp->bot;
//             }
//             // cout << "bef: " << bef->role <<bef->namaPemain << endl;
//             // cout << "del: " << del->namaPemain << endl;
//             bef->bot = del->bot;
//             del->bot = nullptr;
//             del->next = nullptr;
//             delete del;
//         }
//         del = del->next;
//     }
// }

void addST(node *add, string nama){
    helpRole = head;
    if( cekNm(nama) ){
        countST++;
        cout << "gagal" <<endl;
    } else{
        while( helpRole!=nullptr ){   
            // Cek role
            if( helpRole->role=="ST" ){
                add = new node;
                add->namaPemain = nama;
                add->bot = nullptr;
                add->next = nullptr;
                if( helpRole->bot==nullptr ){
                    helpRole->bot = add;
                } else{
                    node *temp = helpRole;
                    while( temp->bot!=nullptr ){
                        temp = temp->bot;
                    }
                    temp->bot = add;
                }
            }
            helpRole = helpRole->next;
        }

        jumlahST++;
    }
}

// void delST(node *del, string nama){
//     del = head;
//     node *temp = del, *bef;
//     while( temp!=nullptr ){
//         if( temp->bot->namaPemain==nama ){
//             bef = temp;
//             del = bef->bot;
//             break;
//         }
//         temp = temp->bot;
//     }
//     bef->bot = del->bot;
//     del->bot = nullptr;
//     del->next = nullptr;
//     free(del);
// }

void delST(node *del, string nama){
    if( !cekNm(nama) ){
        countDel++;
        cout << "gagal" <<endl;
    } else{
        del = head;
        node *temp = del, *bef;
        while( temp!=nullptr ){
            if( temp->bot->namaPemain==nama ){
                bef = temp;
                del = bef->bot;
                break;
            }
            temp = temp->bot;
        }
        bef->bot = del->bot;
        del->bot = nullptr;
        del->next = nullptr;
        penampungHapus[tmpung] = del->namaPemain; // memasukan nama yang dihapus ke string
        tmpung++;
        free(del);

        jumlahST--;
    }
}

void cektakST(node *cetak){
    cetak = head;
    while( cetak!=nullptr ){
        if( cetak->role == "ST" ){
            node *temp = cetak;
            cout << cetak->role << " :";
            while( temp!=nullptr ){
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout <<endl;
}

void addMD(node *add, string nama){
    helpRole = head;
    if( cekNm(nama) ){
        countMD++;
        cout << "gagal" <<endl;
    } else{
        while( helpRole!=nullptr ){   
            // Cek role
            if( helpRole->role=="MD" ){
                add = new node;
                add->namaPemain = nama;
                add->bot = nullptr;
                add->next = nullptr;
                if( helpRole->bot==nullptr ){
                    helpRole->bot = add;
                } else{
                    node *temp = helpRole;
                    while( temp->bot!=nullptr ){
                        temp = temp->bot;
                    }
                    temp->bot = add;
                }
            }
            helpRole = helpRole->next;
        }

        jumlahMD++;
    }
}

// void delMD(node *del, string nama){
//     del = head;
//     while( del!=nullptr ){
//         if( del->role=="MD" ){
//             node *temp = del, *bef;
//             while( temp!=nullptr ){
//                 if( temp->bot->namaPemain==nama ){
//                     bef = temp;
//                     del = bef->bot;
//                     break;
//                 }
//                 temp = temp->bot;
//             }
//             bef->bot = del->bot;
//             del->bot = nullptr;
//             del->next = nullptr;
//             free(del);
//         }
//         del = del->next;
//     }
// }

void delMD(node *del, string nama){
    if( !cekNm(nama) ){
        countDel++;
        cout << "gagal" <<endl;
    } else{
        del = head;
        while( del!=nullptr ){
            if( del->role=="MD" ){
                node *temp = del, *bef;
                while( temp!=nullptr ){
                    if( temp->bot->namaPemain==nama ){
                        bef = temp;
                        del = bef->bot;
                        break;
                    }
                    temp = temp->bot;
                }
                bef->bot = del->bot;
                del->bot = nullptr;
                del->next = nullptr;
                penampungHapus[tmpung] = del->namaPemain; // memasukan nama yang dihapus ke string
                tmpung++;
                free(del);

                jumlahMD--;
            }
            del = del->next;
        }
    }
}

void cektakMD(node *cetak){
    cetak = head;
    while( cetak!=nullptr ){
        if( cetak->role == "MD" ){
            node *temp = cetak;
            cout << cetak->role << " :";
            while( temp!=nullptr ){
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout <<endl;
}

void addDF(node *add, string nama){
    helpRole = head;
    if( cekNm(nama) ){
        countDF++;
        cout << "gagal" <<endl;
    } else{
        while( helpRole!=nullptr ){   
            // Cek role
            if( helpRole->role=="DF" ){
                add = new node;
                add->namaPemain = nama;
                add->bot = nullptr;
                add->next = nullptr;
                if( helpRole->bot==nullptr ){
                    helpRole->bot = add;
                } else{
                    node *temp = helpRole;
                    while( temp->bot!=nullptr ){
                        temp = temp->bot;
                    }
                    temp->bot = add;
                }
            }
            helpRole = helpRole->next;
        }

        jumlahDF++;
    }
}

// void delDF(node *del, string nama){
//     del = head;
//     while( del!=nullptr ){
//         if( del->role=="DF" ){
//             node *temp = del, *bef;
//             while( temp!=nullptr ){
//                 if( temp->bot->namaPemain==nama ){
//                     bef = temp;
//                     del = bef->bot;
//                     break;
//                 }
//                 temp = temp->bot;
//             }
//             bef->bot = del->bot;
//             del->bot = nullptr;
//             del->next = nullptr;
//             free(del);
//         }
//         del = del->next;
//     }
// }

void delDF(node *del, string nama){
    if( !cekNm(nama) ){
        countDel++;
        cout << "gagal" <<endl;
    } else{
        del = head;
        while( del!=nullptr ){
            if( del->role=="DF" ){
                node *temp = del, *bef;
                while( temp!=nullptr ){
                    if( temp->bot->namaPemain==nama ){
                        bef = temp;
                        del = bef->bot;
                        break;
                    }
                    temp = temp->bot;
                }
                bef->bot = del->bot;
                del->bot = nullptr;
                del->next = nullptr;
                penampungHapus[tmpung] = del->namaPemain; // memasukan nama yang dihapus ke string
                tmpung++;
                free(del);

                jumlahDF--;
            }
            del = del->next;
        }
    }
}

void cektakDF(node *cetak){
    cetak = head;
    while( cetak!=nullptr ){
        if( cetak->role == "DF" ){
            node *temp = cetak;
            cout << cetak->role << " :";
            while( temp!=nullptr ){
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout <<endl;
}

void addGK(node *add, string nama){
    helpRole = head;
    if( cekNm(nama) ){
        countGK++;
        cout << "gagal" <<endl;
    } else{
        while( helpRole!=nullptr ){   
            // Cek role
            if( helpRole->role=="GK" ){
                add = new node;
                add->namaPemain = nama;
                add->bot = nullptr;
                add->next = nullptr;
                if( helpRole->bot==nullptr ){
                    helpRole->bot = add;
                } else{
                    node *temp = helpRole;
                    while( temp->bot!=nullptr ){
                        temp = temp->bot;
                    }
                    temp->bot = add;
                }
            }
            helpRole = helpRole->next;
        }

        jumlahGK++;
    }
}

// void delGK(node *del, string nama){
//     del = tail;
//     node *bef;
//     while( del!=nullptr ){
//         if( del->bot->namaPemain==nama ){
//             bef = del;
//             del = bef->bot;
//             break;
//         }
//         del = del->bot;
//     }
//     bef->bot = del->bot;
//     del->bot = nullptr;
//     del->next = nullptr;
//     free(del);
// }

void delGK(node *del, string nama){
    if( !cekNm(nama) ){
        countDel++;
        cout << "gagal" <<endl;
    } else{
        //
        del = tail->bot;
        tail->bot = nullptr;
        penampungHapus[tmpung] = del->namaPemain; // memasukan nama yang dihapus ke string
        tmpung++;
        free(del);
        cout << "Ganti dengan pemain Midfielder" <<endl;
        string str;
        node *tolong;
        tolong = head->next; //posisi MD
        ganti = head->next->bot; //pemain MD pertama
        cout << "Nama pemain : ";
        cin >> str;
        while( ganti!=nullptr ){
            if( ganti->namaPemain==str ){
                tolong->bot = ganti->bot;
                ganti->bot = nullptr;
                tail->bot = ganti;
                break;
            } else{
                tolong = tolong->bot;
                ganti = ganti->bot;
            }
        }

        jumlahMD--;
    }
}

void cektakGK(node *cetak){
    cetak = tail;
    node *temp = cetak;
    cout << cetak->role << " :";
    while( temp!=nullptr ){
        cout << temp->namaPemain << " ";
        temp = temp->bot;
    }
    cout <<endl;
}

void cariPemain(node *cari, string nama){
    cari = head;
    while( cari!=nullptr ){
        node *temp = cari;
        if( cari->role=="ST" ){
            while( temp!=nullptr ){
                if( temp->namaPemain==nama ){
                    cout << "Nama   : " << temp->namaPemain <<endl;
                    cout << "Posisi : " << cari->role <<endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if( cari->role=="MD" ){
            while( temp!=nullptr ){
                if( temp->namaPemain==nama ){
                    cout << "Nama   : " << temp->namaPemain <<endl;
                    cout << "Posisi : " << cari->role <<endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if( cari->role=="DF" ){
            while( temp!=nullptr ){
                if( temp->namaPemain==nama ){
                    cout << "Nama   : " << temp->namaPemain <<endl;
                    cout << "Posisi : " << cari->role <<endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if( cari->role=="GK" ){
            while( temp!=nullptr ){
                if( temp->namaPemain==nama ){
                    cout << "Nama   : " << temp->namaPemain <<endl;
                    cout << "Posisi : " << cari->role <<endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        cari = cari->next;
    }
}

// void subtitusiST(node *del, string hapusNama, string namaBaru){
//     del = head;
//     if( cekNm(namaBaru) ){
//         cout << "gagal" <<endl;
//     } else{
//         while( del!=nullptr ){
//             if( del->role=="ST" ){
//                 node *temp = del, *bef;
//                 while( temp!=nullptr ){
//                     if( temp->bot->namaPemain==hapusNama ){
//                         bef = temp;
//                         del = bef->bot;
//                         break;
//                     }
//                     temp = temp->bot;
//                 }
//                 node *baru;
//                 baru = new node;
//                 baru->namaPemain = namaBaru;
//                 baru->next = nullptr;
//                 baru->bot = del->bot;
//                 bef->bot = baru;
//                 del->bot = nullptr;
//                 del->next = nullptr;
//                 free(del);
//             }
//             del = del->next;
//         }
//     }
// }

void subtitusiST(node *del, string hapusNama, string namaC){
    del = head;
    if( !cekCadangan(namaC) ){
        countSwap++;
        cout << "gagal" <<endl;
    } else{
        while( del!=nullptr ){
            if( del->role=="ST" ){

                node *temp = del, *bef;
                while( temp!=nullptr ){
                    if( temp->bot->namaPemain==hapusNama ){
                        bef = temp;
                        del = bef->bot;
                        break;
                    }
                    temp = temp->bot;
                }

                node *baru = C,*help;
                while( baru->bot!=nullptr ){
                    if( baru->bot->namaPemain==namaC ){
                        help = baru->bot;
                        baru->bot = help->bot;
                        break;
                    }
                    baru = baru->bot;
                }
                help->bot = del->bot;
                bef->bot = help;
                del->bot = nullptr;
                penampungGanti[tmpungC] = del->namaPemain; // memasukan nama yang dihapus ke string
                tmpungC++;
                free(del);
            }
            del = del->next;
        }
    }
}

// void subtitusiMD(node *del, string hapusNama, string namaBaru){
//     del = head;
//     if( cekNm(namaBaru) ){
//         cout << "gagal" <<endl;
//     } else{
//         while( del!=nullptr ){
//             if( del->role=="MD" ){
//                 node *temp = del, *bef;
//                 while( temp!=nullptr ){
//                     if( temp->bot->namaPemain==hapusNama ){
//                         bef = temp;
//                         del = bef->bot;
//                         break;
//                     }
//                     temp = temp->bot;
//                 }
//                 node *baru;
//                 baru = new node;
//                 baru->namaPemain = namaBaru;
//                 baru->next = nullptr;
//                 baru->bot = del->bot;
//                 bef->bot = baru;
//                 del->bot = nullptr;
//                 del->next = nullptr;
//                 free(del);
//             }
//             del = del->next;
//         }
//     }
// }

void subtitusiMD(node *del, string hapusNama, string namaC){
    del = head;
    if( !cekCadangan(namaC) ){
        countSwap++;
        cout << "gagal" <<endl;
    } else{
        while( del!=nullptr ){
            if( del->role=="MD" ){
                node *temp = del, *bef;
                while( temp!=nullptr ){
                    if( temp->bot->namaPemain==hapusNama ){
                        bef = temp;
                        del = bef->bot;
                        break;
                    }
                    temp = temp->bot;
                }

                node *baru = C,*help;
                while( baru->bot!=nullptr ){
                    if( baru->bot->namaPemain==namaC ){
                        help = baru->bot;
                        baru->bot = help->bot;
                        break;
                    }
                    baru = baru->bot;
                }
                help->bot = del->bot;
                bef->bot = help;
                del->bot = nullptr;
                penampungGanti[tmpungC] = del->namaPemain; // memasukan nama yang dihapus ke string
                tmpungC++;
                free(del);
            }
            del = del->next;
        }
    }
}

// void subtitusiDF(node *del, string hapusNama, string namaBaru){
//     del = head;
//         if( cekNm(namaBaru) ){
//         cout << "gagal" <<endl;
//     } else{
//         while( del!=nullptr ){
//             if( del->role=="DF" ){
//                 node *temp = del, *bef;
//                 while( temp!=nullptr ){
//                     if( temp->bot->namaPemain==hapusNama ){
//                         bef = temp;
//                         del = bef->bot;
//                         break;
//                     }
//                     temp = temp->bot;
//                 }
//                 node *baru;
//                 baru = new node;
//                 baru->namaPemain = namaBaru;
//                 baru->next = nullptr;
//                 baru->bot = del->bot;
//                 bef->bot = baru;
//                 del->bot = nullptr;
//                 del->next = nullptr;
//                 free(del);
//             }
//             del = del->next;
//         }
//     }
// }

void subtitusiDF(node *del, string hapusNama, string namaC){
    del = head;
    if( !cekCadangan(namaC) ){
        countSwap++;
        cout << "gagal" <<endl;
    } else{
        while( del!=nullptr ){
            if( del->role=="DF" ){
                node *temp = del, *bef;
                while( temp!=nullptr ){
                    if( temp->bot->namaPemain==hapusNama ){
                        bef = temp;
                        del = bef->bot;
                        break;
                    }
                    temp = temp->bot;
                }
                
                node *baru = C,*help;
                while( baru->bot!=nullptr ){
                    if( baru->bot->namaPemain==namaC ){
                        help = baru->bot;
                        baru->bot = help->bot;
                        break;
                    }
                    baru = baru->bot;
                }
                help->bot = del->bot;
                bef->bot = help;
                del->bot = nullptr;
                penampungGanti[tmpungC] = del->namaPemain; // memasukan nama yang dihapus ke string
                tmpungC++;
                free(del);
            }
            del = del->next;
        }
    }
}

// void subtitusiGK(node *del, string hapusNama, string namaBaru){
//     del = tail;
//         if( cekNm(namaBaru) ){
//         cout << "gagal" <<endl;
//     } else{
//         node *temp = del, *bef;
//         while( temp!=nullptr ){
//             if( temp->bot->namaPemain==hapusNama ){
//                 bef = temp;
//                 del = bef->bot;
//                 break;
//             }
//             temp = temp->bot;
//         }
//         node *baru;
//         baru = new node;
//         baru->namaPemain = namaBaru;
//         baru->next = nullptr;
//         baru->bot = del->bot;
//         bef->bot = baru;
//         del->bot = nullptr;
//         del->next = nullptr;
//         free(del);
//     }
// }

void subtitusiGK(node *del, string hapusNama, string namaC){
    del = tail;
    if( !cekCadangan(namaC) ){
        countSwap++;
        cout << "gagal" <<endl;
    } else{
        node *temp = del, *bef;
        while( temp!=nullptr ){
            if( temp->bot->namaPemain==hapusNama ){
                bef = temp;
                del = bef->bot;
                break;
            }
            temp = temp->bot;
        }
            
        node *baru = C,*help;
        while( baru->bot!=nullptr ){
            if( baru->bot->namaPemain==namaC ){
                help = baru->bot;
                baru->bot = help->bot;
                break;
            }
            baru = baru->bot;
        }
        help->bot = del->bot;
        bef->bot = help;
        del->bot = nullptr;
        penampungGanti[tmpungC] = del->namaPemain; // memasukan nama yang dihapus ke string
        tmpungC++;
        free(del);
    }
}

void hapusPemain(node *del){
    del = head;
    while( del!=nullptr ){
        node *help, *temp;
        help = del->bot;
        del->bot = nullptr;
        while( help!=nullptr ){
            temp = help;
            help = help->bot;
            temp->bot = nullptr;
            free(temp);
        }
        del = del->next;
    }
}

void cetakPemain(node *cetak){
    cetak = head;
    while( cetak!=nullptr ){
        node *cetakPemain = cetak;
        cout << cetak->role << " :";
        while( cetakPemain!=nullptr ){
            cout << cetakPemain->namaPemain <<" ";
            cetakPemain = cetakPemain->bot;
        }
        cout <<endl;
        cetak = cetak->next;
    }
}

// void challenge1(){
//     // menampilkan list pemain pengganti
//     node *cetak = C;
//     cout << cetak->role << " :";
//     while( cetak!=nullptr ){
//         cout << cetak->namaPemain << " ";
//         cetak = cetak->bot;
//     }
//     cout << endl;
//     // menampilkan pemain yang dihapus
//     cout << "Pemain terhapus : ";
//     for( int i=0; i<tmpung; i++ ){
//         cout << penampungHapus[i] << ", ";
//     }
//     cout <<endl;
//     // menampilkan jumlah pemain tiap posisi
//     cout << "Jumlah pemain ST : " << jumlahST <<endl;
//     cout << "Jumlah pemain MD : " << jumlahMD <<endl;
//     cout << "Jumlah pemain DF : " << jumlahDF <<endl;
//     cout << "Jumlah pemain GK : " << jumlahGK <<endl;
// }

void roleCadangan(node *cadangan, string c){
    cadangan = new node;
    cadangan->role = c;
    cadangan->next = nullptr;
    cadangan->bot = nullptr;

    if( tail->next==nullptr ){
        tail->next = cadangan;
        C = tail->next;
    } else{
        cout << "Sudah ada role cadangan" <<endl;
    }
}

void addCadangan(node *temp, string nama){
    temp = new node;
    temp->namaPemain = nama;
    temp->next = nullptr;
    temp->bot = nullptr;

    if( C->bot==nullptr ){
        C->bot = temp;
    } else{
        node *help = C->bot;
        while( help->bot!=nullptr ){
            help = help->bot;
        }
        help->bot = temp;
    }
}

// void challenge2(){
//     // cetak cadangan
//     node *cetak = C;
//     cout << cetak->role << " :";
//     while( cetak!=nullptr ){
//         cout << cetak->namaPemain << " ";
//         cetak = cetak->bot;
//     }
//     cout << endl;
//     //cetak pemain tergantikan
//     cout << "Pemain tergantikan : ";
//     for( int i=0; i<tmpungC; i++ ){
//         cout << penampungGanti[i] << ", ";
//     }
//     cout <<endl;
// }

int main(){
    node *temp;
    addRole(temp, "ST");
    addRole(temp, "MD");
    addRole(temp, "DF");
    addRole(temp, "GK");
    roleCadangan(temp, "C");
    addCadangan(temp, "c1");
    addCadangan(temp, "c2");
    addCadangan(temp, "c3");

    for(int i=0; i<countST; i++){
        cout << "Tambah Striker : ";
        cin >> namaST;
        addST(temp, namaST);
    }
    for(int i=0; i<countMD; i++){
        cout << "Tambah Midfielder : ";
        cin >> namaMD;
        addMD(temp, namaMD);
    }
    for(int i=0; i<countDF; i++){
        cout << "Tambah Defender : ";
        cin >> namaDF;
        addDF(temp, namaDF);
    }
    for(int i=0; i<countGK; i++){
        cout << "Tambah Kiper : ";
        cin >> namaGK;
        addGK(temp, namaGK);
    }
    cout <<endl;
    for(int i=0; i<countDel; i++){
        int j;
        cout << "1. Delete striker" <<endl;
        cout << "2. Delete midfielder" <<endl;
        cout << "3. Delete defender" <<endl;
        cout << "4. Delete kiper" <<endl;
        cout << "5. Delete semua" <<endl;
        cout << "6. Selesai" <<endl;
        cout << "Pilih : ";
        cin >> j;
        if( j==1 ){
            cout << "Nama pemain : ";
            cin >> delNama;
            delST(temp, delNama);
            cout <<endl;
        } else if( j==2 ){
            cout << "Nama pemain : ";
            cin >> delNama;
            delMD(temp, delNama);
            cout <<endl;
        } else if( j==3 ){
            cout << "Nama pemain : ";
            cin >> delNama;
            delDF(temp, delNama);
            cout <<endl;
        } else if( j==4 ){
            cout << "Nama pemain : ";
            cin >> delNama;
            delGK(temp, delNama);
            cout <<endl;
        } else if( j==5 ){
            hapusPemain(temp);
        } else if( j==6 ){
            break;
        } else{
            cout << "Salah input" <<endl;
            break;
        }
    }
    cout <<endl;
    cout <<endl;
    // cout <<endl;

    for(int i=0; i<countSwap; i++){
        int j;
        cout << "1. Subtitusi striker" <<endl;
        cout << "2. Subtitusi midfielder" <<endl;
        cout << "3. Subtitusi defender" <<endl;
        cout << "4. Subtitusi kiper" <<endl;
        cout << "5. Selesai" <<endl;
        cout << "Pilih : ";
        cin >> j;
        if( j==1 ){
            cout << "Nama pemain : ";
            cin >> namaPlay;
            cout << "diganti dengan : ";
            cin >> swapNama;    
            subtitusiST(temp,namaPlay,swapNama);
            cout <<endl;
        } else if( j==2 ){
            cout << "Nama pemain : ";
            cin >> namaPlay;
            cout << "diganti dengan : ";
            cin >> swapNama;
            subtitusiMD(temp,namaPlay,swapNama);
            cout <<endl;
        } else if( j==3 ){
            cout << "Nama pemain : ";
            cin >> namaPlay;
            cout << "diganti dengan : ";
            cin >> swapNama;
            subtitusiDF(temp,namaPlay,swapNama);
            cout <<endl;
        } else if( j==4 ){
            cout << "Nama pemain : ";
            cin >> namaPlay;
            cout << "diganti dengan : ";
            cin >> swapNama;
            subtitusiGK(temp,namaPlay,swapNama);
            cout <<endl;
        } else if( j==5 ){
            cout <<endl;
            break;
        } else{
            cout << "Salah input" <<endl;
            break;
        }
    }
    
    // cariPemain(temp, "2");
    // cektakST(temp);
    // cektakMD(temp);
    // cektakDF(temp);
    // cektakGK(temp);
    // challenge1();

    cout <<"-" <<endl;
    cetakPemain(temp);
    return 0;
}