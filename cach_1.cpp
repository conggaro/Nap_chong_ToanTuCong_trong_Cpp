// Yêu cầu:
// 1. tạo đối tượng dt1, dt2, dt3
// 2. hiển thị đối tượng
// 3. hiển thị số thứ tự của đối tượng
// 4. nạp chồng toán tử cộng (overload operator +)

#include<iostream>
using namespace std;

class PhanSo{
    public:
        int tu;                 // tử số
        int mau;                // mẫu số
        int stt;                // số thứ tự của đối tượng

    private:
        static int dem_dt;      // đếm đối tượng

    public:
        // hàm khởi tạo không tham số
        PhanSo(){
            tu = 0;
            mau = 1;

            dem_dt ++;
            stt = dem_dt;
        }

        // hàm khởi tạo có tham số
        PhanSo(int data1, int data2){
            if (data2 == 0)
            {
                tu = 0;
                mau = 1;
            }
            else if (data2 != 0)
            {
                tu = data1;
                mau = data2;
            }
            
            dem_dt ++;
            stt = dem_dt;
        }

        // hàm hiển thị
        void HienThi(){
            cout << tu << "/" << mau << "\n";
        }

        // nạp chồng toán tử cộng
        PhanSo operator+(PhanSo dt){
            PhanSo ketQua;

            if (mau != dt.mau)
            {
                // tính tử số
                ketQua.tu = tu * dt.mau + dt.tu * mau;

                // tính mẫu số
                ketQua.mau = mau * dt.mau;
            }
            else if (mau == dt.mau)
            {
                // tính tử số
                ketQua.tu = tu + dt.tu;

                // tính mẫu số
                ketQua.mau = mau;
            }

            return ketQua;
        }

        // hàm hủy
        ~PhanSo() {
            cout << "Huy doi tuong\n";
        }
};

int PhanSo::dem_dt = 0;

int main(){
    // tạo đối tượng
    PhanSo dt1 = PhanSo(1, 2);
    PhanSo dt2 = PhanSo(6, 2);
    PhanSo dt3;

    // gọi phương thức hiển thị
    cout << "Hien thi doi tuong:" << endl;
    dt1.HienThi();
    dt2.HienThi();
    dt3.HienThi();
    cout << "\n";

    // hiển thị số thứ tự
    cout << "So thu tu:\n";
    cout << dt1.stt << "\n";
    cout << dt2.stt << "\n";
    cout << dt3.stt << "\n\n";

    // thực hiện cộng dt1 và dt2
    dt3 = dt1 + dt2;
    cout << "\nTong = ";
    dt3.HienThi();
    cout << "\n";

    return 0;
}