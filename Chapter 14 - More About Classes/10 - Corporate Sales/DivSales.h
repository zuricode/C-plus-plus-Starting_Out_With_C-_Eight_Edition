#ifndef DIVSALES_H
#define DIVSALES_H

const int NUMBER_OF_QUARTERS = 4;

class DivSales {

private:

	double sales_data[NUMBER_OF_QUARTERS];
	static double total_annual_corp_sales;

public:

	DivSales();
	DivSales(const double, const double, const double, const double);

	void addSalesData(const double, const double, const double, const double);
	void enterSalesData();

	double getSalesFromQuarter(int) const;
	double getTotalDivSales() const;

	double getTotalAnnualCorpSales() const;

};

#endif