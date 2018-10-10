#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "ErrorState.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <stdlib.h>

using namespace std;

namespace AMA {

    void Product::name(const char *nme){
        prodName = new char[max_name_length + 1];
        strcpy(prodName, nme);
        if (nme == nullptr) {
            delete[] prodName;
        }
    }
    
    const char * Product::name() const{
        return (prodName[0] == '\0' ? nullptr : prodName);
    }
	void Product::setType()
	{
		prodType = 'N';
	}
	void Product::setSku(const char* sk){
        SKU = new char[max_sku_length + 1];
        strcpy(SKU, sk);
    }
    void Product::unit(const char *unit){
        prodUnit = new char[max_unit_length + 1];
        strcpy(prodUnit, unit);
    }
    void Product::price(double price){
        m_price = price;
    }
    void Product::taxed(bool tax){
        taxable = tax;
    }
    void Product::quanReq(int qty){
        qtyReq = qty;
    }
    
    bool Product::chkTaxed(const char* tax){
        return (std::strcmp(tax, "y") == 0 || std::strcmp(tax, "Y") == 0);
    }
    
    double Product::cost() const{
        double tempPrice = price();
        if (taxed()) {
            tempPrice += (tempPrice * tax_rate);
        }
        return tempPrice;
    }
    
    void Product::message(const char *msg){
        prodError.ErrorState::message(msg);
    }
    
    bool Product::isClear() const{
        return prodError.ErrorState::isClear();
    }
    
	
	const char Product::type() const
	{
		return prodType;
	}

	const char* Product::sku() const{
        return SKU;
    }
    
    const char* Product::unit()const{
        return prodUnit;
    }
    
    bool const Product::taxed() const{
        return taxable;
    }
    
    double const Product::price() const{
        return m_price;
    }
    
        //CONSTRUCTORS


    Product::Product(char prodtype){
        if (prodtype == 'N') {
	prodType = 'N';
            SKU = nullptr;
            prodName = nullptr;
            prodUnit = nullptr;
			qtyInStock = 0;
			qtyReq = 0;
			m_price = 0;
	
			prodError.clear();
        }else{
            prodType = prodtype;
        }
    }
    
    Product::Product(const char * sku, const char * nme, const char * unt, int stockQty, bool isTaxed, double prce, int stockReq){
		setType();
        setSku(sku);
        name(nme);
        unit(unt);
        quantity(stockQty);
        taxed(isTaxed);
        price(prce);
        quanReq(stockReq);
    }
    
    Product::Product(const Product &src){
        if(prodName != nullptr){
            name(src.prodName);
        }
		setType();
        setSku(src.SKU);
        unit(src.prodUnit);
        qtyInStock = src.qtyInStock;
        taxable = src.taxable;
        m_price = src.m_price;
        qtyReq = src.qtyReq;
        
    }
    
    Product & Product::operator=(const Product &src){
        
        if (this != &src && !src.isEmpty()) {
         
            name(src.prodName);
            setSku(src.SKU);
            unit(src.prodUnit);
            qtyInStock = src.qtyInStock;
            taxable = src.taxable;
            m_price = src.m_price;
            qtyReq = src.qtyReq;
        }
        return *this;
    }
    
    Product::~Product(){
        delete[]prodName;
    }
    bool Product::operator==(const char * str) const{
        return SKU == str;
           
    }
    double Product::total_cost() const{
        return (qtyInStock * cost());
    }
    void Product::quantity(int newQ){
        qtyInStock = newQ;
    }
    bool Product::isEmpty() const{
        return (prodName[0] == '\0');
    }
    
    int Product::qtyNeeded() const{
        return qtyReq;
    }
    
