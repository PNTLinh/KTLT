#include<bits/stdc++.h>
using namespace std;
typedef struct MonHoc{
    string maMH;
    int sotinchi,sotinchiLT,sotinchiTH,sotinchiBT;
    double sotinchiHp;
    double hocphi=0;
    string kl;
    string loaigio;
}MonHoc;
typedef struct HocVien{
    string maHV;
    string hotenHV;
    int somonhoc;
    int sotiethoc;
    int sotienhoc1tinchi;
    double sotiendanop;
    double sotienphaidong=0;
    double sotienconlai=0;
    string trangthaiHP;
    vector<MonHoc> listMH;
}HocVien;
int main(){
    vector<HocVien> listHV;
    cout<<"NguyenThuyLinh - 20225031 - IT3040 - 20241 - Tuan18 - 744467"<< endl;
    cout<<"**\tCHUONG TRINH QUAN LY HOC PHI\t**"<<endl;
    cout<<"**1. Nhap cac sinh vien va mon hoc\t**"<<endl;
    cout<<"**2.In ds sinh vien va hoc phi cac mon\t**"<<endl;
    cout<<"**0.Thoat\t\t\t**"<<endl;
    for (int i= 0; i<30;i++) cout<<"*";
    cout<<endl;
    int choice, n;
    while(1){
        cout<<"**\tNhap lua chon cua ban\t**"<<endl;
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Ban da chon thoat CT"<<endl;
                break;
            case 1:
                cout<<"Ban da chon nhap danh sach sinh vien"<<endl;
                cout<<"Nhap so sinh vien:"<<endl;
                cin>>n;
                for (int i = 1; i<= n; i++){
                    cout<<"Nhap thong tin sinh vien thu "<<i<<" :"<<endl;
                    HocVien sv1;
                    fflush(stdin);
                    cout<<"\tTen sinh vien:";cin>>sv1.hotenHV;
                    cout<<"\tSo mon hoc: ";cin>> sv1.somonhoc;
                    cout<<"\tSo tien mot tin chi:";cin>>sv1.sotienhoc1tinchi;
                    for ( int i = 1; i<= sv1.somonhoc; i++){
                        cout<<"\tMon hoc thu "<<i<<endl;
                        MonHoc mh1;
                        cout<<"\tMa mon hoc:"; cin>>mh1.maMH;
                        cout<<"\t\tSo tin chi:"; cin>>mh1.sotinchi;
                        cout<<"\t\tNhap tin chi LT:"; cin>>mh1.sotinchiLT;
                        cout<<"\t\tNhap tin chi BT:"; cin>>mh1.sotinchiBT;
                        cout<<"\t\tnhap tin chi TH:"; cin>>mh1.sotinchiTH;
                        mh1.sotinchiHp= mh1.sotinchiBT+mh1.sotinchiLT+mh1.sotinchiTH*1.5;
                        mh1.hocphi=sv1.sotienhoc1tinchi*mh1.sotinchiHp;
                        sv1.sotienphaidong += mh1.hocphi;
                        mh1.kl = (to_string)(mh1.sotinchi) + "(" + (to_string)(mh1.sotinchiLT) + "-" + (to_string)(mh1.sotinchiBT) + "-" + (to_string)(mh1.sotinchiTH) +"-" +(to_string)(2 * mh1.sotinchi)+")";
                        if (mh1.sotinchi== 6){
                            mh1.loaigio = "DATN Cu Nhan";
                            mh1.kl="6(0-0-12-18)";
                            mh1.sotinchiTH =12;
                            mh1.sotinchiHp = 18;
                        }
                        else if (mh1.sotinchi == 12){
                            mh1.sotinchiTH= 12;
                            mh1.sotinchiHp= 18;
                            mh1.loaigio= "DATN Ki su";
                            mh1.kl= "12(0-0-12-24)";
                        }
                        else {
                            if (mh1.sotinchiLT != 0 && mh1.sotinchiBT != 0 && mh1.sotinchiTH != 0){
                                mh1.loaigio = "LT-BT-TH";
                            }
                            else if(mh1.sotinchiLT != 0 && mh1.sotinchiBT != 0 && mh1.sotinchiTH == 0){
                                mh1.loaigio = "LT-BT";
                            }
                            else if (mh1.sotinchiLT != 0 && mh1.sotinchiBT == 0 && mh1.sotinchiTH != 0){
                                mh1.loaigio = "LT-TH";
                            }
                        }
                        sv1.listMH.push_back(mh1);
                    }
                    cout<<endl;
                    cout<<"\tHoc phi da nop:"; cin>>sv1.sotiendanop;
                    sv1.sotienconlai = sv1.sotienphaidong - sv1.sotiendanop;
                    if (sv1.sotienconlai > 0) sv1.trangthaiHP= "Con thieu";
                    else sv1.trangthaiHP = "Da xong";
                    listHV.push_back(sv1);
                }
                break;
            case 2:
                cout<<"Ban da chon in danh sach sinh vien va mon hoc"<<endl;
                for (int i=0; i<=40; i++)cout<<"-";
                cout<<endl;
                for (HocVien hv: listHV){
                    cout<<"\tTen sv:"<< hv.hotenHV<<endl;
                    cout<<"\tSo mon hoc: "<<hv.somonhoc<<endl;
                    cout<<"\tSo tien 1 TC: "<<hv.sotienhoc1tinchi<<endl;
                    cout<<"\tPhai nop: "<<hv.sotienphaidong<<endl;
                    cout<<"\tDa nop dot 1: "<<hv.sotiendanop<<endl;
                    cout<<"\tSo tien thieu: "<<hv.sotienconlai<<endl;
                    cout<<"\tTinh trang nop HP:" <<hv.trangthaiHP<<endl;
                    cout<<"\tChi tiet hoc phi cac mon hoc:"<<endl;
                    cout<<setw(20)<<left<<"Ma MH"<<setw(20)<<left<<"Loai gio"<<setw(20)<<left<<"Khoi luong"<<setw(20)<<left<<"Hoc phi phai nop"<<endl;
                    for (MonHoc mh:hv.listMH){
                        cout<<setw(20)<<left<<mh.maMH;
                        cout<<setw(20)<<left<<mh.loaigio;
                        cout<<setw(20)<<left<<mh.kl;
                        cout<<setw(20)<<left<<mh.hocphi;
                        cout<<endl;
                    }
                }
                break;
        }
    }
	return 0;
}
