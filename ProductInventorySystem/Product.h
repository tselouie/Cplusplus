#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <fstream>
#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"

using namespace std;

namespace AMA {
    
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;
    
    class Product: public iProduct {
        
    private:
        char prodType;
        char* SKU;
        char* prodUnit;
        char* prodName;
        int qtyInStock;
        int qtyReq;
        double m_price;
        bool taxable;
       
        
        
    protected:
		ErrorState prodError;
        void name(const char*);
        const char* name() const;
        double cost() const;
        void message(const char*);
        bool isClear() const;
        
    public:
            //getter

		const char type() const;
        const char* sku() const;
        const char* unit() const;
        const bool taxed() const;
        const double price() const;
        int qtyNeeded() const;
        int quantity() const;
        
            //setter
		void setType();
        void setSku(const char* sku);
        void unit(const char* unit);
        bool chkTaxed(const char* tax);
        void taxed(bool tax);
        void price(double price);
        void quantity(int);
        void quanReq(int qty);

        Product(char prodType = 'N');
        Product(const char* sku,const char* nme,const char* unit,int stockQty = 0,bool isTaxed = true, double price = 0.00, int stockReq = 0 );
        Product(const Product&);
        Product& operator=(const Product&);
        ~Product();
        bool operator==(const char*) const;
        double total_cost() const;      
        bool isEmpty() const;
        
        bool operator>(const char*) const;
        bool operator>(const iProduct&) const;
        int operator+=(int);
        
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear ) const;
        std::istream& read(std::istream& is);
    };
    std::ostream& operator<<(std::ostream&, const iProduct&);
    std::istream& operator>>(std::istream&, iProduct&);
    double operator+=(double&, const iProduct&);
};

#endif
