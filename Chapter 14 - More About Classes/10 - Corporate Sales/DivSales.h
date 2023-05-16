#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales {

private:
	double sales_data[4];
	static double total_annual_corp_sales;

public:

	DivSales();

	void addSalesData(const double, const double, const double, const double);
	double getSalesFromQuarter(int) const;

	double getTotalAnnualCorpSales() const;

};

#endif