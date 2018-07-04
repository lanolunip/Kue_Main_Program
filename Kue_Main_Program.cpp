#include "stdio.h" //Input Output Library
#include "string.h" //String Library
#include "stdlib.h" //standard Library
#include "stdbool.h" // Boolean Library 

int jumlah_data = 0;
struct data{
    int harga_kue,stock_kue; //inisialisasi harga_kue,stock_kue (tipe int)
    char jenis_kue[20]; //inisialisasi jenis_kue (string)
    char nama_kue[20]; //inisialisasi jenis_kue (string)
    bool visibilitas; //inisialisasi visibilitas (bool)
    struct data *next; //inisialisasi pointer next ke struct lain nya 
}*head = NULL,*tail = NULL; //men-struct head dan tail 

void pushtail(int harga_kue,int stock_kue,char nama_kue[50],char jenis_kue[50],bool visibilitas)
{
    // temp = (struct data *)malloc(sizeof(struct data));/ /<-- extensi C 
    data *temp = (data *)malloc(sizeof(data)); //<-- ekstensi cpp | Mengalokasikan temp dan dibuat jadi struct data
    //Data Int
    temp->harga_kue = harga_kue;
    temp->stock_kue = stock_kue;
    //Data Char
    strcpy(temp->nama_kue, nama_kue); //Copy data tipe string --> sama seperti temp->nama_kue = nama_kue .. cuman karena string .. harus pakai strcpy()
    strcpy(temp->jenis_kue, jenis_kue);
    //Data Bool
    temp->visibilitas =  visibilitas;

    if (head == NULL) //jika pointer head masih NULL 
    {
        head = tail = temp; //struct head , tail , temp di samakan
    }
    else
    {
        tail->next = temp; //data selanjutnya setelah tail adalah data temp
        tail = temp; // memberitahu bahwa sekarang tail nya adalah temp
    }
    ++jumlah_data; //tambah jumlah data
    tail->next = NULL; // karena tail berpindah tempat ke paling akhir maka pointer selanjutnya adalah NULL karena belum ada data
}
//###################### view_data part

