#include<bits/stdc++.h>
using namespace std;
typedef struct miengDat{
    string ma;
    double dongia;
    string hinh;
    double dientich;
    double thanhTien;
    double tienDatCoc;
    double giamgia;
}miengDat;
typedef struct congty{
    string tenCty;
    string diachi;
    int soMiengDat;
    double dongiatb;
    double tongdientich;
    double tongthanhtien;
    double tongdatcoc;
    double tonggiamgia;
    vector<miengDat> listLand;
}congty;
typedef struct tong{
    double thanhtien;
    double dientich;
    double datcoc;
    double giamgia;
}tong;
int main(){
    tong tinhtong;
    vector<congty> listCty;
    cout<<"NguyenThuyLinh - 20225031 - IT3040 - 20241 - Tuan18 - 744467"<< endl;
        cout<<"**\tCHUONG TRINH QUAN LY BAT DONG SAN\t**"<<endl;
        cout<<"**1. Nhap THONG TIN CONG TY\t**"<<endl;
        cout<<"**2.IN KET QUA DIEN TICH MANH DAT\t**"<<endl;
        cout<<"**0.Thoat\t\t\t**"<<endl;
        for (int i= 0; i<30;i++) cout<<"*";
        cout<<endl;
    while (true){
        cout<<"**\tNhap lua chon cua ban\t**"<<endl;
        int n, k;
        cin >> n;
        switch (n){
            case 0:
                cout<<"Ban da chon thoat chuong trinh"<<endl;
                break;
            case 1:
                cout<<"Ban da chon nhap MIENG DAT VA DO DAI"<<endl;
                cout<<" Nhap thong tin so Cong ty BDS:"<<endl;
                cin>>k;// nhap so cong ty
                for (int i= 1; i<=k; i++){
                    congty cty1;
                    cout<<"Nhap thong tin Cong ty "<<i <<" :"<<endl;
                    cout<<"\tTen Cong ty:";fflush(stdin); getline(cin,cty1.tenCty);
                    cout<<"\tDia chi cong ty:";getline(cin, cty1.diachi);
                    cout<<"\tSo Mieng Dat:"; cin>> cty1.soMiengDat;
                    for (int i = 1; i<= cty1.soMiengDat; i++){
                        miengDat land1;
                        cout<<"Ma mieng dat thu "<<i<<" :";
                        cin>>land1.ma;
                        double pt;
                        if (land1.ma =="MD001") pt= 0.7;
                        else if (land1.ma == "MD002") pt= 0.5;
                        else pt = 0.3;
                        cout<<"\t\tDon gia theo m^2:";
                        cin>>land1.dongia;
                        cout<<"\t\tMieng dat Hinh:";
                        cin>>land1.hinh;
                        cout<<endl;
                        if (land1.hinh == "Vuong"){
                            cout<<"\t\tCanh hinh vuong:";
                            double canhhv;
                            cin>>canhhv;
                            cout<<endl;
                            land1.dientich = canhhv*canhhv;
                            land1.thanhTien = land1.dongia * land1.dientich;
                            land1.tienDatCoc= land1.thanhTien*pt;
                            land1.giamgia = 0;
                        }
                        else if (land1.hinh =="Thang"){
                            double daylon, daynho,cc;
                            cout<<"\t\tDay nho:";
                            cin>>daynho;
                            cout<<endl;
                            cout<<"\t\tDay lon:";
                            cin>>daylon;
                            //cout<<end;
                            cout<<"\t\tChieu cao:";
                            cin>>cc;
                            cout<<endl;
                            land1.dientich = (daylon + daynho)* cc /2;
                            land1.thanhTien = land1.dongia * land1.dientich;
                            land1.tienDatCoc= land1.thanhTien*pt;
                            land1.giamgia = land1.thanhTien *0.1;
                        }
                        else if (land1.hinh == "Tamgiac"){
                            double cc, day;
                            cout<<"\t\tChieu cao:"; cin>>cc;cout<<endl;
                            cout<<"\t\tCanh day:"; cin>>day;cout<<endl;
                            land1.dientich = day* cc /2;
                            land1.thanhTien = land1.dongia * land1.dientich;
                            land1.tienDatCoc= land1.thanhTien*pt;
                            land1.giamgia = land1.thanhTien *0.1;
                        }
                        else{
                            double dai, rong;
                            cout<<"\t\tChieu dai:";cin>> dai;cout<<endl;
                            cout<<"\t\tChieu rong:"; cin>> rong;cout<<endl;
                            land1.dientich = dai*rong;
                            land1.thanhTien = land1.dongia * land1.dientich;
                            land1.tienDatCoc= land1.thanhTien*pt;
                            land1.giamgia = 0;
                        }
                        cty1.dongiatb += land1.dongia;
                        cty1.tongdientich += land1.dientich;
                        cty1.tongthanhtien += land1.thanhTien;
                        cty1.tongdatcoc +=land1.tienDatCoc;
                        cty1.tonggiamgia += land1.giamgia;
                        cout<<"\t\tDien tich:" <<land1.dientich<<endl;
                        cout<<"\t\tThanh tien:" << land1.thanhTien<<endl;
                        cout<<"\t\tTien dat coc: "<< land1.tienDatCoc<<endl;
                        cout<<"\t\tGiam gia: "<<land1.giamgia<<endl;
                        cty1.listLand.push_back(land1);
                    }
                    tinhtong.datcoc+= cty1.tongdatcoc;
                    tinhtong.dientich += cty1.tongdientich;
                    tinhtong.giamgia +=cty1.tonggiamgia;
                    tinhtong.thanhtien += cty1.tongthanhtien;
                    listCty.push_back(cty1);
                }
                break;
            case 2:
                cout<<"Ban da chon IN RA MIENG DAT"<<endl;
                for (congty cty: listCty){
                    cout<<"\tTen cong ty:"<<cty.tenCty<<endl;
                    cout<<"\tDia chi:"<<cty.diachi<<endl;
                    cout<<"\So mieng dat:"<<cty.soMiengDat<<endl;
                    cout<<"\tDon gia trung binh:"<<cty.dongiatb/cty.soMiengDat<<endl;
                    cout<<"\tTong dien tich:"<<cty.tongdientich<<endl;
                    cout<<"\tTong thanh tien:"<<cty.tongthanhtien<<endl;
                    cout<<"\tTong Dat coc:"<<cty.tongdatcoc<<endl;
                    cout<<"\tTong giam gia:"<<cty.tonggiamgia<<endl;
                    cout<<"\t\tChi tiet cac mieng dat:"<<endl;
                    cout<<setw(6)<<left<<"MaMD"<<setw(12)<<left<<"Hinh dang"<< setw(10)<<left<<"Don gia";
                    cout<<setw(12)<<left<<"Dien tich"<<setw(15)<<left<<"Thanh tien"<<setw(10)<<left<<"Giam gia"<< setw(10)<<left<<"Dat coc"<<endl;
                    for (miengDat md: cty.listLand){
                        cout<<setw(6)<<left<<md.ma;
                        cout<<setw(12)<<left<<md.hinh;
                        cout<<setw(10)<<left<<md.dongia;
                        cout<<setw(12)<<left<<md.dientich;
                        cout<<setw(15)<<left<<md.thanhTien;
                        cout<<setw(10)<<left<<md.giamgia;
                        cout<<setw(10)<<left<<md.tienDatCoc;
                        cout<<endl;
                    }
                    cout<<endl;cout<<endl;cout<<endl;
                    cout<<"Tong thanh tien cac cong ty: "<< tinhtong.thanhtien<<endl;
                    cout<<"Tong dien tich cac cong ty: "<< tinhtong.dientich<<endl;
                    cout<<"Tong dat coc cac cong ty: "<< tinhtong.datcoc<<endl;
                    cout<<"Tong giam gia cac cong ty: "<< tinhtong.giamgia<<endl;
                }
                break;
            default:
                cout<<"Moi nhap lai"<<endl;
                break;
        }
    }
    return 0;
}
