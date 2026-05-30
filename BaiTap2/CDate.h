#pragma once
#include <iostream>

class CDate {
private:
	int ngay, thang, nam;
public:
	CDate(int = 1, int = 1, int = 1);
	
	int getThang();
	int getNam();
	
	friend std::istream& operator>>(std::istream&, CDate&);
	friend std::ostream& operator<<(std::ostream&, const CDate&);
};