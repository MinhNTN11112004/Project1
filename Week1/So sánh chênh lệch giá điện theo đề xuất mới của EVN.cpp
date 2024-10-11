/*Description
Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023), với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND. Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới, giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh. 
Bậc	Biểu giá hiện hành	Phương án 5 bậc
  	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015		
(*) Giá chưa bao gồm thuế VAT
Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.
INPUT: là số kwh điện tiêu thụ của hộ (là số nguyên)
OUTPUT: là chênh lệch giữa giá theo đề xuất và giá theo mô hình bậc thang 6 mức đang được áp dụng.
VAT sẽ được lấy là 10%, và kết quả in ra sẽ lấy tới 2 chữ số thập phân
EXAMPLE 
INPUT
540
OUTPUT
-22176.00
INPUT
70
OUTPUT
-1276.00*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
double price6steps(int kwh){
    double total=0;
    if(kwh<50){
        total=kwh*1728;
    }else if(kwh<100){
        total=50*1728 + (kwh-50)*1786;
    }else if(kwh<200){
        total=50*1728 + 50*1786 + (kwh-100)*2074;
    }else if(kwh<300){
        total=50*1728 + 50*1786 + 100*2074+(kwh-200)*2612;
    }else if(kwh<400){
        total=50*1728 + 50*1786 + 100*2074+ 100*2612+ (kwh-300)*2919;
    }else{
        total=50*1728 + 50*1786 + 100*2074+ 100*2612+ 100*2919+ (kwh-400)*3015;
    }
    return total*1.1;
}
double price5steps(int kwh){
    double total=0;
    if(kwh<100){
        total=kwh*1728;
    }else if(kwh<200){
        total=100*1728 + (kwh-100)*2074;
    }else if(kwh<400){
        total=100*1728 + 100*2074 + (kwh-200)*2612;
    }else if(kwh<700){
        total=100*1728 + 100*2074 + 200*2612+(kwh-400)*3111;
    }else{
        total=100*1728 + 100*2074 + 200*2612+ 300*3111+ (kwh-700)*3457;
    }
    return total*1.1;
}
int main() 
{ 
    int kwh;
    cin>>kwh;
    double diff=(double)price5steps(kwh)-(double)price6steps(kwh);
    cout<<fixed<<setprecision(2)<<diff<<endl;
    return 0;
}