void view() //tampilan data
{
	data *temp = head; //pointer temp ke head data
    int nomor = 1;

        int palingBanyak ;
        int palingSedikit;
        int palingMahal;
        int palingMurah;

    if (temp == NULL){
        palingBanyak = 0;
        palingSedikit = 0;
        palingMahal = 0;
        palingMurah = 0;
    }else{
        palingBanyak = temp->stock_kue;
        palingSedikit = temp->stock_kue;
        palingMahal = temp->harga_kue;
        palingMurah = temp->harga_kue;
    }

    printf("| %2s | %-20s | %-10s | %-10s | %-6s | %-11s |\n","NO","NAMA KUE","JENIS KUE","HARGA","STOCK","VISIBILITAS"); //Kop tabel
	while (temp != NULL) //selama pointer temp tidak null .. print semua data di pointer temp.... 
	{
        if(temp->visibilitas==true){ 
            printf("| %-2d | %-20s | %-10s | Rp.%-7d | %-6d | %-11s |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue,"TRUE");
        }
        else{
            printf("| %-2d | %-20s | %-10s | Rp.%-7d | %-6d | %-11s |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue,"FALSE");
        }
        if (palingBanyak < temp->stock_kue){ //paling Banyak
            palingBanyak = temp->stock_kue;
        }
        if (palingSedikit > temp->stock_kue){ //paling Sedikit
            palingSedikit = temp->stock_kue;
        }
        if (palingMahal<temp->harga_kue){ //paling mahal
            palingMahal = temp->harga_kue;
        }
        if (palingMurah>temp->harga_kue){ //paling murah
            palingMurah = temp->harga_kue;
        }

        puts(" ");
        ++nomor;
		temp = temp -> next; //berpindah ke pointer selanjutnya
	}

    if(palingMahal != 0 ||palingMurah != 0 || palingSedikit != 0 && temp == NULL){ 
        printf("\nHarga Termahal = Rp.%d\n",palingMahal);
        printf("Harga Termurah = Rp.%d\n",palingMurah);
        printf("Stock Terbanyak = %d\n",palingBanyak);
        printf("Stock Tersedikit = %d\n",palingSedikit);
    }
    printf("Hati Hati .. Harga dan stock paling mahal / murah meliat visibilitas");
}
void view_result(){ // sama seperti view hanya saja yang akan di print ke file hanya yang visibilitas nya == True
    data *temp = head; //pointer temp ke head data
    int nomor = 1;

    int palingBanyak ;
    int palingSedikit;
    int palingMahal;
    int palingMurah;

    if (temp == NULL){
        palingBanyak = 0;
        palingSedikit = 0;
        palingMahal = 0;
        palingMurah = 0;
    }else{
        palingBanyak = temp->stock_kue;
        palingSedikit = temp->stock_kue;
        palingMahal = temp->harga_kue;
        palingMurah = temp->harga_kue;
    }

    printf("| %2s | %-20s | %-10s | %-10s | %-6s |\n","NO","NAMA KUE","JENIS KUE","HARGA","STOCK"); //Kop tabel
	while (temp != NULL) //selama pointer temp tidak null .. print semua data di pointer temp.... 
	{
        if(temp->visibilitas==true){ 
            printf("| %-2d | %-20s | %-10s | Rp.%-7d | %-6d |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue);
        }
        if (palingBanyak < temp->stock_kue && temp->visibilitas == true){ //paling Banyak
            palingBanyak = temp->stock_kue;
        }
        if (palingSedikit > temp->stock_kue && temp->visibilitas == true){ //paling Sedikit
            palingSedikit = temp->stock_kue;
        }
        if (palingMahal<temp->harga_kue && temp->visibilitas == true){ //paling mahal
            palingMahal = temp->harga_kue;
        }
        if (palingMurah>temp->harga_kue && temp->visibilitas == true){ //paling murah
            palingMurah = temp->harga_kue;
        }

        puts(" ");
        ++nomor;
		temp = temp -> next; //berpindah ke pointer selanjutnya
	}
    // palingBanyak = paling_banyak();palingSedikit=paling_sedikit();
    // palingMahal = paling_mahal();palingMurah=paling_murah(); 
    if(palingMahal != 0 || palingMurah != 0 || palingSedikit != 0 && temp == NULL){ //|| palingMahal != 0 ||palingMurah != 0 || palingSedikit != 0){
        printf("\nHarga Termahal = Rp.%d\n",palingMahal);
        printf("Harga Termurah = Rp.%d\n",palingMurah);
        printf("Stock Terbanyak = %d\n",palingBanyak);
        printf("Stock Tersedikit = %d",palingSedikit);
    }
}

int main_menu(){
    printf ("-----------------------------------------------------\n");
    printf ("PROGRAM STOCK KUE\n");
    printf ("-----------------------------------------------------\n");
    printf ("1. Menambahkan data\n");
    printf ("2. Mengedit data\n"); 
    printf ("3. Sortir\n");
    printf ("4. Visibilitas Data\n");
    printf ("5. Tampilan Data yang akan dimasukan di file\n");
    printf ("Selain itu keluar dan simpan file dalam file kue.txt\n");
    printf ("----------------------------------------------------\n");
    int masukan;
    printf("Pilih angka 1 - 5 = ");scanf("%d",&masukan);
    return masukan;
}
//###################### add_data part
bool tambah(){
    char nama_kue[50];
    char merit[50];
    char jenis_kue[50];
    int harga_kue,stock_kue,visibilitas_tanya;
    bool ulang,visibilitas_hasil;
    char ulang_edit_tanya[1];

    system("clear");
    fgets(nama_kue,50,stdin);fflush(stdin); //<-- Tumbal ... entah kenapa tidak mau mengambil string nya
    printf("Masukan nama kue = ");scanf("%[^\n]s",merit);//[^\n]s ini agar kita dapat memasukan data spasi .. karena string mencari spasi .. jadi kita rubah mencari enter atau \n
    printf("Masukan jenis kue (Ex. kering/basah) = ");scanf("%s",jenis_kue);
    printf("Masukan harga kue = ");scanf("%d",&harga_kue);
    printf("Masukan stock kue = ");scanf("%d",&stock_kue);
    do{
        printf("Masukan visibilitas data (1 True / 2 False) = ");
        scanf("%d",&visibilitas_tanya);
        if(visibilitas_tanya == 1){
            visibilitas_hasil = true;
        }else if(visibilitas_tanya == 2){
            visibilitas_hasil = false;
        }else{
            printf("Data hanya range 1 - 2 saja\n");
        }
    }while(visibilitas_tanya < 1 || visibilitas_tanya > 2 );
    printf("Setujukah dengan Masukan tersebut ?(Y/y untuk lanjut)");
    scanf("%s",ulang_edit_tanya);
    if(strcmp(ulang_edit_tanya,"y")==0 ||strcmp(ulang_edit_tanya,"Y")==0){
        ulang = false;
        pushtail(harga_kue,stock_kue,merit,jenis_kue,visibilitas_hasil);
        system("clear");
        printf("\n\nData Berhasil Ditambahkan !\n");
        getchar();
    }else{
        ulang = true;
    }
    return ulang;
}

void add_data(){ // main 
    bool ulang_tambah = true;
    bool ulang_edit = true;
    char  ulang_edit_tanya[1];
    //insert str counter
    while (ulang_edit != false){
        while (ulang_tambah != false){
            ulang_tambah=tambah();
        }
        printf("\n\nApakah ingin menambahkan data baru lagi ?(Y/y untuk lagi)");
        scanf("%s",ulang_edit_tanya);
        if (strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y")==0){
            ulang_edit = true;
            ulang_tambah = true;
        }else{
            ulang_edit = false;
        }
    }
}
//###################### edit_data part
void tambah_kurang(){
    // bool ulang_pilihan = true;
    int pilihan_data;
    // while (ulang_pilihan == true){
        system("clear");
        view();
        printf("Pilih data ke berapa ?");
        scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data|| pilihan_data < 1){
            system("clear");
            printf("Data tidak ada\n");
            getchar();
        }else{
            bool ulang_tambah_kurang = true;
            while(ulang_tambah_kurang == true){
                int pilihan_edit;
                system("clear");
                printf("1. Tambah stock\n");
                printf("2. Kurangi Stock\n");
                printf("Nomor selain itu keluar \n");
                scanf("%d",&pilihan_edit);
                data *temp = head;
                for(int i = 1;i<pilihan_data;++i){
                    temp = temp->next;
                }
                if(pilihan_edit == 1){
                    int jumlah_tambah = 1;
                    while (jumlah_tambah != 0){
                        printf("Masukan jumlah tambah (0 untuk keluar) = ");
                        scanf("%d",&jumlah_tambah);
                        temp->stock_kue = temp->stock_kue + jumlah_tambah;
                        printf("Jumlah kue = %d\n\n",temp->stock_kue);
                        }
                }else if(pilihan_edit == 2){
                    int jumlah_kurang = 1;
                    while(jumlah_kurang != 0){
                        printf("Masukan jumlah tambah (0 untuk keluar) = ");
                        scanf("%d",&jumlah_kurang);
                        temp->stock_kue = temp->stock_kue - jumlah_kurang;
                        printf("Jumlah kue = %d\n\n",temp->stock_kue);
                    }
                }else{
                    ulang_tambah_kurang = false;
                }
            }
            // char ulang_pilihan_tanya[1];
            // system("clear");
            // printf("Kembali ke menu edit ?(Y/y untuk kembali) ");
            // scanf("%s",ulang_pilihan_tanya);
            // if(strcmp(ulang_pilihan_tanya,"y") == 0 || strcmp(ulang_pilihan_tanya,"Y") == 0){
            //     ulang_pilihan = false;
            // }else{
            //     ulang_pilihan = true;
            // }
        }
    }
// }

void edit_kue_status(){
    // bool ulang_pilihan = true;
    char ulang_pilihan_tanya[1],nama_kue[50];
    int pilihan_data,counter,nomor,visibilitas;
    // while (ulang_pilihan == true){
        system("clear");
        view();
        printf("Pilih data ke berapa ?");
        scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data || pilihan_data < 1){
            printf("Data tidak ada\n");
        }else{
            bool ulang_edit = true;
            char ulang_edit_tanya[1];
            data *temp = head;
            int visibilitas_tanya;
            for(int i = 1;i<pilihan_data;++i){
                temp = temp->next;
            }
            while (ulang_edit == true){
                fgets(nama_kue,50,stdin);fflush(stdin); //<-- Tumbal ... entah kenapa tidak mau mengambil string nya
                printf("Nama Kue = ");scanf("%[^\n]s",temp->nama_kue);
                printf("Jenis Kue = ");scanf("%s",temp->jenis_kue);
                printf("Harga Kue = ");scanf("%d",&temp->harga_kue);
                printf("Stock Kue = ");scanf("%d",&temp->stock_kue);
                do{
                    printf("Visibilitas (1.True 2.False) = ");scanf("%d",&visibilitas_tanya);
                    if (visibilitas_tanya < 1 || visibilitas_tanya > 2){
                        printf("Data hanya range 1 - 2 saja\n");
                    }else{
                        if(visibilitas_tanya == 1){
                        temp->visibilitas = true;
                        }else{
                            temp->visibilitas = false;
                        }
                    }
                }while (visibilitas_tanya < 1 || visibilitas_tanya > 2);
                printf ("\nSetuju Dengan perubahan di atas? (y/Y untuk setuju) ");scanf("%s",ulang_edit_tanya);
                if(strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y") == 0){
                    ulang_edit = false;
                    puts("\nData telah dirubah !");
                    getchar();
                    system("clear");
                }
            }
            // printf("Mau ulang program ini ?(y/Y untuk mengulang) ");scanf("%s",ulang_pilihan_tanya);
            // if (strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y") == 0){
            //     ulang_pilihan = true;
            // }else{
            //     ulang_pilihan = false;
            // }
        }
    }
// }   

void edit_data(){ //main
    bool ulang_pilihan = true;

    while (ulang_pilihan == true){
        int pilihan;
        char ulang_program_tanya[1],ulang_menu_tanya[1];
        system("clear");
        printf("1. Tambah Kurang Stock\n");
        printf("2. Edit Status Kue\n");
        printf("Nomor lain untuk kembali ke menu utama\n");
        scanf("%d",&pilihan);
        if(pilihan == 1){
            tambah_kurang();
        }else if(pilihan ==2){
            edit_kue_status();
        }else{
            ulang_pilihan = false;
        }
    }
}
//###################### sortir_data part
void termurah(){
    data *temp = head;
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        // temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->harga_kue > temp->next->harga_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}
 
void termahal(){
    data *temp = head;
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        // temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->harga_kue < temp->next->harga_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}

void tersedikit(){
    data *temp = head;
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        // temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->stock_kue > temp->next->stock_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}
 
void terbanyak(){
    data *temp = (data *)malloc(sizeof(data));
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->stock_kue < temp->next->stock_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}

void daritrue(){
   data *temp = (data *)malloc(sizeof(data));
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->visibilitas==false && temp->next->visibilitas){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}

void darifalse(){
    data *temp = (data *)malloc(sizeof(data));
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->visibilitas == true && temp->next->visibilitas == false){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("\nPress Enter ");
    getchar();getchar(); 
}

void sortir_data(){
    // bool ulang = true;
    int pilihan;
    char ulang_tanya[1];
    // while (ulang == true){
        system("clear");
        printf("Sortir data dari:\n");
        printf("1.Harga Termurah\n");
        printf("2.Harga Termahal\n");
        printf("3.Stock Tersedikit\n");
        printf("4.Stock Terbanyak\n");
        printf("5.Visibiltas True\n");
        printf("6.Visibilitas False\n");
        printf("Nomor selain di atas maka kembali ke menu utama\n");
        printf("Pilihan anda = ");scanf("%d",&pilihan);
        if (pilihan == 1){
            termurah();
        }else if(pilihan == 2){
            termahal();
        }else if(pilihan == 3){
            tersedikit();
        }else if(pilihan == 4){
            terbanyak();
        }else if(pilihan == 5){
            daritrue();
        }else if(pilihan == 6){
            darifalse();
        // }else{
        //     break;
        }
        // printf("Kembali ke menu sortir ? (Y / y untuk kembali) ");scanf("%s",ulang_tanya);
        // if(strcmp(ulang_tanya,"y") == 0 || strcmp(ulang_tanya,"Y")==0){
        //     ulang = true;
        // }else{
        //     ulang = false;
        // }
    // }
}
//################### visibilitas part
void visibilitas(){ // untuk edit visibilitas nya saja .
    // bool ulang_pilihan = true;
    char ulang_pilihan_tanya[1];
    int pilihan_data;

    // while (ulang_pilihan == true){
        system("clear");
        view();
        printf("Pilih data keberapa yang ingin di edit visibilitas nya ? ");scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data|| pilihan_data < 1){
            printf("Data tidak ada\n");
            system("clear");
        }else{
            bool ulang_program = true;
            int pilihan_visibilitas;
            data *temp = head;
            for(int i = 1;i<pilihan_data;++i){
                temp = temp->next;
            }
            while (ulang_program == true){
                printf("1.Visibilitas True\n");
                printf("2.Visibilitas False\n");
                printf("Pilihan anda = ");scanf("%d",&pilihan_visibilitas);
                if (pilihan_visibilitas < 1 || pilihan_visibilitas > 2){
                    printf("Nomor pilihan salah\n");
                }else if(pilihan_visibilitas == 1){
                    temp->visibilitas = true;
                    printf("Visibilitas telah diganti !\n");
                    ulang_program = false;
                }else{
                    temp->visibilitas = false;
                    printf("Visibilitas telah diganti !\n");
                    ulang_program = false;
                }
            }
            // printf("Ingin mengulang ke menu utama ? (y/Y untuk kembali) ");scanf("%s",ulang_pilihan_tanya);
            // if (strcmp(ulang_pilihan_tanya,"y") == 0 || strcmp(ulang_pilihan_tanya,"Y") == 0 ){
            //     ulang_pilihan = true;
            // }else{
            //     ulang_pilihan = false;
            // }
        }
    }
// }

void write_to_file(){ //
    FILE *fptr; //inisialisasi fptr pointer ke sebuah FILE
    data *temp = head; //pointer temporary ke head data
    int nomor = 1;
    fptr = fopen("Kue.txt","w");

    int palingBanyak;
    int palingSedikit;
    int palingMahal;
    int palingMurah;

    if (temp == NULL){
        palingBanyak = 0;
        palingSedikit = 0;
        palingMahal = 0;
        palingMurah = 0;
    }else{
        palingBanyak = temp->stock_kue;
        palingSedikit = temp->stock_kue;
        palingMahal = temp->harga_kue;
        palingMurah = temp->harga_kue;
    }

    fprintf(fptr,"| %2s | %-20s | %-10s | %-10s | %-6s |\n","NO","NAMA KUE","JENIS KUE","HARGA","STOCK"); //Kop tabel
	while (temp != NULL) //selama pointer temp tidak null .. print semua data di pointer temp.... 
	{
        if(temp->visibilitas==true){ 
            fprintf(fptr,"| %-2d | %-20s | %-10s | Rp.%-7d | %-6d |\n",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue);
            ++nomor;
        }

        if (palingBanyak < temp->stock_kue && temp->visibilitas == true){ //paling Banyak
            palingBanyak = temp->stock_kue;
        }
        if (palingSedikit > temp->stock_kue && temp->visibilitas == true){ //paling Sedikit
            palingSedikit = temp->stock_kue;
        }
        if (palingMahal < temp->harga_kue && temp->visibilitas == true){ //paling mahal
            palingMahal = temp->harga_kue;
        }
        if (palingMurah > temp->harga_kue && temp->visibilitas == true){ //paling murah
            palingMurah = temp->harga_kue;
        }

		temp = temp -> next; //berpindah ke pointer selanjutnya
	}

    if( temp == NULL){ 
        fprintf(fptr,"\nHarga Termahal = Rp.%d\n",palingMahal);
        fprintf(fptr,"Harga Termurah = Rp.%d\n",palingMurah);
        fprintf(fptr,"Stock Terbanyak = %d\n",palingBanyak);
        fprintf(fptr,"Stock Tersedikit = %d",palingSedikit);
    }
    fclose(fptr); //setelah di isi .file di tutup
}
//################### main part
int main(){
    int pilihan = 1;
    
    while (pilihan >= 1 && pilihan <= 5){
        system("clear");
        view();
        puts("\n");
        pilihan = main_menu();
        if (pilihan == 1){
            add_data();
        }else if(pilihan == 2){
            edit_data();
        }else if(pilihan == 3){
            sortir_data();
        }else if(pilihan == 4){
            visibilitas();
        }else if (pilihan == 5){
            system("clear");
            view_result();
            puts("\nPress Enter");
            getchar();getchar();
        }
    }
    write_to_file();
}