    int Product::quantity() const{
        return qtyInStock;
    }
    bool Product::operator>(const char *sku) const{
        return this->SKU > sku;
    }
    bool Product::operator>(const iProduct & rhs) const{
      unsigned int len = strlen(prodName);
        
        return len > (int)strlen(rhs.name());
    }
    int Product::operator+=(int addUnits){
        if(addUnits > 0){
            quantity(quantity() + addUnits);
        }
        return quantity();
    }
    std::fstream & Product::store(std::fstream & file, bool newLine) const{
        file << type() << "," << sku() << "," << (name() == nullptr ? "" : name()) << "," << unit() << "," << taxed() << "," << price() << "," << quantity() << "," << qtyNeeded();
        
        if (newLine == true) {
            file << std::endl;
        }
        
        return file;
    }
    std::fstream & Product::load(std::fstream & file){
            //extracts the fields for a single record from the fstream object
        
        char skuTemp[max_sku_length + 1];
        char prodUnitTemp[max_unit_length + 1];
        char prodNameTemp[max_name_length + 1];
        int qtyInStockTemp;
        int qtyReqTemp;
        double priceTemp;
        bool taxableTemp;
        file.getline(skuTemp, max_sku_length, ',');
        file.getline(prodNameTemp, max_name_length, ',');
        file.getline(prodUnitTemp, max_unit_length, ',');
        file >> taxableTemp;
		file.ignore();
		file >> priceTemp;	
        file.ignore();
        file >> qtyInStockTemp;
        file.ignore();
        file >> qtyReqTemp;
        
            //creates a temporary object from the extracted field data
		
        Product const temp(skuTemp, prodNameTemp, prodUnitTemp, qtyInStockTemp, taxableTemp, priceTemp, qtyReqTemp);
            //copy assigns the temporary object to the current object.
        *this = temp;
		
        return file;
    }
    std::ostream & Product::write(std::ostream & os, bool linear) const{

        
        if(!prodError.isClear()){
            os << prodError;
        }else{
            
            
            if(linear){
                os << setw(max_sku_length)<< left << sku() << "|"
                << setw(20)<< left << (name() == nullptr ? "" : name()) << "|"
                << setw(7) << right << fixed << setprecision(2) << cost() << "|"
                << setw(4) << quantity() << "|"
                << setw(10) << left << unit() << "|"
                << setw(4) << right << qtyNeeded() << "|";
            }else{
                os << " Sku: " << sku() << std::endl
                << " Name (no spaces): " << name() << std::endl
                << " Price: " << fixed << setprecision(2) << price() << std::endl
                << " Price after tax: ";
                if(!taxed()){
                    os << " N/A" << endl;
                }else{
                    os << cost()  << endl;
                }
                
                os << " Quantity on Hand: " << quantity() << " " << unit() <<std::endl
                << " Quantity needed: " << qtyNeeded();
            }
        }
        return os;
    }
    std::istream & Product::read(std::istream & is){
  
        int qtyInStockTemp;
        int qtyReqTemp;
        double priceTemp;
        char taxableTemp[2];
        bool tax;
        char skuTemp[max_sku_length + 1];
        char prodUnitTemp[max_unit_length + 1];
        char prodNameTemp[max_name_length + 1];
        
        
        std::cout << " Sku: ";
        if(is.peek() == '\n'){
            is.ignore();
        }
        is.getline(skuTemp, '\n');
           std::cout << " Name (no spaces): ";
        is.getline(prodNameTemp,'\n');  
       	   cout << " Unit: ";
        is.getline(prodUnitTemp, '\n');
		
        
        
        cout << " Taxed? (y/n): ";
        is >> taxableTemp;
        if(!is.fail() && (std::strcmp(taxableTemp, "y") == 0 || std::strcmp(taxableTemp, "Y") == 0 || std::strcmp(taxableTemp, "N") == 0 || std::strcmp(taxableTemp, "n") == 0)){
            
            tax = chkTaxed(taxableTemp);

			cout << " Price: ";
            is >> priceTemp;
            if(!is.fail()){
                
                cout << " Quantity on hand: ";
                is >> qtyInStockTemp;
                if(!is.fail()){
                      
                    cout << " Quantity needed: ";
                    is >> qtyReqTemp;
			cin.ignore(1000, '\n');
                    if(!is.fail()){
						
                        Product temp(skuTemp, prodNameTemp, prodUnitTemp, qtyInStockTemp, tax, priceTemp, qtyReqTemp );
                            //copy assigns the temporary object to the current object.
						prodError.clear();
                        *this = temp;
                    }else{
                        prodError.message("Invalid Quantity Needed Entry");
                    }
                }else{
                    prodError.message("Invalid Quantity Entry");
                }
            }else{
                prodError.message("Invalid Price Entry");
            }
            
        }else{
			prodError.message("Only (Y)es or (N)o are acceptable");
            is.setstate(ios::failbit);
            
        }
        return is;
    }
    std::ostream & operator<<(std::ostream &os, const iProduct &temp){
        return temp.write(os, true);
    }
    std::istream & operator>>(std::istream &is, iProduct &temp){
        return temp.read(is);
    }
    double operator+=(double &value, const iProduct &src){
        return value += src.total_cost();
    }
}
