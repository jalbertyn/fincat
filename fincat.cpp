// JA - it is good practice to insert comment about intended use, context, contributors, etc

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int dollars2rands(int x)
{
    return(x*20);
}

double calcRatioPM(double revenue, double expenses)
{
    return((revenue-expenses)/revenue);
}

double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ( (revenue-expenses)/assets );  //fixed the formula for the Return on Assets ratio
}

double calcRatioDE(double assets, double liabilities)
{
    return(liabilities/assets); //fixed the formula for the calculation of Debt-to-Equity
}

char categorisePM(double ratio)
{
    char cat;
    if (ratio<0.08)
        cat='unhealty';
    else if (ratio>=0.08 && ratio<0.15) //fixed the condition to satisfy the not less than 0.08 but less than 0.15
        cat='average';
    else
        cat='healthy';
    return(cat);
}

char categoriseRoA(double ratio)
{
    char cat;
    if (ratio < 0.08)
        cat = 'unhealthy';
    else if (ratio>=0.08 && ratio<0.15) //fixed the condition to satisfy the not less than 0.08 but less than 0.15
        cat = 'average';
    else
        cat = 'healthy';
    return(cat);
}

char categoriseDE(double ratio)
{
    char cat;
    if (ratio < 1)
        cat = 'healthy';
    else if (ratio < 2 && ratio >=1 ) //changed the ratio range for the testing to better suit the not less than 1 but less than 2
        cat = 'average';
    else
        cat = 'unhealthy';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    char cat, cat2, cat3;

    f_in.open(input_file,ios::in); 
    f_out.open(output_file,ofstream::out);

    while (!f_in.eof())
    {
    	f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        revenue_ZAR = dollars2rands(double(revenue_ZAR));
        ratio_PM = calcRatioPM(revenue_USD, expenses);
        cat=categorisePM(ratio_PM);
        ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);
        cat2 = categoriseRoA(ratio_RoA);
        ratio_DE = calcRatioDE(assets, liabilities);
        cat3 = categoriseDE(ratio_DE);;
	f_out << company_id << " " << ratio_PM << " " << cat << ratio_RoA << " " << cat3 << ratio_DE << " " << cat2 << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    // JA - Need to check that 3 arguments were supplied upon execution
    process_data(argv[1], argv[2]);
}
