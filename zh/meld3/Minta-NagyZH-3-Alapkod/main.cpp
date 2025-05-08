#include <iostream>
using namespace std;

#include "date.h"
#include "coupon.h"
#include "monthlycoupon.h"
#include "singleusecoupon.h"
#include "multiusecoupon.h"

#include "wallet.h"
#include "purchase.h"


int main()
{
    cout << "main() eleje!" << endl << endl;

     Wallet wallet;

    wallet.addCoupon( new SingleUseCoupon(1000) );
    wallet.addCoupon( new MultiUseCoupon (2000, 5) );
    wallet.addCoupon( new MonthlyCoupon   (3000, 2024, 5) );

    wallet.addCoupon( new SingleUseCoupon(1000) );
    wallet.addCoupon( new MultiUseCoupon (2000, 5) );
    wallet.addCoupon( new MonthlyCoupon   (3000, 2024, 5) );

    wallet.addCoupon( new SingleUseCoupon(1000) );
    wallet.addCoupon( new MultiUseCoupon (2000, 5) );
    wallet.addCoupon( new MonthlyCoupon   (3000, 2024, 5) );

    wallet.addCoupon( new SingleUseCoupon(1000) );
    wallet.addCoupon( new MultiUseCoupon (2000, 5) );
    wallet.addCoupon( new MonthlyCoupon   (3000, 2024, 5) );

    wallet.addCoupon( new SingleUseCoupon(1000) );
    wallet.addCoupon( new MultiUseCoupon (2000, 5) );
    wallet.addCoupon( new MonthlyCoupon   (3000, 2024, 5) );

     cout << "---Vasarlasok, print()" << endl;
     Purchase purchase("purchases.json");
     purchase.print();
     cout << endl;

     cout << "---Vegosszeg lekerdezese (alap)" << endl;
     cout << "sum == " << purchase.getTotal() << endl;
     cout << endl;

     cout << "---Vegosszeg lekerdezese (kuponok hasznalata)" << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << endl;

     cout << "---Datum atallitasa, havi kuponok" << endl;
     // nem kotelezo ezt a statikus fuggvenyt hasznalni, ez csak pelda
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     MonthlyCoupon::setCurrentDate(2023,12,31);
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     MonthlyCoupon::setCurrentDate(2024,5,1);
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << endl;

//      Az alabbi tesztelendo sorok kozul szabadon lehet valogatni!
     
     cout << "---loadCoupons(), countCoupons(), exportCounts()" << endl;
     cout << ">>> Beolvasas: coupons-1.json ..." << endl;
     wallet.loadCoupons("coupons-1.json");
     wallet.exportCounts("export-example-A.json");
     cout << wallet.countCoupons<SingleUseCoupon>(true) << endl;
     cout << wallet.countCoupons<SingleUseCoupon>(true) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << wallet.countCoupons<SingleUseCoupon>(true) << endl;
     cout << wallet.countCoupons<MonthlyCoupon>(true) << endl;
     cout << wallet.countCoupons<MultiUseCoupon>(true) << endl;
     cout << ">>> Beolvasas: coupons2.json ..." << endl;
     wallet.loadCoupons("coupons-2.json");
     cout << wallet.countCoupons<SingleUseCoupon>(true) << endl;
     cout << wallet.countCoupons<MultiUseCoupon>(true) << endl;
     cout << "sum == " << purchase.useCoupons(wallet) << endl;
     cout << wallet.countCoupons<SingleUseCoupon>(true) << endl;
     cout << wallet.countCoupons<MultiUseCoupon>(true) << endl;
     cout << wallet.countCoupons<MultiUseCoupon>(false) << endl;
     wallet.exportCounts("export-example-B.json");
     cout << endl;

    cout << "main() vege!" << endl;
    return 0;
}
